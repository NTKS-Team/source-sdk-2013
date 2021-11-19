#include "cbase.h"

#include "player_character_stats.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

const PlayerCharacterStats& PlayerCharacterStats::Get( PlayerCharacter character )
{
	static PlayerCharacterStats playerCharacterStats[PC_MAX] =
	{
		// Isaac
		{
			"Isaac" //weaponDataKey
		},
		// Katsu
		{
			"Katsu" //weaponDataKey
		},
	};

	if ( character < 0 || character >= PC_MAX )
	{
		Assert( false );
		character = (PlayerCharacter)0;
	}

	return playerCharacterStats[character];
}

