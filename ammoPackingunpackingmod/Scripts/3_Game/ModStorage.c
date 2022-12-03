#ifdef CF_MODSTORAGE
class DZ_Highlander: ModStructure
{
	override void LoadData()
	{
		super.LoadData();

		SetStorageVersion( 2 );
	}
}
#endif
