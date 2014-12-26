#ifndef __SPI_H
#define __SPI_H

/******************************************************************************
 *
 *                  SPI PERIPHERAL LIBRARY HEADER FILE
 *
 ******************************************************************************
 * FileName:        spi.h
 * Dependencies:    See include below
 * Processor:       PIC24
 * Compiler:        MPLAB C30
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *****************************************************************************/

#include "PIC24F_periph_features.h"

/*This preprocessor conditional statement is to avoid unintended linking for unsuppported devices. */
#if defined (spi_v1_1) || defined (spi_v1_2) || defined (spi_v1_3) || defined (spi_v1_4) || defined (spi_v2_1) || defined (spi_v2_2)|| defined (LIB_BUILD) 

#if defined (spi_v1_1) || defined (spi_v1_2) || defined (spi_v1_3) || defined (spi_v1_4)
#define SPI1STAT_VALUE         0x0000
#define SPI2STAT_VALUE         0x0000
#define SPI3STAT_VALUE         0x0000

#ifndef spi_v1_4 
#define SPI1BUF_VALUE          0x0000
#define SPI2BUF_VALUE          0x0000
#define SPI3BUF_VALUE          0x0000
#endif 

#define SPI1CON1_VALUE         0x0000
#define SPI2CON1_VALUE         0x0000
#define SPI3CON1_VALUE         0x0000

#define SPI1CON2_VALUE         0x0000
#define SPI2CON2_VALUE         0x0000
#define SPI3CON2_VALUE         0x0000
#endif

#if defined (spi_v2_1) || defined (spi_v2_2)
#define SSP1BUF_VALUE          0x0000
#define SSP1CON1_VALUE         0x0000
#define SSP1CON2_VALUE         0x0000
#define SSP1CON3_VALUE         0x0000
#define SSP1STAT_VALUE         0x0000
#define SSP1ADD_VALUE          0x0000
#define PADCFG1_VALUE          0x0000
#if defined (spi_v2_2)
#define SSP2BUF_VALUE          0x0000
#define SSP2CON1_VALUE         0x0000
#define SSP2CON2_VALUE         0x0000
#define SSP2CON3_VALUE         0x0000
#define SSP2STAT_VALUE         0x0000
#define SSP2ADD_VALUE          0x0000
#endif
#endif

#if defined (spi_v1_1) || defined (spi_v1_2) || defined (spi_v1_3) || defined (spi_v1_4)

#ifndef USE_AND_OR /* Format for AND_OR based bit setting */

/* SPIXCON1: SPIx CONTROL REGISTER 1 */
#define  DISABLE_SCK_PIN     	0xffff /* Internal SPI clock is diabled, pin functions as I/O */
#define  ENABLE_SCK_PIN      	0xefff /*Internal SPI clock is enabled */

#define  DISABLE_SDO_PIN        0xffff /* SDO pin is not used by module   */
#define  ENABLE_SDO_PIN         0xf7ff /* SDO pin is  used by module      */

#define  SPI_MODE16_ON          0xffff /* Communication is word wide      */
#define  SPI_MODE16_OFF         0xfbff /* Communication is byte wide      */
#define  SPI_MODE8_ON           SPI_MODE16_OFF

#define  SPI_SMP_ON             0xffff /* Input data sampled at end of data output time */
#define  SPI_SMP_OFF            0xfdff /* Input data sampled at middle of data output time */

#define  SPI_CKE_ON             0xffff /* Transmit happens from active clock state to idle clock state*/
#define  SPI_CKE_OFF            0xfeff /* Transmit happens on transition from idle clock state to active clock state */

#define  SLAVE_ENABLE_ON        0xffff /* Slave Select enbale               */
#define  SLAVE_ENABLE_OFF       0xff7f /* Slave Select not used by module   */

#define  CLK_POL_ACTIVE_LOW     0xffff /* Idle state for clock is high, active is low */
#define  CLK_POL_ACTIVE_HIGH    0xffbf /* Idle state for clock is low, active is high */

#define  MASTER_ENABLE_ON       0xffff /* Master Mode              */
#define  MASTER_ENABLE_OFF      0xffdf /* Slave Mode               */

#define  SEC_PRESCAL_1_1        0xffff /* Secondary Prescale 1:1   */
#define  SEC_PRESCAL_2_1        0xfffb /* Secondary Prescale 2:1   */
#define  SEC_PRESCAL_3_1        0xfff7 /* Secondary Prescale 3:1   */
#define  SEC_PRESCAL_4_1        0xfff3 /* Secondary Prescale 4:1   */
#define  SEC_PRESCAL_5_1        0xffef /* Secondary Prescale 5:1   */
#define  SEC_PRESCAL_6_1        0xffeb /* Secondary Prescale 6:1   */
#define  SEC_PRESCAL_7_1        0xffe7 /* Secondary Prescale 7:1   */
#define  SEC_PRESCAL_8_1        0xffe3 /* Secondary Prescale 8:1   */

#define  PRI_PRESCAL_1_1        0xffff /* Primary Prescale 1:1     */
#define  PRI_PRESCAL_4_1        0xfffe /* Primary Prescale 4:1     */
#define  PRI_PRESCAL_16_1       0xfffd /* Primary Prescale 16:1    */
#define  PRI_PRESCAL_64_1       0xfffc /* Primary Prescale 64:1    */

/* SPIxCON2: SPIx CONTROL REGISTER 2 */
#define  FRAME_ENABLE_ON        0xffff /* Frame SPI support enable        */
#define  FRAME_ENABLE_OFF       0x7fff /* Frame SPI support Disable       */

#define  FRAME_SYNC_INPUT       0xffff /* Frame sync pulse Input (slave)  */
#define  FRAME_SYNC_OUTPUT      0xbfff /* Frame sync pulse Output (master)*/

#define  FRAME_POL_ACTIVE_HIGH  0xffff /* Frame sync pulse is active-high*/
#define  FRAME_POL_ACTIVE_LOW   0xdfff /* Frame sync pulse is active-low */

#define  FRAME_SYNC_ACTIVE_HIGH  FRAME_POL_ACTIVE_HIGH /* Frame sync pulse is active-high*/
#define  FRAME_SYNC_ACTIVE_LOW   FRAME_POL_ACTIVE_LOW /* Frame sync pulse is active-low */

#define  FRAME_SYNC_EDGE_COINCIDE 0xffff /* Frame sync pulse coincides with first bit clock */
#define  FRAME_SYNC_EDGE_PRECEDE  0xfffd /* Frame sync pulse precedes first bit clock */

#define  SPI_FRM_PULSE_FIRST_CLK  FRAME_SYNC_EDGE_COINCIDE/* Frame sync pulse coincides with first bit clock */
#define  SPI_FRM_PULSE_PREV_CLK   FRAME_SYNC_EDGE_PRECEDE /* Frame sync pulse precedes first bit clock */

#ifndef spi_v1_4
#define  FIFO_BUFFER_ENABLE  	0xffff /* FIFO buffer enabled */
#define  FIFO_BUFFER_DISABLE 	0xfffe /* FIFO buffer enabled */

