#ifndef BFIO_GAMESAVE_H
#define BFIO_GAMESAVE_H

#ifdef __cplusplus
extern "C" {
#endif

#define GAMESAVE_OPERATION_WRITE_FILE 0
#define GAMESAVE_OPERATION_READ_FILE 1

void execute(unsigned int operation);

#ifdef __cplusplus
}
#endif

#endif //BFIO_GAMESAVE_H
