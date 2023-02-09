/**
  ADC1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.h

  @Summary
    This is the generated header file for the ADC1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for ADC1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  dsPIC33CH128MP503
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _ADC1_H
#define _ADC1_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Data Types
*/

/** Scan Selected Macro Definition
 
 @Summary 
   Defines the scan option selection done for the shared channels.
 
 @Description
   This macro defines the scan option selection done for the shared channels.
 
 Remarks:
   None
 */
#define ADC1_SCAN_MODE_SELECTED true

/** ADC1 Channel Definition
 
 @Summary 
   Defines the channels selected.
 
 @Description
   This routine defines the channels that are available for the module to use.
 
 Remarks:
   None
 */
typedef enum 
{
    channel_AN0,//Channel Name:AN0   Assigned to:Shared Channel
    channel_AN1,//Channel Name:AN1   Assigned to:Shared Channel
    channel_AN2,//Channel Name:AN2   Assigned to:Shared Channel
    channel_AN3,//Channel Name:AN3   Assigned to:Shared Channel
    channel_AN4,//Channel Name:AN4   Assigned to:Shared Channel
    channel_AN7,//Channel Name:AN7   Assigned to:Shared Channel
    channel_AN9,//Channel Name:AN9   Assigned to:Shared Channel
    channel_AN12,//Channel Name:AN12   Assigned to:Shared Channel
    channel_AN13,//Channel Name:AN13   Assigned to:Shared Channel
    channel_AN14,//Channel Name:AN14   Assigned to:Shared Channel
    channel_AN16,//Channel Name:AN16   Assigned to:Shared Channel
    channel_AN17,//Channel Name:AN17   Assigned to:Shared Channel
    channel_AN18,//Channel Name:AN18   Assigned to:Shared Channel
    channel_AN19,//Channel Name:AN19   Assigned to:Shared Channel
    channel_AN20,//Channel Name:AN20   Assigned to:Shared Channel
} ADC1_CHANNEL;

/**
  Section: Interface Routines
*/

/**
  @Summary
    Initializes ADC1 module.

  @Description
    This routine initializes ADC1 module, using the given initialization data. 
    This routine must be called before any other ADC routine is called. 

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None

  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
*/
void ADC1_Initialize (void);

/**
  @Summary
    Enables the ADC1 module.

  @Description
    This routine is used to enable the ADC1 module.
 
  @Preconditions
    ADC1_Initialize function should have been called 
    before calling this function.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
*/
inline static void ADC1_Enable(void)
{
   ADCON1Lbits.ADON = 1;
}

/**
  @Summary
    Disables the ADC1 module.

  @Description
    This routine is used to disable the ADC1 module.
 
  @Preconditions
    ADC1_Initialize function should have been called 
    before calling this function.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
*/
inline static void ADC1_Disable(void)
{
   ADCON1Lbits.ADON = 0;
}

/**
  @Summary
    Enables software common trigger.

  @Description
    This routine is used to enable the ADC1 software common trigger.
 
  @Preconditions
    ADC1_Initialize function should have been called 
    before calling this function.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
*/

inline static void ADC1_SoftwareTriggerEnable(void)
{
   ADCON3Lbits.SWCTRG = 1;
}

/**
  @Summary
    Disables software common trigger.

  @Description
    This routine is used to disable the ADC1 software common trigger.
 
  @Preconditions
    ADC1_Initialize function should have been called 
    before calling this function.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
*/
inline static void ADC1_SoftwareTriggerDisable(void)
{
   ADCON3Lbits.SWCTRG = 0;
}

/**
  @Summary
    Allows selection of a channel for conversion.

  @Description
    This routine is used to select desired channel for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.

  @Param
    channel - Channel for conversion

  @Returns
    None
  
  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
*/
inline static void ADC1_ChannelSelect( ADC1_CHANNEL channel )
{
    /*This routine does not have any implementation since 
            *Shared channels are selected from UI.
            *Dedicated channels are selected from UI.
    */
}

