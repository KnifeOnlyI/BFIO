#include <errno.h>
#include <malloc.h>

#include "BFIO/io.h"

static BFIO_UINT8 BFIO_error = BFIO_ERROR_NO;

void BFIO_HandleError()
{
    switch (errno)
    {
        case 0:
            BFIO_error = BFIO_ERROR_NO;
            break;
        case EPERM:
            BFIO_error = BFIO_ERROR_EPERM;
            break;
        case ENOENT:
            BFIO_error = BFIO_ERROR_ENOENT;
            break;
        case ESRCH:
            BFIO_error = BFIO_ERROR_ESRCH;
            break;
        case EINTR:
            BFIO_error = BFIO_ERROR_EINTR;
            break;
        case EIO:
            BFIO_error = BFIO_ERROR_EIO;
            break;
        case ENXIO:
            BFIO_error = BFIO_ERROR_ENXIO;
            break;
        case E2BIG:
            BFIO_error = BFIO_ERROR_E2BIG;
            break;
        case ENOEXEC:
            BFIO_error = BFIO_ERROR_ENOEXEC;
            break;
        case EBADF:
            BFIO_error = BFIO_ERROR_EBADF;
            break;
        case ECHILD:
            BFIO_error = BFIO_ERROR_ECHILD;
            break;
        case EAGAIN:
            BFIO_error = BFIO_ERROR_EAGAIN;
            break;
        case ENOMEM:
            BFIO_error = BFIO_ERROR_ENOMEM;
            break;
        case EACCES:
            BFIO_error = BFIO_ERROR_EACCES;
            break;
        case EFAULT:
            BFIO_error = BFIO_ERROR_EFAULT;
            break;
        case ENOTBLK:
            BFIO_error = BFIO_ERROR_ENOTBLK;
            break;
        case EBUSY:
            BFIO_error = BFIO_ERROR_EBUSY;
            break;
        case EEXIST:
            BFIO_error = BFIO_ERROR_EEXIST;
            break;
        case EXDEV:
            BFIO_error = BFIO_ERROR_EXDEV;
            break;
        case ENODEV:
            BFIO_error = BFIO_ERROR_ENODEV;
            break;
        case ENOTDIR:
            BFIO_error = BFIO_ERROR_ENOTDIR;
            break;
        case EISDIR:
            BFIO_error = BFIO_ERROR_EISDIR;
            break;
        case EINVAL:
            BFIO_error = BFIO_ERROR_EINVAL;
            break;
        case ENFILE:
            BFIO_error = BFIO_ERROR_ENFILE;
            break;
        case EMFILE:
            BFIO_error = BFIO_ERROR_EMFILE;
            break;
        case ENOTTY:
            BFIO_error = BFIO_ERROR_ENOTTY;
            break;
        case ETXTBSY:
            BFIO_error = BFIO_ERROR_ETXTBSY;
            break;
        case EFBIG:
            BFIO_error = BFIO_ERROR_EFBIG;
            break;
        case ENOSPC:
            BFIO_error = BFIO_ERROR_ENOSPC;
            break;
        case ESPIPE:
            BFIO_error = BFIO_ERROR_ESPIPE;
            break;
        case EROFS:
            BFIO_error = BFIO_ERROR_EROFS;
            break;
        case EMLINK:
            BFIO_error = BFIO_ERROR_EMLINK;
            break;
        case EPIPE:
            BFIO_error = BFIO_ERROR_EPIPE;
            break;
        case EDOM:
            BFIO_error = BFIO_ERROR_EDOM;
            break;
        case ERANGE:
            BFIO_error = BFIO_ERROR_ERANGE;
            break;
        default:
            BFIO_error = BFIO_ERROR_UNKNOWN;
    }
}

BFIO_UINT8 BFIO_GetError()
{
    return BFIO_error;
}

BFIO_File *BFIO_OpenFile(const BFIO_STRING filepath)
{
    errno = 0;
    BFIO_File *file = malloc(sizeof(BFIO_File));

    file->_readStream = fopen(filepath, "rb");

    BFIO_HandleError();

    if (file->_readStream == NULL)
    {
        fclose(file->_readStream);

        free(file);

        return NULL;
    }
    else
    {
        file->_isOpen = BFIO_TRUE;
        file->_filepath = filepath;

        return file;
    }
}

