/*
 * ApplicationCode.h
 *
 *  Created on: Nov 19, 2024
 *      Author: Owner
 */


#include "LCD_Driver.h"
#include "stm32f4xx_hal.h"
#include "GameLogistics.h"
#include "StartPlayAndTimeScreen.h"

#include <stdio.h>


#ifndef INC_APPLICATIONCODE_H_
#define INC_APPLICATIONCODE_H_

void ApplicationInit(void);
void LCD_Start_Screen(void);



#if (COMPILE_TOUCH_FUNCTIONS == 1) && (COMPILE_TOUCH_INTERRUPT_SUPPORT == 0)
void LCD_Touch_Polling_Demo(void);
#endif // (COMPILE_TOUCH_FUNCTIONS == 1) && (COMPILE_TOUCH_INTERRUPT_SUPPORT == 0)

#endif /* INC_APPLICATIONCODE_H_ */
