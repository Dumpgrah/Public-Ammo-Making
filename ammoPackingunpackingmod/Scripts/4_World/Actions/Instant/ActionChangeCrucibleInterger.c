class ActionAM_BrassChangeCastingAction: ActionSingleUseBase
{
	
	   string TendancyText = "";

    void ActionAM_BrassChangeCastingAction()
	{
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        //m_HUDCursorIcon = CursorIcons.OpenDoors;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "Switch from " + TendancyText ;
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		
		MoltenBaseCrucible BrassCrucible = MoltenBaseCrucible.Cast(player.GetItemInHands());
		
		StrongRifleCasingMold RifleCasingMold = StrongRifleCasingMold.Cast( target_object );
		StrongPistolCasingMold PistolCasingMold = StrongPistolCasingMold.Cast( target_object );

        
        if (BrassCrucible)
		{
			if(RifleCasingMold)
			{
				TendancyText = BrassCrucible.GetRifleTendancyText();
				return true;
			}
			else if(PistolCasingMold)
			{
				TendancyText = BrassCrucible.GetPistolTendancyText();
				return true;
			}
        }
        return false;
    };
    
	override void OnStartServer( ActionData action_data )
    {   
        CrucibleMoltenBrass BrassCrucible = CrucibleMoltenBrass.Cast(action_data.m_MainItem);
		 
		StrongRifleCasingMold RifleCasingMold = StrongRifleCasingMold.Cast( action_data.m_Target.GetObject() );
		StrongPistolCasingMold PistolCasingMold = StrongPistolCasingMold.Cast( action_data.m_Target.GetObject() );

		
        if (BrassCrucible)
		{
            if(RifleCasingMold)
			{
				BrassCrucible.StepCasingRifleTendancy();
			}
			else if(PistolCasingMold)
			{
				BrassCrucible.StepCasingPistolTendancy();
			}
			
        };
    };
};
class ActionAM_LeadChangeCastingAction: ActionSingleUseBase
{
	
	   string TendancyText = "";

    void ActionAM_LeadChangeCastingAction()
	{
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        //m_HUDCursorIcon = CursorIcons.OpenDoors;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "Switch from " + TendancyText ;
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		
		CrucibleMoltenLead LeadCrucible = CrucibleMoltenLead.Cast(player.GetItemInHands());

		StrongRifleTipsMold RifleTipsMold = StrongRifleTipsMold.Cast( target_object );
		StrongPistolTipsMold PistolTipsMold = StrongPistolTipsMold.Cast( target_object );

		if(LeadCrucible)
		{
			if (RifleTipsMold)
			{
				TendancyText = LeadCrucible.GetRifleTendancyText();
				return true;
			}
			else if(PistolTipsMold)
			{
				TendancyText = LeadCrucible.GetPistolTendancyText();
				return true;
			}

		}
        return false;
    };
    
	override void OnStartServer( ActionData action_data )
    {   
		CrucibleMoltenLead LeadCrucible = CrucibleMoltenLead.Cast(action_data.m_MainItem);


		StrongRifleTipsMold RifleTipsMold = StrongRifleTipsMold.Cast( action_data.m_Target.GetObject() );
		StrongPistolTipsMold PistolTipsMold = StrongPistolTipsMold.Cast( action_data.m_Target.GetObject() );

		if (LeadCrucible)
		{
            if(RifleTipsMold)
			{
				LeadCrucible.StepTipsRifleTendancy();
			}
			else if(PistolTipsMold)
			{
				LeadCrucible.StepTipsPistolTendancy();
			}
			
        };


    };
};