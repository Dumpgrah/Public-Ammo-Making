class HighlanderData
{
	EntityAI m_Item;
	int m_ID1;
	int m_ID2;
	int m_ID3;
	int m_ID4;
	bool m_IDSet;

	void HighlanderData( EntityAI item )
	{
		m_Item = item;
	}

	void SetID()
	{
		m_Item.GetPersistentID( m_ID1, m_ID2, m_ID3, m_ID4 );
		m_IDSet = true;
	}
}