#define  SPI_ENH_BUFF_ENABLE  	FIFO_BUFFER_ENABLE /* FIFO buffer enabled */
#define  SPI_ENH_BUFF_DISABLE 	FIFO_BUFFER_DISABLE /* FIFO buffer enabled */
#endif

/* SPIxSTAT REGISTER */
#define  SPI_ENABLE             0xffff /* Enable module */
#define  SPI_DISABLE            0x7fff /* Disable module */

#define  SPI_IDLE_CON           0xdfff /* Continue module operation in idle mode */
#define  SPI_IDLE_STOP          0xffff /* Discontinue module operation in idle mode */

#define  SPI_RX_OVFLOW          0xffff /* SPI receive overflow bit enabled */
#define  SPI_RX_OVFLOW_CLR      0xffbf /* Clear receive overflow bit.*/

#define FIFO_BUF_LEN_1      	0xfff8 /* FIFO buffer length 1 words */
#define FIFO_BUF_LEN_2      	0xfff9 /* FIFO buffer length 2 words */
#define FIFO_BUF_LEN_3      	0xfffa /* FIFO buffer length 3 words */
#define FIFO_BUF_LEN_4      	0xfffb /* FIFO buffer length 4 words */
#define FIFO_BUF_LEN_5      	0xfffc /* FIFO buffer length 5 words */
#define FIFO_BUF_LEN_6      	0xfffd /* FIFO buffer length 6 words */
#define FIFO_BUF_LEN_7      	0xfffe /* FIFO buffer length 7 words */
#define FIFO_BUF_LEN_8      	0xffff /* FIFO buffer length 8 words */

#define  SPI_INT_EN             0xffff /* SPI Interrupt Enable     */
#define  SPI_INT_DIS            0xfff7 /* SPI Interrupt Disable    */

#define  SPI_FAULT_INT_EN       0xffff /* SPI Fault Interrupt Enable     */
#define  SPI_FAULT_INT_DIS      0xff7f /* SPI Fault Interrupt Disable    */

#define  SPI_INT_PRI_0          0xfff8 /* SPI Interrupt Prior Level_0 */
#define  SPI_INT_PRI_1          0xfff9 /* SPI Interrupt Prior Level_1 */
#define  SPI_INT_PRI_2          0xfffa /* SPI Interrupt Prior Level_2 */
#define  SPI_INT_PRI_3          0xfffb /* SPI Interrupt Prior Level_3 */
#define  SPI_INT_PRI_4          0xfffc /* SPI Interrupt Prior Level_4 */
#define  SPI_INT_PRI_5          0xfffd /* SPI Interrupt Prior Level_5 */
#define  SPI_INT_PRI_6          0xfffe /* SPI Interrupt Prior Level_6 */
#define  SPI_INT_PRI_7          0xffff /* SPI Interrupt Prior Level_7 */

#define  SPI_FAULT_INT_PRI_0    0xff8f /* SPI Fault Interrupt Prior Level_0 */
#define  SPI_FAULT_INT_PRI_1    0xff9f /* SPI Fault Interrupt Prior Level_1 */
#define  SPI_FAULT_INT_PRI_2    0xffaf /* SPI Fault Interrupt Prior Level_2 */
#define  SPI_FAULT_INT_PRI_3    0xffbf /* SPI Fault Interrupt Prior Level_3 */
#define  SPI_FAULT_INT_PRI_4    0xffcf /* SPI Fault Interrupt Prior Level_4 */
#define  SPI_FAULT_INT_PRI_5    0xffdf /* SPI Fault Interrupt Prior Level_5 */
#define  SPI_FAULT_INT_PRI_6    0xffef /* SPI Fault Interrupt Prior Level_6 */
#define  SPI_FAULT_INT_PRI_7    0xffff /* SPI Fault Interrupt Prior Level_7 */

#else /* Format for backward compatibility (AND based bit setting). */

/* SPIXCON1: SPIx CONTROL REGISTER 1 */
#define  DISABLE_SCK_PIN        0x1000 /* SCK pin is not used by module */
#define  ENABLE_SCK_PIN         0x0000 /* SCK pin is  used by module */
#define  SCK_PIN_MASK           (~DISABLE_SCK_PIN)

#define  DISABLE_SDO_PIN        0x0800 /* SDO pin is not used by module */
#define  ENABLE_SDO_PIN         0x0000 /* SDO pin is  used by module */
#define  SDO_PIN_MASK           (~DISABLE_SDO_PIN)

#define  SPI_MODE16_ON          0x0400 /* Communication is word wide */
#define  SPI_MODE8_ON           0x0000 /* Communication is byte wide */
#define  SPI_MODE16_OFF         SPI_MODE8_ON  
#define  SPI_MODE_MASK          (~SPI_MODE16_ON)

#define  SPI_SMP_ON             0x0200 /* Input data sampled at end of data output time */
#define  SPI_SMP_OFF            0x0000 /* Input data sampled at middle of data output time */
#define  SPI_SMP_MASK           (~SPI_SMP_ON)

#define  SPI_CKE_ON             0x0100 /* Transmit happens from active clock state to idle clock state*/
#define  SPI_CKE_OFF            0x0000 /* Transmit happens on transition from idle clock state to active clock state */
#define  SPI_CKE_MASK           (~SPI_CKE_ON)

#define  SLAVE_ENABLE_ON        0x0080 /* Slave Select enbale */
#define  SLAVE_ENABLE_OFF       0x0000 /* Slave Select not used by module */
#define  SLAVE_ENABLE_MASK      (~SLAVE_ENABLE_ON)

#define  CLK_POL_ACTIVE_LOW     0x0040 /* Idle state for clock is high, active is low */
#define  CLK_POL_ACTIVE_HIGH    0x0000 /* Idle state for clock is low, active is high */
#define  CLK_POL_ACTIVE_MASK    (~CLK_POL_ACTIVE_LOW)

#define  MASTER_ENABLE_ON       0x0020 /* Master Mode */
#define  MASTER_ENABLE_OFF      0x0000 /* Slave Mode */
#define  MASTER_ENABLE_MASK     (~MASTER_ENABLE_ON)

#define  SEC_PRESCAL_1_1        0x001c /* Secondary Prescale 1:1   */
#define  SEC_PRESCAL_2_1        0x0018 /* Secondary Prescale 2:1   */
#define  SEC_PRESCAL_3_1        0x0014 /* Secondary Prescale 3:1   */
#define  SEC_PRESCAL_4_1        0x0010 /* Secondary Prescale 4:1   */
#define  SEC_PRESCAL_5_1        0x000c /* Secondary Prescale 5:1   */
#define  SEC_PRESCAL_6_1        0x0008 /* Secondary Prescale 6:1   */
#define  SEC_PRESCAL_7_1        0x0004 /* Secondary Prescale 7:1   */
#define  SEC_PRESCAL_8_1        0x0000 /* Secondary Prescale 8:1   */
#define  SEC_PRESCAL_MASK       (~SEC_PRESCAL_1_1)

#define  PRI_PRESCAL_1_1        0x0003 /* Primary Prescale 1:1     */
#define  PRI_PRESCAL_4_1        0x0002 /* Primary Prescale 4:1     */
#define  PRI_PRESCAL_16_1       0x0001 /* Primary Prescale 16:1    */
#define  PRI_PRESCAL_64_1       0x0000 /* Primary Prescale 64:1    */
#define  PRI_PRESCAL_MASK       (~PRI_PRESCAL_1_1)

