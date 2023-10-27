class MoltenBaseCrucible extends ItemBase
{
	void MoltenBaseCrucible()
	{
		SetTemperature(500);
	}
	
	string GetTendancyText(){};
	string GetRifleTendancyText(){};
	string GetPistolTendancyText(){}
	void StepTendancy(){};
	void StepCasingRifleTendancy(){};
	void StepCasingPistolTendancy(){};
	void StepTipsRifleTendancy(){};
	void StepTipsPistolTendancy(){};

	
}

class CrucibleMoltenBrass extends MoltenBaseCrucible
{
	int m_CastRifleCasing = 0;
	int m_CastPistolCasing = 0;
	
	int TempaturetoCast = GetAmmoSmelting().Tempature_To_Cast_Casings;
	
	void CrucibleMoltenBrass()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
			
		}
		if(GetTemperature() <=1)
		{
			StopCooling();
		}
		StartCooling();
	
		
		
		RegisterNetSyncVariableInt("m_CastRifleCasing");
		RegisterNetSyncVariableInt("m_CastPistolCasing");
    };
	bool HotEnough()
	{
		
		if(GetTemperature() > TempaturetoCast)
		{
			return true;
		}
		return false;
		
	}
	override string GetRifleTendancyText()
	{
		if (m_CastRifleCasing == 0)
		{
			if(GetQuantity() >= 28 && GetTemperature() > 300)
			{
				return "Cast 545x39 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if(m_CastRifleCasing == 1)
		{
			if(GetQuantity() >= 30 && GetTemperature() > 300)
			{
				return "Cast 556x45 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
		}		
		if (m_CastRifleCasing == 2)
		{
			if(GetQuantity() >= 35 && GetTemperature() > 300)
			{
				return "Cast 762x39 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";	
        }
		if (m_CastRifleCasing == 3)
		{
			if(GetQuantity() >= 37 && GetTemperature() > 300)
			{
				return "Cast 308Win Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";	
        }
		if (m_CastRifleCasing == 4)
		{
			if(GetQuantity() >= 40 && GetTemperature() > 300)
			{
				return "Cast 762x54 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastRifleCasing == 5)
		{
			if(GetQuantity() >= 25 && GetTemperature() > 300 )
			{
				return "Cast 9x39 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
        return "";

    };
	override string GetPistolTendancyText()
	{
        if (m_CastPistolCasing == 0)
		{
			if(GetQuantity() >= 13 && GetTemperature() > 300)
			{
				return "Cast 22LR Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastPistolCasing == 1)
		{
			if(GetQuantity() >= 20 && GetTemperature() > 300)
			{
				return "Cast 9x19 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
        if (m_CastPistolCasing == 2)
		{
			if(GetQuantity() >= 23 && GetTemperature() > 300)
			{
				return "Cast 45ACP Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastPistolCasing == 3)
		{
			if(GetQuantity() >= 26 && GetTemperature() > 300)
			{
				return "Cast 357 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastPistolCasing == 4)
		{
			if(GetQuantity() >= 15 && GetTemperature() > 300)
			{
				return "Cast 380ACP Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
        return "";

    };
	
    string GetRifleCasingTendancyCreationType()
	{
		if (m_CastRifleCasing == 0)
		{
           return "545x39";
        }
		if(m_CastRifleCasing == 1)
		{
			return "556x45";
		}		
		if (m_CastRifleCasing == 2)
		{
           return "762x39";
        }
		if (m_CastRifleCasing == 3)
		{
           return "308Win";
        }
		if (m_CastRifleCasing == 4)
		{
           return "762x54";
        }
		if (m_CastRifleCasing == 5)
		{
           return "9x39";
        }

        return "";
    };
	
	int GetRifleCasingReqQuantity()
	{
		if (m_CastRifleCasing == 0)
		{
           return 28;
        }
		else if (m_CastRifleCasing == 1)
		{
           return 30;
        }
		else if (m_CastRifleCasing == 2)
		{
           return 35;
        }
		else if (m_CastRifleCasing == 3)
		{
			return 37;
        }
		else if (m_CastRifleCasing == 4)
		{
			return 40;
        }
		else if (m_CastRifleCasing == 5)
		{
           return 25;
        }
		return 0;
    };
	int GetPistolCasingReqQuantity()
	{
		if (m_CastPistolCasing == 0)
		{
          return 13;
        }
		else if (m_CastPistolCasing == 1)
		{
          return 20;
        }
        else if (m_CastPistolCasing == 2)
		{
           return 23 ;
        }
		else if (m_CastPistolCasing == 3)
		{
           return 26;
        }
		else if (m_CastPistolCasing == 4)
		{
           return 15;
        }
		return 0;
		SetSynchDirty();
	};
	
	void MinusQuantityRifle()
	{

		if (m_CastRifleCasing == 0)
		{
           AddQuantity(-28);
        }
		else if (m_CastRifleCasing == 1)
		{
           AddQuantity(-30);
        }
		else if (m_CastRifleCasing == 2)
		{
           AddQuantity(-35);
        }
		else if (m_CastRifleCasing == 3)
		{
			AddQuantity(-37);
        }
		else if (m_CastRifleCasing == 4)
		{
			AddQuantity(-40);
        }
		else if (m_CastRifleCasing == 5)
		{
           AddQuantity(-25);
        }
		Print("m_CastRifleCasing == " + m_CastRifleCasing);
		SetSynchDirty();
	};
	
	string GetPistolCasingTendancyCreationType()
	{
        if (m_CastPistolCasing == 0)
		{
          return "22LR";
        }
		if (m_CastPistolCasing == 1)
		{
          return "9x19";
        }
        if (m_CastPistolCasing == 2)
		{
           return "45ACP";
        }
		if (m_CastPistolCasing == 3)
		{
           return "357";
        }
		if (m_CastPistolCasing == 4)
		{
           return "380ACP";
        }
        return "";
    };
	
	void MinusQuantityPistol()
	{
		if (m_CastPistolCasing == 0)
		{
          AddQuantity(-13);
        }
		else if (m_CastPistolCasing == 1)
		{
          AddQuantity(-20);
        }
        else if (m_CastPistolCasing == 2)
		{
           AddQuantity(-23);
        }
		else if (m_CastPistolCasing == 3)
		{
           AddQuantity(-26);
        }
		else if (m_CastPistolCasing == 4)
		{
           AddQuantity(-15);
        }
		else if (m_CastPistolCasing == 5)
		{
           AddQuantity(-8);
        }	
		SetSynchDirty();
	};
	
	override void StepCasingRifleTendancy()
	{
      m_CastRifleCasing++;
      if (m_CastRifleCasing > 5)
	  {
         m_CastRifleCasing = 0;
      }
      SetSynchDirty();
    };
	override void StepCasingPistolTendancy()
	{
      m_CastPistolCasing++;
      if (m_CastPistolCasing > 5)
	  {
         m_CastPistolCasing = 0;
      }
      SetSynchDirty();
    };
	
	int CasingRifleTendancy()
	{
        return m_CastRifleCasing;
    };
	
	int CasingPistolTendancy()
	{
		return m_CastPistolCasing;
    };

	protected ref Timer m_AmmoCoolingTimer;

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
		
	}
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	}
	
	protected void StartCooling()
	{

		
		m_AmmoCoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_AmmoCoolingTimer.Run( 3, this, "Cooling", NULL, true );		// true param loops
	}


	void Cooling()
	{
		if (GetTemperature() >= 1)
		{
			float temperature = GetTemperature();
			temperature = temperature - 4;
		}

		SetTemperature(temperature);

		if ( GetTemperature() <= 1)
		{
			StopCooling();
		}
	}
	protected void StopCooling()
	{
		//Stop cooling
		if(m_AmmoCoolingTimer)
		{
			m_AmmoCoolingTimer.Stop();
			m_AmmoCoolingTimer = NULL;
		}

	
	}
	override bool CanPutIntoHands(EntityAI parent)
    {
        if ( parent.FindAttachmentBySlotName( "Gloves" ))
        {
            return true;
        }
		if ( GetTemperature() <= 80)
		{
			return true;
		}
		return false;
    }
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAM_BrassChangeCastingAction);
		AddAction(AM_ActionCastingCasingAmmo);
	}	

}
class CrucibleMoltenLead extends MoltenBaseCrucible
{
	int m_CastRifleTips = 0;
	int m_CastPistolTips = 0;
	int TempaturetoCast = GetAmmoSmelting().Tempature_To_Cast_Tips;
	
	void CrucibleMoltenLead()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() <=0)
		{
			StopCooling();
		}
		StartCooling();	
		
		
      RegisterNetSyncVariableInt("m_CastRifleTips");
	  RegisterNetSyncVariableInt("m_CastPistolTips");
    };
	
	bool HotEnough()
	{
		if(GetTemperature() > TempaturetoCast)
		{
			return true;
		}
		return false;
		
	}
	override string GetRifleTendancyText()
	{
		if (m_CastRifleTips == 0)
		{
			if(GetQuantity() >= 28 && GetTemperature() > 120)
			{
				return "Cast 545x39 Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
		if(m_CastRifleTips == 1)
		{
			if(GetQuantity() >= 30 && GetTemperature() > 120)
			{
				return "Cast 556x45 Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";	
		}		
		if (m_CastRifleTips == 2)
		{
			if(GetQuantity() >= 35 && GetTemperature() > 120)
			{
				return "Cast 762x39 Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";	
        }
		if (m_CastRifleTips == 3)
		{
			if(GetQuantity() >= 37 && GetTemperature() > 120)
			{
				return "Cast 308Win Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";	
        }
		if (m_CastRifleTips == 4)
		{
			if(GetQuantity() >= 40 && GetTemperature() > 120)
			{
				return "Cast 762x54 Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
		if (m_CastRifleTips == 5)
		{
			if(GetQuantity() >= 25 && GetTemperature() > 120 )
			{
				return "Cast 9x39 Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
		if (m_CastRifleTips == 6)
		{
			if(GetQuantity() >= 25 && GetTemperature() > 120 )
			{
				return "Cast Shotgun Slugs";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
        return "";
		

    };
	override string GetPistolTendancyText()
	{
        if (m_CastPistolTips == 0)
		{
			if(GetQuantity() >= 13 && GetTemperature() > 120)
			{
				return "Cast 22LR Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
		if (m_CastPistolTips == 1)
		{
			if(GetQuantity() >= 20 && GetTemperature() > 120)
			{
				return "Cast 9x19 Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
        if (m_CastPistolTips == 2)
		{
			if(GetQuantity() >= 23 && GetTemperature() > 120)
			{
				return "Cast 45ACP Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
		if (m_CastPistolTips == 3)
		{
			if(GetQuantity() >= 26 && GetTemperature() > 120)
			{
				return "Cast 357 Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
		if (m_CastPistolTips == 4)
		{
			if(GetQuantity() >= 15 && GetTemperature() > 120)
			{
				return "Cast 380ACP Tips";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }
		if (m_CastPistolTips == 5)
		{
			if(GetQuantity() >= 15 && GetTemperature() > 120)
			{
				return "Cast Buckshot";
			}
			else if(GetTemperature() < 120 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Lead";
        }	
			
        return "";

    };
	
    string GetRifleTipsTendancyCreationType()
	{
		if (m_CastRifleTips == 0)
		{
           return "545x39";
        }
		if(m_CastRifleTips == 1)
		{
			return "556x45";
		}		
		if (m_CastRifleTips == 2)
		{
           return "762x39";
        }
		if (m_CastRifleTips == 3)
		{
           return "308Win";
        }
		if (m_CastRifleTips == 4)
		{
           return "762x54";
        }
		if (m_CastRifleTips == 5)
		{
           return "9x39";
        }
	    if (m_CastRifleTips ==6)
		{
           return "Slug";
        }

        return "";
    };
	
	int GetRifleTipsReqQuantity()
	{
		if (m_CastRifleTips == 0)
		{
           return 28;
        }
		else if (m_CastRifleTips == 1)
		{
           return 30;
        }
		else if (m_CastRifleTips == 2)
		{
           return 35;
        }
		else if (m_CastRifleTips == 3)
		{
			return 37;
        }
		else if (m_CastRifleTips == 4)
		{
			return 40;
        }
		else if (m_CastRifleTips == 5)
		{
           return 25;
        }
		else if (m_CastRifleTips == 6)
		{
           return 8;
        }
		return 0;
    };
	int GetPistolTipsReqQuantity()
	{
		if (m_CastPistolTips == 0)
		{
          return 13;
        }
		else if (m_CastPistolTips == 1)
		{
          return 20;
        }
        else if (m_CastPistolTips == 2)
		{
           return 23 ;
        }
		else if (m_CastPistolTips == 3)
		{
           return 26;
        }
		else if (m_CastPistolTips == 4)
		{
           return 15;
        }
		else if (m_CastPistolTips == 5)
		{
           return 8;
        }
		return 0;
		SetSynchDirty();
	};
	
	void MinusQuantityRifle()
	{

		if (m_CastRifleTips == 0)
		{
           AddQuantity(-28);
        }
		else if (m_CastRifleTips == 1)
		{
           AddQuantity(-30);
        }
		else if (m_CastRifleTips == 2)
		{
           AddQuantity(-35);
        }
		else if (m_CastRifleTips == 3)
		{
			AddQuantity(-37);
        }
		else if (m_CastRifleTips == 4)
		{
			AddQuantity(-40);
        }
		else if (m_CastRifleTips == 5)
		{
           AddQuantity(-25);
        }
		else if (m_CastRifleTips == 6)
		{
           AddQuantity(-8);
        }	
		SetSynchDirty();
	};
	
	string GetPistolTipsTendancyCreationType()
	{
        if (m_CastPistolTips == 0)
		{
          return "22LR";
        }
		if (m_CastPistolTips == 1)
		{
          return "9x19";
        }
        if (m_CastPistolTips == 2)
		{
           return "45ACP";
        }
		if (m_CastPistolTips == 3)
		{
           return "357";
        }
		if (m_CastPistolTips == 4)
		{
           return "380ACP";
        }
		if (m_CastPistolTips == 5)
		{
           return "Buckshot";
        }
        return "";
    };
	
	void MinusQuantityPistol()
	{
		if (m_CastPistolTips == 0)
		{
          AddQuantity(-13);
        }
		else if (m_CastPistolTips == 1)
		{
          AddQuantity(-20);
        }
        else if (m_CastPistolTips == 2)
		{
           AddQuantity(-23);
        }
		else if (m_CastPistolTips == 3)
		{
           AddQuantity(-26);
        }
		else if (m_CastPistolTips == 4)
		{
           AddQuantity(-15);
        }
		else if (m_CastPistolTips == 5)
		{
           AddQuantity(-8);
        }
		SetSynchDirty();
	};
	
	override void StepTipsRifleTendancy()
	{
      m_CastRifleTips++;
      if (m_CastRifleTips > 6)
	  {
         m_CastRifleTips = 0;
      }
      SetSynchDirty();
    };
	override void StepTipsPistolTendancy()
	{
      m_CastPistolTips++;
      if (m_CastPistolTips > 5)
	  {
         m_CastPistolTips = 0;
      }
      SetSynchDirty();
    };
	
	int TipsRifleTendancy()
	{
        return m_CastRifleTips;
    };
	
	int TipsPistolTendancy()
	{
		return m_CastPistolTips;
    };
	
	
	
	protected ref Timer m_AmmoCoolingTimer;
	
	override void EOnInit(IEntity other, int extra)
	{
		SetTemperature(300);
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	}
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	}
	protected void StartCooling()
	{
		m_AmmoCoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_AmmoCoolingTimer.Run( 3, this, "Cooling", NULL, true );		// true param loops
	}


	void Cooling()
	{
		if (GetTemperature() >= 1)
		{
			float temperature = GetTemperature();
			temperature = temperature - 4;
		}

		SetTemperature(temperature);

		if ( GetTemperature() <= 1)
		{
			StopCooling();
		}
	}
	protected void StopCooling()
	{
		if(m_AmmoCoolingTimer)
		{
			//Stop cooling
			m_AmmoCoolingTimer.Stop();
			m_AmmoCoolingTimer = NULL;
		};

	
	}
	override bool CanPutIntoHands(EntityAI parent)
    {
        if ( parent.FindAttachmentBySlotName( "Gloves" ))
        {
            return true;
        }
		if ( GetTemperature() <= 80)
		{
			return true;
		}
		return false;
    }
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAM_LeadChangeCastingAction);
		AddAction(AM_ActionCastingTipsAmmo);
	}	

}