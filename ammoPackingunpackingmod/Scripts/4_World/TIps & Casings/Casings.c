class AM_CasingBase extends ItemBase
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
        AddAction(Action_AM_FillCasingCrucible);
    };
};
class Casing357 extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "357 Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 19;
    };
};
class Casing545x39 extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "545x39 Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 22;
    };
};
class Casing556x45 extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "556x45 Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 25;
    };
};
class Casing762x39 extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "762x39 Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 30;
    };
};
class Casing308Win extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "308Win Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 32;
    };
};
class Casing762x54 extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "762x54 Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 35;
    };
};
class Casing9x39 extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "9x39 Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 20;
    };
};
class Casing45ACP extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "45ACP Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 18;
    };
};
class Casing9X19 extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "9x19 Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 15;
    };
};
class Casing22LR extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "22LR Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 7;
    };
};
class Casing380ACP extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "380ACP Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 10;
    };
};
class CasingBuckshot extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "Buckshot  Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 5;
    };
};
class CasingSlug extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "Slug  Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 5;
    };
};
class DeFormedPistolCasing extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "Deformed Pistol Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 10;
    };
};
class DeFormedRifleCasing extends AM_CasingBase
{
	override string GetAmmoPartTendancyText()
	{
        return "Deformed Rifle Casing";
    };
	
	
	override int GetFillnMakeQuantity()
	{
        return 20;
    };
};
 