/* SPIxSTAT REGISTER */
#define  SPI_ENABLE             0x8000 /* Enable module */
#define  SPI_DISABLE            0x0000 /* Disable module */
#define  SPI_ENBL_DSBL_MASK     (~SPI_ENABLE)

#define  SPI_IDLE_STOP          0x2000 /* Discontinue module operation in idle mode */
#define  SPI_IDLE_CON           0x0000 /* Continue module operation in idle mode */
#define  SPI_IDLE_MASK          (~SPI_IDLE_STOP)

#define  SPI_RX_OVFLOW          0x0040 /* SPI receive overflow bit enabled */
#define  SPI_RX_OVFLOW_CLR      0x0000 /* Clear receive overflow bit */
#define  SPI_RX_OVFLOW_MASK     (~SPI_RX_OVFLOW)

/* SPIxCON2: SPIx CONTROL REGISTER 2 */
#define  FRAME_ENABLE_ON        0x8000 /* Frame SPI support enable */
#define  FRAME_ENABLE_OFF       0x0000 /* Frame SPI support Disable */
#define  FRAME_ENABLE_MASK      (~FRAME_ENABLE_ON)

#define  FRAME_SYNC_INPUT       0x4000 /* Frame sync pulse Input (slave)  */
#define  FRAME_SYNC_OUTPUT      0x0000 /* Frame sync pulse Output (master)*/
#define  FRAME_SYNC_MASK        (~FRAME_SYNC_INPUT)

#define  FRAME_SYNC_ACTIVE_HIGH 0x2000 /* Frame sync pulse Input (slave)  */
#define  FRAME_SYNC_ACTIVE_LOW  0x0000 /* Frame sync pulse Output (master)*/
#define  FRAME_SYNC_POL_MASK    (~FRAME_SYNC_ACTIVE_HIGH)

#define  FRAME_POL_ACTIVE_HIGH  FRAME_SYNC_ACTIVE_HIGH /* Frame sync pulse is active-high*/
#define  FRAME_POL_ACTIVE_LOW   FRAME_SYNC_ACTIVE_LOW /* Frame sync pulse is active-low */
#define  FRAME_POL_SYNC_MASK    (~FRAME_POL_ACTIVE_HIGH)

#define  SPI_FRM_PULSE_FIRST_CLK 0x0002 /* frame pulse coincides with the first bit clock */
#define  SPI_FRM_PULSE_PREV_CLK  0x0000 /* frame pulse precedes the first bit clock */
#define  SPI_FRM_PULSE_MASK     (~SPI_FRM_PULSE_FIRST_CLK)

#define  FRAME_SYNC_EDGE_COINCIDE SPI_FRM_PULSE_FIRST_CLK /* Frame sync pulse coincides with first bit clock */
#define  FRAME_SYNC_EDGE_PRECEDE  SPI_FRM_PULSE_PREV_CLK /* Frame sync pulse precedes first bit clock */
#define  FRAME_SYNC_EDGE_MASK     (~FRAME_SYNC_EDGE_COINCIDE)

#ifndef spi_v1_4
#define  SPI_ENH_BUFF_ENABLE    0x0001 /* enable enhanced buffer */
#define  SPI_ENH_BUFF_DISABLE   0x0000 /* disable enhanced buffer */
#define  SPI_ENH_BUFF_MASK      (~SPI_ENH_BUFF_ENABLE)

#define  FIFO_BUFFER_ENABLE  	SPI_ENH_BUFF_ENABLE /* FIFO buffer enabled */
#define  FIFO_BUFFER_DISABLE 	SPI_ENH_BUFF_DISABLE /* FIFO buffer enabled */
#define  FIFO_BUFFER_MASK      (~FIFO_BUFFER_ENABLE)
#endif

#define FIFO_BUF_LEN_1      	0x0000 /* FIFO buffer length 1 words */
#define FIFO_BUF_LEN_2      	0x0001 /* FIFO buffer length 2 words */
#define FIFO_BUF_LEN_3      	0x0002 /* FIFO buffer length 3 words */
#define FIFO_BUF_LEN_4      	0x0003 /* FIFO buffer length 4 words */
#define FIFO_BUF_LEN_5      	0x0004 /* FIFO buffer length 5 words */
#define FIFO_BUF_LEN_6      	0x0005 /* FIFO buffer length 6 words */
#define FIFO_BUF_LEN_7      	0x0006 /* FIFO buffer length 7 words */
#define FIFO_BUF_LEN_8      	0x0007 /* FIFO buffer length 8 words */
#define FIFO_BUF_LEN_MASK       (~FIFO_BUF_LEN_8)

/* SPI Interrupt defines */
#define  SPI_INT_EN             0x0008 /* SPI Interrupt Enable     */
#define  SPI_INT_DIS            0x0000 /* SPI Interrupt Disable    */
#define  SPI_INT_MASK           (~SPI_INT_EN)

#define  SPI_FAULT_INT_EN       0x0080 /* SPI Fault Interrupt Enable     */
#define  SPI_FAULT_INT_DIS      0x0000 /* SPI Fault Interrupt Disable    */
#define  SPI_FAULT_INT_MASK     (~SPI_FAULT_INT_EN)

#define  SPI_INT_PRI_0          0x0000 /* SPI Interrupt Prior Level_0 */
#define  SPI_INT_PRI_1          0x0001 /* SPI Interrupt Prior Level_1 */
#define  SPI_INT_PRI_2          0x0002 /* SPI Interrupt Prior Level_2 */
#define  SPI_INT_PRI_3          0x0003 /* SPI Interrupt Prior Level_3 */
#define  SPI_INT_PRI_4          0x0004 /* SPI Interrupt Prior Level_4 */
#define  SPI_INT_PRI_5          0x0005 /* SPI Interrupt Prior Level_5 */
#define  SPI_INT_PRI_6          0x0006 /* SPI Interrupt Prior Level_6 */
#define  SPI_INT_PRI_7          0x0007 /* SPI Interrupt Prior Level_7 */
#define  SPI_INT_PRI_MASK       (~SPI_INT_PRI_7)  

#define  SPI_FAULT_INT_PRI_0    0x0000 /* SPI Fault Interrupt Prior Level_0 */
#define  SPI_FAULT_INT_PRI_1    0x0010 /* SPI Fault Interrupt Prior Level_1 */
#define  SPI_FAULT_INT_PRI_2    0x0020 /* SPI Fault Interrupt Prior Level_2 */
#define  SPI_FAULT_INT_PRI_3    0x0030 /* SPI Fault Interrupt Prior Level_3 */
#define  SPI_FAULT_INT_PRI_4    0x0040 /* SPI Fault Interrupt Prior Level_4 */
#define  SPI_FAULT_INT_PRI_5    0x0050 /* SPI Fault Interrupt Prior Level_5 */
#define  SPI_FAULT_INT_PRI_6    0x0060 /* SPI Fault Interrupt Prior Level_6 */
#define  SPI_FAULT_INT_PRI_7    0x0070 /* SPI Fault Interrupt Prior Level_7 */
#define  SPI_FAULT_INT_PRI_MASK (~SPI_FAULT_INT_PRI_7)

