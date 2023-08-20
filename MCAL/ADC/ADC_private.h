/*******************************************************************/
/* Author      : Ibrahim Diab                                      */
/* File Name   : ADC_private.h                                     */
/* Description : Private addresses for ADC module stm32f103        */
/*******************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

typedef struct 
{
    volatile uint32 SR;     // status register
    volatile uint32 CR1;    // control register 1
    volatile uint32 CR2;    // control register 2
    volatile uint32 SMPR1;  // sample time register 1
    volatile uint32 SMPR2;  // sample time register 2
    volatile uint32 JOFR1;  // injected channel data offset register x  
    volatile uint32 JOFR2;  // injected channel data offset register x
    volatile uint32 JOFR3;  // injected channel data offset register x
    volatile uint32 JOFR4;  // injected channel data offset register x
    volatile uint32 HTR;    // watchdog high threshold register
    volatile uint32 LTR;    // watchdog low threshold register
    volatile uint32 SQR1;   // regular sequence register 1
    volatile uint32 SQR2;   // regular sequence register 2
    volatile uint32 SQR3;   // regular sequence register 1
    volatile uint32 JSQR;   // injected sequence register
    volatile uint32 JDR1;   // injected data register x
    volatile uint32 JDR2;   // injected data register x
    volatile uint32 JDR3;   // injected data register x
    volatile uint32 JDR4;   // injected data register x
    volatile uint32 DR;     // regular data register
}ADC_type;

 volatile ADC_type * ADC[NUM_OF_ADC_SUPPORTED] =
 {
     (volatile ADC_type *)(0x40012400), // ADC1 Address
     (volatile ADC_type *)(0x40012800), // ADC2 Address
     (volatile ADC_type *)(0x40013C00), // ADC3 Address
 };

#endif // ADC_PRIVATE_H
