/*
m_FireplaceRadius = is how far the fireplace light shines

m_FireplaceBrightness = is how bright it is

TimeBeforeSmelting = how many seconds before the smelter locks when said variables are met

SetTemperature = how Hot the Furnace will show in Celsius, in the futrue will affect how much heat it provides to said area and also dmg to player if player is too close

ItemGoesHere().GetQuantity() >=  // this is a call to check how much of an item thats just before this to have before starting the smelting operation, if the number is below the number you put just after the >= sign it will not trigger the function(ItemGoesHere = the name of the item you wish to check for quantity off). 

Lock(#) = how long the smelters function will lock the attachments and inventory (if present) of said smelter. when its done in its timer it will unlock and show the contents.

Note 
*/
class Potassium_Nitrate extends ItemBase{};
class Sulfur20LbBag extends ItemBase{};
class EmptyCrucible extends ItemBase{};
class CrucibleFilledCasing extends ItemBase{};
class CrucibleFilledTips extends ItemBase{};


class StandAloneSmelter extends ItemBase
{	

	protected FireplaceLight m_Light; // Light entity
	
	protected ref Timer m_AmmoCoolingTimer;
	
	protected int PARTICLE_Fire_START           = ParticleList.SmelterSmoke11;
	protected Particle m_ParticleSmokeStart;
	protected Particle m_PaticleFireStart;
	
	protected int					m_FirePointIndex = 1;	//limited to 1 decimal place (1-9)
	
	const string SOUND_BURNING 		= "portablegasstove_burn_SoundSet";
	const string SOUND_TURN_ON		= "portablegasstove_turn_on_SoundSet";
	const string SOUND_TURN_OFF		= "portablegasstove_turn_off_SoundSet";
	
	protected EffectSound m_SoundBurningLoop;
	protected EffectSound m_SoundTurnOn;
	protected EffectSound m_SoundTurnOff;
	
	static const string FIREPOINT_FIRE_POSITION 	= "fireplace_point";
	static const string FIREPOINT_SMOKE_POSITION 	= "fireplace_smoke";
	static const string FIREPOINT_LIGHT_POSITION    = "fireplace_light";
	static float m_FireplaceRadius = 5;
	static float m_FireplaceBrightness = 2.75;
	private ref Timer m_FurnaceSmeltTime;
	ref Timer m_TimeBeforeSmelting;
	private bool m_IsLocked = false;
	bool m_IsCurrentlySmelting = false;
	protected bool ActionCondition
	protected bool m_IsIgnited;
	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;


	int TimeToSmeltTips = GetAmmoSmelting().Time_To_Smelt_Tips;
	int TimeToSmeltCasing = GetAmmoSmelting().Time_To_Smelt_Casing;
	int EfficiencyMin = GetAmmoSmelting().Smelter_Efficiency_Min;  
    int EfficiencyMax = GetAmmoSmelting().Smelter_Efficiency_Max;
	int SmelterHeatingRate = GetAmmoSmelting().Smelter_Heating_Rate;
	int SmelterCoolingRate = GetAmmoSmelting().Smelter_Cooling_Rate;
	
	void StandAloneSmelter()
	{
		m_FurnaceSmeltTime = new Timer();
		m_TimeBeforeSmelting = new Timer();
		
		
		
	}	
	FireplaceLight GetLightEntity()
	{
		return m_Light;
	}
	
	void SetLightEntity( FireplaceLight light )
	{
		m_Light = light;
	}

	
	bool IsLocked()
	{
		return m_IsLocked;

	}

	void TimeBeforeSmelting( float actiontime)
	{
		m_TimeBeforeSmelting.Run(actiontime, this, "DoNothing", NULL, false);
	}
	void DoNothing() // timer required 
	{
		
	}

