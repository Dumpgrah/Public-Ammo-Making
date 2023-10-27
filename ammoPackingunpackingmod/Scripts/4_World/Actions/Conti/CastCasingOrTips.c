class AM_ActionCastMetalCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 10 ); // Dont forget to change back to 30
	}
};
class AM_ActionCastingCasingAmmo: ActionContinuousBase
{
	    string TendancyText = "";
		
			int RQuantityRequired = 0;
		int PQuantityRequired = 0;	
	
    void AM_ActionCastingCasingAmmo()
	{
		m_CallbackClass = AM_ActionCastMetalCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "Cast " + TendancyText;
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        CrucibleMoltenBrass Crucible;
        
        if (!Class.CastTo(Crucible, item))
            return false;
		
		RQuantityRequired = Crucible.GetRifleCasingReqQuantity();
		PQuantityRequired = Crucible.GetPistolCasingReqQuantity();
		
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		StrongRifleCasingMold RifleMold = StrongRifleCasingMold.Cast( target_object );
		StrongPistolCasingMold PistolMold = StrongPistolCasingMold.Cast( target_object );
		//CrucibleMoltenBrass Crucible = CrucibleMoltenBrass.Cast(player.GetItemInHands());
        
        if (RifleMold && RifleMold.GetSlotOccupied() == 0 && Crucible && Crucible.GetQuantity() >= RQuantityRequired && Crucible.HotEnough())
		{
			TendancyText = Crucible.GetRifleTendancyText();
			
            return true;
        }
		else if (PistolMold && PistolMold.GetSlotOccupied() == 0 && Crucible && Crucible.GetQuantity() >= PQuantityRequired && Crucible.HotEnough())
		{
			TendancyText = Crucible.GetPistolTendancyText();
			
            return true;
        }
        return false;
    };
    
	override void OnFinishProgressServer( ActionData action_data )
    {
		CrucibleMoltenBrass Crucible = CrucibleMoltenBrass.Cast(action_data.m_MainItem);
		
		StrongRifleCasingMold RifleMold = StrongRifleCasingMold.Cast( action_data.m_Target.GetObject() );
		StrongPistolCasingMold PistolMold = StrongPistolCasingMold.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
        if(RifleMold && Crucible)
		{
            RifleMold.CreateCasing(Crucible.GetRifleCasingTendancyCreationType());
			Crucible.MinusQuantityRifle();
        }
		else if(PistolMold && Crucible)
		{
            PistolMold.CreateCasing(Crucible.GetPistolCasingTendancyCreationType());
			Crucible.MinusQuantityPistol();
        }
    };

};

class AM_ActionCastingTipsAmmo: ActionContinuousBase
{
	    string TendancyText = "";
		int RQuantityRequired = 0;
		int PQuantityRequired = 0;
	
    void AM_ActionCastingTipsAmmo()
	{
		m_CallbackClass = AM_ActionCastMetalCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "" + TendancyText;
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		CrucibleMoltenLead Crucible;
        
        if (!Class.CastTo(Crucible, item))
            return false;
		
		RQuantityRequired = Crucible.GetRifleTipsReqQuantity();
		PQuantityRequired = Crucible.GetPistolTipsReqQuantity();
		
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		StrongRifleTipsMold RifleTipsMold = StrongRifleTipsMold.Cast( target_object );
		StrongPistolTipsMold PistolTipsMold = StrongPistolTipsMold.Cast( target_object );
		//CrucibleMoltenBrass Crucible = CrucibleMoltenBrass.Cast(player.GetItemInHands());
        
        if (RifleTipsMold && RifleTipsMold.GetSlotOccupied() == 0 && Crucible && Crucible.GetQuantity() >= RQuantityRequired && Crucible.HotEnough())
		{
			TendancyText = Crucible.GetRifleTendancyText();
			
            return true;
        }
		else if (PistolTipsMold && PistolTipsMold.GetSlotOccupied() == 0 && Crucible && Crucible.GetQuantity() >= PQuantityRequired && Crucible.HotEnough())
		{
			TendancyText = Crucible.GetPistolTendancyText();
			
            return true;
        }
		TendancyText = Crucible.GetRifleTendancyText();
        return false;
    };
    
	override void OnFinishProgressServer( ActionData action_data )
    {
		CrucibleMoltenLead Crucible = CrucibleMoltenLead.Cast(action_data.m_MainItem);
		
		StrongRifleTipsMold RifleTipsMold = StrongRifleTipsMold.Cast( action_data.m_Target.GetObject() );
		StrongPistolTipsMold PistolTipsMold = StrongPistolTipsMold.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
        if(RifleTipsMold && Crucible)
		{
            RifleTipsMold.CreateTips(Crucible.GetRifleTipsTendancyCreationType());
			Crucible.MinusQuantityRifle();
			
        }
		else if(PistolTipsMold && Crucible)
		{
            PistolTipsMold.CreateTips(Crucible.GetPistolTipsTendancyCreationType());
			Crucible.MinusQuantityPistol();
        }
    };
};