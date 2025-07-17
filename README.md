# Environment Setup Guide
The development environment used in this project is Code Composer Studio. The microcontroller is AM263.
To start working with the microcontroller and AM263Px Control Card development board, a good starting point would be reading this Quick Start Guide from TI:
https://www.ti.com/lit/an/spradf9/spradf9.pdf?ts=1752781017574&ref_url=https%253A%252F%252Fwww.ti.com%252Ftool%252FTMDSCNCD263P
It explains most of the setup.  
**Note:** Even though it says OpenSSL is optional, it is a good idea to set it up, since not having it will result in post-build scripts to crash.  
**Note:** Make sure to install SDK version 10_02_00_15, PMIC library will not work with previous versions of SDK.

After following this guide, if the Control Card board is new, you will likely get an "Update required" message when trying to flash the MCU. 
However, for unknown reason this update crashes in the middle, and bricks the JTAG on the board. You will not be able to flash the firmware, or launch a debugger anymore.

In order to recover it, I followed these 2 threads on the TI forum:
- https://e2e.ti.com/support/microcontrollers/arm-based-microcontrollers-group/arm-based-microcontrollers/f/arm-based-microcontrollers-forum/1385802/mcu-plus-sdk-am263px-debugger-initialization-error-on-initial-setup
- https://e2e.ti.com/support/microcontrollers/arm-based-microcontrollers-group/arm-based-microcontrollers/f/arm-based-microcontrollers-forum/1374638/lp-am263p-xds-110-firmware-update-failure/5282507#5282507

While following these threads you will find that they suggest to short pin 97 of the jtag to ground, which in practice isn't needed, and jtag can be recovered just by running CLI commands described in those threads.

After instailing SDK and Code Composer Studio, you should be ready to start developing, however different issues might arise, which I fixed just by googling them, and don't remember the deatails to outline them here.

**Development Note:** All the peripherals setup in the microcontroller (ADC, Intrrupts, etc.) must be done using SysConfig, which is a powerful GUI tool for setting up the microcontroller.
