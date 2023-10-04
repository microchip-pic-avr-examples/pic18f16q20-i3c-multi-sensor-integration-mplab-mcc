 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

// Software buffer, needed for I3C transactions
uint8_t software_buffer[10]={0,0,0,0,0,0,0,0,0,0};

//Sensor Register array, stores values for relevant ADC configurations and status registers for the two sensors
/*Sensor 1:
 *[0]ADCON0
 *[1]ADCON2
 *[2]ADCON3
 *[3]ADSTAT
 *[4]ADLTHL
 *[5]ADLTHH
 *[6]ADUTHL
 *[7]ADUTHH
 *[8]ADRESL
 *[9]ADRESH
 * 
 * Sensor 2:
 *[10]ADCON0
 *[11]ADCON2
 *[12]ADCON3
 *[13]ADSTAT
 *[14]ADLTHL
 *[15]ADLTHH
 *[16]ADUTHL
 *[17]ADUTHH
 *[18]ADRESL
 *[19]ADRESH
 * */
uint8_t SensorRegister[20]={0x84,0x00,0x10,0x00,0x00,0x00,0x00,0x01,0x00,0x00,
                            0x84,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; 
uint8_t IBIMessage[3];
void TransactionCompleteCallback(struct I3C_TARGET_TRANSACTION_COMPLETE_STATUS *transactionCompleteStatus);
void ThresholdCallback();
int main(void)
{
    SYSTEM_Initialize();
    I3C1_BufferReceive(software_buffer,8);
    I3C1_TransactionCompleteCallbackRegister(TransactionCompleteCallback);
    ADCC_SetADTIInterruptHandler(ThresholdCallback);
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighDisable(); 

    // Enable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowEnable(); 

    // Disable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowDisable(); 

    TMR1_Start(); //Start the Timer for the main loop
    //Main loop, on each Timer1 overflow (1 second period) sets up each sensor from the
    //Sensor Register, reads the value, and stores the ADSTAT and value back into the sensor Register
    while(1)
    {
        if(PIR3bits.TMR1IF==1)
        {
                //first sensor
        ADCON2=SensorRegister[1];
        ADCON3=SensorRegister[2];
        ADCON0=SensorRegister[0];
        ADLTHL=SensorRegister[4];
        ADLTHH=SensorRegister[5];
        ADUTHL=SensorRegister[6];
        ADUTHH=SensorRegister[7];
        ADPCH=0x02; //RA2
        ADCON0bits.GO_nDONE=1;
        while(ADCON0bits.GO_nDONE);
        SensorRegister[3]=ADSTAT;
        SensorRegister[8]=ADRESL;
        SensorRegister[9]=ADRESH;
        //second sensor
        ADCON2=SensorRegister[11];
        ADCON3=SensorRegister[12];
        ADCON0=SensorRegister[10];
        ADLTHL=SensorRegister[14];
        ADLTHH=SensorRegister[15];
        ADUTHL=SensorRegister[16];
        ADUTHH=SensorRegister[17];
        ADPCH=0x0F; //RB7
        ADCON0bits.GO_nDONE=1;
        while(ADCON0bits.GO_nDONE);
        SensorRegister[13]=ADSTAT;
        SensorRegister[18]=ADRESL;
        SensorRegister[19]=ADRESH;
        //clear the timer overflow flag
        PIR3bits.TMR1IF = 0;
        //reload and restart timer
        TMR1_Reload();
        }

    }    
}
void TransactionCompleteCallback(struct I3C_TARGET_TRANSACTION_COMPLETE_STATUS *transactionCompleteStatus)
{
    if(transactionCompleteStatus->numOfBytesReceived==1) 
                //1 byte received=read, load from the sensor register to the I3C transmit buffer
            {
                if(software_buffer[0]>19||software_buffer[0]<0)
                {
                    I3C1_BufferTransmit(&SensorRegister[0],1); //catch case for out-of-bounds, prevent underflow
                }
                else
                {
                    I3C1_BufferTransmit(&SensorRegister[software_buffer[0]],1);
                }
        
            }
            else if(transactionCompleteStatus->numOfBytesReceived==2)
            {   
                //2 bytes received= 2nd byte is loaded into the software buffer
                //based on the address given by the 1st byte
                if(software_buffer[0]>19||software_buffer[0]<0)
                {
                    Nop(); //catch case for out-of-bounds, don't do anything
                }
                else
                {
                    SensorRegister[software_buffer[0]]=software_buffer[1];
                }
            }
}

void ThresholdCallback()
{
    //Threshold interrupt
    if(ADPCH==0x02)
    {
        //ADPCH==0x02; Sensor 1
        IBIMessage[0]=1; //sensor 1
        SensorRegister[2]&=0xF0; //disable threshold interrupt for sensor 1
        
    }
    else if (ADPCH==0x0F)
    {
        IBIMessage[0]=2; //sensor 2
        SensorRegister[12]&=0xF0; //disable threshold interrupt for sensor 2
    }
    else 
    {
        IBIMessage[0]=0xFF; //something has gone wrong
    }
    IBIMessage[1]=ADRESH;  //current ADC results that caused the threshold interrupt
    IBIMessage[2]=ADRESL;
    //In-band interrupt sending message with which sensor and the results
    I3C1_IBIRequest(IBIMessage, 3); 
}