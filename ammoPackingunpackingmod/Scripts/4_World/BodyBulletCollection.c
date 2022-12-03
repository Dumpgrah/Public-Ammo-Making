
modded class Weapon_Base extends Weapon
{
    static float CASING_SPAWN_RATE = GetAmmoMakingSettings().CasingPercentChance;
	
    string GetCasingByAmmo (string ammo)
    {
        switch( ammo )
        {
            case "Bullet_762x54":
               return "DeFormedRifleCasing";
            case "Bullet_45ACP":
              return "DeFormedPistolCasing";
			case "Bullet_762x54":
               return "DeFormedRifleCasing";
			case "Bullet_762x54Tracer":
               return "DeFormedRifleCasing";
			case "Bullet_12GaugePellets"://
               return "CasingBuckshot";
			case "Bullet_12GaugeSlug":
              return "CasingSlug";
			case "Bullet_556x45":
               return "DeFormedRifleCasing";
			case "Bullet_556x45Tracer":
              return "DeFormedRifleCasing";
			 case "Bullet_545x39":
               return "DeFormedRifleCasing";
			case "Bullet_545x39Tracer":
              return "DeFormedRifleCasing";
			case "Bullet_308Win":
               return "DeFormedRifleCasing";
			case "Bullet_308WinTracer"://
               return "DeFormedRifleCasing";
			case "Bullet_762x39":
              return "DeFormedRifleCasing";
			case "Bullet_762x39Tracer":
               return "DeFormedRifleCasing";
			case "Bullet_9x39AP":
              return "DeFormedRifleCasing";
			case "Bullet_9x39":
               return "DeFormedRifleCasing";
			case "Bullet_762x54OP":
              return "DeFormedRifleCasing";
			case "Bullet_308OP":
               return "DeFormedRifleCasing";
			//Pistols
			case "Bullet_357":
              return "DeFormedPistolCasing";
			case "Bullet_9x19":
              return "DeFormedPistolCasing";
			case "Bullet_380":
              return "DeFormedPistolCasing";
			case "Bullet_22":
              return "DeFormedPistolCasing";
			case "Bullet_45ACP":
              return "DeFormedPistolCasing";	
			  
        }
    
        return "";
    };
    
    override void EEFired (int muzzleType, int mode, string ammoType)
    {
        super.EEFired ( muzzleType,  mode,  ammoType);
        if(GetGame().IsServer())
		{
			PlayerBase player = PlayerBase.Cast( this.GetHierarchyRootPlayer() );
			vector pos = player.GetPosition();
			float rndValue = Math.RandomFloat(1,100);

			if ( rndValue < CASING_SPAWN_RATE )
			{
				if (GetCasingByAmmo (ammoType) != "" && player)
				{
					Print(ammoType); //? not 100%
					GetGame().CreateObjectEx( GetCasingByAmmo (ammoType), player.GetPosition(), ECE_PLACE_ON_SURFACE );
				}
			}
        }
    }
};

