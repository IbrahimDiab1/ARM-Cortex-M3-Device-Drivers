/*************************************************************************************/
/* Author      : Ibrahim Diab                                                        */
/* File Name   : FPEC_private.h                                                      */
/* Description : Private addresses for Flash Driver (MCAL Layer)                     */
/*************************************************************************************/


#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

typedef struct
{
    volatile uint32 ACR;
    volatile uint32 KEYR;
    volatile uint32 OPTKEYR;
    volatile uint32 SR;
    volatile uint32 CR;
    volatile uint32 AR;
    volatile uint32 RESERVED;
    volatile uint32 OBR;
    volatile uint32 WRPR;
}FPEC_TYPE;

#define FPEC ((volatile FPEC_TYPE*)0x40022000)

#endif // FPEC_PRIVATE_H