#endif /* USE_AND_OR */

#endif

#if defined (spi_v2_1) || defined (spi_v2_2)

#define   SPI_MODE_00       0x00     /* Setting for SPI bus Mode 0,0 */
//CKE           0x40                   /* SSPSTAT register */
//CKP           0x00                   /*SSPCON1 register */

#define   SPI_MODE_01       0x01     /* Setting for SPI bus Mode 0,1*/
//CKE           0x00                   /* SSPSTAT register */
//CKP           0x00                   /* SSPCON1 register*/

#define   SPI_MODE_10       0x02     /* Setting for SPI bus Mode 1,0 */
//CKE           0x40                   /* SSPSTAT register */
//CKP           0x10                   /* SSPCON1 register */

#define   SPI_MODE_11       0x03      /* Setting for SPI bus Mode 1,1 */
//CKE           0x00                   /* SSPSTAT register */
//CKP           0x10                   /* SSPCON1 register */

#ifndef USE_AND_OR /* Format for AND_OR based bit setting */

/* SSPxSTAT REGISTER */
/* Master SPI mode only */

#define   SPI_SMPEND        	 		0xFF           /* Input data sample at end of data out   */          
#define   SPI_SMPMID        	 		0x7F           /* Input data sample at middle of data out*/

#define   SPI_ACTV_IDL_CLK   	  		0xFF			/* Transmit occurs on transition from active to idle clock state */
#define   SPI_IDL_ACTV_CLK   	  		0xBF 			/* Transmit occurs on transition from idle to active clock state	*/

/* SSPxCON1 REGISTER */
#define   SPI_MSSP_ENABLE         		0xFF          /* Enable serial port and configures SCK, SDO, SDI */
#define   SPI_MSSP_DISABLE          	0xDF          /* Disable serial port and configures SCK, SDO, SDI */

#define  SPI_CLK_POL_HGH				0xFF			/* Idle state for clock is a high level */
#define  SPI_CLK_POL_LOW	 			0xEF			/* Idle state for clock is a low level */

#define   SPI_FOSC_2    	       	 	0xF0              /* SPI Master mode, clock = Fosc/2 */
#define   SPI_FOSC_8   					0xF1              /* SPI Master mode, clock = Fosc/8 */
#define   SPI_FOSC_32   	        	0xF2      		  /* SPI Master mode, clock = Fosc/32 */
#define   SPI_FOSC_TMR2 		    	0xF3          	 /* SPI Master mode, clock = TMR2 output/2 */ 
#define   SLV_SSON      				0xF4              /* SPI Slave mode, /SS pin control enabled */
#define   SLV_SSOFF     				0xF5              /* SPI Slave mode, /SS pin control disabled */
#define   SPI_MM_ON    	        		0xFA              /* SPI Master mode, clock = Fosc/(2*([SSPxADD]+1)) */

/* SSPxCON3 REGISTER */
#define SPI_BUFF_OVRWRT_ENABLE   		0xFF			/* SSPxBUF updates everytime a new data byte is shifted */ 
#define SPI_BUFF_OVRWRT_DISABLE   		0xEF			/* Buffer is not updated when a new byte is recieved with BF bit of the SSPxSTAT */

/*PADCFG1 REGISTER*/
#if defined (spi_v2_2)
#define  SPI_DATAOUT_MSSP2_DISABLE 		0xFFFF			/* SPI output data (SDO2) of MSSP2 to the pin is disabled */
#define  SPI_DATAOUT_MSSP2_ENABLE		0xF7FF			/* SPI output data (SDO2) of MSSP2 is to the output pin */
 
#define  SPI_CLKOUT_MSSP2_DISABLE 		0xFFFF			/* SPI clock (SCK2) of MSSP2 to the pin is disabled */
#define  SPI_CLKOUT_MSSP2_ENABLE 		0xFBFF			/* SPI clock (SCK2) of MSSP2 is output to the pin*/
#endif

#define  SPI_DATAOUT_MSSP1_DISABLE 		0xFFFF			/* SPI output data (SDO1) of MSSP1 to the pin is disabled */
#define  SPI_DATAOUT_MSSP1_ENABLE		0xFDFF			/* SPI output data (SDO1) of MSSP1 is to the output pin*/ 
 
#define  SPI_CLKOUT_MSSP1_DISABLE 		0xFFFF			/* SPI clock (SCK1) of MSSP1 to the pin is disabled */
#define  SPI_CLKOUT_MSSP1_ENABLE 		0xFEFF			/* SPI clock (SCK1) of MSSP1 is output to the pin*/

#define  SPI_INT_PRI_0          0xfff8 /* SPI Interrupt Prior Level_0 */
#define  SPI_INT_PRI_1          0xfff9 /* SPI Interrupt Prior Level_1 */
#define  SPI_INT_PRI_2          0xfffa /* SPI Interrupt Prior Level_2 */
#define  SPI_INT_PRI_3          0xfffb /* SPI Interrupt Prior Level_3 */
#define  SPI_INT_PRI_4          0xfffc /* SPI Interrupt Prior Level_4 */
#define  SPI_INT_PRI_5          0xfffd /* SPI Interrupt Prior Level_5 */
#define  SPI_INT_PRI_6          0xfffe /* SPI Interrupt Prior Level_6 */
#define  SPI_INT_PRI_7          0xffff /* SPI Interrupt Prior Level_7 */

#else

/* SSPxSTAT REGISTER */
/* Master SPI mode only*/

#define   SPI_SMPEND        	 0x80           /* Input data sample at end of data out */            
#define   SPI_SMPMID        	 0x00           /* Input data sample at middle of data out */
#define   SPI_SMP_MASK     		(~SPI_SMPEND) 

#define   SPI_ACTV_IDL_CLK   	  0x40			/* Transmit occurs on transition from active to idle clock state */
#define   SPI_IDL_ACTV_CLK   	  0x00 			/* Transmit occurs on transition from idle to active clock state */	
#define   SPI_CLK_SELECT_MASK    (~SPI_ACTV_IDL_CLK)

/* SSPxCON1 REGISTER */
#define   SPI_MSSP_ENABLE         		0x20          /* Enable serial port and configures SCK, SDO, SDI */
#define   SPI_MSSP_DISABLE          	0x00          /* Disable serial port and configures SCK, SDO, SDI */
#define   SPI_MSSP_MASK     			(~SPI_MSSP_ENABLE)

#define  SPI_CLK_POL_HGH				0x01			/* Idle state for clock is a high level */
#define  SPI_CLK_POL_LOW	 			0x00			/* Idle state for clock is a low level */
#define  SPI_CLK_POL_MASK     			(~SPI_CLK_POL_HGH)

