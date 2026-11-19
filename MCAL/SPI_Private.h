/*
 * SPI_Private.h
 *
 *  Created on: Sep 9, 2025
 *      Author: MG
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define CPOL_RISING_FALLING    0
#define CPOL_FALLING_RISING    1

#define CPHA_SAMPLE_SETUP      0
#define CPHA_SETUP_SAMPLE      1


#define SPI_CLK_4              0  //0b00
#define SPI_CLK_16             1  //0b01
#define SPI_CLK_64             2  //0b10
#define SPI_CLK_128            3  //0b11


#define MASTER                 0
#define SLAVE                  1


#define LSB                    0
#define MSB                    1


#define DISABLE                0
#define ENABLE                 1


#define SINGLE                 0
#define DOUBLE                 1

#endif /* SPI_PRIVATE_H_ */
