/*
**                        POWER MONITOR
**                   (c) 07.2014 Piotr Zapart
**                      www.hexeguitar.com
**
**********************************************************************/

#include <xc.h>


_FOSCSEL(FNOSC_FRCDIV);			// Select 8 MHz FRC oscillator with divide-by-N (FRCDIV)


_FOSC (	FCKSM_CSECMD & 			// Enable Clock Switching
	OSCIOFNC_ON &			// Clock output = digital IO
	POSCMOD_NONE );			// Primay osc disable

_FWDT (	FWDTEN_OFF &			//watchdog on
	FWPSA_PR32 &			//prescaler /32
	WDTPS_PS2048 );			//postscaler /2048

_FPOR ( BOREN_BOR3 &                    //Brown-out Reset enabled in hardware; SBOREN bit disabled
        PWRTEN_ON &                     //PWRT enabled
        BORV_V27                        //Brown-out Reset set to Highest Voltage (2.7V)
                    );
_FDS    (DSWDTEN_OFF);                   //DSWDT disabled

_FICD (ICS_PGx2);

#include "platform.h"


// ################ FUNCTION DEFINITIONS ##################


/// ### Ialarm calculation ###
uint16_t calc_Ialarm(uint16_t input, uint16_t max)
{
    uint32_t temp32;
    uint16_t temp16;

    temp32 = __builtin_muluu(input,input);      //square for better resolutionx
    temp16 = (uint16_t)(temp32>>10);            //settings

    temp32 = __builtin_muluu(temp16,(max+5));   //scale it 0...IalMax+5
    temp16 = (uint16_t)((temp32>>10)+1);
    
    if (temp16 > max)   return 0;       //Ial = 0 -> alarm shutdown
   // else                return myround((float)temp16);
    else                return temp16;
}

