modded class MissionGameplay extends MissionBase
{
    override void OnMissionStart()
	{
        super.OnMissionStart();
		GetRPCManager().AddRPC( "Dumpgrah_AMS", "RPCAmmoMakingSettings", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "Dumpgrah_ABS", "RPCAmmoBuildingSettings", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "Dumpgrah_AS", "RPCAmmoSmelting", this, SingeplayerExecutionType.Both );
		
		
		GetRPCManager().SendRPC("Dumpgrah_AMS", "RPCAmmoMakingSettings", new Param1< AmmoMakingSettings >( NULL ), true, NULL);
		GetRPCManager().SendRPC("Dumpgrah_ABS", "RPCAmmoBuildingSettings", new Param1< AmmoBuildingSettings >( NULL ), true, NULL);
		GetRPCManager().SendRPC("Dumpgrah_AS", "RPCAmmoSmelting", new Param1< AmmoSmelting >( NULL ), true, NULL);
	}
	
	void RPCAmmoMakingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< AmmoMakingSettings > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_AmmoMakingSettings = data.param1;
	}
	void RPCAmmoBuildingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< AmmoBuildingSettings > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_AmmoBuildingSettings = data.param1;
	}
	void RPCAmmoSmelting( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< AmmoSmelting > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_AmmoSmelting = data.param1;
	}
};
modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		GetAmmoMakingSettings();
		GetAmmoBuildingSettings();
		GetAmmoSmelting();
		
		
		GetRPCManager().AddRPC( "Dumpgrah_AMS", "RPCSyncMyCustomConfig", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "Dumpgrah_ABS", "RPCSyncMyCustomConfig", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "Dumpgrah_AS", "RPCSyncMyCustomConfig", this, SingeplayerExecutionType.Both );
	}
	
			
	void SendAmmoMakingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
        if (sender)
		{
			GetRPCManager().SendRPC("Dumpgrah_AMS", "RPCAmmoMakingSettings", new Param1< AmmoMakingSettings >( GetAmmoMakingSettings() ), true, sender);
		}
	}
	
	void SendAmmoBuildingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
        if (sender)
		{
			GetRPCManager().SendRPC("Dumpgrah_ABS", "RPCAmmoBuildingSettings", new Param1< AmmoBuildingSettings >( GetAmmoBuildingSettings() ), true, sender);
		}
	}
	
	void SendAmmoSmelting( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
        if (sender)
		{
			GetRPCManager().SendRPC("Dumpgrah_AS", "RPCAmmoSmelting", new Param1< AmmoSmelting >( GetAmmoSmelting() ), true, sender);
		}
	}
};