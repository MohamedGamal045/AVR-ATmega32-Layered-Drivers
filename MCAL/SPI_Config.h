/*
 * SPI_Config.h
 *
 *  Created on: Sep 9, 2025
 *      Author: MG
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/**
 * Options for SPI_CPOL
 *   1- CPOL_RISING_FALLING
 *   2- CPOL_FALLING_RISING
 *
 */

#define SPI_CPOL      CPOL_RISING_FALLING

/*
 * Options for SPI_CPHA
 *   1- CPHA_SAMPLE_SETUP
 *   2- CPHA_SETUP_SAMPLE
 *
 */

#define SPI_CPHA        CPHA_SAMPLE_SETUP

/**
 * Options for SPI_CLK
 *  1-  SPI_CLK_4
 *  2-  SPI_CLK_16
 *  3-  SPI_CLK_64
 *  4-  SPI_CLK_128
 */

#define SPI_CLK        SPI_CLK_128

/**
 * Options for SPI_MODE
 *  1- MASTER
 *  2- SLAVE
 *
 */

#define SPI_MODE     SLAVE

/**
 * Options for SPI_OPERATE
 *  1- DISABLE
 *  2- ENABLE
 *
 */

#define SPI_OPERATE  ENABLE

/*
 * Options for SPI_DDOR
 *  1- LSB
 *  2- MSB
 */

#define SPI_DORD   LSB

/**
 * Options for SPI_DOUBLE_SPEED
 *  1- SINGLE
 *  2- DOUBLE
 */

#define SPI_DOUBLE_SPEED    SINGLE

#endif /* SPI_CONFIG_H_ */
