################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
SYSCFG_SRCS += \
../example.syscfg 

C_SRCS += \
../ADS_adc.c \
../BQ25751.c \
../BQ25856.c \
../PDMtesting.c \
../board.c \
./syscfg/ti_dpl_config.c \
./syscfg/ti_drivers_config.c \
./syscfg/ti_drivers_open_close.c \
./syscfg/ti_pinmux_config.c \
./syscfg/ti_power_clock_config.c \
./syscfg/ti_board_config.c \
./syscfg/ti_board_open_close.c \
./syscfg/ti_enet_config.c \
./syscfg/ti_enet_open_close.c \
./syscfg/ti_enet_soc.c \
./syscfg/ti_enet_lwipif.c \
./syscfg/ti_sdl_config.c \
../i2c_helper.c \
../int_adc.c \
../ioexp_tca6408.c \
../ioexp_tca6416.c \
../ioexp_tca6424.c \
../logger.c \
../main.c \
../testing.c 

GEN_CMDS += \
./syscfg/linker.cmd 

GEN_FILES += \
./syscfg/ti_dpl_config.c \
./syscfg/ti_drivers_config.c \
./syscfg/ti_drivers_open_close.c \
./syscfg/ti_pinmux_config.c \
./syscfg/ti_power_clock_config.c \
./syscfg/ti_board_config.c \
./syscfg/ti_board_open_close.c \
./syscfg/ti_enet_config.c \
./syscfg/ti_enet_open_close.c \
./syscfg/ti_enet_soc.c \
./syscfg/ti_enet_lwipif.c \
./syscfg/linker.cmd \
./syscfg/ti_sdl_config.c 

GEN_MISC_DIRS += \
./syscfg 

C_DEPS += \
./ADS_adc.d \
./BQ25751.d \
./BQ25856.d \
./PDMtesting.d \
./board.d \
./syscfg/ti_dpl_config.d \
./syscfg/ti_drivers_config.d \
./syscfg/ti_drivers_open_close.d \
./syscfg/ti_pinmux_config.d \
./syscfg/ti_power_clock_config.d \
./syscfg/ti_board_config.d \
./syscfg/ti_board_open_close.d \
./syscfg/ti_enet_config.d \
./syscfg/ti_enet_open_close.d \
./syscfg/ti_enet_soc.d \
./syscfg/ti_enet_lwipif.d \
./syscfg/ti_sdl_config.d \
./i2c_helper.d \
./int_adc.d \
./ioexp_tca6408.d \
./ioexp_tca6416.d \
./ioexp_tca6424.d \
./logger.d \
./main.d \
./testing.d 

OBJS += \
./ADS_adc.o \
./BQ25751.o \
./BQ25856.o \
./PDMtesting.o \
./board.o \
./syscfg/ti_dpl_config.o \
./syscfg/ti_drivers_config.o \
./syscfg/ti_drivers_open_close.o \
./syscfg/ti_pinmux_config.o \
./syscfg/ti_power_clock_config.o \
./syscfg/ti_board_config.o \
./syscfg/ti_board_open_close.o \
./syscfg/ti_enet_config.o \
./syscfg/ti_enet_open_close.o \
./syscfg/ti_enet_soc.o \
./syscfg/ti_enet_lwipif.o \
./syscfg/ti_sdl_config.o \
./i2c_helper.o \
./int_adc.o \
./ioexp_tca6408.o \
./ioexp_tca6416.o \
./ioexp_tca6424.o \
./logger.o \
./main.o \
./testing.o 

GEN_MISC_FILES += \
./syscfg/ti_dpl_config.h \
./syscfg/ti_drivers_config.h \
./syscfg/ti_drivers_open_close.h \
./syscfg/pinmux.csv \
./syscfg/ti_board_config.h \
./syscfg/ti_board_open_close.h \
./syscfg/ti_enet_config.h \
./syscfg/ti_enet_open_close.h \
./syscfg/ti_enet_lwipif.h \
./syscfg/linker_defines.h \
./syscfg/ti_sdl_config.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg" 