void wait8ms(unsigned int cnt)
{
	delay8ms = cnt;
	while(delay8ms);
}
// ################## DISPLAY DATA ##########################
void display_data(cal_modes cal_mode)
{
        char temp_txt[9];
	static uint8_t blinker;
	blinker++;
        //convert and format float values to ascii    
        f_to_txt(bus_voltage_V,V_txt);
        f_to_txt(current_mA,I_txt);
        
        //convert and format int values to ascii
        int_to_txt(power_mW,4,P_txt);
        int_to_txt(Ialarm,4,Ial_txt);

        switch(cal_mode)
        {
            case CL_OFF:
                      //update OLED display
                        OLED_char_F8x16(0,0,vbus_txt,NORMAL);
                        OLED_char_F8x16(100,0,volts_txt,NORMAL);
                        OLED_char_F8x16(32,0,V_txt,NORMAL);
                        OLED_char_F8x16(0,2,current_txt,NORMAL);
                        OLED_char_F8x16(32,2,I_txt,(status.alarm&&(blinker&_BV(0))));
                        OLED_char_F8x16(100,2,mA_txt,NORMAL);
                        OLED_char_F8x16(0,4,power_txt,NORMAL);
                        OLED_char_F8x16(32,4,P_txt,NORMAL);
                        OLED_char_F8x16(100,4,mW_txt,NORMAL);
                        OLED_char_F8x16(0,6,curr_al_txt,NORMAL);
                        if (status.alarm_sdown)
                        {
                            OLED_char_F8x16(32,6,off_txt,NORMAL);
                            OLED_char_F8x16(100,6,"  ",NORMAL);
                        }
                        else
                        {
                            OLED_char_F8x16(32,6,Ial_txt,NORMAL);
                            OLED_char_F8x16(100,6,mA_txt,NORMAL);
                        }
                        //update 5110 display
                        LCD5110_write_string(3,0,"POWER MONITOR",DISP_NORMAL);
                        LCD5110_write_string(0,2,vbus_txt,DISP_NORMAL);
                        LCD5110_write_string(72,2,volts_txt,DISP_NORMAL);
                        LCD5110_write_string(24,2,V_txt,DISP_NORMAL);
                        LCD5110_write_string(0,3,current_txt,DISP_NORMAL);
                        LCD5110_write_string(24,3,I_txt,(status.alarm&&(blinker&_BV(0))));
                        LCD5110_write_string(72,3,mA_txt,DISP_NORMAL);
                        LCD5110_write_string(0,4,power_txt,DISP_NORMAL);
                        LCD5110_write_string(24,4,P_txt,DISP_NORMAL);
                        LCD5110_write_string(72,4,mW_txt,DISP_NORMAL);
                        LCD5110_write_string(0,5,curr_al_txt,DISP_NORMAL);
                        if (status.alarm_sdown)
                        {
                            LCD5110_write_string(24,5,off_txt,DISP_NORMAL);
                        }
                        else
                        {
                            LCD5110_write_string(24,5,Ial_txt,DISP_NORMAL);
                            LCD5110_write_string(72,5,mA_txt,DISP_NORMAL);
                        }
                        break;
            case CL_RST:
                        
            case CL_RST_CONFIRM:
                        OLED_char_F8x16(16,0,cal_txt,NORMAL);
                        OLED_char_F8x16(32,2,rst_txt,NORMAL);
                        OLED_char_F8x16(0,6,save_txt,NORMAL);
                        OLED_char_F8x16(48,6,yn_txt,NORMAL);
                        LCD5110_write_string(8,0,cal_txt,DISP_NORMAL);
                        LCD5110_write_string(18,2,rst_txt,DISP_NORMAL);
                        LCD5110_write_string(0,5,save_txt,DISP_NORMAL);
                        LCD5110_write_string(30,5,yn_txt,DISP_NORMAL);
                        break;
            case RCL_ON:
                        OLED_char_F8x16(16,0,cal_txt,NORMAL);
                        OLED_char_F8x16(0,2,current_txt,NORMAL);
                        OLED_char_F8x16(32,2,I_txt,NORMAL);
                        OLED_char_F8x16(100,2,mA_txt,NORMAL);
                        OLED_char_F8x16(0,4,iref_txt,NORMAL);
                        OLED_char_F8x16(32,4,he_txt,(blinker&_BV(0)));
                        OLED_char_F8x16(100,4,mA_txt,NORMAL);
                        LCD5110_write_string(12,0,cal_txt,DISP_NORMAL);
                        LCD5110_write_string(0,2,current_txt,DISP_NORMAL);
                        LCD5110_write_string(24,2,I_txt,NORMAL);
                        LCD5110_write_string(72,2,mA_txt,DISP_NORMAL);
                        LCD5110_write_string(0,3,iref_txt,DISP_NORMAL);
                        LCD5110_write_string(24,3,he_txt,(blinker&_BV(0)));
                        LCD5110_write_string(72,3,mA_txt,DISP_NORMAL);
                        break;
            case RCL_CONFIRM:
                        
                        f_to_txt(ref_current_mA,temp_txt);
              
                        OLED_char_F8x16(16,0,cal_txt,NORMAL);

                        OLED_char_F8x16(0,2,current_txt,NORMAL);
                        OLED_char_F8x16(32,2,I_txt,NORMAL);
                        OLED_char_F8x16(100,2,mA_txt,NORMAL);
                        OLED_char_F8x16(0,4,iref_txt,NORMAL);
                        OLED_char_F8x16(32,4,temp_txt,NORMAL);
                        OLED_char_F8x16(100,4,mA_txt,NORMAL);
                        OLED_char_F8x16(0,6,save_txt,NORMAL);
                        OLED_char_F8x16(48,6,yn_txt,NORMAL);

                        LCD5110_write_string(12,0,cal_txt,DISP_NORMAL);
                        LCD5110_write_string(0,2,current_txt,DISP_NORMAL);
                        LCD5110_write_string(24,2,I_txt,NORMAL);
                        LCD5110_write_string(72,2,mA_txt,DISP_NORMAL);
                        LCD5110_write_string(0,3,iref_txt,DISP_NORMAL);
                        LCD5110_write_string(24,3,temp_txt,NORMAL);
                        LCD5110_write_string(72,3,mA_txt,DISP_NORMAL);
                        LCD5110_write_string(0,5,save_txt,DISP_NORMAL);
                        LCD5110_write_string(30,5,yn_txt,DISP_NORMAL);
                        break;          
        }       
}
// ################## DISPLAY WARNING #######################
void display_warning(void)
{
	static uint8_t blinker;
	blinker++;
	OLED_char_F8x16(20,0,warning1_txt,NORMAL);
	OLED_char_F8x16(32,2,warning2_txt,(blinker&_BV(0)));
	OLED_char_F8x16(44,4,warning3_txt,NORMAL);
	OLED_char_F8x16(0,6,warning4_txt,NORMAL);
        OLED_char_F8x16(32,6,warning5_txt,NORMAL);

        LCD5110_write_string(8,0,warning1_txt,DISP_NORMAL);
        LCD5110_write_string(15,2,warning2_txt,(blinker&_BV(0)));
        LCD5110_write_string(13,4,warning3_txt,DISP_NORMAL);
        LCD5110_write_string(49,4,warning4_txt,DISP_NORMAL);
        LCD5110_write_string(8,5,warning5_txt,DISP_NORMAL);

}
// ################## SEND RESULTS VIA UART #######################
uart_data_format get_udata_format(void)
{
    uart1.setup_eep =  eeRead(UART_SETUP_EEP_ADDR);

    if (uart1.setup_eep&_BV(U1_DISP_MODE))
    {
        UART1_send_string_ln(format_raw_txt);
        return RAW;
    }
    else
    {
        UART1_send_string_ln(format_lcd_txt);
        return LCD;
    }
}
void update_uart(uart_data_format mode)
{
    char uart_cnt_txt[9];

    itoa(uart_cnt_txt, (int)uart1.counter, 10);

    uart1.counter++;
    switch(mode)
    {
        case OFF:   break;
        case LCD:
                    UART1_send_string("Count:");
                    UART1_send_string_ln(uart_cnt_txt);
                    UART1_send_string(vbus_txt);
                    UART1_send_string(V_txt);
                    UART1_send_string_ln(volts_txt);
                    UART1_send_string(current_txt);
                    UART1_send_string(I_txt);
                    UART1_send_string_ln(mA_txt);
                    UART1_send_string(power_txt);
                    UART1_send_string(P_txt);
                    UART1_send_string_ln(mW_txt);
                    UART1_send_string(curr_al_txt);
                    if (status.alarm_sdown)
                    {
                        UART1_send_string(off_txt);
                    }
                    else
                    {
                        UART1_send_string(Ial_txt);
                        UART1_send_string(mA_txt);
                    }
                    UART1_send_string("\n");
                    break;
        case RAW:
                    UART1_send_string(uart_cnt_txt);
                    UART1_send_string(V_txt);
                    UART1_send_string(sep_char);
                    UART1_send_string(I_txt);
                    UART1_send_string(sep_char);
                    UART1_send_string(P_txt);
                    UART1_send_string(sep_char);
                    if (status.alarm_sdown)
                    {
                        UART1_send_string(off_txt);
                    }
                    else
                    {
                        UART1_send_string(Ial_txt);
                    }
                    break;
    }
}

