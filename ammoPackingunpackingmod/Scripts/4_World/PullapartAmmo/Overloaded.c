class Decraft762x54OL extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Pull apart 762x54 Overloaded ammo";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 2;//animation length in relative time units
		m_Specialty = -0.02;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"Ammo_762x54OP");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Pliers");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = -33;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("Tips762x54");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		AddResult("Casing762x54");//add results here

		m_ResultSetFullQuantity[1] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[1] = -1;//-1 = do nothing
		m_ResultSetHealth[1] = -1;//-1 = do nothing
		m_ResultInheritsHealth[1] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[1] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[1] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[1] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		AddResult("Gunpowder");//add results here

		m_ResultSetFullQuantity[2] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[2] = -1;//-1 = do nothing
		m_ResultSetHealth[2] = -1;//-1 = do nothing
		m_ResultInheritsHealth[2] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[2] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[2] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[2] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[2] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}
	int OutcomeTips = 1;
	int OutcomeCasing = 1;
	int OutcomeGunpowder = 46;
	float Plierdamage = 0.5;
	float Minamount = 100;
	float Maxamount = 100;
	int pliermaxhealth;
	int pliercurrenthealth;
	int itemone;
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		Magazine ingredient1 = Magazine.Cast(ingredients[0]);
		itemone = ingredient1.GetAmmoCount();
		ItemBase ingredient2 = ingredients[1];
		pliercurrenthealth = ingredient2.GetHealth();
		pliermaxhealth = ingredient2.GetMaxHealth();
		
		
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		Magazine ingredient1 = Magazine.Cast(ingredients[0]);
		ItemBase ingredient2 = ingredients[1];
		ItemBase ResultTips = results.Get(0);
		ItemBase ResultCasing = results.Get(1);
		ItemBase ResultGunpowder = results.Get(2);
		int TipsTemp = (itemone*OutcomeTips);
		int CasingTemp = (itemone*OutcomeCasing);
		int GunpowderTemp = (itemone*OutcomeGunpowder);
		float SoftSkill = ( Math.RandomInt(Minamount,Maxamount) );
		
		if ( Plierdamage * itemone >= pliermaxhealth)
		{
			float PliersRuined = (Math.Round( pliermaxhealth / Plierdamage ));
			//Print("NYAN CRAFTING MOD PliersRuined + " + PliersRuined);
			//Print("NYAN CRAFTING MOD OPTION1");
			float ResultTipsi = (PliersRuined * OutcomeTips / 100 * SoftSkill);
			float ResultCasi = (PliersRuined * OutcomeCasing / 100 * SoftSkill);
			
			
			
			ResultTips.SetQuantity(Math.Round(ResultTipsi));
			ResultCasing.SetQuantity(Math.Round(ResultCasi));
			ResultGunpowder.SetQuantity(PliersRuined * OutcomeGunpowder);
			ingredient1.ServerSetAmmoCount(itemone - PliersRuined);
			if( ingredient1.GetAmmoCount() == 0)
			{
				ingredient1.AddQuantity(-1);
			}
			ingredient2.AddHealth(-pliermaxhealth);
		}
		
		else if ( Plierdamage * itemone >= pliercurrenthealth )
		{
			
			int PliersTooDamaged;
			//Print("NYAN CRAFTING MOD OPTION2 + " + pliercurrenthealth);
			for(float i = Plierdamage; pliercurrenthealth <= i;Plierdamage++) 
			{
				PliersTooDamaged = Plierdamage++;
			}
			//int PliersTooDamaged = (Math.Round((pliermaxhealth - pliercurrenthealth) / Plierdamage));
			//Print("NYAN CRAFTING MOD PliersTooDamaged + " + PliersTooDamaged);
			//Print("NYAN CRAFTING MOD OPTION2");
			float ResultTipsTD = ( i / 100 * SoftSkill );
			float ResultCaseTD = ( i / 100 * SoftSkill );
			
			
			ResultTips.SetQuantity(Math.Round(ResultTipsTD));
			ResultCasing.SetQuantity(Math.Round(ResultCaseTD));
			ResultGunpowder.SetQuantity(Math.Round(i) * OutcomeGunpowder);
			ingredient1.ServerAddAmmoCount(Math.Round(-i));
			if( ingredient1.GetAmmoCount() == 0)
			{
				ingredient1.AddQuantity(-1);
			}
			ingredient2.AddHealth(-pliermaxhealth);
		}
		else
		{
			float ResultTipsis = (TipsTemp / 100 * SoftSkill);
			float ResultCasis = (CasingTemp / 100 * SoftSkill);
			//Print("NYAN CRAFTING MOD OPTION3");
			ResultTips.SetQuantity(Math.Round(ResultTipsis));
			ResultCasing.SetQuantity(Math.Round(ResultCasis));
			ResultGunpowder.SetQuantity(GunpowderTemp);
		
			ingredient1.AddQuantity(-itemone);
			ingredient2.AddHealth(-itemone * Plierdamage);
		}
		
	}
};
class Decraft380WinOL extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Pull apart 308 Win Overloaded ammo";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 2;//animation length in relative time units
		m_Specialty = -0.02;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"Ammo_308WinOverloaded");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Pliers");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("Tips308Win");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		AddResult("Casing308Win");//add results here

		m_ResultSetFullQuantity[1] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[1] = -1;//-1 = do nothing
		m_ResultSetHealth[1] = -1;//-1 = do nothing
		m_ResultInheritsHealth[1] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[1] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[1] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[1] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		AddResult("Gunpowder");//add results here

		m_ResultSetFullQuantity[2] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[2] = -1;//-1 = do nothing
		m_ResultSetHealth[2] = -1;//-1 = do nothing
		m_ResultInheritsHealth[2] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[2] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[2] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[2] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[2] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}
	int OutcomeTips = 1;
	int OutcomeCasing = 1;
	int OutcomeGunpowder = 51;
	float Plierdamage = 0.5;
	float Minamount = 100;
	float Maxamount = 100;
	int pliermaxhealth = 100;
	int pliercurrenthealth;
	int itemone;
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		Magazine ingredient1 = Magazine.Cast(ingredients[0]);
		itemone = ingredient1.GetAmmoCount();
		ItemBase ingredient2 = ingredients[1];
		pliercurrenthealth = ingredient2.GetHealth();
		
		
		if ( Plierdamage  <= pliercurrenthealth )
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
		Magazine ingredient1 = Magazine.Cast(ingredients[0]);
		ItemBase ingredient2 = ingredients[1];
		ItemBase ResultTips = results.Get(0);
		ItemBase ResultCasing = results.Get(1);
		ItemBase ResultGunpowder = results.Get(2);
		int TipsTemp = (itemone*OutcomeTips);
		int CasingTemp = (itemone*OutcomeCasing);
		int GunpowderTemp = (itemone*OutcomeGunpowder);
		float SoftSkill = ( Math.RandomInt(Minamount,Maxamount) );
		
		if ( Plierdamage * itemone >= pliermaxhealth)
		{
			float PliersRuined = (Math.Round( pliermaxhealth / Plierdamage ));
			//Print("NYAN CRAFTING MOD PliersRuined + " + PliersRuined);
			//Print("NYAN CRAFTING MOD OPTION1");
			float ResultTipsi = (PliersRuined * OutcomeTips / 100 * SoftSkill);
			float ResultCasi = (PliersRuined * OutcomeCasing / 100 * SoftSkill);
			
			
			
			ResultTips.SetQuantity(Math.Round(ResultTipsi));
			ResultCasing.SetQuantity(Math.Round(ResultCasi));
			ResultGunpowder.SetQuantity(PliersRuined * OutcomeGunpowder);
			ingredient1.ServerSetAmmoCount(itemone - PliersRuined);
			if( ingredient1.GetAmmoCount() == 0)
			{
				ingredient1.AddQuantity(-1);
			}
			ingredient2.AddHealth(-pliermaxhealth);
		}
		
		else if ( Plierdamage * itemone >= pliercurrenthealth )
		{
			
			int PliersTooDamaged;
			//Print("NYAN CRAFTING MOD OPTION2 + " + pliercurrenthealth);
			for(float i = Plierdamage; pliercurrenthealth <= i;Plierdamage++) 
			{
				PliersTooDamaged = Plierdamage++;
			}
			//int PliersTooDamaged = (Math.Round((pliermaxhealth - pliercurrenthealth) / Plierdamage));
			//Print("NYAN CRAFTING MOD PliersTooDamaged + " + PliersTooDamaged);
			//Print("NYAN CRAFTING MOD OPTION2");
			float ResultTipsTD = ( i / 100 * SoftSkill );
			float ResultCaseTD = ( i / 100 * SoftSkill );
			
			
			ResultTips.SetQuantity(Math.Round(ResultTipsTD));
			ResultCasing.SetQuantity(Math.Round(ResultCaseTD));
			ResultGunpowder.SetQuantity(Math.Round(i) * OutcomeGunpowder);
			ingredient1.ServerAddAmmoCount(Math.Round(-i));
			if( ingredient1.GetAmmoCount() == 0)
			{
				ingredient1.AddQuantity(-1);
			}
			ingredient2.AddHealth(-pliermaxhealth);
		}
		else
		{
			float ResultTipsis = (TipsTemp / 100 * SoftSkill);
			float ResultCasis = (CasingTemp / 100 * SoftSkill);
			//Print("NYAN CRAFTING MOD OPTION3");
			ResultTips.SetQuantity(Math.Round(ResultTipsis));
			ResultCasing.SetQuantity(Math.Round(ResultCasis));
			ResultGunpowder.SetQuantity(GunpowderTemp);
		
			ingredient1.AddQuantity(-itemone);
			ingredient2.AddHealth(-itemone * Plierdamage);
		}
		
	}
};