#define   SPI_FOSC_2    	       	 	0x00              /* SPI Master mode, clock = Fosc/2 */
#define   SPI_FOSC_8   					0x01              /* SPI Master mode, clock = Fosc/8 */
#define   SPI_FOSC_32   	        	0x02      		  /* SPI Master mode, clock = Fosc/32 */
#define   SPI_FOSC_TMR2 		    	0x03          	 /* SPI Master mode, clock = TMR2 output/2 */
#define   SLV_SSON      				0x04              /* SPI Slave mode, /SS pin control enabled */
#define   SLV_SSOFF     				0x05              /* SPI Slave mode, /SS pin control disabled */
#define   SPI_MM_ON    	        		0x0A              /* SPI Master mode, clock = Fosc/(2*([SSPxADD]+1)) */
#define   SPI_MODE_SELECT_MASK     		(~SPI_MM_ON)

/* SSPxCON3 REGISTER */
#define SPI_BUFF_OVRWRT_ENABLE   		0x10			/* SSPxBUF updates everytime a new data byte is shifted */ 
#define SPI_BUFF_OVRWRT_DISABLE   		0x00			/* Buffer is not updated when a new byte is recieved with BF bit of the SSPxSTAT */
#define SPI_BUFF_OVRWRT_MASK 			(~SPI_BUFF_OVRWRT_MASK)

/*PADCFG1 REGISTER*/
#if defined (spi_v2_2)
#define  SPI_DATAOUT_MSSP2_DISABLE 		0x0800			/* SPI output data (SDO2) of MSSP2 to the pin is disabled */
#define  SPI_DATAOUT_MSSP2_ENABLE		0x0000			/* SPI output data (SDO2) of MSSP2 is to the output pin */
#define  SPI_DATAOUT_MSSP2_MASK 		(~SPI_DATAOUT_MSSP2_DISABLE)
 
#define  SPI_CLKOUT_MSSP2_DISABLE 		0x0700			/* SPI clock (SCK2) of MSSP2 to the pin is disabled */
#define  SPI_CLKOUT_MSSP2_ENABLE 		0x0000			/* SPI clock (SCK2) of MSSP2 is output to the pin */
#define  SPI_CLKOUT_MSSP2_MASK 			(~SPI_CLKOUT_MSSP2_DISABLE)
#endif

#define  SPI_DATAOUT_MSSP1_DISABLE 		0x0800			/* SPI output data (SDO1) of MSSP1 to the pin is disabled */
#define  SPI_DATAOUT_MSSP1_ENABLE		0x0000			/* SPI output data (SDO1) of MSSP1 is to the output pin */
#define  SPI_DATAOUT_MSSP1_MASK 		(~SPI_DATAOUT_MSSP2_DISABLE)
 
#define  SPI_CLKOUT_MSSP1_DISABLE 		0x0700			/* SPI clock (SCK1) of MSSP1 to the pin is disabled */
#define  SPI_CLKOUT_MSSP1_ENABLE 		0x0000			/* SPI clock (SCK1) of MSSP1 is output to the pin */
#define  SPI_CLKOUT_MSSP1_MASK 			(~SPI_CLKOUT_MSSP2_DISABLE)

/* SPI Interrupt defines */
#define  SPI_INT_EN             0x0008 /* SPI Interrupt Enable     */
#define  SPI_INT_DIS            0x0000 /* SPI Interrupt Disable    */
#define  SPI_INT_MASK           (~SPI_INT_EN)

#define  SPI_FAULT_INT_EN       0x0080 /* SPI Fault Interrupt Enable     */
#define  SPI_FAULT_INT_DIS      0x0000 /* SPI Fault Interrupt Disable    */
#define  SPI_FAULT_INT_MASK     (~SPI_FAULT_INT_EN)

#define  SPI_INT_PRI_0          0x0000 /* SPI Interrupt Prior Level_0 */
#define  SPI_INT_PRI_1          0x0001 /* SPI Interrupt Prior Level_1 */
#define  SPI_INT_PRI_2          0x0002 /* SPI Interrupt Prior Level_2 */
#define  SPI_INT_PRI_3          0x0003 /* SPI Interrupt Prior Level_3 */
#define  SPI_INT_PRI_4          0x0004 /* SPI Interrupt Prior Level_4 */
#define  SPI_INT_PRI_5          0x0005 /* SPI Interrupt Prior Level_5 */
#define  SPI_INT_PRI_6          0x0006 /* SPI Interrupt Prior Level_6 */
#define  SPI_INT_PRI_7          0x0007 /* SPI Interrupt Prior Level_7 */
#define  SPI_INT_PRI_MASK       (~SPI_INT_PRI_7)  

#define  SPI_FAULT_INT_PRI_0    0x0000 /* SPI Fault Interrupt Prior Level_0 */
#define  SPI_FAULT_INT_PRI_1    0x0010 /* SPI Fault Interrupt Prior Level_1 */
#define  SPI_FAULT_INT_PRI_2    0x0020 /* SPI Fault Interrupt Prior Level_2 */
#define  SPI_FAULT_INT_PRI_3    0x0030 /* SPI Fault Interrupt Prior Level_3 */
#define  SPI_FAULT_INT_PRI_4    0x0040 /* SPI Fault Interrupt Prior Level_4 */
#define  SPI_FAULT_INT_PRI_5    0x0050 /* SPI Fault Interrupt Prior Level_5 */
#define  SPI_FAULT_INT_PRI_6    0x0060 /* SPI Fault Interrupt Prior Level_6 */
#define  SPI_FAULT_INT_PRI_7    0x0070 /* SPI Fault Interrupt Prior Level_7 */
#define  SPI_FAULT_INT_PRI_MASK (~SPI_FAULT_INT_PRI_7)

#endif /* USE_AND_OR */


/* These devices have two SPI modules */
/* ***** SPI1 ***** */

/**************************************************************************
Macro       : EnableIntSPI1
 
Description : Enables SPIx Interrupt
 
Arguments   : None
 
Remarks     : This macro sets SPI Interrupt Enable bit of Interrupt Enable 
		Control register.
***************************************************************************/ 
#define EnableIntSPI1                   (IEC1bits.SSP1IE = 1)

/**************************************************************************
Macro       : DisableIntSPI1

Description : This macro disables the SPI Interrupt
 
Arguments   : None
 
Remarks     : This macro clears SPI Interrupt Enable bit of Interrupt Enable 
		Control register.
***************************************************************************/ 
#define DisableIntSPI1                  (IEC1bits.SSP1IE = 0)

/**************************************************************************
Macro       : SetPriorityIntSPI1(priority)
 
Description : This macro sets the priority level for SPI interrupt
 
Arguments   : priority - This input parameter is the level of interrupt priority.
		* 0 -- Low priority (Default Value)
		* 1 -- High Priority
		
Remarks     : None 
***************************************************************************/
#define SetPriorityIntSPI1(priority)     (IPC4bits.SSP1IP = priority)

/*******************************************************************
Macro       : SPI1_Clear_Intr_Status_Bit

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define SPI1_Clear_Intr_Status_Bit     (IFS1bits.SSP1IF = 0)

/*******************************************************************
Macro       : SPI1_Intr_Status

Description : Macro to Return SPI Interrupt Status  

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define SPI1_Intr_Status     (IFS1bits.SSP1IF)

/**************************************************************************
Macro       : SPI1_Clear_Recv_OV

Description : macro clears Receive Overflow flag
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  SPI1_Clear_Recv_OV    SSP1CON1bits.SSPOV = 0

/*********************************************************************
Macro  	:	CloseSPI1()

Include        : 	spi.h 

Description : 	This Macro turns off the SPI module 

Arguments   : 	None 

Return Value: 	None 

Remarks      : 	This Macro disables the SPI module.
*********************************************************************/
#define  CloseSPI1_Mac()    (SSP1CON1 &=0xDF)

