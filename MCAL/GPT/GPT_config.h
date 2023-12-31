/********************************************************************************/
/* Author      : Ibrahim Diab                                                   */
/* File Name   : GPT_config.h                                                   */
/* Description : Configuration for GPT (General Purpose Timers) module in STM32 */
/********************************************************************************/
#ifndef GPT_CONFIG_H
#define GPT_CONFIG_H

/**
 General-Purpose Timer (GPT) Configuration:
 
 Requirements:
 
 - RCC must be enabled for the timers you intend to use.
 - If interrupts are enabled, ensure that you enable the corresponding interrupt in the NVIC.
 - Initialize the timer configuration structure before calling GPT_init function,
   for desired operation, including prescaler, counting mode, and auto-reload value.


 Note: Failing to meet any of these requirements may lead to unexpected behavior of the timer module.
*/



/*
 options:
            TIMER_PRESCALER_AUTO , TIMER_PRESCALER_MANUAL
*/
#define TIMER_PRESCALER_CALCULATE       TIMER_PRESCALER_AUTO

#endif // GPT_CONFIG_H
