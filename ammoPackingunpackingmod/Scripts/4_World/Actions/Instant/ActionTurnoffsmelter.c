class ActionTurnOffSmelter: ActionInteractBase
{	
	void ActionTurnOffSmelter()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}
	

	override string GetText()
	{
		return "#switch_off";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		StandAloneSmelter Smelter = StandAloneSmelter.Cast( target_object );
		if ( player.IsAlive() && target_entity.HasEnergyManager()  &&  target_entity.GetCompEM().IsSwitchedOn() )
		{
			if ( player.IsAlive() && target_entity.HasEnergyManager()  &&  target_entity.GetCompEM().CanSwitchOff() && !Smelter.IsLocked() )
			{
				return true;
			}
			return false;
		}
		return true;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		EntityAI target_entity = EntityAI.Cast( action_data.m_Target.GetObject() );
		
		if ( target_entity.GetCompEM().CanSwitchOff() )
		{
			target_entity.GetCompEM().SwitchOff();
			
			InformPlayers( action_data.m_Player, action_data.m_Target, UA_FINISHED );	//Success
		}
		else
		{
			InformPlayers( action_data.m_Player, action_data.m_Target, UA_FAILED );		//Already turned off
		}	
	}
};