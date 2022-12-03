class CasingMoldBase : ItemBase
{
	PlayerBase 		m_Player;
	
	bool IsTemperatureValid()
	{
		if(GetTemperature() >= 1)
		{
			 return true; 
		}
		return false;
	};
	//int GetOutPutOccupied()
	//{
	//	ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("RifleCasingMold"));
	//	if(thing)
	//	{
	//		if(thing.IsInherited(ND_IngotBase))
	//		{
	//			return 1;
	//		}
	//		return thing.GetQuantity();
	//		
	//	}
	//
	//	
	//	return 0;
	//};
	//
	//void CreateCasingOrTips(string CreationType)
	//{
	//	CrucibleMoltenBrass Crucible = m_Player.GetItemInHands();
	//	
	//	
	//	if ( Crucible.m_CastCasing == 0)
	//	{
	//		Ham.AddQuantity(-2);
	//		GetInventory().CreateAttachment("Casing" + CreationType ); //Produces Item in the output slot
	//		AddHealth("","Health",-2);
	//	};
	//	if ( Crucible.m_CastCasing == 1 )
	//	{
	//		GetGame().ObjectDelete( GetImPureIronIngot() );
	//		GetInventory().CreateAttachment("Casing" + CreationType); //Produces Item in the output slot
	//		AddHealth("","Health",-2);
	//	};
	//	if ( thingName == "ND_IronIngot" )
	//	{
	//		GetGame().ObjectDelete( GetIronIngot() );
	//		GetInventory().CreateAttachment("Casing" + CreationType); //Produces Item in the output slot
	//		AddHealth("","Health",-2);
	//	};
	//};
	
	void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	
}

class StrongRifleCasingMold: CasingMoldBase
{
	void StrongRifleCasingMold()
	{
		ShowSimpleSelection("Casted_Casing", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 0);

		};
	};
	
	void CreateCasing(string CreationType)
	{
		AM_CasingBase Casing = AM_CasingBase.Cast(GetInventory().CreateAttachment("Casing" + CreationType) );
		Casing.AddQuantity(20);
		AddQuantity(-2.5);
	};
};
class StrongRifleTipsMold: CasingMoldBase
{
	void StrongRifleTipsMold()
	{
		ShowSimpleSelection("Casted_Tips", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 0);

		};
	};
	void CreateTips(string CreationType)
	{
		AM_TipsBase Tips = AM_TipsBase.Cast(GetInventory().CreateAttachment("Tips" + CreationType) );
		Tips.AddQuantity(20);
		AddQuantity(-2.5);
	};
};
class StrongPistolCasingMold: CasingMoldBase
{
	void StrongPistolCasingMold()
	{
		ShowSimpleSelection("Casted_Casing", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 0);
	
		};
	};
	
	void CreateCasing(string CreationType)
	{
		AM_CasingBase Casing = AM_CasingBase.Cast(GetInventory().CreateAttachment("Casing" + CreationType) );
		Casing.AddQuantity(20);
		AddQuantity(-2.5);
	};
};
 

class StrongPistolTipsMold: CasingMoldBase
{
	void StrongPistolTipsMold()
	{
		ShowSimpleSelection("Casted_Tips", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 0);

		};
	};
	void CreateTips(string CreationType)
	{
		AM_TipsBase Tips = AM_TipsBase.Cast(GetInventory().CreateAttachment("Tips" + CreationType) );
		Tips.AddQuantity(20);
		AddQuantity(-2.5);
	};
};