/**
  @Summary
    Returns the conversion value for the channel selected.

  @Description
    This routine is used to get the analog to digital converted value for a 
    specific channel.
 
  @Preconditions
    This routine returns the conversion value only after the conversion is complete. 
    Conversion completion status can be checked using ADC1_IsConversionComplete(channel)
    routine.

  @Param
    channel - Selected channel
   
  @Returns
   Returns the analog to digital converted value
  
  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
 */
inline static uint16_t ADC1_ConversionResultGet( ADC1_CHANNEL channel )
{
    uint16_t result;

    switch(channel)
    {
        case channel_AN0:
                result = ADCBUF0;
                break;
        case channel_AN1:
                result = ADCBUF1;
                break;
        case channel_AN2:
                result = ADCBUF2;
                break;
        case channel_AN3:
                result = ADCBUF3;
                break;
        case channel_AN4:
                result = ADCBUF4;
                break;
        case channel_AN7:
                result = ADCBUF7;
                break;
        case channel_AN9:
                result = ADCBUF9;
                break;
        case channel_AN12:
                result = ADCBUF12;
                break;
        case channel_AN13:
                result = ADCBUF13;
                break;
        case channel_AN14:
                result = ADCBUF14;
                break;
        case channel_AN16:
                result = ADCBUF16;
                break;
        case channel_AN17:
                result = ADCBUF17;
                break;
        case channel_AN18:
                result = ADCBUF18;
                break;
        case channel_AN19:
                result = ADCBUF19;
                break;
        case channel_AN20:
                result = ADCBUF20;
                break;
        default:
                break;
    }
    return result;
}

/**
  @Summary
    Returns the status of conversion.

  @Description
    This routine is used to determine if conversion is completed. When conversion
    is complete the routine returns true otherwise false.
 
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.

  @Param
    channel - Selected channel
 
  @Returns
    true - Conversion is complete.
    false - Conversion is not complete.
  
  @Example
    <code>
        int conversion,i=0;
        ADC1_Initialize();

        ADC1_Enable();
        ADC1_ChannelSelect(channel);
        ADC1_SoftwareTriggerEnable();
        //Provide Delay
        for(i=0;i <1000;i++)
        {
        }
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(channel));
        conversion = ADC1_ConversionResultGet(channel);
        ADC1_Disable(); 
    </code>
 */
inline static bool ADC1_IsConversionComplete(ADC1_CHANNEL channel)
{
    bool status;

    switch(channel)
    {
        case channel_AN0:
                status = ADSTATLbits.AN0RDY;
                break;
        case channel_AN1:
                status = ADSTATLbits.AN1RDY;
                break;
        case channel_AN2:
                status = ADSTATLbits.AN2RDY;
                break;
        case channel_AN3:
                status = ADSTATLbits.AN3RDY;
                break;
        case channel_AN4:
                status = ADSTATLbits.AN4RDY;
                break;
        case channel_AN7:
                status = ADSTATLbits.AN7RDY;
                break;
        case channel_AN9:
                status = ADSTATLbits.AN9RDY;
                break;
        case channel_AN12:
                status = ADSTATLbits.AN12RDY;
                break;
        case channel_AN13:
                status = ADSTATLbits.AN13RDY;
                break;
        case channel_AN14:
                status = ADSTATLbits.AN14RDY;
                break;
        case channel_AN16:
                status = ADSTATHbits.AN16RDY;
                break;
        case channel_AN17:
                status = ADSTATHbits.AN17RDY;
                break;
        case channel_AN18:
                status = ADSTATHbits.AN18RDY;
                break;
        case channel_AN19:
                status = ADSTATHbits.AN19RDY;
                break;
        case channel_AN20:
                status = ADSTATHbits.AN20RDY;
                break;
        default:
                break;
    }

    return status;
}

/**
  @Summary
    Enables interrupts.

  @Description
    This routine is used to enable the ADC1 interrupt.
 
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        ADC1_InterruptEnable(); 
    </code>
*/
inline static void ADC1_InterruptEnable(void)
{
    IEC5bits.ADCIE = 1;
}

/**
  @Summary
    Disables interrupts.

  @Description
    This routine is used to disable the ADC1 interrupt.
 
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        ADC1_InterruptDisable(); 
    </code>
*/
inline static void ADC1_InterruptDisable(void)
{
    IEC5bits.ADCIE = 0;
}

