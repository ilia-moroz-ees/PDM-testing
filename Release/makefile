################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := -Wl,-l"syscfg/linker.cmd" 

ORDERED_OBJS += \
"./ADS_adc.o" \
"./BQ25751.o" \
"./BQ25856.o" \
"./PDMtesting.o" \
"./board.o" \
"./syscfg/ti_dpl_config.o" \
"./syscfg/ti_drivers_config.o" \
"./syscfg/ti_drivers_open_close.o" \
"./syscfg/ti_pinmux_config.o" \
"./syscfg/ti_power_clock_config.o" \
"./syscfg/ti_board_config.o" \
"./syscfg/ti_board_open_close.o" \
"./syscfg/ti_enet_config.o" \
"./syscfg/ti_enet_open_close.o" \
"./syscfg/ti_enet_soc.o" \
"./syscfg/ti_enet_lwipif.o" \
"./syscfg/ti_sdl_config.o" \
"./i2c_helper.o" \
"./int_adc.o" \
"./ioexp_tca6424.o" \
"./logger.o" \
"./main.o" \
"./pmic_test.o" \
"./testing.o" \
$(GEN_CMDS__FLAG) \
-Wl,-lnortos.am263px.r5f.ti-arm-clang.release.lib \
-Wl,-ldrivers.am263px.r5f.ti-arm-clang.release.lib \
-Wl,-llibc.a \
-Wl,-llibsysbm.a \
-Wl,-lpmic_blackbird.am263px.r5f.ti-arm-clang.release.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
second_stage_PDM_testing.out 

EXE_OUTPUTS__QUOTED += \
"second_stage_PDM_testing.out" 


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "second_stage_PDM_testing.out"

# Tool invocations
second_stage_PDM_testing.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16 -mlittle-endian -mthumb -Os -DSOC_AM263PX -g -Wall -Wno-gnu-variable-sized-type-not-at-end -Wno-unused-function -Wl,-m"pmic_user_reg_cfg.Release.map" -Wl,-i"C:/Users/carim/Desktop/mcu_plus_sdk_am263px_10_02_00_15__all/mcu_plus_sdk_am263px_10_02_00_15/source/kernel/nortos/lib" -Wl,-i"C:/Users/carim/Desktop/mcu_plus_sdk_am263px_10_02_00_15__all/mcu_plus_sdk_am263px_10_02_00_15/source/drivers/lib" -Wl,-i"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/lib" -Wl,-i"C:/Users/carim/Desktop/mcu_plus_sdk_am263px_10_02_00_15__all/mcu_plus_sdk_am263px_10_02_00_15/source/board/lib" -Wl,-i"C:/Users/carim/Desktop/mcu_plus_sdk_am263px_10_02_00_15__all/mcu_plus_sdk_am263px_10_02_00_15/source/board/pmic/pmic_lld/blackbird/include" -Wl,-i"C:/Users/carim/Desktop/mcu_plus_sdk_am263px_10_02_00_15__all/mcu_plus_sdk_am263px_10_02_00_15/source/board/pmic/lib" -Wl,--reread_libs -Wl,--diag_suppress=10063 -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--gen_xml_func_hash -Wl,--xml_link_info="second_stage_PDM_testing_linkInfo.xml" -Wl,--ram_model -o "second_stage_PDM_testing.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "ADS_adc.o" "BQ25751.o" "BQ25856.o" "PDMtesting.o" "board.o" "syscfg\ti_dpl_config.o" "syscfg\ti_drivers_config.o" "syscfg\ti_drivers_open_close.o" "syscfg\ti_pinmux_config.o" "syscfg\ti_power_clock_config.o" "syscfg\ti_board_config.o" "syscfg\ti_board_open_close.o" "syscfg\ti_enet_config.o" "syscfg\ti_enet_open_close.o" "syscfg\ti_enet_soc.o" "syscfg\ti_enet_lwipif.o" "syscfg\ti_sdl_config.o" "i2c_helper.o" "int_adc.o" "ioexp_tca6424.o" "logger.o" "main.o" "pmic_test.o" "testing.o" 
	-$(RM) "ADS_adc.d" "BQ25751.d" "BQ25856.d" "PDMtesting.d" "board.d" "syscfg\ti_dpl_config.d" "syscfg\ti_drivers_config.d" "syscfg\ti_drivers_open_close.d" "syscfg\ti_pinmux_config.d" "syscfg\ti_power_clock_config.d" "syscfg\ti_board_config.d" "syscfg\ti_board_open_close.d" "syscfg\ti_enet_config.d" "syscfg\ti_enet_open_close.d" "syscfg\ti_enet_soc.d" "syscfg\ti_enet_lwipif.d" "syscfg\ti_sdl_config.d" "i2c_helper.d" "int_adc.d" "ioexp_tca6424.d" "logger.d" "main.d" "pmic_test.d" "testing.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-$(MAKE) -C C:\Users\carim\workspace_ccstheia\second_stage_PDM_testing -f makefile_ccs_bootimage_gen OUTNAME=second_stage_PDM_testing PROFILE=Release MCU_PLUS_SDK_PATH=C:/Users/carim/Desktop/mcu_plus_sdk_am263px_10_02_00_15__all/mcu_plus_sdk_am263px_10_02_00_15 CG_TOOL_ROOT=C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS CCS_INSTALL_DIR=C:\ti\ccs2011\ccs\ CCS_IDE_MODE=desktop DEVICE=am263px
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

