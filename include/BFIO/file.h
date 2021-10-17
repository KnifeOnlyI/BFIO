#ifndef BFIO_FILE_H
#define BFIO_FILE_H

#include "BFIO/types.h"

/**
 * Represent a BFIO file wrapper
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
struct BFIO_File
{
    BFIO_FILE readStream;       /* The read stream */
    BFIO_FILE writeStream;      /* The write stream */
};
typedef struct BFIO_File BFIO_File;

#endif //BFIO_FILE_H
