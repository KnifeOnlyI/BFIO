#include "examples/gamesave/gamesave.h"

int main()
{
    execute(GAMESAVE_OPERATION_WRITE_FILE);
    execute(GAMESAVE_OPERATION_READ_FILE);

    return 0;
}