/************************************************************************
Macro :  DataRdySPI1() 

Include            : spi.h 

Description        : This Macro provides status back to user if SSPxBUF
			register contain data. 
                     
Arguments          : None 

Remarks            : This Macro determines if there is any byte to read from
			SSPxBUF register.
*************************************************************************/
#define  DataRdySPI1_Mac()  (SSP1STATbits.BF)

/**************************************************************************
Macro       : getcSPI1

Description : macro is identical to ReadSPI1,#define to ReadSPI1 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  getcSPI1  ReadSPI1


/**************************************************************************
Macro       : putcSPI1

Description : macro is identical to WriteSPI1,#define to WriteSPI1 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  putcSPI1  WriteSPI1

/**************************************************************************
Macro       : SPI1_Tx_Buf_Full

Description : macro reads the status of Transmit Buffer.
              Returns 1 - Indicates buffer is full , Transmit is not yet stated
                      0 - Indicates buffer is empty , Transmit is complete
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI1_Tx_Buf_Full    SSP1STATbits.BF
 
 
/**************************************************************************
Macro       : SPI1_Rx_Buf_Full

Description : macro reads the status of Receive Buffer.
              Returns 1 - Indicates Receive complete
                      0 - Indicates not yet received 
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI1_Rx_Buf_Full    SSP1STATbits.BF

 
#ifndef LIB_BUILD
#define OpenSPI1  		OpenSPI1_v2
#define CloseSPI1  		CloseSPI1_v2
#define MasterputsSPI1  MasterputsSPI1_v2
#define MastergetsSPI1  MastergetsSPI1_v2
#define SlaveputsSPI1  	SlaveputsSPI1_v2
#define SlavegetsSPI1  	SlavegetsSPI1_v2
#define DataRdySPI1  	DataRdySPI1_v2
#define ReadSPI1  		ReadSPI1_v2
#define WriteSPI1  		WriteSPI1_v2
#define ConfigIntSPI1   ConfigIntSPI1_v2
#endif

/* CloseSPI. Disables SPI module */
    void __attribute__ ((section (".libperi"))) CloseSPI1_v2() ;

/* ConfigINtSPI1. Configure Interrupt enable and priorities */
    void __attribute__ ((section(".libperi"))) ConfigIntSPI1_v2(unsigned int config) ;

/* DataRdySPI */
    char __attribute__ ((section (".libperi"))) DataRdySPI1_v2();   

/* SlavegetsSPI.Write string to SSPBUF */
    unsigned int __attribute__ ((section (".libperi")))SlavegetsSPI1_v2(unsigned int length, unsigned char *rdptr,unsigned int spi_data_wait);

/* MastergetsSPI.Write string to SSPBUF */
    unsigned int __attribute__ ((section (".libperi")))MastergetsSPI1_v2(unsigned int length, unsigned char *rdptr);
	
/* OpenSPI */
    void __attribute__ ((section (".libperi")))OpenSPI1_v2(unsigned int config1,unsigned int config2,unsigned int config3,unsigned int config4,unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase);

/* SlaveputsSPI Read string from SSPBUF */
    void __attribute__ ((section (".libperi"))) SlaveputsSPI1_v2(unsigned char *wrptr);
	
/* MasterputsSPI Read string from SSPBUF */
	void __attribute__ ((section (".libperi"))) MasterputsSPI1_v2(unsigned char *wrptr);

/* ReadSPI.Read byte/word from SSPBUF register */
    unsigned int __attribute__ ((section (".libperi"))) ReadSPI1_v2();

/* WriteSPI. Write byte/word to SSPBUF register */
    int __attribute__ ((section (".libperi"))) WriteSPI1_v2(unsigned int data_out);


/* ***** SPI2 ***** */

#if defined (spi_v2_2)
/**************************************************************************
Macro       : EnableIntSPI2
 
Description : Enables SPIx Interrupt
 
Arguments   : None
 
Remarks     : This macro sets SPI Interrupt Enable bit of Interrupt Enable 
		Control register.
***************************************************************************/ 
#define EnableIntSPI2                   (IEC3bits.SSP2IE = 1)

/**************************************************************************
Macro       : DisableIntSPI2

Description : This macro disables the SPI Interrupt
 
Arguments   : None
 
Remarks     : This macro clears SPI Interrupt Enable bit of Interrupt Enable 
		Control register.
***************************************************************************/ 
#define DisableIntSPI2                  (IEC3bits.SSP2IE = 0)

/**************************************************************************
Macro       : SetPriorityIntSPI2(priority)
 
Description : This macro sets the priority level for SPI interrupt
 
Arguments   : priority - This input parameter is the level of interrupt priority.
		* 0 -- Low priority (Default Value)
		* 1 -- High Priority
		
Remarks     : None 
***************************************************************************/
#define SetPriorityIntSPI2(priority)     (IPC12bits.SSP2IP = priority)

/*******************************************************************
Macro       : SPI2_Clear_Intr_Status_Bit

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define SPI2_Clear_Intr_Status_Bit     (IFS3bits.SSP2IF = 0)

/*******************************************************************
Macro       : SPI2_Intr_Status

Description : Macro to Return SPI Interrupt Status  

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define SPI2_Intr_Status     (IFS3bits.SSP2IF)

/**************************************************************************
Macro       : SPI2_Clear_Recv_OV

Description : macro clears Receive Overflow flag
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  SPI2_Clear_Recv_OV    SSP2CON1bits.SSPOV = 0

/*********************************************************************
Macro  	:	CloseSPI2()

Include        : 	spi.h 

Description : 	This Macro turns off the SPI module 

Arguments   : 	None 

Return Value: 	None 

Remarks      : 	This Macro disables the SPI module.
*********************************************************************/
#define  CloseSPI2_Mac()      (SSP2CON1 &=0xDF)

/************************************************************************
Macro :  DataRdySPI2() 

Include            : spi.h 

Description        : This Macro provides status back to user if SSPxBUF
			register contain data. 
                     
Arguments          : None 

Remarks            : This Macro determines if there is any byte to read from
			SSPxBUF register.
*************************************************************************/
#define  DataRdySPI2_Mac()    (SSP2STATbits.BF)

