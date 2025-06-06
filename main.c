#include <stdlib.h>
#include "ti_drivers_config.h"
#include "ti_board_config.h"

void PDM_testing(void *args);

int main(void)
{
    System_init();
    Board_init();

    PDM_testing(NULL);

    Board_deinit();
    System_deinit();

    return 0;
}
