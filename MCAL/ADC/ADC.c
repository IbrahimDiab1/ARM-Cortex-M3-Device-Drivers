/*******************************************************************/
/* Author      : Ibrahim Diab                                      */
/* File Name   : ADC.c                                             */
/* Description : Functions Implementation for ADC module           */
/*******************************************************************/

#include "std_types.h"
#include "common_macros.h"

#include "stm32f103c6.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

// Function responsible for initializing the ADC
void ADC_init(ADC_Num ADCX, ADC_CONFIG_t* ADC_cfg)
{
    SET_BIT(ADC[ADCX]->CR2,0);                  // Set ADON bit on.
    
    if(ADC_cfg->conversionMode == ADC_Conversion_Mode_Single)       // Set Conversion mode.
        CLR_BIT(ADC[ADCX]->CR2,1);
    else
        SET_BIT(ADC[ADCX]->CR2,1);
    
    SET_BIT(ADC[ADCX]->CR2,2);                  // Calibrate ADC.

    if(ADC_cfg->align == ADC_Align_Right)       // Set register data alignment.
        CLR_BIT(ADC[ADCX]->CR2,11);
    else
        SET_BIT(ADC[ADCX]->CR2,11);
    
    if(ADC_cfg->channelType == ADC_Channel_Mode_Regular)         // Set register data alignment.
        SET_BIT(ADC[ADCX]->CR2,20);
    else
        CLR_BIT(ADC[ADCX]->CR2,20);
    
    MOD_3BIT(ADC[ADCX]->CR2, 17, 0b111);        // Select SWSTART as trigger event.
    
    if(ADC_cfg->Mode == ADC_Mode_Independent)   // Set ADC mode.
        MOD_4BIT(ADC[ADCX]->CR1, 16, 0b0000);
    
    for(uint8 index =0; index<16; index++)      // set all channels with chosen sampling time as default.
        ADC_changeChannelSamplingTime(ADCX, index, ADC_cfg->sampleTime);
}

// Function responsible for changing the sampling time of a specific ADC channel
void ADC_changeChannelSamplingTime(ADC_Num ADCX, ADC_Channel_Num channel_x, ADC_Sampling_Time samplingTime)
{
    if (channel_x <= ADC_channel_9)                                     // Check if the channel is in the range of 0 to 9
        MOD_3BIT(ADC[ADCX]->SMPR2, (3 * channel_x), samplingTime);         
    else if (channel_x <= ADC_channel_15)                               // Check if the channel is in the range of 10 to 15
        MOD_3BIT(ADC[ADCX]->SMPR1, (3 * (channel_x - 10)), samplingTime);  
}

// Function responsible for reading the converted value from a specific ADC channel
uint16 ADC_readChannel(ADC_Num ADCX, ADC_Channel_Num channelx)
{
    uint16 value = 0;  

    ADC[ADCX]->SQR3 = channelx;              // Set the desired channel for conversion in the regular sequence register

    SET_BIT(ADC[ADCX]->CR2, 22);             // Start the ADC conversion by setting the SWSTART bit

    while (GET_BIT(ADC[ADCX]->SR, 1) == 0);  // Wait until the conversion is complete (EOC flag is set)

    value = (ADC[ADCX]->DR) & 0xFFFF;        // Read the converted value from the ADC data register (DR)

    CLR_BIT(ADC[ADCX]->SR, 1);               // Clear the EOC flag by writing 1 to it

    return value;  
}
