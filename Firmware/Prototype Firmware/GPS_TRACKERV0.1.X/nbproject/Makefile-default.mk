#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/GPGGA_Parser.cpp src/PORT_INIT.cpp main.cpp src/ConvertToString.cpp src/ACCEL_BMI160.cpp src/I2C_DRIVER.c src/TIMER_INIT.cpp src/UART_INIT.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/GPGGA_Parser.o ${OBJECTDIR}/src/PORT_INIT.o ${OBJECTDIR}/main.o ${OBJECTDIR}/src/ConvertToString.o ${OBJECTDIR}/src/ACCEL_BMI160.o ${OBJECTDIR}/src/I2C_DRIVER.o ${OBJECTDIR}/src/TIMER_INIT.o ${OBJECTDIR}/src/UART_INIT.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/GPGGA_Parser.o.d ${OBJECTDIR}/src/PORT_INIT.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/src/ConvertToString.o.d ${OBJECTDIR}/src/ACCEL_BMI160.o.d ${OBJECTDIR}/src/I2C_DRIVER.o.d ${OBJECTDIR}/src/TIMER_INIT.o.d ${OBJECTDIR}/src/UART_INIT.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/GPGGA_Parser.o ${OBJECTDIR}/src/PORT_INIT.o ${OBJECTDIR}/main.o ${OBJECTDIR}/src/ConvertToString.o ${OBJECTDIR}/src/ACCEL_BMI160.o ${OBJECTDIR}/src/I2C_DRIVER.o ${OBJECTDIR}/src/TIMER_INIT.o ${OBJECTDIR}/src/UART_INIT.o

