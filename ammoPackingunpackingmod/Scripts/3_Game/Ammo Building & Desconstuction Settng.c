ref AmmoBuildingSettings m_AmmoBuildingSettings
class AmmoBuildingSettings
{ 
	protected static string DirPATH = "$profile:Ammo Making";
	protected static string AmmoBuildingPath = DirPATH + "\\Deconstruct & Build Ammo.json";
	
	//Default Values
	string ConfigVersion = "3";
	
	int Safe_Mode = 1;
	string I1  ="GunPowder Required to Fill Casings";
	float GunPowder_Percentage_Required = 100; //value of 0-100
	string Deconstruct ="Deconstruct Loss Percentages";
	float Gunpowder_Saved_Percentage = 85;
	float Tips_Saved_Percentage = 80;
	float Casing_Saved_Percentage = 80;
	float Dmg_To_Pliers_Per_Bullet = 0.5;
	float Chance_To_DMG_40mm_Grenade = 20;
	float Dmg_Done_To_Grenade_Per_Fail = 16.66;
	
	void AmmoBuildingSettings()
	{
		
	}
	
	// Load config file or create default file if config doesn't exsit
	void Load()
	{
		if (FileExist(AmmoBuildingPath)) //If config exist load File
		{
	        JsonFileLoader<AmmoBuildingSettings>.JsonLoadFile(AmmoBuildingPath, this);
			if ( ConfigVersion != "3")
			{
				ConfigVersion = "3";
				Safe_Mode = 1;
				I1  ="GunPowder Required to Fill Casings";
				GunPowder_Percentage_Required = 100; //value of 0-100
				Deconstruct = "Deconstruct Loss Percentages";
				Gunpowder_Saved_Percentage = 85; //value of 0-100
				Tips_Saved_Percentage = 80;
				Casing_Saved_Percentage = 80;
				Dmg_To_Pliers_Per_Bullet = 0.5;
				Chance_To_DMG_40mm_Grenade = 20;
				Dmg_Done_To_Grenade_Per_Fail = 16.66;
				JsonFileLoader<AmmoBuildingSettings>.JsonSaveFile(AmmoBuildingPath, this);
			}
		}
		else//File does not exist create file
		{
			if (!FileExist(DirPATH))
			{
				MakeDirectory(DirPATH);
			}
			JsonFileLoader<AmmoBuildingSettings>.JsonSaveFile(AmmoBuildingPath, this);
		}
		
		if(Safe_Mode == 1 )
		{
			if (GunPowder_Percentage_Required > 500)
			{
				GunPowder_Percentage_Required = 500;
			}
			else if(GunPowder_Percentage_Required < 0)
			{
				GunPowder_Percentage_Required = 0;
			}
			
			if (Gunpowder_Saved_Percentage > 200)
			{
				Gunpowder_Saved_Percentage = 200;
			}
			else if(Gunpowder_Saved_Percentage < 0)
			{
				Gunpowder_Saved_Percentage = 0;
			}
			
			if (Tips_Saved_Percentage > 100)
			{
				Tips_Saved_Percentage = 100;
			}
			else if(Tips_Saved_Percentage < 0)
			{
				Tips_Saved_Percentage = 0;
			}
			
			if (Casing_Saved_Percentage > 100)
			{
				Casing_Saved_Percentage = 100;
			}
			else if(Casing_Saved_Percentage < 0)
			{
				Casing_Saved_Percentage = 0;
			}
			
			
			if (Chance_To_DMG_40mm_Grenade > 100)
			{
				Chance_To_DMG_40mm_Grenade = 100;
			}
			else if(Chance_To_DMG_40mm_Grenade < 0)
			{
				Chance_To_DMG_40mm_Grenade = 0;
			}
			
			if (Dmg_Done_To_Grenade_Per_Fail > 50)
			{
				Dmg_Done_To_Grenade_Per_Fail = 50;
			}
			else if(Dmg_Done_To_Grenade_Per_Fail < 0)
			{
				Dmg_Done_To_Grenade_Per_Fail = 0;
			}
		};
	
	}
	//Perchanged Math
	float GetPercentageValueGunpowderRequired()
	{
		return GunPowder_Percentage_Required / 100;
	}
	float GetPercentageValueGunPowderLoss()
	{
		return Gunpowder_Saved_Percentage / 100;
	}
	float GetPercentageValueTipsLoss()
	{
		return Tips_Saved_Percentage / 100;
	}
	float GetPercentageValueCasingLoss()
	{
		return Casing_Saved_Percentage / 100;
	}
	
};

//Helper function to return Config
static ref AmmoBuildingSettings GetAmmoBuildingSettings()
{
	if (!m_AmmoBuildingSettings)
	{
		m_AmmoBuildingSettings = new AmmoBuildingSettings;
		m_AmmoBuildingSettings.Load();
	}
	return m_AmmoBuildingSettings;
};