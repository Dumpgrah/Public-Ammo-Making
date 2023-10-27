modded class ModItemRegisterCallbacks
{
	override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterTwoHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("CrucibleBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/CookingPot.anm");
		pType.AddItemInHandsProfileIK("PressBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/CookingPot.anm");
	};
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		
		pType.AddItemInHandsProfileIK("AM_Improvised_Grenade", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,			"dz/anims/anm/player/ik/ammunition/40mm_Grenade.anm");
		pType.AddItemInHandsProfileIK("AM_Smoke_Improvised_Grenade", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,			"dz/anims/anm/player/ik/ammunition/40mm_Grenade.anm");		// Not configured
	};
};