/**************************************************************************
Macro       : getcSPI2

Description : macro is identical to ReadSPI2,#define to ReadSPI2 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  getcSPI2  ReadSPI2

/**************************************************************************
Macro       : putcSPI2

Description : macro is identical to WriteSPI2,#define to WriteSPI2 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  putcSPI2  WriteSPI2

/**************************************************************************
Macro       : SPI2_Tx_Buf_Full

Description : macro reads the status of Transmit Buffer.
              Returns 1 - Indicates buffer is full , Transmit is not yet stated
                      0 - Indicates buffer is empty , Transmit is complete
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI2_Tx_Buf_Full    SSP2STATbits.BF
 
 
/**************************************************************************
Macro       : SPI2_Rx_Buf_Full

Description : macro reads the status of Receive Buffer.
              Returns 1 - Indicates Receive complete
                      0 - Indicates not yet received 
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI2_Rx_Buf_Full    SSP2STATbits.BF


#ifndef LIB_BUILD
#define OpenSPI2  		OpenSPI2_v2
#define CloseSPI2  		CloseSPI2_v2
#define MasterputsSPI2  MasterputsSPI2_v2
#define MastergetsSPI2  MastergetsSPI2_v2
#define SlaveputsSPI2  	SlaveputsSPI2_v2
#define SlavegetsSPI2  	SlavegetsSPI2_v2
#define DataRdySPI2  	DataRdySPI2_v2
#define ReadSPI2  		ReadSPI2_v2
#define WriteSPI2  		WriteSPI2_v2
#define ConfigIntSPI2   ConfigIntSPI2_v2
#endif


/* CloseSPI. Disables SPI module */
    void __attribute__ ((section (".libperi"))) CloseSPI2_v2() ;

/* ConfigINtSPI1. Configure Interrupt enable and priorities */
    void __attribute__ ((section(".libperi"))) ConfigIntSPI2_v2(unsigned int config) ;

/* DataRdySPI */
    char __attribute__ ((section (".libperi"))) DataRdySPI2_v2();   

/* SlavegetsSPI.Write string to SSPBUF */
    unsigned int __attribute__ ((section (".libperi")))SlavegetsSPI2_v2(unsigned int length, unsigned char *rdptr,unsigned int spi_data_wait);

/* MastergetsSPI.Write string to SSPBUF */
    unsigned int __attribute__ ((section (".libperi")))MastergetsSPI2_v2(unsigned int length, unsigned char *rdptr);

/* OpenSPI */
    void __attribute__ ((section (".libperi"))) OpenSPI2_v2(unsigned int config1,unsigned int config2,unsigned int config3,unsigned int config4,unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase);

/* SlaveputsSPI Read string from SSPBUF */
    void __attribute__ ((section (".libperi"))) SlaveputsSPI2_v2(unsigned char *wrptr);
	
/* MasterputsSPI Read string from SSPBUF */
void __attribute__ ((section (".libperi"))) MasterputsSPI2_v2(unsigned char *wrptr);

/* ReadSPI.Read byte/word from SSPBUF register */
    unsigned int __attribute__ ((section (".libperi"))) ReadSPI2_v2();

/* WriteSPI. Write byte/word to SSPBUF register */
    int __attribute__ ((section (".libperi"))) WriteSPI2_v2(unsigned int data_out);

#endif // v2 

#endif

#if defined (spi_v1_1) || defined (spi_v1_2) || defined (spi_v1_3)  || defined (spi_v1_4) || defined (LIB_BUILD)
/**************************************************************************
Macro       : EnableIntSPI1
 
Description : Enables SPIx Transfer Complete Interrupt 
 
Arguments   : None
 
Remarks     : This macro sets SPI Interrupt Enable bit of Interrupt Enable 
              Control register.
***************************************************************************/ 
#define EnableIntSPI1                   (IEC0bits.SPI1IE = 1)

/**************************************************************************
Macro       : DisableIntSPI1

Description : This macro disables the SPI Interrupt
 
Arguments   : None
 
Remarks     : This macro clears SPI Interrupt Enable bit of Interrupt Enable 
              Control register.
***************************************************************************/ 
#define DisableIntSPI1                  (IEC0bits.SPI1IE = 0)

/**************************************************************************
Macro       : SetPriorityIntSPI1(priority)
 
Description : This macro sets the priority level for SPI interrupt
 
Arguments   : Priority - This input parameter is the level of interrupt priority
 
Remarks     : None 
***************************************************************************/
#define SetPriorityIntSPI1(priority)     (IPC2bits.SPI1IP = priority)

/*******************************************************************
Macro       : SPI1_Clear_Intr_Status_Bit

Description : Macro to Clear SPI Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define SPI1_Clear_Intr_Status_Bit     (IFS0bits.SPI1IF = 0)

/**************************************************************************
Macro       : getcSPI1

Description : macro is identical to ReadSPI1,#define to ReadSPI1 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  getcSPI1   ReadSPI1
 
/**************************************************************************
Macro       : putcSPI1

Description : macro is identical to WriteSPI1,#define to WriteSPI1 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  putcSPI1   WriteSPI1
 
 
/**************************************************************************
Macro       : SPI1_Clear_Recv_OV

Description : macro clears Receive Overflow flag
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI1_Clear_Recv_OV    SPI1STATbits.SPIROV = 0
 
/**************************************************************************
Macro       : SPI1_Tx_Buf_Full

Description : macro reads the status of Transmit Buffer.
              Returns 1 - Indicates buffer is full , Transmit is not yet stated
                      0 - Indicates buffer is empty , Transmit is complete
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI1_Tx_Buf_Full    SPI1STATbits.SPITBF
 
 
/**************************************************************************
Macro       : SPI1_Rx_Buf_Full

Description : macro reads the status of Receive Buffer.
              Returns 1 - Indicates Receive complete
                      0 - Indicates not yet received 
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI1_Rx_Buf_Full    SPI1STATbits.SPIRBF

  
/* CloseSPI. Disables SPI module */
    void __attribute__ ((section (".libperi"))) CloseSPI1() ;

/* ConfigINtSPI1. Configure Interrupt enable and priorities */
    void __attribute__ ((section(".libperi"))) ConfigIntSPI1(unsigned int config) ;

/* DataRdySPI */
    char __attribute__ ((section (".libperi"))) DataRdySPI1();   

/* getsSPI.Write string to SPIBUF */
    unsigned int __attribute__ ((section (".libperi")))getsSPI1(unsigned int length, unsigned int *rdptr,unsigned int spi_data_wait);

/* OpenSPI */
    void __attribute__ ((section (".libperi"))) OpenSPI1(unsigned int config1,unsigned int config2,unsigned int config3 );   

/* putsSPI Read string from SPIBUF */
    void __attribute__ ((section (".libperi"))) putsSPI1(unsigned int length, unsigned int *wrptr);

/* ReadSPI.Read byte/word from SPIBUF register */
    unsigned int __attribute__ ((section (".libperi"))) ReadSPI1();

/* WriteSPI. Write byte/word to SPIBUF register */
    void __attribute__ ((section (".libperi"))) WriteSPI1(unsigned int data_out);

#endif /* _SPI_1 */


#if defined (spi_v1_2) || defined (spi_v1_3) || defined (LIB_BUILD)
/**************************************************************************
Macro       : EnableIntSPI2

Description : Enables SPIx Transfer Complete Interrupt 
 
Arguments   : None
 
Remarks     : This macro sets SPI Interrupt Enable bit of Interrupt Enable 
              Control register.
***************************************************************************/ 
#define EnableIntSPI2                    (IEC2bits.SPI2IE = 1)

/**************************************************************************
Macro       : DisableIntSPI2

Description : This macro disables the SPI Interrupt
 
Arguments   : None
 
Remarks     : This macro clears SPI Interrupt Enable bit of Interrupt Enable 
              Control register.
***************************************************************************/ 
#define DisableIntSPI2                  (IEC2bits.SPI2IE = 0)

