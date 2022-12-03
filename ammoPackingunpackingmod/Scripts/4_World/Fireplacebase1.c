modded class FireplaceBase
{
	typename ATTACHMENT_COAL		    = ND_Coal;
    void FireplaceBase()
    {
        m_FireConsumableTypes.Insert( ATTACHMENT_COAL,         new FireConsumableType( ATTACHMENT_COAL,     300,     false,    "ND_Coal" ) );
    }
}