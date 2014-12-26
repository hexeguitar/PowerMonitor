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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Sources/Src/heltec_oled_driver.c ../Sources/Src/lowlevel.c ../Sources/Src/main.c ../Sources/Src/ina219.c ../Sources/Src/i2c_Func.c ../Sources/Src/n5110_lcd_driver.c ../Sources/Src/uart.c ../Sources/Src/converter.c ../Sources/Src/eeprom.c ../Sources/Src/traps.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o ${OBJECTDIR}/_ext/979045630/lowlevel.o ${OBJECTDIR}/_ext/979045630/main.o ${OBJECTDIR}/_ext/979045630/ina219.o ${OBJECTDIR}/_ext/979045630/i2c_Func.o ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o ${OBJECTDIR}/_ext/979045630/uart.o ${OBJECTDIR}/_ext/979045630/converter.o ${OBJECTDIR}/_ext/979045630/eeprom.o ${OBJECTDIR}/_ext/979045630/traps.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o.d ${OBJECTDIR}/_ext/979045630/lowlevel.o.d ${OBJECTDIR}/_ext/979045630/main.o.d ${OBJECTDIR}/_ext/979045630/ina219.o.d ${OBJECTDIR}/_ext/979045630/i2c_Func.o.d ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o.d ${OBJECTDIR}/_ext/979045630/uart.o.d ${OBJECTDIR}/_ext/979045630/converter.o.d ${OBJECTDIR}/_ext/979045630/eeprom.o.d ${OBJECTDIR}/_ext/979045630/traps.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o ${OBJECTDIR}/_ext/979045630/lowlevel.o ${OBJECTDIR}/_ext/979045630/main.o ${OBJECTDIR}/_ext/979045630/ina219.o ${OBJECTDIR}/_ext/979045630/i2c_Func.o ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o ${OBJECTDIR}/_ext/979045630/uart.o ${OBJECTDIR}/_ext/979045630/converter.o ${OBJECTDIR}/_ext/979045630/eeprom.o ${OBJECTDIR}/_ext/979045630/traps.o

# Source Files
SOURCEFILES=../Sources/Src/heltec_oled_driver.c ../Sources/Src/lowlevel.c ../Sources/Src/main.c ../Sources/Src/ina219.c ../Sources/Src/i2c_Func.c ../Sources/Src/n5110_lcd_driver.c ../Sources/Src/uart.c ../Sources/Src/converter.c ../Sources/Src/eeprom.c ../Sources/Src/traps.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24F16KA101
MP_LINKER_FILE_OPTION=,--script=p24F16KA101.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o: ../Sources/Src/heltec_oled_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/heltec_oled_driver.c  -o ${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/lowlevel.o: ../Sources/Src/lowlevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/lowlevel.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/lowlevel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/lowlevel.c  -o ${OBJECTDIR}/_ext/979045630/lowlevel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/lowlevel.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/lowlevel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/main.o: ../Sources/Src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/main.c  -o ${OBJECTDIR}/_ext/979045630/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/ina219.o: ../Sources/Src/ina219.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/ina219.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/ina219.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/ina219.c  -o ${OBJECTDIR}/_ext/979045630/ina219.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/ina219.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/ina219.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/i2c_Func.o: ../Sources/Src/i2c_Func.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/i2c_Func.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/i2c_Func.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/i2c_Func.c  -o ${OBJECTDIR}/_ext/979045630/i2c_Func.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/i2c_Func.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/i2c_Func.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o: ../Sources/Src/n5110_lcd_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/n5110_lcd_driver.c  -o ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/uart.o: ../Sources/Src/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/uart.c  -o ${OBJECTDIR}/_ext/979045630/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/converter.o: ../Sources/Src/converter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/converter.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/converter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/converter.c  -o ${OBJECTDIR}/_ext/979045630/converter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/converter.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/converter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/eeprom.o: ../Sources/Src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/eeprom.c  -o ${OBJECTDIR}/_ext/979045630/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/eeprom.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/traps.o: ../Sources/Src/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/traps.c  -o ${OBJECTDIR}/_ext/979045630/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o: ../Sources/Src/heltec_oled_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/heltec_oled_driver.c  -o ${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/heltec_oled_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/lowlevel.o: ../Sources/Src/lowlevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/lowlevel.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/lowlevel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/lowlevel.c  -o ${OBJECTDIR}/_ext/979045630/lowlevel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/lowlevel.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/lowlevel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/main.o: ../Sources/Src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/main.c  -o ${OBJECTDIR}/_ext/979045630/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/main.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/ina219.o: ../Sources/Src/ina219.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/ina219.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/ina219.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/ina219.c  -o ${OBJECTDIR}/_ext/979045630/ina219.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/ina219.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/ina219.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/i2c_Func.o: ../Sources/Src/i2c_Func.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/i2c_Func.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/i2c_Func.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/i2c_Func.c  -o ${OBJECTDIR}/_ext/979045630/i2c_Func.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/i2c_Func.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/i2c_Func.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o: ../Sources/Src/n5110_lcd_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/n5110_lcd_driver.c  -o ${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/n5110_lcd_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/uart.o: ../Sources/Src/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/uart.c  -o ${OBJECTDIR}/_ext/979045630/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/uart.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/converter.o: ../Sources/Src/converter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/converter.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/converter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/converter.c  -o ${OBJECTDIR}/_ext/979045630/converter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/converter.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/converter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/eeprom.o: ../Sources/Src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/eeprom.c  -o ${OBJECTDIR}/_ext/979045630/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/eeprom.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/979045630/traps.o: ../Sources/Src/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/979045630 
	@${RM} ${OBJECTDIR}/_ext/979045630/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/979045630/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sources/Src/traps.c  -o ${OBJECTDIR}/_ext/979045630/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/979045630/traps.o.d"        -g -omf=elf -Os -I"../Sources/Inc" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/979045630/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/power_monitor.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/power_monitor.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/power_monitor.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