void BFIO_CloseFile(BFIO_File *file)
{
    errno = 0;

    if (file != NULL && file->_isOpen)
    {
        fclose(file->_readStream);

        if (file->_writeStream != NULL)
        {
            fclose(file->_writeStream);
        }

        file->_isOpen = BFIO_FALSE;

        free(file);

        BFIO_HandleError();
    }
}

void BFIO_FlushFile(BFIO_File *file)
{
    if (file != NULL && file->_isOpen && file->_writeStream != NULL)
    {
        fflush(file->_writeStream);

        BFIO_HandleError();
    }
}

BFIO_BOOL BFIO_FileIsOpen(BFIO_File *file)
{
    return (BFIO_BOOL) (file != NULL && file->_isOpen);
}

void BFIO_ReadData(BFIO_File *file, void *buffer, BFIO_SIZE size)
{
    errno = 0;

    if (file == NULL)
    {
        BFIO_error = BFIO_ERROR_NULL_FILE;
    }
    else if (!file->_isOpen)
    {
        BFIO_error = BFIO_ERROR_NOT_OPEN_FILE;
    }
    else
    {
        BFIO_SIZE results = fread(buffer, size, 1, file->_readStream);

        BFIO_HandleError();

        if (results < 1 && BFIO_error == BFIO_ERROR_NO)
        {
            if (feof(file->_readStream))
            {
                BFIO_error = BFIO_ERROR_EOF;
            }
        }
    }
}

void BFIO_WriteData(BFIO_File *file, const void *data, BFIO_SIZE size)
{
    errno = 0;

    if (file == NULL)
    {
        BFIO_error = BFIO_ERROR_NULL_FILE;
    }
    else if (!file->_isOpen)
    {
        BFIO_error = BFIO_ERROR_NOT_OPEN_FILE;
    }
    else
    {
        if (file->_writeStream == NULL)
        {
            file->_writeStream = fopen(file->_filepath, "wb");

            fseek(file->_readStream, 0, SEEK_SET);

            BFIO_HandleError();
        }

        if (file->_writeStream != NULL)
        {
            fwrite(data, size, 1, file->_writeStream);

            BFIO_HandleError();
        }
    }
}

void BFIO_WriteBool(BFIO_File *file, BFIO_BOOL data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteInt8(BFIO_File *file, BFIO_INT8 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteUInt8(BFIO_File *file, BFIO_UINT8 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteInt16(BFIO_File *file, BFIO_INT16 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteUInt16(BFIO_File *file, BFIO_UINT16 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteInt32(BFIO_File *file, BFIO_INT32 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteUInt32(BFIO_File *file, BFIO_UINT32 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteInt64(BFIO_File *file, BFIO_INT64 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteUInt64(BFIO_File *file, BFIO_UINT64 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteFloat32(BFIO_File *file, BFIO_FLOAT32 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

void BFIO_WriteFloat64(BFIO_File *file, BFIO_FLOAT64 data)
{
    BFIO_WriteData(file, &data, sizeof(data));
}

BFIO_BOOL BFIO_ReadBool(BFIO_File *file)
{
    BFIO_BOOL results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_INT8 BFIO_ReadInt8(BFIO_File *file)
{
    BFIO_INT8 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_UINT8 BFIO_ReadUInt8(BFIO_File *file)
{
    BFIO_UINT8 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_INT16 BFIO_ReadInt16(BFIO_File *file)
{
    BFIO_INT16 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_UINT16 BFIO_ReadUInt16(BFIO_File *file)
{
    BFIO_UINT16 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_INT32 BFIO_ReadInt32(BFIO_File *file)
{
    BFIO_INT32 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_UINT32 BFIO_ReadUInt32(BFIO_File *file)
{
    BFIO_UINT32 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_INT64 BFIO_ReadInt64(BFIO_File *file)
{
    BFIO_INT64 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_UINT64 BFIO_ReadUInt64(BFIO_File *file)
{
    BFIO_UINT64 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_FLOAT32 BFIO_ReadFloat32(BFIO_File *file)
{
    BFIO_FLOAT32 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}

BFIO_FLOAT64 BFIO_ReadFloat64(BFIO_File *file)
{
    BFIO_FLOAT64 results = 0;

    BFIO_ReadData(file, &results, sizeof(results));

    return results;
}