#ifndef BFIO_IO_H
#define BFIO_IO_H

#include <stdio.h>

#include "BFIO/types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BFIO_ERROR_NO 0                     /* No error */
#define BFIO_ERROR_EPERM EPERM              /* Operation not permitted */
#define BFIO_ERROR_ENOENT ENOENT            /* No such file or directory */
#define BFIO_ERROR_ESRCH ESRCH              /* No such process */
#define BFIO_ERROR_EINTR EINTR              /* Interrupted system call */
#define BFIO_ERROR_EIO EIO                  /* I/O error */
#define BFIO_ERROR_ENXIO ENXIO              /* No such device or address */
#define BFIO_ERROR_E2BIG E2BIG              /* Argument list too long */
#define BFIO_ERROR_ENOEXEC ENOEXEC          /* Exec format error */
#define BFIO_ERROR_EBADF EBADF              /* Bad file number */
#define BFIO_ERROR_ECHILD ECHILD            /* No child processes */
#define BFIO_ERROR_EAGAIN EAGAIN            /* Try again */
#define BFIO_ERROR_ENOMEM ENOMEM            /* Out of memory */
#define BFIO_ERROR_EACCES EACCES            /* Permission denied */
#define BFIO_ERROR_EFAULT EFAULT            /* Bad address */
#define BFIO_ERROR_ENOTBLK ENOTBLK          /* Block device required */
#define BFIO_ERROR_EBUSY EBUSY              /* Device or resource busy */
#define BFIO_ERROR_EEXIST EEXIST            /* File exists */
#define BFIO_ERROR_EXDEV EXDEV              /* Cross-device link */
#define BFIO_ERROR_ENODEV ENODEV            /* No such device */
#define BFIO_ERROR_ENOTDIR ENOTDIR          /* Not a directory */
#define BFIO_ERROR_EISDIR EISDIR            /* Is a directory */
#define BFIO_ERROR_EINVAL EINVAL            /* Invalid argument */
#define BFIO_ERROR_ENFILE ENFILE            /* File table overflow */
#define BFIO_ERROR_EMFILE EMFILE            /* Too many open files */
#define BFIO_ERROR_ENOTTY ENOTTY            /* Not a typewriter */
#define BFIO_ERROR_ETXTBSY ETXTBSY          /* Text file busy */
#define BFIO_ERROR_EFBIG EFBIG              /* File too large */
#define BFIO_ERROR_ENOSPC ENOSPC            /* No space left on device */
#define BFIO_ERROR_ESPIPE ESPIPE            /* Illegal seek */
#define BFIO_ERROR_EROFS EROFS              /* Read-only file system */
#define BFIO_ERROR_EMLINK EMLINK            /* Too many links */
#define BFIO_ERROR_EPIPE EPIPE              /* Broken pipe */
#define BFIO_ERROR_EDOM EDOM                /* Broken pipe */
#define BFIO_ERROR_ERANGE ERANGE            /* Broken pipe */
#define BFIO_ERROR_NULL_FILE 35             /* NULL file pointer */
#define BFIO_ERROR_EOF 36                   /* Already reach the end of file */
#define BFIO_ERROR_UNKNOWN 255              /* Unknow error, check errno value */

/**
* Handle the errno current error
*/
static void BFIO_HandleError();

/**
 * Get the last error
 *
 * @return The last error
 */
BFIO_UINT8 BFIO_GetError();

/**
 * Open the specified file with the specified mode
 *
 * @param filepath The file to open
 * @param mode The mode
 *
 * @return The file, NULL if error
 */
BFIO_FILE BFIO_OpenFile(const char *filepath, const char *mode);

/**
 * Close the specified file
 *
 * @param file The file to close
 */
void BFIO_CloseFile(BFIO_FILE file);

/**
 * Read the specified size data from the specified file and put into the specified buffer
 *
 * @param file The file
 * @param buffer The buffer where to put the readed data
 * @param size The size to read
 */
void BFIO_ReadData(BFIO_FILE file, void *buffer, BFIO_SIZE size);

/**
 * Write the specified size data from the specified file from into the specified buffer
 *
 * @param file The file
 * @param buffer The buffer where to find the data write
 * @param size The size to write
 */
void BFIO_WriteData(BFIO_FILE file, void *data, BFIO_SIZE size);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteBool(BFIO_FILE file, BFIO_BOOL data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteInt8(BFIO_FILE file, BFIO_INT8 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteUInt8(BFIO_FILE file, BFIO_UINT8 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteInt16(BFIO_FILE file, BFIO_INT16 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteUInt16(BFIO_FILE file, BFIO_UINT16 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteInt32(BFIO_FILE file, BFIO_INT32 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteUInt32(BFIO_FILE file, BFIO_UINT32 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteInt64(BFIO_FILE file, BFIO_INT64 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteUInt64(BFIO_FILE file, BFIO_UINT64 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteFloat32(BFIO_FILE file, BFIO_FLOAT32 data);

/**
 * Write the specified data to the specified file
 *
 * @param file The file where to write
 * @param data The data to write
 */
void BFIO_WriteFloat64(BFIO_FILE file, BFIO_FLOAT64 data);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_BOOL BFIO_ReadBool(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_INT8 BFIO_ReadInt8(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_UINT8 BFIO_ReadUInt8(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_INT16 BFIO_ReadInt16(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_UINT16 BFIO_ReadUInt16(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_INT32 BFIO_ReadInt32(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_UINT32 BFIO_ReadUInt32(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_INT64 BFIO_ReadInt64(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_UINT64 BFIO_ReadUInt64(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_FLOAT32 BFIO_ReadFloat32(BFIO_FILE file);

/**
 * Read the specified data from the specified file
 *
 * @param file The file where to read
 *
 * @return The readed data
 */
BFIO_FLOAT64 BFIO_ReadFloat64(BFIO_FILE file);

#ifdef __cplusplus
}
#endif

#endif //BFIO_IO_H
