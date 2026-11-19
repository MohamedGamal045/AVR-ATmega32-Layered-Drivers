/*
 * TWI_Program.c
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */

//LIB: Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//MCAL: Microcontroller_upstruction_Layer
#include "TWI_Register.h"
#include "TWI_Private.h"
#include "TWI_Config.h"
#include "TWI_Interface.h"


void TWI_voidMasterInit(u8 Master_address)
{
    //SCL 400000 bit / sec
	//CPU Clock F: 8MHZ
	//TWBR  value is 2
	//CLEAR all Bits of TWPS

	TWBR = 2;
	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);

    TWAR = Master_address << 1;


    SET_BIT(TWCR,TWCR_TWEA);


    //Enable for TWI HardWare
    SET_BIT(TWCR,TWCR_TWEN);


}

void TWI_voidSlaveInit(u8 Slave_address)
{
	TWAR = Slave_address<<1;
	SET_BIT(TWCR,TWCR_TWEN);

}

u8 TWI_u8SendStartCondition()
{
	u8 Status = 0;


   //Send Start Condition
   SET_BIT(TWCR,TWCR_TWSTA);

   while(GET_BIT(TWCR,TWCR_TWINT) == 0);
   SET_BIT(TWCR,TWCR_TWINT);


   if( (TWSR>>3)  == START_ACK )
   {
	      CLR_BIT(TWCR,TWCR_TWSTA);
          Status = 1;
   }

   else
   {
	   Status = 0;

   }


    return Status;

}

u8 TWI_u8SendSlaveAddress(u8 Slave_address, u8 mode)
{

   u8 Status = 1;
   TWDR = Slave_address<<1;

   if(mode == Write)
   {
     CLR_BIT(TWDR,0);
   }
   else if(mode == Read)
   {
	   SET_BIT(TWDR,0);
   }

   else
   {
	   Status = 0;
   }

   while(GET_BIT(TWCR,TWCR_TWINT) == 0);
   SET_BIT(TWCR,TWCR_TWINT);


   if((TWSR>>3) == SLAVE_ADD_WR_ACK || (TWSR>>3) == SLAVE_ADD_RD_ACK)
   {
	   Status = 1;
   }
   else
   {
	   Status = 0;
   }



   return Status;
}

u8 TWI_u8MasterWriteData(u8 data)
{
   u8 Status = 0;

   TWDR = data;

   while(GET_BIT(TWCR,TWCR_TWINT) == 0);
   SET_BIT(TWCR,TWCR_TWINT);

   if( (TWSR>>3) == MSTR_WR_BYTE_ACK)
   {
	   Status = 1;
   }
   else
   {
	   Status = 0;
   }

   return Status ;

}

u8 TWI_u8MasterReadData(u8 *RecievedData)
{
	u8 Status = 0;
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
	SET_BIT(TWCR,TWCR_TWINT);

	if( (TWSR>>3) ==  MSTR_RD_BYTE_ACK )
	{
		Status = 1;
		*RecievedData = TWDR;
	}
	else
	{
		Status = 0;
	}

	return Status ;
}

u8 TWI_u8SendStopConditon()
{
	//Send Stop Condition on Bus
	SET_BIT(TWCR,TWCR_TWSTO);
	return 1;
}

u8 TWI_SendFrame(u8 Slave_Address,u8 data)
{
	u8 Status;

	//Send Start Condition
	Status = TWI_u8SendStartCondition();

	if(Status == 1)
	{
		Status = TWI_u8SendSlaveAddress(Slave_Address,Write);
		if(Status == 1)
		{
			Status = TWI_u8MasterWriteData(data);

			if(Status == 1)
			{
                TWI_u8SendStopConditon();
			}
		}
	}


	return Status;

}

u8 TWI_RecieveFrame(u8 slave_Address , u8 *recievedata)
{



	u8 Status;

		//Send Start Condition
		Status = TWI_u8SendStartCondition();

		if(Status == 1)
		{
			Status = TWI_u8SendSlaveAddress(slave_Address,Read);
			if(Status == 1)
			{
				Status = TWI_u8MasterReadData(recievedata);

				if(Status == 1)
				{
	                TWI_u8SendStopConditon();
				}
			}
		}

    return Status;
}