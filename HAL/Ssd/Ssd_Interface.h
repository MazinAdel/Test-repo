/*
 * Ssd_Interface.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Mazin
 */
#include "Ssd_Configurations.h"

#include "Dio_Interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

void Hal_Ssd_void_SsdInit(void);
void Hal_Ssd_void_SsdDisplay(u8);
void Hal_Ssd_void_SsdCountUp(u8);
void Hal_Ssd_void_SsdCountDown(u8);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
