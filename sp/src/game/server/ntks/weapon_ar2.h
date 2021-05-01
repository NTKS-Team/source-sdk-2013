//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:		Projectile shot from the AR2 
//
// $Workfile:     $
// $Date:         $
//
//-----------------------------------------------------------------------------
// $Log: $
//
// $NoKeywords: $
//=============================================================================//

#ifndef	WEAPONAR2_H
#define	WEAPONAR2_H

#include "basehlcombatweapon.h"

class CWeaponAR2 : public CHLMachineGun
{
public:
	DECLARE_CLASS( CWeaponAR2, CHLMachineGun );

	CWeaponAR2();

	DECLARE_SERVERCLASS();

	void	ItemPostFrame( void );
	void	SecondaryAttack( void );
	void	DisableIronsights( void );
	bool	Holster( CBaseCombatWeapon *pSwitchingTo );
	bool	Reload( void );
	void	Drop( const Vector &vecVelocity );

	void	GetViewModelOffset( Vector &vecOffset, QAngle &angOffset, float &blend );

	void	AddViewKick( void );

	void	FireNPCPrimaryAttack( CBaseCombatCharacter *pOperator, bool bUseWeaponAngles );
	void	Operator_ForceNPCFire( CBaseCombatCharacter  *pOperator, bool bSecondary );
	void	Operator_HandleAnimEvent( animevent_t *pEvent, CBaseCombatCharacter *pOperator );

	int		GetMinBurst( void ) { return 2; }
	int		GetMaxBurst( void ) { return 5; }
	float	GetFireRate( void ) { return 0.1f; }

	bool	UsesSecondaryAmmo( void ) { return false; }
	int		CapabilitiesGet( void ) { return bits_CAP_WEAPON_RANGE_ATTACK1; }

	Activity	GetPrimaryAttackActivity( void );

	virtual const Vector& GetBulletSpread( void );

	const WeaponProficiencyInfo_t *GetProficiencyValues();

protected:

	int						m_nVentPose;
	CNetworkVar( bool, m_bIsIronsighting );
	CNetworkVar( float, m_flIronsightTime );

	DECLARE_ACTTABLE();
	DECLARE_DATADESC();
};


#endif	//WEAPONAR2_H
