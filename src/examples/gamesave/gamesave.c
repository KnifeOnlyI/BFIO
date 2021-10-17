#include "examples/gamesave/gamesave.h"
#include "examples/gamesave/gamedata.h"

void execute(unsigned int operation)
{
    if (operation == GAMESAVE_OPERATION_WRITE_FILE) {
        BFIO_File *file = BFIO_OpenFile("resources/save.dat");
        GameData *data = CreateGameData();

        SetPlayerLife(data, 50);
        SetPlayerName(data, "JohnWick");

        BFIO_WriteUInt8(file, GetPlayerLife(data));
        BFIO_WriteData(file, GetPlayerName(data), MAX_PLAYER_NAME_LENGTH);

        DestroyGameData(data);
        BFIO_CloseFile(file);
    } else {
        BFIO_File *file = BFIO_OpenFile("resources/save.dat");

        GameData *data = CreateGameData();

        SetPlayerLife(data, BFIO_ReadUInt8(file));
        BFIO_ReadData(file, data->_playerName, MAX_PLAYER_NAME_LENGTH);

        printf("Player : %d - %s\n", GetPlayerLife(data), GetPlayerName(data));
    }
}