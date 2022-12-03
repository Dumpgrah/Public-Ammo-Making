class AM_Improvised_Grenade : Grenade_Base
{
	protected bool 					m_Exploded;
	protected ParticleSource 		m_ParticleExploded;
	protected EffectSound 			m_ExplosionSound;
	
	
	void AM_Improvised_Grenade()
	{
		SetParticleExplosion(ParticleList.M67);
		SetAmmoType("AM_Impact_RDX40mm");
		m_Pinned = false;
		SetPinnable(false);
		Arm();
	};

	void ~AM_Improvised_Grenade();

	override protected void OnExplode()
	{
		m_Exploded = true;
	};
	
	override void EOnContact(IEntity other, Contact extra)
	{
		super.EOnContact(other, extra);
		
		if (GetGame().IsServer())
		{
			if (!m_Exploded)
			{
				OnActivateFinished();
			}
		};
	};
	
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
	};
	
	override void OnDamageDestroyed(int oldLevel)
	{

	};
	
	override protected void Activate()
	{
		
	};
	
	override void OnActivatedByItem(notnull ItemBase item)
	{
		OnActivateFinished();
	};
	
};

class AM_Smoke_Improvised_Grenade extends M18SmokeGrenade_ColorBase
{
	protected bool 			  m_Exploded;
	protected ParticleSource  m_ParticleExploded;
	protected EffectSound 	  m_ExplosionSound;
	protected float 		  m_ParticleLifetime;
	protected bool			  m_Activated;
		
	void AM_Smoke_Improvised_Grenade()
	{
		SetParticlePosition("0 0.1 0");
		SetSoundSmokeStart(SOUND_SMOKE_START);
		SetSoundSmokeLoop(SOUND_SMOKE_LOOP);
		SetSoundSmokeEnd(SOUND_SMOKE_END);
		m_Pinned = false;
		SetPinnable(false);
		Arm();
	}

	void ~AM_Smoke_Improvised_Grenade();

	override protected void OnExplode()
	{
		m_Exploded = true;
	};
	
	override void EOnContact(IEntity other, Contact extra)
	{
		super.EOnContact(other, extra);
		
		if (GetGame().IsServer())
		{
			if (!m_Exploded)
			{
				OnActivateFinished();
				SetHealth(5);
			};
		};
	};
	
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
	}
	
	override void OnDamageDestroyed(int oldLevel)
	{

	};
	
	protected void Activate()
	{
		
	};
	
	override void OnActivatedByItem(notnull ItemBase item)
	{
		GetCompEM().SwitchOn();
		OnActivateFinished();
	};
	
	override void OnExplosionEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, float energyFactor, float explosionFactor, bool isWater, string ammoType)
	{
		super.OnExplosionEffects(source, directHit, componentIndex, surface, pos, surfNormal, energyFactor, explosionFactor, isWater, ammoType);

		if (m_ParticleExplosionId > ParticleList.INVALID)
		{
			EntityAI parent = this;
			if (GetHierarchyParent())
			{
				parent = GetHierarchyParent();
			}

			ParticleSource p = ParticleManager.GetInstance().PlayOnObject(m_ParticleExplosionId, parent, m_ParticlePosition, m_ParticleOrientation);
			m_ParticleExplosionArr.Insert(p);
			m_ParticleExplosion = p;
		}

		CreateLight();
	}
};

class AM_Smoke_Improvised_Grenade_Red extends AM_Smoke_Improvised_Grenade
{
	void AM_Smoke_Improvised_Grenade_Red()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_RED_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_RED_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_RED_END);
	};
};

class AM_Smoke_Improvised_Grenade_Green extends AM_Smoke_Improvised_Grenade
{
	void AM_Smoke_Improvised_Grenade_Green()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_GREEN_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_GREEN_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_GREEN_END);
	};
};

class AM_Smoke_Improvised_Grenade_Yellow extends AM_Smoke_Improvised_Grenade
{
	void AM_Smoke_Improvised_Grenade_Yellow()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_YELLOW_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_YELLOW_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_YELLOW_END);
	};
};

class AM_Smoke_Improvised_Grenade_Purple extends AM_Smoke_Improvised_Grenade
{
	void AM_Smoke_Improvised_Grenade_Purple()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_PURPLE_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_PURPLE_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_PURPLE_END);
	};
};

class AM_Smoke_Improvised_Grenade_White extends AM_Smoke_Improvised_Grenade
{
	void AM_Smoke_Improvised_Grenade_White()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_WHITE_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_WHITE_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_WHITE_END);
	};
};
class AM_Smoke_Improvised_Grenade_Black extends AM_Smoke_Improvised_Grenade
{
	void AM_Smoke_Improvised_Grenade_Black()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_RDG2_BLACK_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_RDG2_BLACK_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_RDG2_BLACK_END);
	};
};


