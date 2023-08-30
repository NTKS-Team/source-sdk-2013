#ifndef NTKS_INFO_PLAYER_START_H
#define NTKS_INFO_PLAYER_START_H

#include "baseplayer_shared.h"

class CNtksStart : public CPointEntity
{
public:
	DECLARE_CLASS( CNtksStart, CPointEntity );

	DECLARE_DATADESC();

	CNtksStart();

	PlayerCharacter m_iPlayerCharacter;
};

#endif