/**
  @Summary
    Clears interrupt flag

  @Description
    This routine is used to clear the interrupt flag manually.
 
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        ADC1_InterruptFlagClear(); 
    </code>
*/
inline static void ADC1_InterruptFlagClear(void)
{
    IFS5bits.ADCIF = 0;
}

/**
  @Summary
    Allows selection of priority for interrupt.

  @Description
    This routine is used to select desired priority for interrupt.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        uint16_t priorityValue;
        priorityValue = 0x002;
 
        ADC1_InterruptPrioritySet(priorityValue); 
    </code>
*/
inline static void ADC1_InterruptPrioritySet( uint16_t priorityValue )
{
    IPC22bits.ADCIP = 0x7 & priorityValue;
}

/**
  @Summary
    ADC1 Common callback routine.

  @Description
    This routine is a ADC1 Common callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_SetCommonInterruptHandler(&ADC1_CallBack);
    </code>
*/
void ADC1_CallBack(void);

/**
  @Summary
    Assigns a function pointer with a ADC1 Common callback address.

  @Description
    This routine assigns a function pointer with a ADC1 Common callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_SetCommonInterruptHandler(&ADC1_CallBack);
    </code>
*/
void ADC1_SetCommonInterruptHandler(void* handler);

/**
  @Summary
    Polled implementation

  @Description
    This routine is used to implement the tasks for polled implementations.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Param
    None

  @Returns 
    None
 
  @Example
    <code>    
        ADC1_Tasks();
    </code>
*/
void ADC1_Tasks(void);

/**
  @Summary
    Enables individual channel interrupt.

  @Description
    This routine is used to enable the ADC1 individual channel
    interrupt.
 
  @Preconditions
    None.

  @Param
    channel - Selected channel

  @Returns
    None.

  @Example
    <code>
        ADC1_IndividualChannelInterruptEnable(channel); 
    </code>
*/
inline static void ADC1_IndividualChannelInterruptEnable(ADC1_CHANNEL channel)
{
    switch(channel)
    {
        case channel_AN0:
                IEC5bits.ADCAN0IE = 1;
                break;
        case channel_AN1:
                IEC5bits.ADCAN1IE = 1;
                break;
        case channel_AN2:
                IEC5bits.ADCAN2IE = 1;
                break;
        case channel_AN3:
                IEC5bits.ADCAN3IE = 1;
                break;
        case channel_AN4:
                IEC5bits.ADCAN4IE = 1;
                break;
        case channel_AN7:
                IEC6bits.ADCAN7IE = 1;
                break;
        case channel_AN9:
                IEC6bits.ADCAN9IE = 1;
                break;
        case channel_AN12:
                IEC6bits.ADCAN12IE = 1;
                break;
        case channel_AN13:
                IEC6bits.ADCAN13IE = 1;
                break;
        case channel_AN14:
                IEC6bits.ADCAN14IE = 1;
                break;
        case channel_AN16:
                IEC6bits.ADCAN16IE = 1;
                break;
        case channel_AN17:
                IEC6bits.ADCAN17IE = 1;
                break;
        case channel_AN18:
                IEC6bits.ADCAN18IE = 1;
                break;
        case channel_AN19:
                IEC6bits.ADCAN19IE = 1;
                break;
        case channel_AN20:
                IEC6bits.ADCAN20IE = 1;
                break;
        default:
                break;
    }
}

