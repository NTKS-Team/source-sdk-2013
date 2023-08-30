#include "cbase.h"

#include "info_player_start.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

BEGIN_DATADESC( CNtksStart )
	DEFINE_KEYFIELD( m_iPlayerCharacter, FIELD_INTEGER, "player_character" ),
END_DATADESC()

LINK_ENTITY_TO_CLASS( info_player_start, CNtksStart );

CNtksStart::CNtksStart()
	: m_iPlayerCharacter( PC_INVALID )
{
}
