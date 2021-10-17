#include <malloc.h>
#include <string.h>

#include "examples/gamesave/gamedata.h"

GameData *CreateGameData()
{
    GameData *data = malloc(sizeof(GameData));

    if (data != NULL)
    {
        data->_playerLife = MAX_PLAYER_LIFE;
        data->_playerName = malloc(sizeof(BFIO_CHAR) * (MAX_PLAYER_NAME_LENGTH + 1));

        if (data->_playerName == NULL)
        {
            free(data);

            return NULL;
        }
    }

    return data;
}

void DestroyGameData(GameData *data)
{
    if (data != NULL)
    {
        free(data->_playerName);
        free(data);
    }
}

BFIO_UINT8 GetPlayerLife(GameData *data)
{
    BFIO_UINT8 results = 0;

    if (data != NULL)
    {
        results = data->_playerLife;
    }

    return results;
}

const BFIO_STRING GetPlayerName(GameData *data)
{
    BFIO_STRING results = 0;

    if (data != NULL)
    {
        results = data->_playerName;
    }

    return results;
}

void SetPlayerLife(GameData *data, BFIO_UINT8 value)
{
    if (data != NULL)
    {
        if (value > MAX_PLAYER_LIFE)
        {
            value = MAX_PLAYER_LIFE;
        }

        data->_playerLife = value;
    }
}

void SetPlayerName(GameData *data, const BFIO_STRING value)
{
    if (data != NULL)
    {
        BFIO_SIZE valueNbCharacters = strlen(value);

        if (valueNbCharacters >= MAX_PLAYER_NAME_LENGTH)
        {
            for (int i = 0; i < MAX_PLAYER_NAME_LENGTH; i++)
            {
                data->_playerName[i] = value[i];
            }

            data->_playerName[MAX_PLAYER_NAME_LENGTH + 1] = '\0';
        }
        else
        {
            for (int i = 0; i < valueNbCharacters; i++)
            {
                data->_playerName[i] = value[i];
            }

            data->_playerName[valueNbCharacters] = '\0';
        }
    }
}