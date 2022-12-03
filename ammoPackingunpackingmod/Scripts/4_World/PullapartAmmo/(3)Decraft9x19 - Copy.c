class Decraft9x39AP extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Pull apart 9x39AP ammo";
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
		InsertIngredient(0,"Ammo_9x39AP");//you can insert multiple ingredients this way
		
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
		AddResult("Gunpowder");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	int OutcomeGunpowder = Math.Ceil(12 * GetAmmoBuildingSettings().GetPercentageValueGunPowderLoss());
	float Plierdamage = GetAmmoBuildingSettings().Dmg_To_Pliers_Per_Bullet;
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
		ItemBase ResultGunpowder = results.Get(0);
		ItemBase ingredient2 = ingredients[1];
		int GunpowderTemp = (itemone*OutcomeGunpowder);
		float SoftSkill = ( Math.RandomInt(Minamount,Maxamount) );
		
		if ( Plierdamage * itemone >= pliermaxhealth)
		{
			float PliersRuined = (Math.Ceil( pliermaxhealth / Plierdamage ));

			
			
			

			ResultGunpowder.SetQuantity(PliersRuined * OutcomeGunpowder);
			ingredient1.ServerSetAmmoCount(itemone - PliersRuined);
			//if( ingredient1.GetAmmoCount() == 0)
			//{
			//	ingredient1.AddQuantity(-1);
			//}
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

			ResultGunpowder.SetQuantity(Math.Ceil(i) * OutcomeGunpowder);
			ingredient1.ServerAddAmmoCount(Math.Ceil(-i));
			//if( ingredient1.GetAmmoCount() == 0)
			//{
			//	ingredient1.AddQuantity(-1);
			//}
			ingredient2.AddHealth(-pliermaxhealth);
		}
		else
		{
			ResultGunpowder.SetQuantity(GunpowderTemp);
		
			ingredient1.AddQuantity(-itemone);
			ingredient2.AddHealth(-itemone * Plierdamage);
		}
		
		float OutcomeTips = GetAmmoBuildingSettings().GetPercentageValueTipsLoss();
		float OutcomeCasing = GetAmmoBuildingSettings().GetPercentageValueCasingLoss();
		ItemBase Tips;
		ItemBase Casing;
		if(itemone > 1 )
		{
			float outcomedeformedtips = 0.99999 - OutcomeTips;
			float outcomedeformedcasing = 0.99999 - OutcomeCasing;
			
			int deformedtipscount = Math.Round(itemone * outcomedeformedtips);
			int deformedcasingcount = Math.Round(itemone * outcomedeformedcasing);
			
			int tipscount = Math.Round(itemone * OutcomeTips);
			int casingcount = Math.Round(itemone * OutcomeCasing);
		
			if(deformedtipscount > 0 )
			{

				Tips = ItemBase.Cast(GetGame().CreateObject("DeFormedRifleTips", ResultGunpowder.GetPosition()));
				Tips.SetQuantity(deformedtipscount);
			}
			if(tipscount > 0 )
			{
				Tips = ItemBase.Cast(GetGame().CreateObject("Tips9x39", ResultGunpowder.GetPosition()));
				Tips.SetQuantity(tipscount);
			}
			if(deformedcasingcount > 0)
			{
				Casing = ItemBase.Cast(GetGame().CreateObject("DeFormedRifleCasing", ResultGunpowder.GetPosition()));
				Casing.SetQuantity(deformedcasingcount);
			}
			if(casingcount > 0 )
			{
				Casing = ItemBase.Cast(GetGame().CreateObject("Casing9x39", ResultGunpowder.GetPosition()));
				Casing.SetQuantity(casingcount);
			}
			
		}
		else
		{
			
			float RandomTips = Math.RandomFloat(0,1);
			float RandomCasing = Math.RandomFloat(0,1);
			if(RandomTips > OutcomeTips)
			{
				Tips = ItemBase.Cast(GetGame().CreateObject("DeFormedRifleTips", ResultGunpowder.GetPosition()));
				Tips.SetQuantity(1);
				
			}
			else
			{
				Tips = ItemBase.Cast(GetGame().CreateObject("Tips9x39", ResultGunpowder.GetPosition()));
				Tips.SetQuantity(1);
			}

			if(RandomTips > OutcomeTips)
			{
				Casing = ItemBase.Cast(GetGame().CreateObject("DeFormedRifleCasing", ResultGunpowder.GetPosition()));
				Casing.SetQuantity(1);
				
			}
			else
			{
				Casing = ItemBase.Cast(GetGame().CreateObject("Casing9x39", ResultGunpowder.GetPosition()));
				Casing.SetQuantity(1);
			}
			
		};
		if(ingredient1 && ingredient1.GetAmmoCount() < 1 )
		{
			ingredient1.Delete();
		}
	}
};