// ### send reverse power jacks warning ####
void uart_warning(void)
{
    UART1_send_string(warning1_txt);
    UART1_send_string(" ");
    UART1_send_string_ln(warning2_txt);
    UART1_send_string(warning3_txt);
    UART1_send_string(" ");
    UART1_send_string(warning4_txt);
    UART1_send_string(" ");
    UART1_send_string_ln(warning5_txt);
}
// ### decode incoming UART commands ###
uint8_t decode_char(uint16_t err_data)
{
    char data;
    static uint8_t data_complete;
    uint8_t eep_changed = 0;

    if (err_data == UART_NO_DATA)    return 0;

    status.error = (err_data&0xFF00)>>8;
    data = (char) (err_data&0x00FF);

    cmd_buffer[cmdbuf_index++] = data;

    if (data=='\n')
    {
        data_complete = 1;
    }

    if (cmdbuf_index>8) cmdbuf_index = 0;
    
    
    if (data_complete)    
    {

            switch (status.cal_mode)
            {
                case CL_OFF:
                            if (!strncmp(cmd_buffer,"lcd",3))
                            {
                                if (uart1.format != LCD)
                                {
                                    uart1.format = LCD;
                                    uart1.setup_eep = 0;
                                    eep_changed |= _BV(U1_DISP_MODE);
                                }

                                UART1_send_string(format_lcd_txt);
                                flush_cmd_buff();
                            }
                            if (!strncmp(cmd_buffer,"raw",3))
                            {
                                if(uart1.format != RAW)
                                {
                                    uart1.format = RAW;
                                    uart1.setup_eep = 1;
                                    eep_changed |= _BV(U1_DISP_MODE);
                                }
                                UART1_send_string(format_raw_txt);
                                flush_cmd_buff();
                            }
                            if (!strncmp(cmd_buffer,"stop",4))
                            {
                                uart1.updater = 0;
                                UART1_send_string("UART UPDATE STOP");
                                flush_cmd_buff();
                            }
                            if (!strncmp(cmd_buffer,"start",5))
                            {
                                uart1.updater = 1;
                                UART1_send_string("UART UPDATE START");
                                flush_cmd_buff();
                            }
                           if (!strncmp(cmd_buffer,"rstcnt",5))
                            {
                                uart1.counter = 0;
                                UART1_send_string("RESET COUNTER");
                                flush_cmd_buff();
                            }
                           if (!strncmp(cmd_buffer,"getcnt",6))
                            {
                                itoa(cmd_buffer, (int)(uart1.counter), 10);
                                UART1_send_string("COUNTER VALUE = ");
                                UART1_send_string(cmd_buffer);
                                flush_cmd_buff();
                            }
                            if (!strncmp(cmd_buffer,"calrst",6))
                            {
                                OLED_fill_screen(0x00);      //cls OLED
                                LCD5110_clear();            //cls LCD
                                status.cal_mode = CL_RST;
                                UART1_send_string_ln("INA219 Calibration mode");
                                UART1_send_string_ln("Restore to default value: 8192");
                                UART1_send_string(save_txt);
                                UART1_send_string_ln(yn_txt);
                                status.cal_mode = CL_RST_CONFIRM;
                                flush_cmd_buff();
                            }
                            if (!strncmp(cmd_buffer,"recal",5))
                            {
                                OLED_fill_screen(0x00);      //cls OLED
                                LCD5110_clear();            //cls LCD
                                status.cal_mode = RCL_ON;
                                UART1_send_string_ln("INA219 REcalibration mode");
                                UART1_send_string_ln("(type exit to cancel)");
                                UART1_send_string_ln(enter_I_txt);
                                flush_cmd_buff();
                            }
                            break;

                case RCL_ON:
                                    // exit command, calibration cancel
                                    if (!strncmp(cmd_buffer,"exit",4))
                                    {
                                        OLED_fill_screen(0x00);      //cls OLED
                                        LCD5110_clear();            //cls LCD
                                        status.cal_mode = CL_OFF;
                                        UART1_send_string_ln("INA219 Recalibration");
                                        UART1_send_string_ln("cancelled");
                                        flush_cmd_buff();
                                        break;
                                    }

                                    //wait for refernce current
                                    ref_current_mA = atof(cmd_buffer);
                                    if (ref_current_mA && (ref_current_mA<=MAX_I_ALARM))
                                    {
                                       f_to_txt(ref_current_mA,cmd_buffer);
                                       UART1_send_string(iref_txt);
                                       UART1_send_string(cmd_buffer);
                                       UART1_send_string_ln(mA_txt);
                                       ina219_calValue_new = calc_new_cal( ref_current_mA,
                                                                current_mA,
                                                                ina219_calValue);
                                       itoa(cmd_buffer, (int)ina219_calValue, 10);
                                       UART1_send_string(old_txt);
                                       UART1_send_string(inacal_txt);
                                       UART1_send_string_ln(cmd_buffer);

                                       itoa(cmd_buffer, (int)ina219_calValue_new, 10);
                                       UART1_send_string(new_txt);
                                       UART1_send_string(inacal_txt);
                                       UART1_send_string_ln(cmd_buffer);
                                       UART1_send_string(save_txt);
                                       UART1_send_string_ln(yn_txt);
                                       status.cal_mode = RCL_CONFIRM;
                                    }
                                    else
                                    {
                                        UART1_send_string(error_txt);
                                        UART1_send_string(iref_txt);
                                        UART1_send_string_ln(err_oor_txt);
                                    }

                                    flush_cmd_buff();
                                    data_complete = 0;
                                    break;
                
               case CL_RST_CONFIRM:  
                                    ina219_calValue_new = 8192;
                                                    
                case RCL_CONFIRM:
                                    if (!strncmp(cmd_buffer,"y",1))
                                    {
                                        eeWrite(INA219_CALC_EEP_ADDR,ina219_calValue_new); //store in eeprom
                                        INA219_calibrate(ina219_calValue_new);
                                        UART1_send_string_ln("INA219 Calibration");
                                        UART1_send_string_ln("updated");
                                        OLED_fill_screen(0x00);      //cls OLED
                                        LCD5110_clear();            //cls LCD
                                        status.cal_mode = CL_OFF;
                                        flush_cmd_buff();
                                    }
                                    if (!strncmp(cmd_buffer,"n",1))
                                    {
                                        OLED_fill_screen(0x00);      //cls OLED
                                        LCD5110_clear();            //cls LCD
                                        UART1_send_string_ln("INA219 Calibration");
                                        UART1_send_string_ln("calcelled");
                                        status.cal_mode = CL_OFF;
                                        flush_cmd_buff();
                                    }
                                    break;
            }
            if (!strncmp(cmd_buffer,"getcal",6))
            {
                itoa(cmd_buffer, (int)ina219_calValue, 10);
                UART1_send_string("INA219 CAL = ");
                UART1_send_string(cmd_buffer);
                flush_cmd_buff();
            }

            flush_cmd_buff();
            data_complete = 0;
    }
    // ### save eeprom data ###
    if (eep_changed & _BV(U1_DISP_MODE))           //save the UART DISP MODE
    {
        eep_changed &= ~_BV(U1_DISP_MODE);
        eeWrite(UART_SETUP_EEP_ADDR, uart1.setup_eep);
    }
    return 0;
}
// ################ FLUSH CMD BUFFER ##################
void flush_cmd_buff(void)
{
    uint8_t i;
    for (i=0;i<9;i++)
    {
        cmd_buffer[i] = '*';
    }
    cmdbuf_index = 0;
}
// ################ CALC NEW CALIBRATION CONSTANT #####
uint16_t calc_new_cal(float ref_current, float m_current, uint16_t old_cal)
{
    float i;
    i = (ref_current/m_current)* old_cal;

    return (uint16_t) i;
}

