ref AmmoMakingSettings m_AmmoMakingSettings
class AmmoMakingSettings
{ 
	protected static string DirPATH = "$profile:Ammo Making";
	protected static string AmmoMakingPath = DirPATH + "\\Spent Ammo.json";
	
	//Default Values
	string ConfigVersion = "2";
	
	int CasingPercentChance = 20;
	int TipsPercentChanceInfected = 50;
	int TipsPercentChancePlayer = 35;
	
	void AmmoMakingSettings()
	{
		
	}
	
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (FileExist(AmmoMakingPath)) //If config exist load File
		{
	        JsonFileLoader<AmmoMakingSettings>.JsonLoadFile(AmmoMakingPath, this);
			if ( ConfigVersion != "2")
			{
				ConfigVersion = "2";
				CasingPercentChance = 20;
				TipsPercentChanceInfected = 50;
				TipsPercentChancePlayer = 35;
				JsonFileLoader<AmmoMakingSettings>.JsonSaveFile(AmmoMakingPath, this);
			}
		}
		else//File does not exist create file
		{
			if (!FileExist(DirPATH))
			{
				MakeDirectory(DirPATH);
			}
			JsonFileLoader<AmmoMakingSettings>.JsonSaveFile(AmmoMakingPath, this);
		}
	}
	
};

//Helper function to return Config
static ref AmmoMakingSettings GetAmmoMakingSettings()
{
	if (!m_AmmoMakingSettings)
	{
		m_AmmoMakingSettings = new AmmoMakingSettings;
		m_AmmoMakingSettings.Load();
	}
	return m_AmmoMakingSettings;
};
