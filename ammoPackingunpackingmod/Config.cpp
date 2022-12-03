class CfgPatches
{
    class ND_ammoMaking
    {
        units[] =
		{
			""
		};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Gear_Camping",
			"DZ_Gear_Medical"
		};
    };
};
class CfgMods
{
	class ND_ammoMaking
	{
		dir="ammoPackingunpackingmod";
		name="ammoMaking";
		credits="Dumpgrah";
		author="Dumpgrah";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[] = 
				{ 
					"ammoPackingunpackingmod\Scripts\3_Game" 
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"ammoPackingunpackingmod\Scripts\4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"ammoPackingunpackingmod\Scripts\5_Mission"
				};
			};
		};
	};
};
class CfgSlots
{
    class Slot_Crucible_Input
    {
        name="CrucibleInput";
        displayName="CrucibleInput";
    };
	class Slot_Charcoal_Gunpowder
    {
        name="GunPowderCharcoal";
        displayName="GunPowderCharcoal";
    };
	class Slot_MountingPlate
    {
        name="MountingPlate";
        displayName="MountingPlate";
    };
	class Slot_DieCast
    {
        name="DieCast";
        displayName="DieCast";
    };
	class Slot_MechanismHandle
    {
        name="Mechanism";
        displayName="Mechanism";
    };
	class Slot_RifleCasingMold
	{
		name="RifleCasingMold";
        displayName="Casted Casings";
	}
	class Slot_RifleTipsMold
	{
		name="RifleTipsMold";
        displayName="Casted Tips";
	};
	class Slot_Gunpowder_RDX
	{
		name="Gunpowder_RDX";
        displayName="Gunpowder";
		stackMax=40;
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyGasHookupSmelter : ProxyAttachment
	{
		scope = 2;
		inventorySlot[]+={"GasCanister"};
		model="GasCannisterLarge.p3d";
	};
	class ProxyCrucibleFilledCasing : ProxyAttachment
	{
		scope = 2;
		inventorySlot[]+={"CrucibleInput"};
		model="ammoPackingunpackingmod\ammo_ColorBase\CrucibleFilledCasing.p3d";
	};
	class ProxyPotassiumNitrate : ProxyAttachment
	{
		scope = 2;
		inventorySlot[]+={"GunPowderCharcoal"};
		model="DZ\gear\medical\PotassiumNitrate.p3d";
	};
	class ProxyPressCasingholder : ProxyAttachment
	{
		scope = 2;
		inventorySlot[]+={"DieCast"};
		model="ammoPackingunpackingmod\ammo_ColorBase\PressCasingholder.p3d";
	};
	class ProxyPressHandle : ProxyAttachment
	{
		scope = 2;
		inventorySlot[]+={"Handle"};
		model="ammoPackingunpackingmod\ammo_ColorBase\PressHandle.p3d";
	};
	class ProxyPressMechaismhandle : ProxyAttachment
	{
		scope = 2;
		inventorySlot[]+={"Mechanism"};
		model="ammoPackingunpackingmod\ammo_ColorBase\PressMechaismhandle.p3d";
	};
	class ProxyPressMountPlate : ProxyAttachment
	{
		scope = 2;
		inventorySlot[]+={"MountingPlate"};
		model="ammoPackingunpackingmod\ammo_ColorBase\PressMountPlate..p3d";
	};

};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class HouseNoDestruct;
	class Doors;
	class SeaChest;
	class Rag;
	class WeaponCleaningKit;
	class FireplaceBase;
	class Firewood;
	class Bottle_Base;
	class AM_CasingBase: Inventory_Base
	{inventorySlot[]+={"RifleCasingMold"};};
	class AM_TipsBase: Inventory_Base
	{inventorySlot[]+={"RifleTipsMold"};};
	class PressBase : Inventory_Base{};
	class CrucibleBase : Inventory_Base{};
	