// ################ STARTUP INIT ##################
void startup(void)
{
    //initilize variables
    status.error = NO_ERROR;
    status.cal_mode = CL_OFF;
    uart1.counter = 0;
    uart1.update_clock = UART_UPDATE_RATE_MS;

    hardware_init();

    ///OLED
    OLED_init();        //initalize the OLED display
    LCD5110_init(LCD_CONTRAST);         //initalize the 5110 LCD

    INA219_configure(       INA219_RANGE_32V,
                            INA219_GAIN_320MV,
                            INA219_BUS_RES_12BIT,
                            INA219_SHUNT_RES_12BIT_128S,
                            INA219_MODE_SHUNT_BUS_CONT);

    INA219_calibrate(eeRead(INA219_CALC_EEP_ADDR));

    OLED_fill_screen(0x00);      //cls OLED
    LCD5110_clear();            //cls LCD
    BUZZER = BUZZER_OFF;
    OLED_draw_BMP(0,0,128,8,start_screen);

    LCD5110_write_string(3,0,pwmon_txt,DISP_NORMAL);
    LCD5110_write_string(22,2,version,DISP_NORMAL);
    LCD5110_write_string(0,5,link_txt,DISP_NORMAL);

    UART1_send_string_ln(pwmon_txt);
    UART1_send_string_ln(version);
    UART1_send_string_ln(link_txt);

    uart1.format = get_udata_format();

    UART1_send_string("UPDATE STOPPED");
    ClrWdt();
    wait8ms(150);
    OLED_fill_screen(0x00);
    LCD5110_clear();

}
// ###########################################################
// ######################### MAIN ############################
// ###########################################################
int main(void)
{
   startup();

   while(1)
   {
        ClrWdt();

        wait8ms(8);		//INA219 averaging time

        current_mA = INA219_getCurrent_mA();
        bus_voltage_V = INA219_getBusVoltage_V();
        power_mW = INA219_getPower_mW();

        Ialarm = calc_Ialarm(Ialarm_adc, MAX_I_ALARM);

        // check if the alarm is switched on
        if (Ialarm)     status.alarm_sdown = 0;
        else            status.alarm_sdown = 1;
        // check if the current > set threshold
        if ((current_mA > Ialarm) && !status.alarm_sdown)
                        status.alarm = 1;
        else		status.alarm = 0;

        if(current_mA < -2.0) // negative current, jacks reversed!!!
        {
            display_warning();
            status.pwr_rev = 1;
            uart1.updater = 1;
        }
        else
        {
            display_data(status.cal_mode);
            status.pwr_rev = 0;
        }
        if (uart1.updater && !(uart1.update_clock))
        {
            if (status.pwr_rev) uart_warning();
            else                update_uart(uart1.format);
            uart1.update_clock = UART_UPDATE_RATE_MS;
        }
        // check if there is anything in the UART RX buffer
        decode_char(UART1_get_char());

   }    // loop end
}       //main end

// ###########################################################
// ######################### ISRs ############################
// ###########################################################


// ###### ADC ######
void __attribute__((interrupt,no_auto_psv)) _ADC1Interrupt( void )
{
	IFS0bits.AD1IF = 0;			//clear flag
	static volatile uint32_t avg;           //simple lowpass filter
	avg -= avg>>8;
	avg += ADC1BUF0+1;
	Ialarm_adc = (uint16_t) (avg>>8);
}

// ################## TIMER 3 Interrupt #######################
/*
	8ms 
	delays, beeper pulses
*/

void __attribute__((interrupt,no_auto_psv)) _T3Interrupt( void )
{
	IFS0bits.T3IF = 0;					  //clear flag
	uint16_t temp16;
	
	temp16 = delay8ms;
	if (temp16) temp16--;
	delay8ms = temp16;

        temp16 = uart1.update_clock;
        if (temp16) temp16--;
        uart1.update_clock = temp16;
	
	temp16 = beeper;
	temp16++;
	if ((temp16 & _BV(6)) && (status.alarm || status.pwr_rev))
		BUZZER = BUZZER_ON;
	else    BUZZER = BUZZER_OFF;
	
	beeper = temp16;
}


