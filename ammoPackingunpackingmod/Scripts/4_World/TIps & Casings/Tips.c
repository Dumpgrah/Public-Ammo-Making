class AM_TipsBase extends ItemBase
{
    string GetAmmoPartTendancyText()
    {
        return "Base Do Not Use";
    };
    int MutliQuantity()
	{
		return (GetQuantity() * 10);
	}
    float MathAddtion()
    {
		return (MutliQuantity() / GetFillnMakeQuantity() * 2);
    };
    
	int ReduceQuantity()
	{
		return GetQuantity();
	};
	
    int GetFillnMakeQuantity()
    {
        return 0;
    };
    
    override void SetActions()
    {
        super.SetActions();
        AddAction(Action_AM_FillTipsCrucible);
    };
    
};	
class Tips357 extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "357 Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 19;
    };
};
class Tips545x39 extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "545x39 Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 22;
    };
};
class Tips556x45 extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "556x45 Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 25;
    };
};
class Tips762x39 extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "762x39 Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 30;
    };
};
class Tips308Win extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "308 Win Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 32;
    };
};
class Tips762x54 extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "762x54 Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 35;
    };
};
class Tips9x39 extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "9x39 Tips";
    };

	
	override int GetFillnMakeQuantity()
	{
        return 20;
    };
};
class Tips45ACP extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "45ACP Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 18;
    };
};
class Tips9X19 extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "9x19 Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 15;
    };
};
class Tips22LR extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "22LR Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 7;
    };
};
class Tips380ACP extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "380ACP Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 10;
    };
};
class TipsBuckshot extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "BuckShot Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 5;
    };
};
class TipsSlug extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "Slug Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 5;
    };
};
class DeFormedPistolTips extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "Deformed Pistol Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 10;
    };
};
class DeFormedRifleTips extends AM_TipsBase
{
	override string GetAmmoPartTendancyText()
	{
        return "Deformed Rifle Tips";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 20;
    };
};