	protected bool PlayParticle( out Particle particle, int particle_type, vector local_pos )
	{
		if ( !particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle = Particle.PlayOnObject( particle_type, this, local_pos );
			
			return true;
		}
		
		return false;
	}
	protected bool StopParticle( out Particle particle )
	{
		if ( particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle.Stop();
			particle = NULL;
			
			return true;
		}
		
		return false;
	}
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		
		return false;
	}
	//Has attachments of required quantity
	bool IsItemAttachedQuantity( typename item_type, float quantity )
	{
		ItemBase item = ItemBase.Cast( GetAttachmentByType( item_type ) );
		
		if ( item.GetQuantity() >= quantity )
		{
			GetLightEntity().SetInteriorMode();
			return true;
		}
		
		return false;
	}


	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);

		//if ( !item.IsKindOf("ND_StackedCoal")) // any attachment but coal
		//{
		//	StopCooling();
		//	TimeBeforeSmelting(5);
		//}
		//if ( item.IsKindOf("ND_StackedCoal")) // attachmented coal
		//{
		//	SetTemperature(1);
		//	StopCooling();
		//}
	}
	
	

	void Lock(float actiontime)
	{	

		m_IsLocked = true;
		m_FurnaceSmeltTime.Run(actiontime, this, "Unlock", NULL,false);
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		//RemoveAction(ActionTurnOffWhileOnGround) = true;
		//if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		//{
		//  ParticleSmokeStart();
		//}

	}
	
	//protected void ParticleSmokeStart()
	//{
	//	PlayParticle( m_ParticleSmokeStart, PARTICLE_Smoke_Start, GetMemoryPointPos("fireplace_smoke") );
	//}
	
	void Unlock()
	{
		m_IsLocked = false;
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		
	}
	override void OnWork( float consumed_energy  )
	{
		
		if ( GetGame() && GetGame().IsServer()  )
		{
			StartHeating();
			float temperature = GetTemperature();
			temperature = temperature + SmelterHeatingRate;
			SetTemperature( temperature );
			TransferHeatToNearPlayers();
			LockGas(true);
			Smelt();
			BurnItemsInFireplace();
		}
	}
	override void OnWorkStart()
	{

		if ( !GetLightEntity() && (!GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
		   PlayParticle( m_PaticleFireStart, PARTICLE_Fire_START, GetMemoryPointPos("fireplace_point") );
		  // PlayParticle( m_ParticleSmokeStart, PARTICLE_Smoke_Start, GetMemoryPointPos("fireplace_smoke") );
		   SetLightEntity( FireplaceLight.Cast( ScriptedLightBase.CreateLight(FireplaceLight, GetMemoryPointPos("fireplace_light") ) ) );
		   GetLightEntity().AttachOnMemoryPoint(this, "fireplace_light");
		   TransferHeatToNearPlayers();
		   SoundBurningStart();
		}
	}
	override void OnWorkStop()
	{
		m_IsCurrentlySmelting = false;
		StopParticle(m_PaticleFireStart);
		//StopParticle(m_ParticleSmokeStart);
		if (GetLightEntity())
		{
			GetLightEntity().FadeOut();
		}
		LockGas(false);
		StopHeating();
		StartCooling();
		SoundBurningStop();
		

	}
	protected void BurnItemsInFireplace()
	{

		
		//Fuel (only) attachments
		for ( int j = 0; j < GetInventory().AttachmentCount(); ++j )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );

			//add temperature
			AddTemperatureToItemByFire( attachment );
		
		}
	}
	protected void AddTemperatureToItemByFire( ItemBase item )
	{
		if ( item.GetTemperatureMax())
		{
			float temperature = item.GetTemperature();
			temperature = temperature + 55;
			item.SetTemperature( temperature );
		}
	}
	
	protected void TransferHeatToNearPlayers()
	{
		float distance;

		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition ( GetPosition(), 3.0, nearest_objects, proxy_cargos ); 

		for ( int i = 0; i < nearest_objects.Count(); i++ )
		{
			Object nearest_object = nearest_objects.Get(i);
			
			//! heat transfer to player
			if ( nearest_object.IsInherited( PlayerBase ) )
			{
				PlayerBase player = PlayerBase.Cast( nearest_object );
				distance = vector.Distance( player.GetPosition(), GetPosition() );
				distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
				
				//! heat transfer through air to player ( anv temperature )
				float temperature = GetTemperature() * ( 0.017 / distance );
				player.AddToEnvironmentTemperature( temperature );
			}
			//! heat transfer to items (not in player possession)
			else if ( nearest_object != this && nearest_object.IsInherited( ItemBase ) && nearest_object.GetParent() == null )
			{
				ItemBase item = ItemBase.Cast( nearest_object );
				float wetness = item.GetWet();

				//! drying of items around the fireplace (based on distance)
				if ( wetness > 0 )
				{
					distance = vector.Distance( item.GetPosition(), GetPosition() );
					distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
					
					wetness = wetness * ( 0.035 / distance );
					wetness = Math.Clamp( wetness, item.GetWetMin(), item.GetWetMax() );
					item.AddWet( -wetness );
				}
			}
		}
	}

	protected void StartHeating()
	{		
		m_HeatingTimer = new Timer ( CALL_CATEGORY_GAMEPLAY );
		m_HeatingTimer.Run ( 2, this, "Heating", NULL, true );	
	}

	protected void StopHeating()
	{
		if(m_HeatingTimer)
		{
			m_HeatingTimer.Stop();
			m_HeatingTimer = NULL;
		};
	}
	protected void StartCooling()
	{
		if ( m_HeatingTimer )
		{
			m_HeatingTimer.Stop();
			m_HeatingTimer = NULL;
		}
		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 5, this, "Cooling", NULL, true );		// true param loops
	}
	void Cooling()
	{
		float temperature = GetTemperature();
		temperature = temperature - SmelterCoolingRate;

		SetTemperature(temperature);

		if ( GetTemperature() == 1)
		{
			StopCooling();
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
			//Print("zxd");
		}
	}
	protected void StopCooling()
	{
		//Stop cooling
		if(m_CoolingTimer)
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
		};
	}

	//Do heating
	protected void Heating()
	{

		float temperature = GetTemperature();
		temperature = temperature + SmelterHeatingRate;
		SetTemperature( temperature );
		
		//transfer heat to near players
		TransferHeatToNearPlayers();
		
	}
	
	void LockGas(bool do_lock)
	{
		ItemBase SmelterLargeGasCanister = GetlargeGasFuel();
		ItemBase SmelterMediumGasCanister = GetMediumGasFuel();
		ItemBase SmelterSmallGasCanister = GetSmallGasFuel();
		
		if (SmelterLargeGasCanister)
		{
			if (do_lock)
			{
				SmelterLargeGasCanister.LockToParent();
			}
			else
			{
				SmelterLargeGasCanister.UnlockFromParent();
			}
		}
		if (SmelterMediumGasCanister)
		{
			if (do_lock)
			{
				SmelterMediumGasCanister.LockToParent();
			}
			else
			{
				SmelterMediumGasCanister.UnlockFromParent();
			}
		}
		if (SmelterSmallGasCanister)
		{
			if (do_lock)
			{
				SmelterSmallGasCanister.LockToParent();
			}
			else
			{
				SmelterSmallGasCanister.UnlockFromParent();
			}
		}
	}
	
	override bool CanPutIntoHands(EntityAI parent)
    {
		if ( GetTemperature() >= 10)
		{
			return false;
		}
		return true;
    }
	
	override bool CanPutInCargo( EntityAI parent )
    {
		if ( GetTemperature() >= 10)
		{
			return false;
		}
		return true;
    }
	
	protected void SoundBurningStart()
	{
		PlaySoundSetLoop( m_SoundBurningLoop, SOUND_BURNING, 0.1, 0.3 );
	}
	
	protected void SoundBurningStop()
	{
		StopSoundSet( m_SoundBurningLoop );
	}	

	protected void SoundTurnOn()
	{
		PlaySoundSet( m_SoundTurnOn, SOUND_TURN_ON, 0.1, 0.1 );
	}
	
	protected void SoundTurnOff()
	{
		PlaySoundSet( m_SoundTurnOff, SOUND_TURN_OFF, 0.1, 0.1 );
	}	


		

    LargeGasCanister GetlargeGasFuel()
	{
		if (!GetInventory())
		{
			return null;
		}
		
		return LargeGasCanister.Cast( GetAttachmentByType(LargeGasCanister) );
	}
	MediumGasCanister GetMediumGasFuel()
	{
		if (!GetInventory())
		{
			return null;
		}
		return MediumGasCanister.Cast( GetAttachmentByType(MediumGasCanister) );
	}
	SmallGasCanister GetSmallGasFuel()
	{
		if (!GetInventory())
		{
			return null;
		}
		return SmallGasCanister.Cast( GetAttachmentByType(SmallGasCanister) );
	}
	

	CrucibleFilledTips GetTheTip()
	{
		if (!GetInventory())
		{
			return null;
		}
		return CrucibleFilledTips.Cast( GetAttachmentByType(CrucibleFilledTips) );
	}

	CrucibleFilledCasing GetCasing()
	{
		if (!GetInventory())
		{
			return null;
		}
		return CrucibleFilledCasing.Cast( GetAttachmentByType(CrucibleFilledCasing) );
	}

	CrucibleMoltenBrass GetMoltenBrass()
	{
		if (!GetInventory())
		{
			return null;
		}
		return CrucibleMoltenBrass.Cast( GetAttachmentByType( CrucibleMoltenBrass ));
	}

	CrucibleMoltenLead GetMoltenLead()
	{
		if (!GetInventory())
		{
			return null;
		}
		return CrucibleMoltenLead.Cast( GetAttachmentByType( CrucibleMoltenLead ) );
	}

	void Smelt()
	{
	  
	    if (!GetMoltenBrass() && !GetMoltenLead() && !m_TimeBeforeSmelting.IsRunning() ) //Has no outputs, disabled other smelting operations if Molten metal above is present.
	    {
				
			if ( GetCasing() && !GetSmallGasFuel() && !m_TimeBeforeSmelting.IsRunning() ) // after the timer for attaching items is over and the requisite item is attached
			{
				float CasingQuantity = GetCasing().GetQuantity();
				float percentage 10;
				GetGame().ObjectDelete(GetCasing() );
				GetInventory().CreateAttachment ("CrucibleMoltenBrass"); // attachment must be created before inventory is locked
				float moltenBrassQuantity = (percentage + Math.RandomInt(EfficiencyMin,EfficiencyMax) ) / 100 * CasingQuantity;
				GetMoltenBrass().SetQuantity (moltenBrassQuantity);
				//GetCasing().SetQuantity( CasingQuantity )
				Lock(TimeToSmeltCasing); 
				
			}
		
			if ( GetTheTip() && !m_TimeBeforeSmelting.IsRunning() ) // after the timer for attaching items is over and the requisite item is attached
			{
				float TipQuantity = GetTheTip().GetQuantity();
				GetGame().ObjectDelete(GetTheTip() );
				GetInventory().CreateAttachment("CrucibleMoltenLead"); // attachment must be created before inventory is locked
				float moltenLeadQuantity2 = (percentage + Math.RandomInt(EfficiencyMin,EfficiencyMax) ) / 100 * TipQuantity;
				GetMoltenLead().SetQuantity (moltenLeadQuantity2);
				Lock(TimeToSmeltTips); 
			}

	    } 
	}
	
	
	
	override void SetActions()
	{
		super.SetActions();

        AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTurnOffSmelter);

	}
	//Tips.GetQuantity() == Tips.GetQuantityMax() && !m_TimeBeforeSmelting.IsRunning()
};