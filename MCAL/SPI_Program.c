/*
 * SPI_Program.c
 *
 *  Created on: Sep 9, 2025
 *      Author: MG
 */

//LIB: Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//MCAL: Microcontroller_upstruction_Layer
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Register.h"
#include "SPI_Interface.h"



void SPI_Init()
{
	#if  SPI_CPOL  == CPOL_RISING_FALLING
		CLR_BIT(SPCR,SPCR_CPOL);

	#elif  SPI_CPOL == CPOL_FALLING_RISING
		SET_BIT(SPCR,SPCR_CPOL);
	#else
	#error
		"You Must Set Value For SPI_CPOL Options"

	#endif


	#if  SPI_CPHA  == CPHA_SAMPLE_SETUP
		CLR_BIT(SPCR,SPCR_CPHA);
	#elif SPI_CPHA == CPHA_SETUP_SAMPLE
		SET_BIT(SPCR,SPCR_CPHA);

	#else
	#error  "You Must Set Value For SPI_CPHA OPTIONS"

	#endif


	#if  SPI_CLK == SPI_CLK_4
		CLR_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1);

	#elif SPI_CLK == SPI_CLK_16
		SET_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1);

	#elif SPI_CLK == SPI_CLK_64
		CLR_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1);

	#elif SPI_CLK == SPI_CLK_128
		SET_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1);
	#else
   #error "You Must Set Value For SPI_CLK OPTIONS"

	#endif



	#if  SPI_MODE  == MASTER
		  SET_BIT(SPCR,SPCR_MSTR);
	#elif SPI_MODE == SLAVE
		  CLR_BIT(SPCR,SPCR_MSTR);
	#else
	   #error "You Must Set Value For SPI_MODE OPTIONS"
	#endif


	#if SPI_OPERATE == ENABLE
	 SET_BIT(SPCR,SPCR_SPE);
	#elif SPI_OPERATE == DISABLE
	 CLR_BIT(SPCR,SPCR_SPE);
	#else
	  #error  "You Must Set Value For SPI_OPERATE OPTIONS"
	#endif


	#if SPI_DORD  == LSB
	  SET_BIT(SPCR,SPCR_DORD);
	#elif SPI_DORD == MSB
	  CLR_BIT(SPCR,SPCR_DORD);
	#else
	  #error "You Must Set Value For SPI_DORD OPTIONS"
	#endif


	#if SPI_DOUBLE_SPEED == SINGLE
	 CLR_BIT(SPSR,SPSR_SPI2X);
	#elif SPI_DOUBLE_SPEED == DOUBLE
	 SET_BIT(SPSR,SPSR_SPI2X);
	#else
	#error "You Must Set Value for SPI_DOUBLE SPEED OPTIONS"

	#endif
}



u8 SPI_Transieve(u8 Data)
{
  SPDR = Data;
  while(GET_BIT(SPSR,SPSR_SPIF) == 0);
  return SPDR;

}