/**************************************************************************
Macro       : SetPriorityIntSPI2(priority)

Description : This macro sets the priority level for SPI interrupt
 
Arguments   : Priority - This input parameter is the level of interrupt priority
 
Remarks     : None 
***************************************************************************/
#define SetPriorityIntSPI2(priority)     (IPC8bits.SPI2IP = priority)

/*******************************************************************
Macro       : SPI2_Clear_Intr_Status_Bit

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define SPI2_Clear_Intr_Status_Bit     (IFS2bits.SPI2IF = 0)

/**************************************************************************
Macro       : getcSPI2

Description : macro is identical to ReadSPI2,#define to ReadSPI2 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  getcSPI2   ReadSPI2

/**************************************************************************
Macro       : putcSPI2

Description : macro is identical to WriteSPI2,#define to WriteSPI2 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  putcSPI2    WriteSPI2

/**************************************************************************
Macro       : SPI2_Clear_Recv_OV

Description : macro clears Receive Overflow flag
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI2_Clear_Recv_OV    SPI2STATbits.SPIROV = 0
 
/**************************************************************************
Macro       : SPI2_Tx_Buf_Full

Description : macro reads the status of Transmit Buffer.
              Returns 1 - Indicates buffer is full , Transmit is not yet stated
                      0 - Indicates buffer is empty , Transmit is complete
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI2_Tx_Buf_Full    SPI2STATbits.SPITBF
 
 
/**************************************************************************
Macro       : SPI2_Rx_Buf_Full
 
Description : macro reads the status of Receive Buffer.
              Returns 1 - Indicates Receive complete
                      0 - Indicates not yet received 
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI2_Rx_Buf_Full    SPI2STATbits.SPIRBF


/* CloseSPI2.Disables SPI module */
    void  __attribute__ ((section (".libperi")))  CloseSPI2();

/* ConfigINtSPI2. Configures Interrupt enable and priorities */
    void  __attribute__ ((section(".libperi"))) ConfigIntSPI2(unsigned int config);

/* OpenSPI */
    void __attribute__ ((section(".libperi"))) OpenSPI2(unsigned int config1,unsigned int config2, unsigned int config3 );

/* DataRdySPI. Test if SPIBUF register is full */
    char  __attribute__ ((section (".libperi"))) DataRdySPI2();

/* getsSPI.Write string to SPIBUF */
    unsigned int __attribute__ ((section(".libperi"))) getsSPI2(unsigned int length, unsigned int *rdptr, unsigned int spi_data_wait);   

/* putsSPI. Read string from SPIBUF */
    void __attribute__ ((section(".libperi"))) putsSPI2(unsigned int length, unsigned int *wrptr);

/* ReadSPI.Read byte/word from SPIBUF register */
    unsigned int __attribute__ ((section (".libperi"))) ReadSPI2();

/* WriteSPI. Write byte/word to SPIBUF register */
    void __attribute__ ((section(".libperi"))) WriteSPI2( unsigned int data_out);
#endif /* _SPI_2 */


#if defined (spi_v1_3) || defined (LIB_BUILD)
/**************************************************************************
Macro       : EnableIntSPI3

Description : Enables SPIx Transfer Complete Interrupt 
 
Arguments   : None
 
Remarks     : This macro sets SPI Interrupt Enable bit of Interrupt Enable 
              Control register.
***************************************************************************/ 
#define EnableIntSPI3                    (IEC5bits.SPI3IE = 1)

/**************************************************************************
Macro       : DisableIntSPI3

Description : This macro disables the SPI Interrupt
 
Arguments   : None
 
Remarks     : This macro clears SPI Interrupt Enable bit of Interrupt Enable 
              Control register.
***************************************************************************/ 
#define DisableIntSPI3                  (IEC5bits.SPI3IE = 0)

/**************************************************************************
Macro       : SetPriorityIntSPI3(priority)

Description : This macro sets the priority level for SPI interrupt
 
Arguments   : Priority - This input parameter is the level of interrupt priority
 
Remarks     : None 
***************************************************************************/
#define SetPriorityIntSPI3(priority)     (IPC22bits.SPI3IP = priority)

/*******************************************************************
Macro       : SPI3_Clear_Intr_Status_Bit

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define SPI3_Clear_Intr_Status_Bit     (IFS5bits.SPI3IF = 0)

/**************************************************************************
Macro       : getcSPI3

Description : macro is identical to ReadSPI3,#define to ReadSPI3 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  getcSPI3    ReadSPI3

/**************************************************************************
Macro       : putcSPI3

Description : macro is identical to WriteSPI3,#define to WriteSPI3 in spi.h
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
#define  putcSPI3    WriteSPI3

/**************************************************************************
Macro       : SPI3_Clear_Recv_OV

Description : macro clears Receive Overflow flag
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI3_Clear_Recv_OV    SPI3STATbits.SPIROV = 0
 
/**************************************************************************
Macro       : SPI3_Tx_Buf_Full
 
Description : macro reads the status of Transmit Buffer.
              Returns 1 - Indicates buffer is full , Transmit is not yet stated
                      0 - Indicates buffer is empty , Transmit is complete
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI3_Tx_Buf_Full    SPI3STATbits.SPITBF 
 
/**************************************************************************
Macro       : SPI3_Rx_Buf_Full

Description : macro reads the status of Receive Buffer.
              Returns 1 - Indicates Receive complete
                      0 - Indicates not yet received 
 
Arguments   : None
 
Remarks     : None 
***************************************************************************/
 #define  SPI3_Rx_Buf_Full    SPI3STATbits.SPIRBF

     
/* CloseSPI3.Disables SPI module */
    void  __attribute__ ((section (".libperi")))  CloseSPI3(void);

/* ConfigINtSPI3. Configures Interrupt enable and priorities */
    void  __attribute__ ((section(".libperi"))) ConfigIntSPI3(unsigned int config);

/* OpenSPI */
    void __attribute__ ((section(".libperi"))) OpenSPI3(unsigned int config1,unsigned int config2, unsigned int config3 );

/* DataRdySPI. Test if SPIBUF register is full */
    char  __attribute__ ((section (".libperi"))) DataRdySPI3();

/* getsSPI.Write string to SPIBUF */
    unsigned int __attribute__ ((section(".libperi"))) getsSPI3(unsigned int length, unsigned int *rdptr, unsigned int spi_data_wait);   

/* putsSPI. Read string from SPIBUF */
    void __attribute__ ((section(".libperi"))) putsSPI3(unsigned int length, unsigned int *wrptr);

/* ReadSPI.Read byte/word from SPIBUF register */
    unsigned int __attribute__ ((section (".libperi"))) ReadSPI3();

/* WriteSPI. Write byte/word to SPIBUF register */
    void __attribute__ ((section(".libperi"))) WriteSPI3( unsigned int data_out);

//#else
//#warning "Selected device not supports this function"
#endif


#else		/*This preprocessor conditional statement is to avoid unintended linking for unsuppported devices. */
#warning "Does not build on this target"
#endif

#endif  /* __SPI_H */

