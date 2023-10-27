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
		//ShowSimpleSelection("Casted_Casing", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		//if(slot_name == "RifleCasingMold")
		//{
		//	ShowSimpleSelection("Casted_Casing", 1);
		//};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		//if(slot_name == "RifleCasingMold")
		//{
		//	ShowSimpleSelection("Casted_Casing", 0);
		//
		//};
	};
	
	void CreateCasing(string CreationType)
	{
		AM_CasingBase Casing = AM_CasingBase.Cast(GetInventory().CreateAttachment("Casing" + CreationType) );
		if(Casing && Casing.GetQuantity() >= 0)
		{
			Casing.AddQuantity(20);
		};
		AddQuantity(-2.5);
	};

	int GetSlotOccupied()
	{
		ItemBase Count = ItemBase.Cast(FindAttachmentBySlotName("RifleCasingMold"));
		if(Count)
		{
			if(Count.IsInherited(AM_CasingBase))
			{
				return 1;
			}
			return Count.GetQuantity();
			
		}
		return 0;
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
		if(Tips && Tips.GetQuantity() >= 0)
		{
			Tips.AddQuantity(20);
		};
		AddQuantity(-2.5);
	};
	
	int GetSlotOccupied()
	{
		ItemBase Count = ItemBase.Cast(FindAttachmentBySlotName("RifleTipsMold"));
		if(Count)
		{
			if(Count.IsInherited(AM_TipsBase))
			{
				return 1;
			}
			return Count.GetQuantity();
			
		}
		return 0;
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
		if(Casing && Casing.GetQuantity() >= 0)
		{
			Casing.AddQuantity(20);
		};
		AddQuantity(-2.5);
	};
	
	int GetSlotOccupied()
	{
		ItemBase Count = ItemBase.Cast(FindAttachmentBySlotName("RifleCasingMold"));
		if(Count)
		{
			if(Count.IsInherited(AM_CasingBase))
			{
				return 1;
			}
			return Count.GetQuantity();
			
		}
		return 0;
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
		if(Tips && Tips.GetQuantity() >= 0)
		{
			Tips.AddQuantity(20);
		};
		AddQuantity(-2.5);
	};
	int GetSlotOccupied()
	{
		ItemBase Count = ItemBase.Cast(FindAttachmentBySlotName("RifleTipsMold"));
		if(Count)
		{
			if(Count.IsInherited(AM_TipsBase))
			{
				return 1;
			}
			return Count.GetQuantity();
			
		}
		return 0;
	};
	
};