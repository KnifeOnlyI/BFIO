#include "BFIO/io.h"

int main()
{
    BFIO_UINT8 data = 128;
    BFIO_UINT8 res;

    BFIO_FILE fileW = BFIO_OpenFile("resources/save.dat", BFIO_FILEMODE_WRITE_BINARY);
    BFIO_WriteUInt8(fileW, data);
    BFIO_CloseFile(fileW);

    BFIO_FILE fileR = BFIO_OpenFile("resources/save.dat", BFIO_FILEMODE_READ_BINARY);
    res = BFIO_ReadUInt8(fileR);
    BFIO_CloseFile(fileR);

    printf("Data : %d\n", data);
    printf("Res : %d\n", res);

    return 0;
}
