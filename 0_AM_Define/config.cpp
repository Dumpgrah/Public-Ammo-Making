class CfgPatches
{
	class AM_Define
	{
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class AM_Define
	{
		dir = "0_AM_Define";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Ammo_Making";
		credits = "";
		author = "Dumpgrah";
		authorID = "0";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Core","Game","World","Mission"};
		class defs
		{
			class engineScriptModule
			{
				value = "";
				files[] = {"0_AM_Define/scripts/Common"};
			};
			class gameLibScriptModule
			{
				files[] = {"0_AM_Define/scripts/Common"};
			};
			class gameScriptModule
			{
				files[] = {"0_AM_Define/scripts/Common"};
			};
			class worldScriptModule
			{
				files[] = {"0_AM_Define/scripts/Common"};
			};
			class missionScriptModule
			{
				files[] = {"0_AM_Define/scripts/Common"};
			};
		};
	};
};