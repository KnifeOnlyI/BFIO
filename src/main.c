#include "BFIO/io.h"

int main()
{
    BFIO_UINT8 data = 255;
    BFIO_UINT8 res;

    BFIO_File *file = BFIO_OpenFile("resources/save.dat");

    BFIO_WriteUInt8(file, data);
    BFIO_FlushFile(file);
    res = BFIO_ReadUInt8(file);

    BFIO_CloseFile(file);

    printf("Data : %d\n", data);
    printf("Res : %d\n", res);

    return 0;
}
