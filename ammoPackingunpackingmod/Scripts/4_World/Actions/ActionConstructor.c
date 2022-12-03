modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {	
		super.RegisterActions(actions);
		actions.Insert(ActionTurnOffSmelter);
		actions.Insert(Action_AM_FillTipsCrucible);
		actions.Insert(Action_AM_FillCasingCrucible);
		actions.Insert(ActionAM_BrassChangeCastingAction);
		actions.Insert(ActionAM_LeadChangeCastingAction);
		actions.Insert(AM_ActionCastingCasingAmmo);
		actions.Insert(AM_ActionCastingTipsAmmo);
		actions.Insert(AM_BreakDown40m);
    }
};