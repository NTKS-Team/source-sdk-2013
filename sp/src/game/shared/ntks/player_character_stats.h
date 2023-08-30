#ifndef NTKS_PLAYER_CHARACTER_STATS_H
#define NTKS_PLAYER_CHARACTER_STATS_H

#include "baseplayer_shared.h"

struct PlayerCharacterStats
{
	static const PlayerCharacterStats& Get( PlayerCharacter character );

	const char* m_szWeaponDataKey;
};

#endif
