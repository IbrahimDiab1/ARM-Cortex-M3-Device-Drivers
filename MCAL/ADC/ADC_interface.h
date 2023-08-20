/*******************************************************************/
/* Author      : Ibrahim Diab                                      */
/* File Name   : ADC_interface.h                                   */
/* Description : Interfacing macros for ADC module stm32f103       */
/*******************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_MAX_VALUE               4096  // 4096 pulses    
#define ADC_REF_VOLT_VALUE          3.3   // 3.3 Volt

typedef enum
{
    ADC1,
    ADC2,
    ADC3
}ADC_Num;

typedef enum
{
    ADC_channel_0,
    ADC_channel_1,
    ADC_channel_2,
    ADC_channel_3,
    ADC_channel_4,
    ADC_channel_5,
    ADC_channel_6,
    ADC_channel_7,
    ADC_channel_8,
    ADC_channel_9,
    ADC_channel_10,
    ADC_channel_11,
    ADC_channel_12,
    ADC_channel_13,
    ADC_channel_14,
    ADC_channel_15
}ADC_Channel_Num;

typedef enum
{
    ADC_Align_Right,    // ADC data aligned to the right (LSBs)
    ADC_Align_Left      // ADC data aligned to the left  (MSBs)
} ADC_Align_t;


typedef enum
{
    ADC_Sampling_Time_1_5_Cycle,       // 1.5 ADC clock cycles
    ADC_Sampling_Time_7_5_Cycle,       // 7.5 ADC clock cycles
    ADC_Sampling_Time_13_5_Cycle,      // 13.5 ADC clock cycles
    ADC_Sampling_Time_28_5_Cycle,      // 28.5 ADC clock cycles
    ADC_Sampling_Time_41_5_Cycle,      // 41.5 ADC clock cycles
    ADC_Sampling_Time_55_5_Cycle,      // 55.5 ADC clock cycles
    ADC_Sampling_Time_71_5_Cycle,      // 71.5 ADC clock cycles
    ADC_Sampling_Time_239_5_Cycle      // 239.5 ADC clock cycles
}ADC_Sampling_Time;


typedef enum
{
    ADC_Mode_Independent,              // Independent mode (no synchronization)
    ADC_Mode_Reginjecsimult,           // Regular & Injected Simultaneous Mode
    ADC_Mode_Regsimult_altertrig,      // Regular Simultaneous with Alternate Trigger
    ADC_Mode_Injecsimult_fastinterl,   // Injected Simultaneous with Fast Interleaving
    ADC_Mode_Injecsimult_slowinterl,   // Injected Simultaneous with Slow Interleaving
    ADC_Mode_Injecsimult,              // Injected Simultaneous Mode
    ADC_Mode_Regsimult,                // Regular Simultaneous Mode
    ADC_Mode_Fastinterl,               // Fast Interleaved Mode
    ADC_Mode_Slowinterl,               // Slow Interleaved Mode
    ADC_Mode_Altertrig                 // Alternate Trigger Mode
}ADC_Mode_t;

typedef enum
{
    ADC_Conversion_Mode_Single,
    ADC_Conversion_Mode_Continuous
}ADC_Conversion_Mode_t;

typedef enum
{
    ADC_Channel_Mode_Regular,
    ADC_Channel_Mode_Injected
}ADC_Channel_t;

typedef struct
{
    ADC_Mode_t Mode;                        // ADC operating mode (Independent, Simultaneous, Alternate Trigger, etc.)
    ADC_Sampling_Time sampleTime;           // Sampling time selection for ADC channels (1.5 cycles, 7.5 cycles, etc.)
    ADC_Align_t align;                      // ADC data alignment (Right or Left alignment)
    ADC_Conversion_Mode_t conversionMode;   // ADC conversion mode (Single or Continuous)
    ADC_Channel_t channelType;              // ADC channel type (Regular or Injected)
} ADC_CONFIG_t;


// Function responsible for initializing the ADC
void ADC_init(ADC_Num ADCX,ADC_CONFIG_t* ADC_cfg);

// Function responsible for changing the sampling time of a specific ADC channel
void ADC_changeChannelSamplingTime(ADC_Num ADCX, ADC_Channel_Num channel_x, ADC_Sampling_Time samplingTime);

// Function responsible for reading the converted value from a specific ADC channel
uint16 ADC_readChannel(ADC_Num ADCX, ADC_Channel_Num Channelx);

#endif // ADC_INTERFACE_H
