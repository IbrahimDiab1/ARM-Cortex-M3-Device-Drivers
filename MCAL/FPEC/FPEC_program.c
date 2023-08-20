/********************************************************************************************/
/* Author      : Ibrahim Diab                                                               */
/* File Name   : FPEC_program.c                                                             */
/* Description : Functions Implementation for Flash Driver (MCAL Layer)                     */
/********************************************************************************************/

#include "std_types.h"
#include "common_macros.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"

void FPEC_init()
{
    if(GET_BIT(FPEC->CR,7) == 1)                                //Check if FPEC is Locked   
    {               
        FPEC -> KEYR = 0x45670123;                              //The write sequence to unlock FPEC
        FPEC -> KEYR = 0xCDEF89AB;              
    } 
}


void FPEC_eraseAppArea(uint16 NumOfAppPages, uint8 pageBaseNum)
{
    if(pageBaseNum>=0 && NumOfAppPages>=0)
        if((NumOfAppPages + pageBaseNum) < FLASH_SIZE_IN_PAGES)
            for(uint16 counter = pageBaseNum;counter < (NumOfAppPages+pageBaseNum);counter++)
                FPEC_eraseFlashPage(counter);
}
    
    
void FPEC_eraseFlashPage(uint8 PageNumber)
{
    while(GET_BIT(FPEC->SR,0) == 1);                            //Check Busy Flag
                    
    if(GET_BIT(FPEC->CR,7) == 1)                                //Check if FPEC is Locked   
    {               
        FPEC -> KEYR = 0x45670123;                              //The write sequence to unlock FPEC
        FPEC -> KEYR = 0xCDEF89AB;              
    }               
                    
    SET_BIT(FPEC->CR,1);                                        //Chose Page Erasing 
                    
    FPEC->AR = ( PageNumber * PAGE_SIZE )+ PAGE_0_BASE_ADDRESS; //Set Page Address to erase
                    
    SET_BIT(FPEC->CR, 6);                                       //Start operation
                    
    while (GET_BIT(FPEC->SR,0) == 1);                           //Wait Busy Flag
                    
    SET_BIT(FPEC->SR,5);                                        //Reset EOP Flag 
    CLR_BIT(FPEC->CR,1);                                        //Reset Page Erasing Choice
}


void FPEC_writeFlash(uint32 Address, uint16* Data, uint8 Length)
{
    
    while(GET_BIT(FPEC->SR,0) == 1);                            //Check Busy Flag
                    
    if(GET_BIT(FPEC->CR,7) == 1)                                //Check if FPEC is Locked   
    {               
        FPEC -> KEYR = 0x45670123;                              //The write sequence to unlock FPEC
        FPEC -> KEYR = 0xCDEF89AB;              
    }


    for(uint8 i=0; i<Length; i++)
    {
        SET_BIT(FPEC->CR,0);                                    //Chose Programming operation
        
        *(volatile uint16*)Address = *Data;                     //Write half word data
        Data++;
        Address+=2;
        
                
        while (GET_BIT(FPEC->SR,0) == 1);                       //Wait Busy Flag
        
        SET_BIT(FPEC->SR,5);                                    //Reset EOP Flag 
        CLR_BIT(FPEC->CR,0);                                    //Reset Programming operation Choice
    }
}
