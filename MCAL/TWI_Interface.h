/*
 * TWI_Interface.h
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */

#ifndef MCAL_TWI_INTERFACE_H_
#define MCAL_TWI_INTERFACE_H_

void TWI_voidMasterInit(u8 Master_address);

void TWI_voidSlaveInit(u8 Slave_address);

u8 TWI_u8SendStartCondition();

u8 TWI_u8SendSlaveAddress(u8 Slave_address, u8 mode);

u8 TWI_u8MasterWriteData(u8 data);

u8 TWI_u8MasterReadData(u8 *RecievedData);

u8 TWI_u8SendStopConditon();



u8 TWI_SendFrame(u8 Slave_Address,u8 data);
u8 TWI_RecieveFrame(u8 slave_Address , u8 *recievedata);





#endif /* MCAL_TWI_INTERFACE_H_ */
