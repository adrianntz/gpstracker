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
SOURCEFILES_QUOTED_IF_SPACED=src/GPGGA_Parser.cpp src/PORT_INIT.cpp src/accelerometer.cpp src/i2c.c src/timer_init.cpp main.cpp src/ConvertToString.cpp src/uart_initialization.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/GPGGA_Parser.o ${OBJECTDIR}/src/PORT_INIT.o ${OBJECTDIR}/src/accelerometer.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/timer_init.o ${OBJECTDIR}/main.o ${OBJECTDIR}/src/ConvertToString.o ${OBJECTDIR}/src/uart_initialization.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/GPGGA_Parser.o.d ${OBJECTDIR}/src/PORT_INIT.o.d ${OBJECTDIR}/src/accelerometer.o.d ${OBJECTDIR}/src/i2c.o.d ${OBJECTDIR}/src/timer_init.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/src/ConvertToString.o.d ${OBJECTDIR}/src/uart_initialization.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/GPGGA_Parser.o ${OBJECTDIR}/src/PORT_INIT.o ${OBJECTDIR}/src/accelerometer.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/timer_init.o ${OBJECTDIR}/main.o ${OBJECTDIR}/src/ConvertToString.o ${OBJECTDIR}/src/uart_initialization.o

# Source Files
SOURCEFILES=src/GPGGA_Parser.cpp src/PORT_INIT.cpp src/accelerometer.cpp src/i2c.c src/timer_init.cpp main.cpp src/ConvertToString.cpp src/uart_initialization.cpp

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
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/default/d62db13ecfea3f95541527f4477c2ee93593ca34 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	 ${MP_CPPC}  $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums  -I "src" -I "headers" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/i2c.o.d" -MT "${OBJECTDIR}/src/i2c.o.d" -MT ${OBJECTDIR}/src/i2c.o  -o ${OBJECTDIR}/src/i2c.o src/i2c.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/default/52f4d8d67a4352986c6714d5e3ea90b27270b852 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	 ${MP_CPPC}  $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums  -I "src" -I "headers" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/i2c.o.d" -MT "${OBJECTDIR}/src/i2c.o.d" -MT ${OBJECTDIR}/src/i2c.o  -o ${OBJECTDIR}/src/i2c.o src/i2c.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/GPGGA_Parser.o: src/GPGGA_Parser.cpp  .generated_files/flags/default/66fa47121294772f917d9fcda2aaf2c8453258a4 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o.d 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT ${OBJECTDIR}/src/GPGGA_Parser.o  -o ${OBJECTDIR}/src/GPGGA_Parser.o src/GPGGA_Parser.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PORT_INIT.o: src/PORT_INIT.cpp  .generated_files/flags/default/37c1d6a27960934a599ce47b9b00d7761a5735de .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/PORT_INIT.o.d" -MT "${OBJECTDIR}/src/PORT_INIT.o.d" -MT ${OBJECTDIR}/src/PORT_INIT.o  -o ${OBJECTDIR}/src/PORT_INIT.o src/PORT_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/accelerometer.o: src/accelerometer.cpp  .generated_files/flags/default/9b1ef0d364a3509dd0e5f6a3b6bea6fb00533d94 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/accelerometer.o.d 
	@${RM} ${OBJECTDIR}/src/accelerometer.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/accelerometer.o.d" -MT "${OBJECTDIR}/src/accelerometer.o.d" -MT ${OBJECTDIR}/src/accelerometer.o  -o ${OBJECTDIR}/src/accelerometer.o src/accelerometer.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/timer_init.o: src/timer_init.cpp  .generated_files/flags/default/254993a1662e02e0b669df7fe30230799a181b10 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer_init.o.d 
	@${RM} ${OBJECTDIR}/src/timer_init.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/timer_init.o.d" -MT "${OBJECTDIR}/src/timer_init.o.d" -MT ${OBJECTDIR}/src/timer_init.o  -o ${OBJECTDIR}/src/timer_init.o src/timer_init.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.cpp  .generated_files/flags/default/1100b1748813ba633cec18cd87ae15743e125205 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ConvertToString.o: src/ConvertToString.cpp  .generated_files/flags/default/76b9a761123e4caf7a448db9b819962012fc56d8 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o.d 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/ConvertToString.o.d" -MT "${OBJECTDIR}/src/ConvertToString.o.d" -MT ${OBJECTDIR}/src/ConvertToString.o  -o ${OBJECTDIR}/src/ConvertToString.o src/ConvertToString.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/uart_initialization.o: src/uart_initialization.cpp  .generated_files/flags/default/59a43f1cb40662dc4b93ce79cd7e3a45526c0004 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart_initialization.o.d 
	@${RM} ${OBJECTDIR}/src/uart_initialization.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/uart_initialization.o.d" -MT "${OBJECTDIR}/src/uart_initialization.o.d" -MT ${OBJECTDIR}/src/uart_initialization.o  -o ${OBJECTDIR}/src/uart_initialization.o src/uart_initialization.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/GPGGA_Parser.o: src/GPGGA_Parser.cpp  .generated_files/flags/default/b485625414501db510f23bc71e6bda755eff2ce7 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o.d 
	@${RM} ${OBJECTDIR}/src/GPGGA_Parser.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT "${OBJECTDIR}/src/GPGGA_Parser.o.d" -MT ${OBJECTDIR}/src/GPGGA_Parser.o  -o ${OBJECTDIR}/src/GPGGA_Parser.o src/GPGGA_Parser.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PORT_INIT.o: src/PORT_INIT.cpp  .generated_files/flags/default/e3da7ef758c2363766e5845f37bfcf26b4a6834d .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o.d 
	@${RM} ${OBJECTDIR}/src/PORT_INIT.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/PORT_INIT.o.d" -MT "${OBJECTDIR}/src/PORT_INIT.o.d" -MT ${OBJECTDIR}/src/PORT_INIT.o  -o ${OBJECTDIR}/src/PORT_INIT.o src/PORT_INIT.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/accelerometer.o: src/accelerometer.cpp  .generated_files/flags/default/1a780169c1fc7509ac726c250a853b8b48fc02ed .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/accelerometer.o.d 
	@${RM} ${OBJECTDIR}/src/accelerometer.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/accelerometer.o.d" -MT "${OBJECTDIR}/src/accelerometer.o.d" -MT ${OBJECTDIR}/src/accelerometer.o  -o ${OBJECTDIR}/src/accelerometer.o src/accelerometer.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/timer_init.o: src/timer_init.cpp  .generated_files/flags/default/c3b609c5db8830d0025ab6ebef2d686e03e74d7f .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer_init.o.d 
	@${RM} ${OBJECTDIR}/src/timer_init.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/timer_init.o.d" -MT "${OBJECTDIR}/src/timer_init.o.d" -MT ${OBJECTDIR}/src/timer_init.o  -o ${OBJECTDIR}/src/timer_init.o src/timer_init.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.cpp  .generated_files/flags/default/5d54b7985d6c96f47aaf03f3d18b6688a6857a6 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ConvertToString.o: src/ConvertToString.cpp  .generated_files/flags/default/14b733e120a91ba0b5d0fff2eea15e0494394c47 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o.d 
	@${RM} ${OBJECTDIR}/src/ConvertToString.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/ConvertToString.o.d" -MT "${OBJECTDIR}/src/ConvertToString.o.d" -MT ${OBJECTDIR}/src/ConvertToString.o  -o ${OBJECTDIR}/src/ConvertToString.o src/ConvertToString.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/uart_initialization.o: src/uart_initialization.cpp  .generated_files/flags/default/796fcab637c4dafcd05c86e229b944975aa458 .generated_files/flags/default/2847147cc19e2b28307852bc3da9366579aefe7e
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart_initialization.o.d 
	@${RM} ${OBJECTDIR}/src/uart_initialization.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128da48 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -I "headers" -I "src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/src" -I "C:/Users/M68150/OneDrive - Microchip Technology Inc/Desktop/GPS TRACKER/!! current !!! GPS_TRACKER_SW_BETA/GPS_TRACKERV0.1.X/headers" -Wall -MD -MP -MF "${OBJECTDIR}/src/uart_initialization.o.d" -MT "${OBJECTDIR}/src/uart_initialization.o.d" -MT ${OBJECTDIR}/src/uart_initialization.o  -o ${OBJECTDIR}/src/uart_initialization.o src/uart_initialization.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
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
