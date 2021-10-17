#ifndef BFIO_TYPES_H
#define BFIO_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#define BFIO_BOOL char
#define BFIO_INT8 signed char
#define BFIO_UINT8 unsigned char
#define BFIO_CHAR char
#define BFIO_INT16 signed short
#define BFIO_UINT16 unsigned short
#define BFIO_INT32 signed int
#define BFIO_UINT32 unsigned int
#define BFIO_INT64 signed long
#define BFIO_UINT64 unsigned long
#define BFIO_FLOAT32 float
#define BFIO_FLOAT64 double
#define BFIO_STRING BFIO_CHAR *

#define BFIO_SIZE size_t

#define BFIO_FILE FILE *

#define BFIO_FILEMODE_READ_BINARY "rb"
#define BFIO_FILEMODE_WRITE_BINARY "rb"

#define BFIO_FALSE 0
#define BFIO_TRUE 1

#ifdef __cplusplus
}
#endif

#endif //BFIO_TYPES_H