/**
  @Summary
    Disables individual channel interrupt.

  @Description
    This routine is used to disable the ADC1 individual channel
    interrupt.
 
  @Preconditions
    None.

  @Param
    channel - Selected channel

  @Returns
    None.

  @Example
    <code>
        ADC1_IndividualChannelInterruptDisable(channel); 
    </code>
*/
inline static void ADC1_IndividualChannelInterruptDisable(ADC1_CHANNEL channel)
{
    switch(channel)
    {
        case channel_AN0:
                IEC5bits.ADCAN0IE = 0;
                break;
        case channel_AN1:
                IEC5bits.ADCAN1IE = 0;
                break;
        case channel_AN2:
                IEC5bits.ADCAN2IE = 0;
                break;
        case channel_AN3:
                IEC5bits.ADCAN3IE = 0;
                break;
        case channel_AN4:
                IEC5bits.ADCAN4IE = 0;
                break;
        case channel_AN7:
                IEC6bits.ADCAN7IE = 0;
                break;
        case channel_AN9:
                IEC6bits.ADCAN9IE = 0;
                break;
        case channel_AN12:
                IEC6bits.ADCAN12IE = 0;
                break;
        case channel_AN13:
                IEC6bits.ADCAN13IE = 0;
                break;
        case channel_AN14:
                IEC6bits.ADCAN14IE = 0;
                break;
        case channel_AN16:
                IEC6bits.ADCAN16IE = 0;
                break;
        case channel_AN17:
                IEC6bits.ADCAN17IE = 0;
                break;
        case channel_AN18:
                IEC6bits.ADCAN18IE = 0;
                break;
        case channel_AN19:
                IEC6bits.ADCAN19IE = 0;
                break;
        case channel_AN20:
                IEC6bits.ADCAN20IE = 0;
                break;
        default:
                break;
    }
}

/**
  @Summary
    Clears individual channel interrupt flag

  @Description
    This routine is used to clear the individual channel interrupt flag manually.
 
  @Preconditions
    None.

  @Param
    channel - Selected channel

  @Returns
    None.

  @Example
    <code>
        ADC1_IndividualChannelInterruptFlagClear(channel); 
    </code>
*/
inline static void ADC1_IndividualChannelInterruptFlagClear(ADC1_CHANNEL channel)
{
    switch(channel)
    {
        case channel_AN0:
                IFS5bits.ADCAN0IF = 0;
                break;
        case channel_AN1:
                IFS5bits.ADCAN1IF = 0;
                break;
        case channel_AN2:
                IFS5bits.ADCAN2IF = 0;
                break;
        case channel_AN3:
                IFS5bits.ADCAN3IF = 0;
                break;
        case channel_AN4:
                IFS5bits.ADCAN4IF = 0;
                break;
        case channel_AN7:
                IFS6bits.ADCAN7IF = 0;
                break;
        case channel_AN9:
                IFS6bits.ADCAN9IF = 0;
                break;
        case channel_AN12:
                IFS6bits.ADCAN12IF = 0;
                break;
        case channel_AN13:
                IFS6bits.ADCAN13IF = 0;
                break;
        case channel_AN14:
                IFS6bits.ADCAN14IF = 0;
                break;
        case channel_AN16:
                IFS6bits.ADCAN16IF = 0;
                break;
        case channel_AN17:
                IFS6bits.ADCAN17IF = 0;
                break;
        case channel_AN18:
                IFS6bits.ADCAN18IF = 0;
                break;
        case channel_AN19:
                IFS6bits.ADCAN19IF = 0;
                break;
        case channel_AN20:
                IFS6bits.ADCAN20IF = 0;
                break;
        default:
                break;
    }
}

/**
  @Summary
    ADC1 channel_AN0 callback routine.

  @Description
    This routine is a ADC1 channel_AN0 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN0InterruptHandler(&ADC1_channel_AN0_CallBack);
    </code>
*/
void ADC1_channel_AN0_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN0 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN0 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN0InterruptHandler(&ADC1_channel_AN0_CallBack);
    </code>
*/
void ADC1_Setchannel_AN0InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN1 callback routine.

  @Description
    This routine is a ADC1 channel_AN1 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN1InterruptHandler(&ADC1_channel_AN1_CallBack);
    </code>
*/
void ADC1_channel_AN1_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN1 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN1 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN1InterruptHandler(&ADC1_channel_AN1_CallBack);
    </code>
*/
void ADC1_Setchannel_AN1InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN2 callback routine.

  @Description
    This routine is a ADC1 channel_AN2 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN2InterruptHandler(&ADC1_channel_AN2_CallBack);
    </code>
*/
void ADC1_channel_AN2_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN2 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN2 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN2InterruptHandler(&ADC1_channel_AN2_CallBack);
    </code>
*/
void ADC1_Setchannel_AN2InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN3 callback routine.

  @Description
    This routine is a ADC1 channel_AN3 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN3InterruptHandler(&ADC1_channel_AN3_CallBack);
    </code>
