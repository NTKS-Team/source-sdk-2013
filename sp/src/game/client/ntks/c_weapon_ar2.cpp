//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//
#include "cbase.h"
#include "c_basehlcombatweapon.h"
#include "c_weapon__stubs.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#if 0
ConVar is_f( "is_f", "0.0", FCVAR_REPLICATED );
ConVar is_r( "is_r", "0.0", FCVAR_REPLICATED );
ConVar is_u( "is_u", "0.0", FCVAR_REPLICATED );
ConVar is_p( "is_p", "0.0", FCVAR_REPLICATED );
ConVar is_y( "is_y", "0.0", FCVAR_REPLICATED );
ConVar is_l( "is_l", "0.0", FCVAR_REPLICATED );
#endif

class C_WeaponAR2 : public C_HLMachineGun
{
	DECLARE_CLASS( C_WeaponAR2, C_HLMachineGun );
public:
	DECLARE_CLIENTCLASS();
	DECLARE_PREDICTABLE();

	void GetViewModelOffset( Vector &vecOffset, QAngle &angOffset, float &blend )
	{
		blend = min( 1.0f, ( gpGlobals->curtime - m_flIronsightTime ) * 5.5f );
		if ( ! m_bIsIronsighting )
		{
			blend = 1.0f - blend;
		}

		//vecOffset = Vector( is_f.GetFloat(), is_r.GetFloat(), is_u.GetFloat() );
		//angOffset = QAngle( is_p.GetFloat(), is_y.GetFloat(), is_l.GetFloat() );
		vecOffset = Vector( 0.0f, -2.81f, 0.68f );
		angOffset = QAngle( 0, 0, 0 );
	}

	void ViewModelDrawn( C_BaseViewModel *pViewModel )
	{
		BaseClass::ViewModelDrawn( pViewModel );
		if ( m_bIsIronsighting )
		{
			pViewModel->SetPlaybackRate( pViewModel->GetSequence() == 0 ? 0.0f : 1.0f );
		}
	}

private:
	CNetworkVar( bool, m_bIsIronsighting );
	CNetworkVar( float, m_flIronsightTime );
};

void RecvProxy_IsIronsighting( const CRecvProxyData *pData, void *pStruct, void *pOut )
{
	bool state = *((bool *)&pData->m_Value.m_Int);

	C_WeaponAR2 *pWeapon = (C_WeaponAR2 *) pStruct;

	CBasePlayer *pPlayer = ToBasePlayer( pWeapon->GetOwner() );
	if ( pPlayer )
	{
		if ( state )
		{
			pPlayer->GetViewModel()->SetPlaybackRate( 0.0f );
			pPlayer->SetFOV( pPlayer, pPlayer->GetDefaultFOV() - 35, 0.2f );
		}
		else
		{
			pPlayer->GetViewModel()->SetPlaybackRate( 1.0f );
			pPlayer->SetFOV( pPlayer, pPlayer->GetDefaultFOV(), 0.2f );
		}
	}

	*(bool *)pOut = state;
}

STUB_WEAPON_CLASS_IMPLEMENT( weapon_ar2, C_WeaponAR2 );

IMPLEMENT_CLIENTCLASS_DT( C_WeaponAR2, DT_WeaponAR2, CWeaponAR2 )
	RecvPropInt( RECVINFO(m_bIsIronsighting), 0, RecvProxy_IsIronsighting ),
	RecvPropTime( RECVINFO(m_flIronsightTime) ),
END_RECV_TABLE()