OBJS__QUOTED += \
"ADS_adc.o" \
"BQ25751.o" \
"BQ25856.o" \
"PDMtesting.o" \
"board.o" \
"syscfg\ti_dpl_config.o" \
"syscfg\ti_drivers_config.o" \
"syscfg\ti_drivers_open_close.o" \
"syscfg\ti_pinmux_config.o" \
"syscfg\ti_power_clock_config.o" \
"syscfg\ti_board_config.o" \
"syscfg\ti_board_open_close.o" \
"syscfg\ti_enet_config.o" \
"syscfg\ti_enet_open_close.o" \
"syscfg\ti_enet_soc.o" \
"syscfg\ti_enet_lwipif.o" \
"syscfg\ti_sdl_config.o" \
"i2c_helper.o" \
"int_adc.o" \
"ioexp_tca6408.o" \
"ioexp_tca6416.o" \
"ioexp_tca6424.o" \
"logger.o" \
"main.o" \
"testing.o" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_dpl_config.h" \
"syscfg\ti_drivers_config.h" \
"syscfg\ti_drivers_open_close.h" \
"syscfg\pinmux.csv" \
"syscfg\ti_board_config.h" \
"syscfg\ti_board_open_close.h" \
"syscfg\ti_enet_config.h" \
"syscfg\ti_enet_open_close.h" \
"syscfg\ti_enet_lwipif.h" \
"syscfg\linker_defines.h" \
"syscfg\ti_sdl_config.h" 

C_DEPS__QUOTED += \
"ADS_adc.d" \
"BQ25751.d" \
"BQ25856.d" \
"PDMtesting.d" \
"board.d" \
"syscfg\ti_dpl_config.d" \
"syscfg\ti_drivers_config.d" \
"syscfg\ti_drivers_open_close.d" \
"syscfg\ti_pinmux_config.d" \
"syscfg\ti_power_clock_config.d" \
"syscfg\ti_board_config.d" \
"syscfg\ti_board_open_close.d" \
"syscfg\ti_enet_config.d" \
"syscfg\ti_enet_open_close.d" \
"syscfg\ti_enet_soc.d" \
"syscfg\ti_enet_lwipif.d" \
"syscfg\ti_sdl_config.d" \
"i2c_helper.d" \
"int_adc.d" \
"ioexp_tca6408.d" \
"ioexp_tca6416.d" \
"ioexp_tca6424.d" \
"logger.d" \
"main.d" \
"testing.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_dpl_config.c" \
"syscfg\ti_drivers_config.c" \
"syscfg\ti_drivers_open_close.c" \
"syscfg\ti_pinmux_config.c" \
"syscfg\ti_power_clock_config.c" \
"syscfg\ti_board_config.c" \
"syscfg\ti_board_open_close.c" \
"syscfg\ti_enet_config.c" \
"syscfg\ti_enet_open_close.c" \
"syscfg\ti_enet_soc.c" \
"syscfg\ti_enet_lwipif.c" \
"syscfg\linker.cmd" \
"syscfg\ti_sdl_config.c" 

C_SRCS__QUOTED += \
"../ADS_adc.c" \
"../BQ25751.c" \
"../BQ25856.c" \
"../PDMtesting.c" \
"../board.c" \
"./syscfg/ti_dpl_config.c" \
"./syscfg/ti_drivers_config.c" \
"./syscfg/ti_drivers_open_close.c" \
"./syscfg/ti_pinmux_config.c" \
"./syscfg/ti_power_clock_config.c" \
"./syscfg/ti_board_config.c" \
"./syscfg/ti_board_open_close.c" \
"./syscfg/ti_enet_config.c" \
"./syscfg/ti_enet_open_close.c" \
"./syscfg/ti_enet_soc.c" \
"./syscfg/ti_enet_lwipif.c" \
"./syscfg/ti_sdl_config.c" \
"../i2c_helper.c" \
"../int_adc.c" \
"../ioexp_tca6408.c" \
"../ioexp_tca6416.c" \
"../ioexp_tca6424.c" \
"../logger.c" \
"../main.c" \
"../testing.c" 

SYSCFG_SRCS__QUOTED += \
"../example.syscfg" 