*/
void ADC1_channel_AN3_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN3 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN3 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN3InterruptHandler(&ADC1_channel_AN3_CallBack);
    </code>
*/
void ADC1_Setchannel_AN3InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN4 callback routine.

  @Description
    This routine is a ADC1 channel_AN4 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN4InterruptHandler(&ADC1_channel_AN4_CallBack);
    </code>
*/
void ADC1_channel_AN4_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN4 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN4 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN4InterruptHandler(&ADC1_channel_AN4_CallBack);
    </code>
*/
void ADC1_Setchannel_AN4InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN7 callback routine.

  @Description
    This routine is a ADC1 channel_AN7 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN7InterruptHandler(&ADC1_channel_AN7_CallBack);
    </code>
*/
void ADC1_channel_AN7_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN7 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN7 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN7InterruptHandler(&ADC1_channel_AN7_CallBack);
    </code>
*/
void ADC1_Setchannel_AN7InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN9 callback routine.

  @Description
    This routine is a ADC1 channel_AN9 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN9InterruptHandler(&ADC1_channel_AN9_CallBack);
    </code>
*/
void ADC1_channel_AN9_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN9 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN9 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN9InterruptHandler(&ADC1_channel_AN9_CallBack);
    </code>
*/
void ADC1_Setchannel_AN9InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN12 callback routine.

  @Description
    This routine is a ADC1 channel_AN12 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN12InterruptHandler(&ADC1_channel_AN12_CallBack);
    </code>
*/
void ADC1_channel_AN12_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN12 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN12 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN12InterruptHandler(&ADC1_channel_AN12_CallBack);
    </code>
*/
void ADC1_Setchannel_AN12InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN13 callback routine.

  @Description
    This routine is a ADC1 channel_AN13 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN13InterruptHandler(&ADC1_channel_AN13_CallBack);
    </code>
*/
void ADC1_channel_AN13_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN13 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN13 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN13InterruptHandler(&ADC1_channel_AN13_CallBack);
    </code>
*/
void ADC1_Setchannel_AN13InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN14 callback routine.

  @Description
    This routine is a ADC1 channel_AN14 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN14InterruptHandler(&ADC1_channel_AN14_CallBack);
    </code>
*/
void ADC1_channel_AN14_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN14 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN14 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN14InterruptHandler(&ADC1_channel_AN14_CallBack);
    </code>
*/
void ADC1_Setchannel_AN14InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN16 callback routine.

  @Description
    This routine is a ADC1 channel_AN16 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN16InterruptHandler(&ADC1_channel_AN16_CallBack);
    </code>
*/
void ADC1_channel_AN16_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN16 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN16 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN16InterruptHandler(&ADC1_channel_AN16_CallBack);
    </code>
*/
void ADC1_Setchannel_AN16InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN17 callback routine.

  @Description
    This routine is a ADC1 channel_AN17 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN17InterruptHandler(&ADC1_channel_AN17_CallBack);
    </code>
*/
void ADC1_channel_AN17_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN17 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN17 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN17InterruptHandler(&ADC1_channel_AN17_CallBack);
    </code>
*/
void ADC1_Setchannel_AN17InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN18 callback routine.

  @Description
    This routine is a ADC1 channel_AN18 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN18InterruptHandler(&ADC1_channel_AN18_CallBack);
    </code>
*/
void ADC1_channel_AN18_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN18 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN18 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN18InterruptHandler(&ADC1_channel_AN18_CallBack);
    </code>
*/
void ADC1_Setchannel_AN18InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN19 callback routine.

  @Description
    This routine is a ADC1 channel_AN19 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN19InterruptHandler(&ADC1_channel_AN19_CallBack);
    </code>
*/
void ADC1_channel_AN19_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN19 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN19 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN19InterruptHandler(&ADC1_channel_AN19_CallBack);
    </code>
*/
void ADC1_Setchannel_AN19InterruptHandler(void* handler);

/**
  @Summary
    ADC1 channel_AN20 callback routine.

  @Description
    This routine is a ADC1 channel_AN20 callback function.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN20InterruptHandler(&ADC1_channel_AN20_CallBack);
    </code>
*/
void ADC1_channel_AN20_CallBack(uint16_t adcVal);

