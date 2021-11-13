################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Sources/Det.obj: ../Sources/Det.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER" --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER/Includes" --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER/Sources" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c89 --strict_ansi --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --check_misra="all,-1.1,-19" --preproc_with_compile --preproc_dependency="Sources/Det.d_raw" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Sources/Dio.obj: ../Sources/Dio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER" --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER/Includes" --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER/Sources" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c89 --strict_ansi --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --check_misra="all,-1.1,-19" --preproc_with_compile --preproc_dependency="Sources/Dio.d_raw" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Sources/Dio_Lcfg.obj: ../Sources/Dio_Lcfg.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER" --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER/Includes" --include_path="C:/Users/AVE-LAP-064/workspace/DIO_AUTOSAR_DRIVER/Sources" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c89 --strict_ansi --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --check_misra="all,-1.1,-19" --preproc_with_compile --preproc_dependency="Sources/Dio_Lcfg.d_raw" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


