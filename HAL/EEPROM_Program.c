/*
 * EEPROM_Program.c
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */

//LIB: Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//MCAL: Microcontroller_upstruction_Layer
#include "TWI_Private.h"
#include "TWI_Interface.h"

//HAL: Hardware_Upstruction_Layer
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"



void EEPROM_Init()
{

	TWI_voidMasterInit(2);

}

void EEPROM_SendByte(u8 blockNumber, u8 address, u8 data)
{
	u8 Status;

	//Send Start Condition
	Status = TWI_u8SendStartCondition();
	if(Status == 1)
	{
		u8 EEPROM_Address = 0b10100 | blockNumber;
		Status = TWI_u8SendSlaveAddress(EEPROM_Address,Write);

		if(Status == 1)
		{
			Status = TWI_u8MasterWriteData(address);
			if(Status == 1)
			{
				Status = TWI_u8MasterWriteData(data);
				if(Status == 1)
				{
					TWI_u8SendStopConditon();
				}

			}

		}
	}


}

void EEPROM_RecieveByte(u8 blockNumber,u8 address, u8*recievedByte)
{
	u8 Status;

	//Send Start Condition
	Status = TWI_u8SendStartCondition();

	if(Status == 1)
	{
		u8 EEPROM_Address = 0b10100 | blockNumber;
		Status = TWI_u8SendSlaveAddress(EEPROM_Address,Write);
		if(Status == 1)
		{
			Status = TWI_u8MasterWriteData(address);
			if(Status == 1)
			{
				Status = TWI_u8SendStartCondition();
				if(Status == 1)
				{
					Status = TWI_u8SendSlaveAddress(EEPROM_Address,Read);
					if(Status == 1)
					{
						Status = TWI_u8MasterReadData(recievedByte);
						if(Status == 1)
						{
							TWI_u8SendStopConditon();
						}
					}
				}
			}
		}
	}


}
