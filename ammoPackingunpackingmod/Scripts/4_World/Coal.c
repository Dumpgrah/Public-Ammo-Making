class ND_Coal extends ItemBase
{
	override bool CanPutInCargo( EntityAI parent )
	{
		if ( super.CanPutInCargo(parent) || !( this.GetQuantity() > 5 ) )
		{
			return true;
		}
		return false;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionClapBearTrapWithThisItem);
	}
}
class PressBase extends ItemBase{};