# Source Files
SOURCEFILES=src/GPGGA_Parser.cpp src/PORT_INIT.cpp main.cpp src/ConvertToString.cpp src/ACCEL_BMI160.cpp src/I2C_DRIVER.c src/TIMER_INIT.cpp src/UART_INIT.cpp

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/avr128da48"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=AVR128DA48
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/I2C_DRIVER.o: src/I2C_DRIVER.c  .generated_files/flags/default/c90036fb18f75f2cdd061c55577c0742d2b9978e .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/I2C_DRIVER.o.d 
	@${RM} ${OBJECTDIR}/src/I2C_DRIVER.o 
	 ${MP_CPPC}  $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums  -I "src" -I "headers" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/I2C_DRIVER.o.d" -MT "${OBJECTDIR}/src/I2C_DRIVER.o.d" -MT ${OBJECTDIR}/src/I2C_DRIVER.o  -o ${OBJECTDIR}/src/I2C_DRIVER.o src/I2C_DRIVER.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/I2C_DRIVER.o: src/I2C_DRIVER.c  .generated_files/flags/default/f204981c5508bda93238a2493e1f149be76438c5 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/I2C_DRIVER.o.d 
	@${RM} ${OBJECTDIR}/src/I2C_DRIVER.o 
	 ${MP_CPPC}  $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums  -I "src" -I "headers" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/I2C_DRIVER.o.d" -MT "${OBJECTDIR}/src/I2C_DRIVER.o.d" -MT ${OBJECTDIR}/src/I2C_DRIVER.o  -o ${OBJECTDIR}/src/I2C_DRIVER.o src/I2C_DRIVER.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/GPGGA_Parser.o: src/GPGGA_Parser.cpp  .generated_files/flags/default/80a737a581ee035415d0b5e51e11571e7f4ffce3 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o.d 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT ${OBJECTDIR}/src/GPGGA_Parser.o  -o ${OBJECTDIR}/src/GPGGA_Parser.o src/GPGGA_Parser.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PORT_INIT.o: src/PORT_INIT.cpp  .generated_files/flags/default/3162678a48c6fc03bbc9a02d92c09b6aca7ffe95 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/PORT_INIT.o.d" -MT "${OBJECTDIR}/src/PORT_INIT.o.d" -MT ${OBJECTDIR}/src/PORT_INIT.o  -o ${OBJECTDIR}/src/PORT_INIT.o src/PORT_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.cpp  .generated_files/flags/default/c4218d47177d09bc6c963d7569905a50e71f333b .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ConvertToString.o: src/ConvertToString.cpp  .generated_files/flags/default/4a65a12fec23c767ac9e4e447985d3bc812077d .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o.d 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/ConvertToString.o.d" -MT "${OBJECTDIR}/src/ConvertToString.o.d" -MT ${OBJECTDIR}/src/ConvertToString.o  -o ${OBJECTDIR}/src/ConvertToString.o src/ConvertToString.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ACCEL_BMI160.o: src/ACCEL_BMI160.cpp  .generated_files/flags/default/e1d6bcd4962949404d99a967ff141b46e6c4bab8 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ACCEL_BMI160.o.d 
	@${RM} ${OBJECTDIR}/src/ACCEL_BMI160.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/ACCEL_BMI160.o.d" -MT "${OBJECTDIR}/src/ACCEL_BMI160.o.d" -MT ${OBJECTDIR}/src/ACCEL_BMI160.o  -o ${OBJECTDIR}/src/ACCEL_BMI160.o src/ACCEL_BMI160.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/TIMER_INIT.o: src/TIMER_INIT.cpp  .generated_files/flags/default/df83b339361026dfdcddfeafc8bb92908fe889e0 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/TIMER_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/TIMER_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/TIMER_INIT.o.d" -MT "${OBJECTDIR}/src/TIMER_INIT.o.d" -MT ${OBJECTDIR}/src/TIMER_INIT.o  -o ${OBJECTDIR}/src/TIMER_INIT.o src/TIMER_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/UART_INIT.o: src/UART_INIT.cpp  .generated_files/flags/default/bc35ff07ab3e60bc1db08e46a5a2b8b877256601 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/UART_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/UART_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/UART_INIT.o.d" -MT "${OBJECTDIR}/src/UART_INIT.o.d" -MT ${OBJECTDIR}/src/UART_INIT.o  -o ${OBJECTDIR}/src/UART_INIT.o src/UART_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/GPGGA_Parser.o: src/GPGGA_Parser.cpp  .generated_files/flags/default/2c8631aabe15bbe9526ec3e19590d3e66d02fed7 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o.d 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT ${OBJECTDIR}/src/GPGGA_Parser.o  -o ${OBJECTDIR}/src/GPGGA_Parser.o src/GPGGA_Parser.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PORT_INIT.o: src/PORT_INIT.cpp  .generated_files/flags/default/6665eef8dde6929e62e38243cefa346c3268c777 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/PORT_INIT.o.d" -MT "${OBJECTDIR}/src/PORT_INIT.o.d" -MT ${OBJECTDIR}/src/PORT_INIT.o  -o ${OBJECTDIR}/src/PORT_INIT.o src/PORT_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.cpp  .generated_files/flags/default/631968186ae3ce6e95de5b1aab07d6a6e1b4ac8b .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ConvertToString.o: src/ConvertToString.cpp  .generated_files/flags/default/daee83a9f44df5a65f75b9250f5d2cd8f259aee6 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o.d 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/ConvertToString.o.d" -MT "${OBJECTDIR}/src/ConvertToString.o.d" -MT ${OBJECTDIR}/src/ConvertToString.o  -o ${OBJECTDIR}/src/ConvertToString.o src/ConvertToString.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ACCEL_BMI160.o: src/ACCEL_BMI160.cpp  .generated_files/flags/default/faac52cfbf736eeef76c765dbc37c50d4991aa5c .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ACCEL_BMI160.o.d 
	@${RM} ${OBJECTDIR}/src/ACCEL_BMI160.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/ACCEL_BMI160.o.d" -MT "${OBJECTDIR}/src/ACCEL_BMI160.o.d" -MT ${OBJECTDIR}/src/ACCEL_BMI160.o  -o ${OBJECTDIR}/src/ACCEL_BMI160.o src/ACCEL_BMI160.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/TIMER_INIT.o: src/TIMER_INIT.cpp  .generated_files/flags/default/73a0772dfc9faf66fb3ad2ee83c32ddb3d76f99b .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/TIMER_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/TIMER_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/TIMER_INIT.o.d" -MT "${OBJECTDIR}/src/TIMER_INIT.o.d" -MT ${OBJECTDIR}/src/TIMER_INIT.o  -o ${OBJECTDIR}/src/TIMER_INIT.o src/TIMER_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/UART_INIT.o: src/UART_INIT.cpp  .generated_files/flags/default/536339c19190e296646b4c4c8a55f6caf5abba00 .generated_files/flags/default/d9bc40944b7852f93f3a58e4aaa02267fb434de8
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/UART_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/UART_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/UART_INIT.o.d" -MT "${OBJECTDIR}/src/UART_INIT.o.d" -MT ${OBJECTDIR}/src/UART_INIT.o  -o ${OBJECTDIR}/src/UART_INIT.o src/UART_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=avr128da48 ${PACK_COMMON_OPTIONS}   -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\GPS_TRACKERV0.1.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=avr128da48 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\GPS_TRACKERV0.1.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/GPS_TRACKERV0.1.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
