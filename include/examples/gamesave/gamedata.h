#ifndef BFIO_GAMEDATA_H
#define BFIO_GAMEDATA_H

#include "BFIO/io.h"

#ifdef __cplusplus
}
#endif

#define MAX_PLAYER_LIFE 100
#define MAX_PLAYER_NAME_LENGTH 8

/**
 * Represent a game data
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
struct GameData
{
    BFIO_UINT8 _playerLife;         /* Tha player life */
    BFIO_STRING _playerName;        /* The player name (on 8 characters, the 9th is for \0 */
};

typedef struct GameData GameData;

GameData *CreateGameData();

void DestroyGameData(GameData *data);

BFIO_UINT8 GetPlayerLife(GameData *data);

const BFIO_STRING GetPlayerName(GameData *data);

void SetPlayerLife(GameData *data, BFIO_UINT8 value);

void SetPlayerName(GameData *data, const BFIO_STRING value);

#ifdef __cplusplus
}
#endif

#endif //BFIO_GAMEDATA_H