/**
  @Summary
    Assigns a function pointer with a ADC1 channel_AN20 callback address.

  @Description
    This routine assigns a function pointer with a ADC1 channel_AN20 callback address.
  
  @Preconditions
    None.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ADC1_Setchannel_AN20InterruptHandler(&ADC1_channel_AN20_CallBack);
    </code>
*/
void ADC1_Setchannel_AN20InterruptHandler(void* handler);





/**
  @Summary
    Enables power for ADC1 shared Core

  @Description
    This routine is used to set the analog and digital power for ADC1 shared Core.
 
  @Preconditions
    None.

  @Param
    None

  @Returns
    None.

  @Example
    Refer to ADC1_Initialize() for an example
*/
void ADC1_SharedCorePowerEnable(void);



/*******************************************************************************

  !!! Deprecated Definitions and APIs !!!
  !!! These functions will not be supported in future releases !!!

*******************************************************************************/
/** ADC1 Data Format Type Definition
 
 @Summary 
   Defines the data format types available
 
 @Description
   This routine defines the data format types that are available for the module 
   to use.
 
 Remarks:
   None
 */
typedef enum 
{
    ADC1_FORM_INT   = 0, /* Integer */
    ADC1_FORM_FRACT = 1  /* Fraction */
} ADC1_FORM_TYPE;

/** ADC1 Resolution Type Definition
 
 @Summary 
   Defines the resolution types available
 
 @Description
   This routine defines the resolution types that are available for the module 
   to use.
 
 Remarks:
   None
 */
typedef enum 
{
    ADC1_RESOLUTION_6_BIT    = 0, /* 6-bit ADC1 operation */
    ADC1_RESOLUTION_8_BIT    = 1, /* 8-bit ADC1 operation */
    ADC1_RESOLUTION_10_BIT   = 0, /* 10-bit ADC1 operation */
    ADC1_RESOLUTION_12_BIT   = 1  /* 12-bit ADC1 operation */
} ADC1_RESOLUTION_TYPE;

/**
  @Summary
    Allows software level-sensitive common trigger to be enabled manually

  @Description
    This routine is used to enable the ADC1 software level-sensitive common trigger manually
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function. 
 
  @Returns
    None

  @Param
    None
  
  @Example
*/
inline static void __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SoftwareLevelTriggerEnable(void)
{
    ADCON3Lbits.SWLCTRG = 1;
}

