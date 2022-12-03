modded class Screwdriver
{

	override void SetActions()
	{
		super.SetActions();

		AddAction(AM_BreakDown40m);
	}
};
class AM_UADamageApplied
{
	const float Dmg40mmGrenade	= GetAmmoBuildingSettings().Dmg_Done_To_Grenade_Per_Fail;
	const float dmgMainItemscrewDriver = 2;
};
class AM_BreakDown40mCA : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5 ); // Dont forget to change back to 30
	}
};
class AM_BreakDown40m: ActionContinuousBase
{
	void AM_BreakDown40m()
	{
		m_CallbackClass = AM_BreakDown40mCA;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody 		= true;
    };

    override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINonRuined;
		m_ConditionTarget 	= new CCTCursor;
    };

    override string GetText()
	{
        return "Break Down ";
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{

        Object target_object = target.GetObject();
		Ammo_40mm_Base FortyGrenade = Ammo_40mm_Base.Cast( target_object );
        
        if (FortyGrenade)
		{
            return true;
        }
        return false;
    };
    
	override void OnFinishProgressServer( ActionData action_data )
    {
	   float ChanceToPullApart = GetAmmoBuildingSettings().Chance_To_DMG_40mm_Grenade;
	   
	   
	
		float ChanceSuccess = Math.RandomInt(0,100);

		Ammo_40mm_Base FortymmGrenade = Ammo_40mm_Base.Cast( action_data.m_Target.GetObject() );

		
		if(ChanceSuccess <= ChanceToPullApart)
		{
			if(FortymmGrenade.IsKindOf("Ammo_40mm_Explosive"))
			{
				GetGame().CreateObjectEx("Tips40mm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
			}
			else if(FortymmGrenade.IsKindOf("Ammo_40mm_Smoke_Red"))
			{
				GetGame().CreateObjectEx("Tips40mm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
			}
			else if(FortymmGrenade.IsKindOf("Ammo_40mm_Smoke_Green"))
			{
				GetGame().CreateObjectEx("Tips40mm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
			}
			else if(FortymmGrenade.IsKindOf("Ammo_40mm_Smoke_White"))
			{
				GetGame().CreateObjectEx("Tips40mm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
			}
			else if(FortymmGrenade.IsKindOf("Ammo_40mm_Smoke_Black"))
			{
				GetGame().CreateObjectEx("Tips40mm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
			}
				GetGame().CreateObjectEx("Casing40mm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
				ItemBase RDXCompound = ItemBase.Cast( GetGame().CreateObjectEx("RDXCompound", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE) );
				ItemBase Gunpowder1 = ItemBase.Cast( GetGame().CreateObjectEx("Gunpowder", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE) );
				RDXCompound.SetQuantity(23);
				Gunpowder1.SetQuantity(36);
				FortymmGrenade.Delete();
			
		}
		else
		{
			action_data.m_MainItem.DecreaseHealth( AM_UADamageApplied.dmgMainItemscrewDriver, false );	
				
			FortymmGrenade.DecreaseHealth( AM_UADamageApplied.Dmg40mmGrenade, false );
			
		};

	
    };
};
