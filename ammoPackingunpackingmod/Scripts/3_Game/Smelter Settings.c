ref AmmoSmelting m_AmmoSmelting
class AmmoSmelting
{ 
	protected static string DirPATH = "$profile:Ammo Making";
	protected static string AmmoMakingPath = DirPATH + "\\Smelter & Casting.json";
	
	//Default Values
	string ConfigVersion = "1";
	string ZeroSpacer = "Ignore me dont touch";
	string ZeroBreak = "SMELTER SETTINGS";
	int Time_To_Smelt_Tips = 120;
	int Time_To_Smelt_Casing = 250;
	int Smelter_Efficiency_Min = 90;
	int Smelter_Efficiency_Max = 100;
	int Smelter_Heating_Rate = 8;
	int Smelter_Cooling_Rate = 10;
	string FirstSpacer = "Ignore me dont touch";
	string FirstBreak = "CASTING SETTINGS";
	int Tempature_To_Cast_Tips = 150;
	int Tempature_To_Cast_Casings = 300;
	
	
	void AmmoSmelting()
	{
		
	}
	
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (FileExist(AmmoMakingPath)) //If config exist load File
		{
	        JsonFileLoader<AmmoSmelting>.JsonLoadFile(AmmoMakingPath, this);
			if ( ConfigVersion != "1")
			{
				ConfigVersion = "1";

				JsonFileLoader<AmmoSmelting>.JsonSaveFile(AmmoMakingPath, this);
			}
		}
		else//File does not exist create file
		{
			if (!FileExist(DirPATH))
			{
				MakeDirectory(DirPATH);
			}
			JsonFileLoader<AmmoSmelting>.JsonSaveFile(AmmoMakingPath, this);
		}
	}
	
};

//Helper function to return Config
static ref AmmoSmelting GetAmmoSmelting()
{
	if (!m_AmmoSmelting)
	{
		m_AmmoSmelting = new AmmoSmelting;
		m_AmmoSmelting.Load();
	}
	return m_AmmoSmelting;
};
