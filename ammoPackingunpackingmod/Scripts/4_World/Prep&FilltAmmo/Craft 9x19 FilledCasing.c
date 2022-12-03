class Craft9x19FilledCasing extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Fill 9x19 Casing";
		m_IsInstaRecipe = false;
		m_AnimationLength = 1;
		m_Specialty = -0.02;
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;
		
		m_MinQuantityIngredient[0] = -1; // Add how much casing is needed to craft ONE bullet
		m_MaxQuantityIngredient[0] = -1; 
		
		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3; 
		
		m_MinQuantityIngredient[1] = -1; // Add how much powder is needed to craft ONE bullet
		m_MaxQuantityIngredient[1] = -1;
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"Casing9X19");//Add the Casing in here
		
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = -1; // Add how much casing is needed to craft ONE bullet
		m_IngredientDestroy[0] = false;
		m_IngredientUseSoftSkills[0] = false;
		
		//ingredient 2
		InsertIngredient(1,"Gunpowder");//Add the Powder in here
		
		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = 0;// Add how much powder is needed to craft ONE bullet
		m_IngredientDestroy[1] = false;
		m_IngredientUseSoftSkills[1] = false;
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("FilledCasing9X19");//add results here

		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -2;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
	}
	int ItemOneRequirement = 1;				// Add here the requirement to craft ONE item
	int ItemTwoRequirement = Math.Ceil(10 * GetAmmoBuildingSettings().GetPercentageValueGunpowderRequired());				// Add here the requirement to craft ONE item
	int itemone
	int itemtwo
	
	
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ItemBase ingredient1 = ingredients[0];
		ItemBase ingredient2 = ingredients[1];
		itemone = ingredient1.GetQuantity();
		itemtwo = ingredient2.GetQuantity();
		
		
		if( itemone >= ItemOneRequirement && itemtwo >= ItemTwoRequirement )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase ingredient1 = ingredients[0];
		ItemBase ingredient2 = ingredients[1];
		ItemBase Result = results.Get(0);
		int itemtempone = ( itemone / ItemOneRequirement );
		int itemtemptwo = ( itemtwo / ItemTwoRequirement );
		int Outcome
		
		
		if ( itemtempone >= itemtemptwo )
		{	
			Outcome = ( itemtemptwo );
			
		}
		
		if ( itemtempone < itemtemptwo )
		{	
			
			Outcome = ( itemtempone );
			
		}
		
		Result.SetQuantity(Outcome);
		ingredient1.AddQuantity(-Outcome * ItemOneRequirement);
		ingredient2.AddQuantity(-Outcome * ItemTwoRequirement);
		
	}
};
