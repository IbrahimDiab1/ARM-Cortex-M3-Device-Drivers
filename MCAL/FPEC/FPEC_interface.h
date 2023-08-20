/**************************************************************************************/
/* Author      : Ibrahim Diab                                                         */
/* File Name   : FPEC_interface.h                                                     */
/* Description : Interfacing macros for Flash Driver (MCAL Layer)                     */
/**************************************************************************************/


#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H    

void FPEC_init();

void FPEC_eraseAppArea(uint16 NumOfAppPages, uint8 pageBaseNum);
    
void FPEC_eraseFlashPage(uint8 PageNumber);

void FPEC_writeFlash(uint32 Address, uint16* Data, uint8 Length);

#endif // FPEC_INTERFACE_H