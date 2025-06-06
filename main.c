#include <stdlib.h>
#include "ti_drivers_config.h"
#include "ti_board_config.h"

void empty_main(void *args);

int main(void)
{
    System_init();
    Board_init();

    empty_main(NULL);

    Board_deinit();
    System_deinit();

    return 0;
}