	class Potassium_Nitrate : Inventory_Base
	{
		scope=2;
		displayName="Potassium Nitrate";
		descriptionShort="Potassium nitrate probably is used as a oxidizer in blackpowder. From the most ancient times until the late 1880s, blackpowder provided the explosive power for all the world's firearms. After that time, small arms and large artillery increasingly began to depend on cordite, a smokeless powder.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PotassiumNitrate.p3d";
		animClass="NoFireClass";
		weight=20;
		absorbency=0.30000001;
		itemSize[]={2,2};
		canBeSplit=0;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		stackedUnit = "percentage";
		quantityBar = 1;
		hitpoints=500;

	};
	class Potassium_Nitrate_Charcoal : Inventory_Base
	{
		scope=2;
		displayName="Potassium Nitrate With Charcoal";
		descriptionShort="Potassium nitrate probably is used as a oxidizer in blackpowder. From the most ancient times until the late 1880s, blackpowder provided the explosive power for all the world's firearms. After that time, small arms and large artillery increasingly began to depend on cordite, a smokeless powder. Upon further inspection I see charcoal has been mixed in this.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PotassiumNitrate.p3d";
		animClass="NoFireClass";
		weight=20;
		absorbency=0.30000001;
		itemSize[]={2,2};
		canBeSplit=0;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		stackedUnit = "percentage";
		quantityBar = 1;
		hitpoints=500;

	};
	class EmptyCrucible : CrucibleBase
	{
		scope=2;
		displayName="Crucible";
		descriptionShort="A empty crucible";
		model="\ammoPackingunpackingmod\ammo_ColorBase\EmptyCrucible.p3d";
	//	overrideDrawArea="3.0";
		itemSize[]={4,4};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=1;
		varTemperatureMin=0;
		varTemperatureMax=100;
		varStackMax=0;
		quantityBar = 0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=225;
		carveNavmesh=0;
	};
	class CrucibleFilledCasing : CrucibleBase
	{
		scope=2;
		displayName="Crucible with Casings";
		descriptionShort="Crucible Filled with Casing";
		model="\ammoPackingunpackingmod\ammo_ColorBase\CrucibleFilledCasing.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]+={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=500;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class CrucibleFilledTips : CrucibleBase
	{
		scope=2;
		displayName="Crucible with Tips";
		descriptionShort="Crucible Filled with Tips";
		model="\ammoPackingunpackingmod\ammo_ColorBase\CrucibleFilledTips.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]+={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1250;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class CrucibleMoltenBrass : CrucibleBase
	{
		scope=2;
		displayName="Crucible with molten brass";
		descriptionShort="Crucible Filled with Molten Brass";
		model="\ammoPackingunpackingmod\ammo_ColorBase\MoltenBrass.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]+={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1250;
		varLiquidTypeInit=600;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class CrucibleMoltenLead : CrucibleBase
	{
		scope=2;
		displayName="Crucible with molten Lead";
		descriptionShort="Crucible Filled with Molten Lead";
		model="\ammoPackingunpackingmod\ammo_ColorBase\MoltenLead.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]+={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=500;
		varLiquidTypeInit=600;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	
	class StandAloneSmelter : CrucibleBase
	{
		scope = 2;
		displayName = "Stand-Alone Smelter";
		descriptionShort = " StandAlone Smelter, used in melting down tips or casings ";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\StandaloneSmelter.p3d";
	//	overrideDrawArea="3.0";
		hitpoints=1000;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		rotationFlags=2;
	//	varTemperatureMin=0;
		varTemperatureMax=1800;
		absorbency=0.0;
		openable=0;
		heavyItem=1;
		carveNavmesh=0;
		stackedUnit="";
		randomQuantity=0;
		varLiquidTypeInit=0;
		liquidContainerType="";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		weight=8000;
		itemSize[]={10,13};
		physLayer = "item_large";
		itemBehaviour = 2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{
			"GasCanister",
			"CrucibleInput"
			
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="Gas Hook Up";
				description="";
				attachmentSlots[]=
				{
					"GasCanister"
				};
				icon="gascanister";
			};
			class CrucibleInput
			{
				name="Crucible Holder ";
				description="";
				attachmentSlots[]=
				{
					"CrucibleInput"
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=0;
			autoSwitchOff=1;
			autoSwitchOffWhenInCargo=1;
			energyStorageMax=0;
			energyUsagePerSecond=0.75;
			energyAtSpawn=0;
			powerSocketsCount=0;
			plugType=7;
			attachmentAction=1;
		};
	};
	class Sulfur20LbBag : PressBase
	{
		scope = 2;
		displayName = "25KG Sulfur Bag";
		descriptionShort = " 25KG bag of sulfur, used in creating gunpowder. ";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\Sulfur20LbsBag.p3d";
		animClass = "Knife";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=200;
		varQuantityMin=0;
		varQuantityMax=200;
		varQuantityDestroyOnMin=1;
		stackedUnit = "percentage";
		quantityBar = 1;
		weight = 17.5;
		itemSize[] = { 4,5 };
		repairableWithKits[]={0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\tanned_leather.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\tanned_leather.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\tanned_leather_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\tanned_leather_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\tanned_leather_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class StrongRifleCasingMold : Inventory_Base
	{
		scope=2;
		displayName="Metal Rifle Casing Mold";
		descriptionShort="Mold that is Used for making metal casing for ammo, seems to be high quality and will last a while";
		model="\ammoPackingunpackingmod\ammo_ColorBase\RifleMoldCasing.p3d";
		attachments[]={"RifleCasingMold"};
		simpleHiddenSelections[] = {"Casted_Casing"};
	//	overrideDrawArea="3.0";
		itemSize[]={4,4};
		hitpoints=50;
	    inventorySlot[]+={};
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=50;
		carveNavmesh=0;
	};
	class StrongRifleTipsMold : Inventory_Base
	{
		scope=2;
		displayName="Metal Rifle Tips Mold";
		descriptionShort="Mold that is Used for making metal tips for ammo, seems to be high quality and will last a while";
		model="\ammoPackingunpackingmod\ammo_ColorBase\MetalTipMold.p3d";
		attachments[]={"RifleTipsMold"};
		simpleHiddenSelections[] = {"Casted_Tips"};
	//	overrideDrawArea="3.0";
		itemSize[]={4,4};
		hitpoints=50;
	    inventorySlot[]+={};
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=50;
		carveNavmesh=0;
	};
	class StrongPistolCasingMold : Inventory_Base
	{
		scope=2;
		displayName="Metal Pistol Casing Mold";
		descriptionShort="Mold that is Used for making metal casing for ammo, seems to be high quality and will last a while";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PistolCasingMold.p3d";
		attachments[]={"RifleCasingMold"};
		simpleHiddenSelections[] = {"Casted_Casing"};
	//	overrideDrawArea="3.0";
		itemSize[]={4,2};
		hitpoints=50;
	    inventorySlot[]+={};
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=50;
		carveNavmesh=0;
	};
	class StrongPistolTipsMold : Inventory_Base
	{
		scope=2;
		displayName="Metal Pistol Tips Mold";
		descriptionShort="Mold that is Used for making metal tips for ammo, seems to be high quality and will last a while";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PistolTipsMold.p3d";
		//	overrideDrawArea="3.0";
		attachments[]={"RifleTipsMold"};
		simpleHiddenSelections[] = {"Casted_Tips"};
		itemSize[]={4,2};
		hitpoints=50;
	    inventorySlot[]+={};
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=50;
		carveNavmesh=0;
	};
	
	class Tips40mm : AM_TipsBase
	{
		scope = 2;
		displayName = "40mm Grenade Head";
		descriptionShort = "Grenade Head from a 40mm grenade round, seem quite dangrous. not made of lead but maybe i can create something with the rdx and gunpowder with this.";
		model = "ammoPackingunpackingmod\ammo_ColorBase\Tips_40mm_Grenade_AM.p3d";
		animClass = "Knife";
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		hiddenSelections[]=
		{
			"Grenade_Head_None"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_hedp_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade.rvmat"
		};
	};
	
	class Tips40mmRedSmoke : Tips40mm
	{
		scope = 2;
		displayName = "40mm Red Smoke Grenade Head";
		descriptionShort = "Red Smoke Grenade Head from a 40mm grenade round, seem quite dangrous. not made of lead but maybe i can create something with the rdx and gunpowder with this.";
		model = "ammoPackingunpackingmod\ammo_ColorBase\Tips_40mm_Grenade_AM.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokered.rvmat"
		};
	};
	
	class Tips40mmGreenSmoke : Tips40mm
	{
		scope = 2;
		displayName = "40mm Green Smoke Grenade Head";
		descriptionShort = "Green Smoke Grenade Head from a 40mm grenade round, seem quite dangrous. not made of lead but maybe i can create something with the rdx and gunpowder with this.";
		model = "ammoPackingunpackingmod\ammo_ColorBase\Tips_40mm_Grenade_AM.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokegreen.rvmat"
		};
	};
	
	class Tips40mmWhiteSmoke : Tips40mm
	{
		scope = 2;
		displayName = "40mm White Smoke Grenade Head";
		descriptionShort = "White Smoke Grenade Head from a 40mm grenade round, seem quite dangrous. not made of lead but maybe i can create something with the rdx and gunpowder with this.";
		model = "ammoPackingunpackingmod\ammo_ColorBase\Tips_40mm_Grenade_AM.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokewhite.rvmat"
		};
	};
	
	class Tips40mmBlackSmoke : Tips40mm
	{
		scope = 2;
		displayName = "40mm Black Smoke Grenade Head";
		descriptionShort = "Black Smoke Grenade Head from a 40mm grenade round, seem quite dangrous. not made of lead but maybe i can create something with the rdx and gunpowder with this.";
		model = "ammoPackingunpackingmod\ammo_ColorBase\Tips_40mm_Grenade_AM.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokeblack.rvmat"
		};
	};
	
	class Casing40mm : AM_CasingBase
	{
		scope = 2;
		displayName = "40mm Grenade Casing";
		descriptionShort = "Grenade Casing from a 40mm grenade round, seem quite dangrous. not made of brass so mostly useless, who knows maybe one day ill figure it out.";
		model = "ammoPackingunpackingmod\ammo_ColorBase\Data\40mm Grenade\Casing_40mm_Grenade_AM.p3d";
		animClass = "Knife";
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
	};
	
	class Tips357 : AM_TipsBase
	{
		scope = 2;
		displayName = ".357 Magnum tips";
		descriptionShort = ".357 magmun tips used for crafting";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\357Tips.p3d";
		animClass = "Knife";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing357 : AM_CasingBase
	{
		scope = 2;
		displayName = ".357 Magnum Casings";
		descriptionShort = ".357 Magnum Casings used for crafting";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\357Casing.p3d";
		animClass = "Knife";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing357 : Inventory_Base
	{
		scope = 2;
		displayName = "Filled .357 Magnum Casings";
		descriptionShort = "Filled .357 Magnum Casings,missing the tips?";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\357Casing.p3d";
		animClass = "Knife";
		canBeDigged=0;
	       isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Prep357Magnum : Inventory_Base
	{
		scope = 2;
		displayName = "Prep'd .357 Magnum";
		descriptionShort = "Just need to use on the press to finish the process.";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\357Prep.p3d";
		animClass = "Knife";
		canBeDigged=0;
	       isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips545x39 : AM_TipsBase
	{
		scope = 2;
		displayName = "545x39 tips";
		descriptionShort = "545x39 tips used for crafting";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\545x39Tips.p3d";
		animClass = "Knife";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing545x39 : AM_CasingBase
	{
			scope = 2;
			displayName = "545x39 Casings";
			descriptionShort = "545x39 Casings used for crafting";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\545x39Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class FilledCasing545x39 : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 545x39 Casings";
			descriptionShort = "Filled 545x39 Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\545x39Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep545x39 : Inventory_Base
	{
			scope = 2;
			displayName = "Prep'd 545x39";
			descriptionShort = "Just need to use on the press to finish the process";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\545x39Prep.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,2 };
			repairableWithKits[]={0};
		
	};
	class Tips556x45 : AM_TipsBase
	{
		scope=2;
		displayName = "556x45 Tips";
		descriptionShort = "556x45 Tips  used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\556x45Tips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing556x45 : AM_CasingBase
	{
		scope=2;
		displayName = "556x45 Casing";
		descriptionShort = "556x45 Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\556x45Casings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing556x45 : Inventory_Base
	{
		scope = 2;
		displayName = "Filled 545x45 Casings";
		descriptionShort = "Filled 545x39 Casings,missing the tips?";
		model = "\ammoPackingunpackingmod\ammo_ColorBase\556x45Casings.p3d";
		animClass = "Knife";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Prep556x45 : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 556x45";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\556x45Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips762x39 : AM_TipsBase
	{
		scope=2;
		displayName = "762x39 Tips";
		descriptionShort = "762x39 Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x39Tips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing762x39 : AM_CasingBase
	{
		scope=2;
		displayName = "762x39 Casing";
		descriptionShort = "762x39 Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x39Casings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing762x39 : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 762x39 Casings";
			descriptionShort = "Filled 762x39 Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\762x39Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep762x39 : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 762x39";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x39Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips308Win : AM_TipsBase
	{
		scope=2;
		displayName = "308 Win Tips";
		descriptionShort = "308 Win Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\308WinTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing308Win : AM_CasingBase
	{
		scope=2;
		displayName = "308 Win Casing";
		descriptionShort = "308 Win Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\308WinCasings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing308Win : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 308 Win Casings";
			descriptionShort = "Filled 308 Win Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\308WinCasings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class FilledCasing308WinOL : Inventory_Base
	{
			scope = 2;
			displayName = "Filled overloaded 308 Win Casings";
			descriptionShort = "Filled overloaded 308 Win Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\308WinCasingsOL.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep308Win : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 308 Win";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\308WinPrep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Prep308WinOL : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd overloaded 308 Win";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\308WinPrepOL.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips762x54 : AM_TipsBase
	{
		scope=2;
		displayName = "762x54 Tips";
		descriptionShort = "762x54 Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x54Tips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Tips762x54Rubber : AM_TipsBase
	{
		scope=2;
		displayName = "762x54 Rubber Tips";
		descriptionShort = "762x54 rubber tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x54_Rubber_Tips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing762x54 : AM_CasingBase
	{
		scope=2;
		displayName = "762x54 Casing";
		descriptionShort = "762x54 Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x54Casings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing762x54 : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 762x54 Casing";
			descriptionShort = "Filled 762x54 Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\762x54Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class FilledCasing762x54OP : Inventory_Base
	{
			scope = 2;
			displayName = "Filled Overloaded 762x54 Casing";
			descriptionShort = "Filled overloaded 762x54 Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\762x54Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep762x54 : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 762x54";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x54Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Prep762x54Rubber : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd Rubber 762x54";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x54_Rubber_Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Prep762x54OP : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd Overloaded 762x54";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\762x54Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips9x39 : AM_TipsBase
	{
		scope=2;
		displayName = "9x39 Tips";
		descriptionShort = "9x39 Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x39Tips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing9x39 : AM_CasingBase
	{
		scope=2;
		displayName = "9x39 Casing";
		descriptionShort = "9x39 Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x39Casings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing9x39 : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 9x39 Casing";
			descriptionShort = "Filled 9x39 Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\9x39Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=20;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep9x39 : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 9x39";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x39Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips45ACP : AM_TipsBase
	{
		scope=2;
		displayName = "45ACP Tips";
		descriptionShort = "45ACP Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\45ACPTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class TipsRubber45ACP : AM_TipsBase
	{
		scope=2;
		displayName = "45ACP Rubber Tips";
		descriptionShort = "45ACP Rubber Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\45ACPRubberTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing45ACP : AM_CasingBase
	{
		scope=2;
		displayName = "45ACP Casing";
		descriptionShort = "45ACP Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\45ACPCasings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing45ACP : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 45ACP Casing";
			descriptionShort = "Filled 45ACP Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\45ACPCasings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=25;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep45ACP : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 45ACP";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\45ACPPrep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class PrepRubber45ACP : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd Rubber 45ACP";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\45ACPPrepRubber.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips9X19 : AM_TipsBase
	{
		scope=2;
		displayName = "9X19 Tips";
		descriptionShort = "9X19 Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x19Tips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class TipsRubber9X19 : AM_TipsBase
	{
		scope=2;
		displayName = "9X19 Rubber Tips";
		descriptionShort = "9X19 Rubber Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x19RubberTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing9X19 : AM_CasingBase
	{
		scope=2;
		displayName = "9X19 Casing";
		descriptionShort = "9X19 Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x19Casings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing9X19 : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 9X19 Casing";
			descriptionShort = "Filled 9X19 Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\9x19Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=25;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep9X19 : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 9X19";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x19Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class PrepRubber9X19 : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd Rubber 9X19";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\9x19PrepRubber.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips22LR : AM_TipsBase
	{
		scope=2;
		displayName = "22LR Tips";
		descriptionShort = "22LR Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\22Tips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing22LR : AM_CasingBase
	{
		scope=2;
		displayName = "22LR Casing";
		descriptionShort = "22LR Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\22Casings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing22LR : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 22LR Casing";
			descriptionShort = "Filled 22LR Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\22Casings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=50;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep22LR : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 22LR";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\22Prep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class Tips380ACP : AM_TipsBase
	{
		scope=2;
		displayName = "380ACP Tips";
		descriptionShort = "380ACP Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\380ACPTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=35;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class TipsRubber380ACP : AM_TipsBase
	{
		scope=2;
		displayName = "380ACP Rubber Tips";
		descriptionShort = "380ACP Rubber Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\380ACPRubberTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=35;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Casing380ACP : AM_CasingBase
	{
		scope=2;
		displayName = "380ACP Casing";
		descriptionShort = "380ACP Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\380ACPCasingss.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=35;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasing380ACP : Inventory_Base
	{
			scope = 2;
			displayName = "Filled 380ACP Casing";
			descriptionShort = "Filled 380ACP Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\380ACPCasingss.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=35;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class Prep380ACP : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd 380ACP";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\380ACPPrep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=35;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class PrepRubber380ACP : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd Rubber 380ACP";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\380ACPPrepRubber.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=35;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class TipsBuckshot : AM_TipsBase
	{
		scope=2;
		displayName = "Buckshot";
		descriptionShort = "Buckshot Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\BuckshotTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class CasingBuckshot : AM_CasingBase
	{
		scope=2;
		displayName = "Buckshot Casing";
		descriptionShort = "Buckshot Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\BuckshotCasings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCasingBuckshot : Inventory_Base
	{
			scope = 2;
			displayName = "Filled Buckshot Casing";
			descriptionShort = "Filled Buckshot Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\BuckshotCasings.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=10;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class PrepBuckshot : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd Buckshot";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\BuckshotPrep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class TipsSlug : AM_TipsBase
	{
		scope=2;
		displayName = "Slugs";
		descriptionShort = "Slugs Tips used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\ShotgunslugTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class TipsRubberSlug : AM_TipsBase
	{
		scope=2;
		displayName = "Rubber Slugs Tips";
		descriptionShort = "Rubber Slugs Tips used for crafting";
		model="ammoPackingunpackingmod\ammo_ColorBase\Data\Rubber Slugs\RubberSlug_Tip.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class CasingSlug : AM_CasingBase
	{
		scope=2;
		displayName = "Slug Casing";
		descriptionShort = "Slug Casing used for crafting";
		model="\ammoPackingunpackingmod\ammo_ColorBase\ShotgunslugCasining.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class CasingCraftedShotgunShells : AM_CasingBase
	{
		scope=2;
		displayName = "Crafted Shotgun Casing";
		descriptionShort = "Crafted Casing used for crafting shotgun shells";
		model="ammoPackingunpackingmod\ammo_ColorBase\HandMadeShotgunCasining.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class FilledCraftedShotgunShell : Inventory_Base
	{
			scope = 2;
			displayName = "Filled Shotgun Casing";
			descriptionShort = "Filled Slug Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\HandMadeShotgunCasining.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=10;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class FilledCasingSlug : Inventory_Base
	{
			scope = 2;
			displayName = "Filled Slug Casing";
			descriptionShort = "Filled Slug Casings,missing the tips?";
			model = "\ammoPackingunpackingmod\ammo_ColorBase\ShotgunslugCasining.p3d";
			animClass = "Knife";
			canBeDigged=0;
	        isMeleeWeapon=1; 
			rotationFlags = 17;
			quantityBar = 0;
			canBeSplit=1;
			varQuantityInit=1;
			varQuantityMin=0;
			varQuantityMax=10;
			varQuantityDestroyOnMin=1;
			weight = 20;
			itemSize[] = { 1,1 };
			repairableWithKits[]={0};
		
	};
	class PrepSlug : Inventory_Base
	{
		scope=2;
		displayName = "Prep'd Slugs";
		descriptionShort = "Just need to use on the press to finish the process";
		model="\ammoPackingunpackingmod\ammo_ColorBase\ShotgunslugPrep.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		
	};
	class DeFormedPistolCasing : AM_CasingBase
	{
		scope=2;
		displayName = "Deformed Pistol Casing";
		descriptionShort = "A Pistol Casing, its deformed from being shot.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\DeformedPistolCasings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class DeFormedPistolTips : AM_TipsBase
	{
		scope=2;
		displayName = "Deformed Pistol Tips";
		descriptionShort = "A Pistol Tip, its deformed from being shot into something.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\DeformedPistolTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class DeFormedRifleCasing : AM_CasingBase
	{
		scope=2;
		displayName = "Deformed Rifle Casing";
		descriptionShort = "A Rifle Casing, its deformed from being shot.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\DeformedRifleCasings.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class DeFormedRifleTips : AM_TipsBase
	{
		scope=2;
		displayName = "Deformed Rifle Tips";
		descriptionShort = "A Rifle Tip, its deformed from being shot into something.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\DeformedRifleTips.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		weight = 20;
		itemSize[] = { 1,1 };
		repairableWithKits[]={0};
		
	};
	class Gunpowder : WeaponCleaningKit
	{
		scope=2;
		displayName = "Gunpowder grains";
		descriptionShort = "Gunpowder grains, maybe I can make ammo from this";
		model="\ammoPackingunpackingmod\ammo_ColorBase\Gunpowder.p3d";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1400;
		varQuantityDestroyOnMin=1;
		weight = 2;
		itemSize[] = { 3,2 };
		repairableWithKits[]={0};
		inventorySlot[]+={"Gunpowder_RDX"};
	};
	
	class RDXCompound : WeaponCleaningKit
	{
		scope=2;
		displayName = "RDX Compound";
		descriptionShort = "Gunpowder grains, maybe I can make ammo from this";
		model="ammoPackingunpackingmod\ammo_ColorBase\Data\40mm Grenade\RDX_Compound.p3d";
		canBeDigged=0;
	    isMeleeWeapon=1;
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=23;
		varQuantityDestroyOnMin=1;
		weight = 2;
		itemSize[] = { 1,2 };
		repairableWithKits[]={0};
		attachments[]={"Gunpowder_RDX"};
	};
	class Scale : Inventory_Base
	{
		scope=2;
		displayName = "Digital scale";
		descriptionShort = "A digital precision scale, by the looks of it, it has gunpowder residue on it. ";
		model="\ammoPackingunpackingmod\ammo_ColorBase\Scale.p3d";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		canBeSplit=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		weight = 200;
		itemSize[] = { 2,2 };
		repairableWithKits[]={0};
		
	};
	class Funnel : Inventory_Base
	{
		scope=2;
		displayName = "A funnel";
		descriptionShort = "A funnel,maybe can use this for filling ammo?";
		model="\ammoPackingunpackingmod\ammo_ColorBase\Funnel.p3d";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		canBeSplit=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		weight = 100;
		itemSize[] = { 2,2 };
		repairableWithKits[]={0};
		
	};
	class ammoWorkbenchlegs : SeaChest
	{
		scope=2;
		displayName = "WorkBench Legs";
		descriptionShort = "Legs used in crafting the ammo making workbench base.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchLegs.p3d";
		weight=2000;
		itemBehaviour=0;
		itemSize[]={10,10};
		carveNavmesh=1;
		quantityBar = 0;
		canBeSplit=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=4;
		varQuantityDestroyOnMin=1;
		repairableWithKits[]={0};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		
	};
	class ammoWorkbenchEmpty : SeaChest
	{
		scope=2;
		displayName = "WorkBench";
		descriptionShort = "Maybe I could put stuff on it?";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchempty.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=12000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class ammoWorkbenchPressAttached : SeaChest
	{
		scope=2;
		displayName = "WorkBench with Press";
		descriptionShort = "Looks like I need a few more things";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchPressAttached.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=20000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		
	};
	class ammoWorkbenchScalePressAttached : SeaChest
	{
		scope=2;
		displayName = "WorkBench with press and scale";
		descriptionShort = "I am missing something?";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchScalePressAttached.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=20000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		
	};
	class ammoWorkbenchScale : SeaChest
	{
		scope=2;
		displayName = "WorkBench with scale";
		descriptionShort = "Not yet completed";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchScaledAttached.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=12000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class ammoWorkbenchFunnel : SeaChest
	{
		scope=2;
		displayName = "WorkBench with funnel";
		descriptionShort = "Not yet completed";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchFunnelAttached.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=12000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class ammoWorkbenchScaleFunnel : SeaChest
	{
		scope=2;
		displayName = "WorkBench with scale/funnel";
		descriptionShort = "Almost completed";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchScaleFunnelAttached.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=12000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class ammoWorkbenchPressFunnel : SeaChest
	{
		scope=2;
		displayName = "WorkBench with press and funnel";
		descriptionShort = "Almost completed";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchPressFunnel.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=12000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class ammoWorkbenchCompleted : SeaChest
	{
		scope=2;
		displayName = "Completed workbench";
		descriptionShort = "Now I can start making ammo.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchCompleted.p3d";
		hitpoints=10000;
		heavyItem=1;
		weight=20000;
		itemBehaviour=0;
		itemSize[]={20,20};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		repairableWithKits[]={0};
		placement="ForceSlopeOnTerrain";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		
	};
	class UnMoveableammoWorkbenchCompleted : Container_Base
	{
		scope=2;
		model="\ammoPackingunpackingmod\ammo_ColorBase\AmmoWorkbenchCompleted.p3d";
		physLayer = "item_large";
		heavyItem=1;
		slopeTolerance=0.44999999;


	};
	
	class PressCompleted : PressBase
	{
		scope=2;
		displayName = "Completed ammo press";
		descriptionShort = "A ammo making setup, time to make some ammo.";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PressCompleted.p3d";
		heavyItem=1;
		weight=20000;
		itemBehaviour=0;
		itemSize[]={8,8};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		
	};
	class PressCasingholder : Inventory_Base
	{
		scope=2;
		displayName = "Press Die";
		descriptionShort = "Looks like a ammo die that belongs to a machine?";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PressCasingholder.p3d";
		animClass = "Knife";
		weight=2000;
	    isMeleeWeapon=1; 
		itemBehaviour=0;
		itemSize[]={1,3};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		fragility = 0.0020999998;
		repairableWithKits[]={0};
		inventorySlot[]+={"DieCast"};
	};
	class PressBody : PressBase
	{
		scope=2;
		displayName = "Press Body";
		descriptionShort = "Ammo Press Body, Looks like it would be easy to attach parts to make a complete press";
		model="\ammoPackingunpackingmod\ammo_ColorBase\FuturePress.p3d";
		animClass = "SledgeHammer";
		weight=14000;
	    isMeleeWeapon=1; 
		itemBehaviour=0;
		itemSize[]={5,4};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		fragility = 0.0020999998;
		repairableWithKits[]={0};
		attachments[]=
		{
			"DieCast",
			"Mechanism",
			"MountingPlate"
			
		};
		class GUIInventoryAttachmentsProps
		{
			class PressParts
			{
				name="parts";
				description="";
				attachmentSlots[]=
				{
					"DieCast",
					"Mechanism",
					"MountingPlate"
				};
				icon="";
			};
		};
	};
	class PressMountPlate : Inventory_Base
	{
		scope=2;
		displayName = "Mount Plate";
		descriptionShort = "Looks like a mounting plate to some machine";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PressMountPlate.p3d";
		animClass = "Knife";
		weight=4000;
	    isMeleeWeapon=1; 
		itemBehaviour=0;
		itemSize[]={2,2};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		fragility = 0.0020999998;
		repairableWithKits[]={0};
		inventorySlot[]+={"MountingPlate"};
	};
    class PressHandle : Inventory_Base
	{
		scope=2;
		displayName = "Handle";
		descriptionShort = "Looks like a Handle for some machine?";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PressHandle.p3d";
		animClass = "Knife";
		weight=1000;
	    isMeleeWeapon=1; 
		itemBehaviour=0;
		itemSize[]={1,3};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		fragility = 0.0020999998;
		repairableWithKits[]={0};
		
	};
	class PressMechanism : Inventory_Base
	{
		scope=2;
		displayName = "A Mechanism";
		descriptionShort = "A leverage mechanism for some machine";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PressMechanism.p3d";
		animClass = "Knife";
		weight=3000;
	    isMeleeWeapon=1; 
		itemBehaviour=0;
		itemSize[]={4,2};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		fragility = 0.0020999998;
		repairableWithKits[]={0};
		
	};
	
	class PressMechaismhandle : Inventory_Base
	{
		scope=2;
		displayName = "A Mechanism/lever";
		descriptionShort = "A leverage mechanism with a handle for some machine";
		model="\ammoPackingunpackingmod\ammo_ColorBase\PressMechaismhandle.p3d";
		animClass = "Knife";
		weight=4000;
	    isMeleeWeapon=1; 
		itemBehaviour=0;
		itemSize[]={5,3};
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		fragility = 0.0020999998;
		repairableWithKits[]={0};
		inventorySlot[]+={"mechanism"};
	};
	
	class Grenade_Base;
	class AM_Improvised_Grenade: Grenade_Base
	{
		scope=2;
		displayName="Improvised 40mm Grenade";
		descriptionShort="40mm warhead with RDX making it a throwable impact grenade. Throw me, and make a impact today... on yourself or others!! ";
		model="ammoPackingunpackingmod\ammo_ColorBase\Improvised_40mm_Grenade_AM.p3d";
		weight=500;
		itemSize[]={1,1};
		//rotationFlags=1;
		inventorySlot[]=
		{
			"IEDExplosiveA",
			"IEDExplosiveB",
			"VestGrenadeA",
			"VestGrenadeB",
			"VestGrenadeC",
			"VestGrenadeD",
			"tripWireAttachment"
		};
		hiddenSelections[]=
		{
			"Grenade_Head"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_hedp_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\ammunition\data\40mm_grenade.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\ammunition\data\40mm_grenade.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\ammunition\data\40mm_grenade_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\ammunition\data\40mm_grenade_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\ammunition\data\40mm_grenade_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	
	class M18SmokeGrenade_ColorBase;
	class AM_Smoke_Improvised_Grenade : M18SmokeGrenade_ColorBase
	{
		scope=2;
		displayName="Improvised Smoke 40mm Grenade";
		descriptionShort="40mm warhead with RDX making it a throwable impact grenade. Throw me, and make a impact today... on yourself or others!! ";
		model="ammoPackingunpackingmod\ammo_ColorBase\Improvised_Smoke_40mm_Grenade_AM.p3d";
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"Grenade_Head"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
		hiddenSelectionsMaterials[]=
		{
			"\DZ\weapons\ammunition\data\40mm_grenade.rvmat"
		};
	};

	class AM_Smoke_Improvised_Grenade_Red: AM_Smoke_Improvised_Grenade
	{
		scope=2;
		displayName="Improvised 40mm Red Smoke Grenade";
		descriptionShort="40mm warhead with RDX making it a throwable impact grenade. Throw me, and make a impact today... on yourself or others!! ";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokered.rvmat"
		};
	};
	
	class AM_Smoke_Improvised_Grenade_Green: AM_Smoke_Improvised_Grenade
	{
		scope=2;
		displayName="Improvised 40mm Green Smoke Grenade";
		descriptionShort="40mm warhead with RDX making it a throwable impact grenade. Throw me, and make a impact today... on yourself or others!! ";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokegreen.rvmat"
		};
	};
	
	class AM_Smoke_Improvised_Grenade_White: AM_Smoke_Improvised_Grenade
	{
		scope=2;
		displayName="Improvised 40mm White Smoke Grenade";
		descriptionShort="40mm warhead with RDX making it a throwable impact grenade. Throw me, and make a impact today... on yourself or others!! ";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokewhite.rvmat"
		};
	};
	
	class AM_Smoke_Improvised_Grenade_Black: AM_Smoke_Improvised_Grenade
	{
		scope=2;
		displayName="Improvised 40mm Black Smoke Grenade";
		descriptionShort="40mm warhead with RDX making it a throwable impact grenade. Throw me, and make a impact today... on yourself or others!! ";
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\ammunition\data\40mm_grenade_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\weapons\ammunition\data\40mm_grenade_smokeblack.rvmat"
		};
	};
	
};
class CfgAmmo
{
	class DefaultAmmo;
	class AM_Impact_RDX40mm: DefaultAmmo
	{
		indirectHit=1;
		indirectHitRange=3;
		indirectHitRangeMultiplier=4;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		caliber=1;
		deflecting=0;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			class Health
			{
				damage=45;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=0;
			};
		};
		class NoiseHit
		{
			strength=200;
			type="shot";
		};
	};
	class AM_Smoke_Impact_RDX40mm: DefaultAmmo
	{
		indirectHit=0;
		indirectHitRange=0;
		indirectHitRangeMultiplier=0;
		explosive=1;
		typicalSpeed=0;
		initSpeed=0;
		caliber=1;
		deflecting=0;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			class Health
			{
				damage=0;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=0;
			};
		};
		class NoiseHit
		{
			strength=200;
			type="shot";
		};
	};
};