modded class PlayerBase
{
	static float TIP_SPAWN_RATE = GetAmmoMakingSettings().TipsPercentChancePlayer;
	
	ref map<string, int> AmmoHitBy = new map<string, int>;

	void IncrementAmmo(string ammo)
	{
		if ( AmmoHitBy.Get(ammo) )
		{ //ammo exsist
            int count = AmmoHitBy.Get(ammo);
            count++;
            AmmoHitBy.Set(ammo, count);
		}
		else
		{
           AmmoHitBy.Set(ammo, 1);
		}
	}

	string GetTipByAmmo (string ammo)
	{
		switch( ammo )
        {	
			case "Bullet_762x54":
               return "DeFormedRifleTips";
			case "Bullet_762x54Tracer":
               return "DeFormedRifleTips";
			case "Bullet_12GaugePellets"://
               return "TipsBuckshot";
			case "Bullet_12GaugeSlug":
              return "TipsSlug";
			case "Bullet_556x45":
               return "DeFormedRifleTips";
			case "Bullet_556x45Tracer":
              return "DeFormedRifleTips";
			 case "Bullet_545x39":
               return "DeFormedRifleTips";
			case "Bullet_545x39Tracer":
              return "DeFormedRifleTips";
			case "Bullet_308Win":
               return "DeFormedRifleTips";
			case "Bullet_308WinTracer"://
               return "DeFormedRifleTips";
			case "Bullet_762x39":
              return "DeFormedRifleTips";
			case "Bullet_762x39Tracer":
               return "DeFormedRifleTips";
			case "Bullet_9x39AP":
              return "DeFormedRifleTips";
			case "Bullet_9x39":
               return "DeFormedRifleTips";
			case "Bullet_762x54OP":
              return "DeFormedRifleTips";
			case "Bullet_308OP":
               return "DeFormedRifleTips";
			//Pistols
			case "Bullet_357":
              return "DeFormedPistolTips";
			case "Bullet_9x19":
              return "DeFormedPistolTips";
			case "Bullet_380":
              return "DeFormedPistolTips";
			case "Bullet_22":
              return "DeFormedPistolTips";
			case "Bullet_45ACP":
              return "DeFormedPistolTips";			  
        }

        return "";
	};
		override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{    
        super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		float rndValue = Math.RandomFloat(1,100);

		if ( rndValue < TIP_SPAWN_RATE )
		{
			if ( ammo && ammo != "")
			{
				IncrementAmmo( ammo);
				Print (ammo);
			}
		}
    }
	override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
		for (int i = 0; i < AmmoHitBy.Count(); i++)
		{
			string ammo = AmmoHitBy.GetKey(i);
			int count = AmmoHitBy.GetElement(i); 
			if (GetTipByAmmo(ammo) != "")
			{
				ItemBase theTip = ItemBase.Cast(this.GetInventory().CreateInInventory(GetTipByAmmo (ammo)));
				if (theTip)
				{
					theTip.SetQuantity(count);
				}
			}
		}
	};
};
modded class ZombieBase
{
	static float TIP_SPAWN_RATE = GetAmmoMakingSettings().TipsPercentChanceInfected;
	
	ref map<string, int> AmmoHitBy = new map<string, int>;

	void IncrementAmmo(string ammo)
	{
		if ( AmmoHitBy.Get(ammo) )
		{ //ammo exsist
            int count = AmmoHitBy.Get(ammo);
            count++;
            AmmoHitBy.Set(ammo, count);
		}
		else
		{
           AmmoHitBy.Set(ammo, 1);
		}
	}
	
	string GetTipByAmmo (string ammo)
	{
		switch( ammo )
        {	
			case "Bullet_762x54":
               return "DeFormedRifleTips";
			case "Bullet_762x54Tracer":
               return "DeFormedRifleTips";
			case "Bullet_12GaugePellets"://
               return "TipsBuckshot";
			case "Bullet_12GaugeSlug":
              return "TipsSlug";
			case "Bullet_556x45":
               return "DeFormedRifleTips";
			case "Bullet_556x45Tracer":
              return "DeFormedRifleTips";
			 case "Bullet_545x39":
               return "DeFormedRifleTips";
			case "Bullet_545x39Tracer":
              return "DeFormedRifleTips";
			case "Bullet_308Win":
               return "DeFormedRifleTips";
			case "Bullet_308WinTracer"://
               return "DeFormedRifleTips";
			case "Bullet_762x39":
              return "DeFormedRifleTips";
			case "Bullet_762x39Tracer":
               return "DeFormedRifleTips";
			case "Bullet_9x39AP":
              return "DeFormedRifleTips";
			case "Bullet_9x39":
               return "DeFormedRifleTips";
			case "Bullet_762x54OP":
              return "DeFormedRifleTips";
			case "Bullet_308OP":
               return "DeFormedRifleTips";
			//Pistols
			case "Bullet_357":
              return "DeFormedPistolTips";
			case "Bullet_9x19":
              return "DeFormedPistolTips";
			case "Bullet_380":
              return "DeFormedPistolTips";
			case "Bullet_22":
              return "DeFormedPistolTips";
			case "Bullet_45ACP":
              return "DeFormedPistolTips";			  
        }

        return "";
	};
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{    
        super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		float rndValue = Math.RandomFloat(1,100);

		if ( rndValue < TIP_SPAWN_RATE )
		{
			if ( ammo && ammo != "")
			{
				IncrementAmmo( ammo);
				Print (ammo);
			}
		}
    }
	override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
		for (int i = 0; i < AmmoHitBy.Count(); i++)
		{
			string ammo = AmmoHitBy.GetKey(i);
			int count = AmmoHitBy.GetElement(i); 
			if (GetTipByAmmo(ammo) != "")
			{
				ItemBase theTip = ItemBase.Cast(this.GetInventory().CreateInInventory(GetTipByAmmo (ammo)));
				if (theTip)
				{
					theTip.SetQuantity(count);
				}
			}
		}
	};
};