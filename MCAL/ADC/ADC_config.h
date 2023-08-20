/*******************************************************************/
/* Author      : Ibrahim Diab                                      */
/* File Name   : ADC_config.h                                      */
/* Description : Configuration for ADC module stm32f103            */
/*******************************************************************/
#ifndef ADC_CONFIG_H    
#define ADC_CONFIG_H

/**
Requirements:

- Enable the ADC peripheral in the RCC driver.
- Configure the GPIO pins as Analog mode for ADC input channels.
- Initialize the ADC configuration structure before calling ADC_init function.


Note: For ADC2 and ADC3, you may need to remap some of the pins using the AFIO registers because the default pins may not be available.

Note: Failing to meet any of these requirements may result in unexpected behavior of the ADC driver.
*/      

#endif // ADC_CONFIG_H