/**
  @Summary
    Allows selection of a data format type for conversion

  @Description
    This routine is used to select desired data format for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    Pass in required data format type from the ADC1_FORM_TYPE list
  
  @Example
    Refer to ADC1_Initialize(); for an example
*/
inline static void __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_FormatDataSet( ADC1_FORM_TYPE form )
{
    ADCON1Hbits.FORM = form;
}
/**
  @Summary
    Allows selection of a resolution mode for conversion

  @Description
    This routine is used to select desired resolution mode for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    Pass in required resolution mode from the ADC1_RESOLUTION_TYPE list
  
  @Example
    Refer to ADC1_Initialize(); for an example
*/
inline static void __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedCoreResolutionModeSet( ADC1_RESOLUTION_TYPE resolution )
{
    ADCON1Hbits.SHRRES = resolution;
}
/**
  @Summary
    Allows conversion clock prescaler value to be set

  @Description
    This routine is used to allow conversion clock prescaler value to be set manually
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    Pass in required prescaler integer value
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/
inline static void __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedCoreConversionClockPrescalerSet(uint8_t prescaler)
{
    ADCON2Lbits.SHRADCS = prescaler;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN0

  @Description
    This routine is used to get the analog to digital converted value for channel AN0. This
    routine gets converted values from the shared core channel AN0.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN0ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN0ConversionResultGet(void) 
{
    return ADCBUF0;
}
/**
  @Summary
    Returns the conversion status of shared channel AN0 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN0 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN0 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN0ConversionComplete(void)
{   
    return ADSTATLbits.AN0RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN1

  @Description
    This routine is used to get the analog to digital converted value for channel AN1. This
    routine gets converted values from the shared core channel AN1.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN1ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN1ConversionResultGet(void) 
{
    return ADCBUF1;
}
/**
  @Summary
    Returns the conversion status of shared channel AN1 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN1 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN1 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN1ConversionComplete(void)
{   
    return ADSTATLbits.AN1RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN2

  @Description
    This routine is used to get the analog to digital converted value for channel AN2. This
    routine gets converted values from the shared core channel AN2.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN2ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN2ConversionResultGet(void) 
{
    return ADCBUF2;
}
/**
  @Summary
    Returns the conversion status of shared channel AN2 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN2 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN2 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN2ConversionComplete(void)
{   
    return ADSTATLbits.AN2RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN3

  @Description
    This routine is used to get the analog to digital converted value for channel AN3. This
    routine gets converted values from the shared core channel AN3.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN3ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN3ConversionResultGet(void) 
{
    return ADCBUF3;
}
/**
  @Summary
    Returns the conversion status of shared channel AN3 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN3 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN3 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN3ConversionComplete(void)
{   
    return ADSTATLbits.AN3RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN4

  @Description
    This routine is used to get the analog to digital converted value for channel AN4. This
    routine gets converted values from the shared core channel AN4.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN4ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN4ConversionResultGet(void) 
{
    return ADCBUF4;
}
/**
  @Summary
    Returns the conversion status of shared channel AN4 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN4 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN4 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN4ConversionComplete(void)
{   
    return ADSTATLbits.AN4RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN7

  @Description
    This routine is used to get the analog to digital converted value for channel AN7. This
    routine gets converted values from the shared core channel AN7.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN7ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN7ConversionResultGet(void) 
{
    return ADCBUF7;
}
/**
  @Summary
    Returns the conversion status of shared channel AN7 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN7 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN7 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN7ConversionComplete(void)
{   
    return ADSTATLbits.AN7RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN9

  @Description
    This routine is used to get the analog to digital converted value for channel AN9. This
    routine gets converted values from the shared core channel AN9.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN9ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN9ConversionResultGet(void) 
{
    return ADCBUF9;
}
/**
  @Summary
    Returns the conversion status of shared channel AN9 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN9 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN9 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN9ConversionComplete(void)
{   
    return ADSTATLbits.AN9RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN12

  @Description
    This routine is used to get the analog to digital converted value for channel AN12. This
    routine gets converted values from the shared core channel AN12.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN12ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN12ConversionResultGet(void) 
{
    return ADCBUF12;
}
/**
  @Summary
    Returns the conversion status of shared channel AN12 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN12 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN12 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN12ConversionComplete(void)
{   
    return ADSTATLbits.AN12RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN13

  @Description
    This routine is used to get the analog to digital converted value for channel AN13. This
    routine gets converted values from the shared core channel AN13.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN13ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN13ConversionResultGet(void) 
{
    return ADCBUF13;
}
/**
  @Summary
    Returns the conversion status of shared channel AN13 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN13 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN13 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN13ConversionComplete(void)
{   
    return ADSTATLbits.AN13RDY;
}
/**
  @Summary
    Returns the ADC1 conversion value for the shared core channel AN14

  @Description
    This routine is used to get the analog to digital converted value for channel AN14. This
    routine gets converted values from the shared core channel AN14.
 
  @Preconditions
    The shared core must be enabled and calibrated before calling this routine 
    using ADC1_SharedCorePowerEnable() and ADC1_SharedCoreCalibration() 
    respectively. This routine returns the conversion value only after the 
    conversion is complete. Completion status conversion can be checked using 
    ADC1_IsSharedChannelAN14ConversionComplete() routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */
inline static uint16_t __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_SharedChannelAN14ConversionResultGet(void) 
{
    return ADCBUF14;
}
/**
  @Summary
    Returns the conversion status of shared channel AN14 selected for conversion

  @Description
    This routine is used to return the conversion status of the shared channel AN14 
    selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel AN14 Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static bool __attribute__((deprecated("\nThis will be removed in future MCC releases."))) ADC1_IsSharedChannelAN14ConversionComplete(void)
{   
    return ADSTATLbits.AN14RDY;
}

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //_ADC1_H
    
/**
 End of File
*/
