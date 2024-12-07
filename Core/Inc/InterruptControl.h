/*
 * InterruptControl.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Owner
 */

#ifndef INC_INTERRUPTCONTROL_H_
#define INC_INTERRUPTCONTROL_H_
/*
 * InterruptControl.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Owner
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_
#include <stdint.h>
#include "Stm32F429.h"

//just handles the nvic
#define EXTI0_IRQ_NUMBER 6//This irq number is responsible for the button, call IRQ 6 when we want to do button interrupt
#define LENGTH_OF_REGISTER 32
#define TIM2_IRQ_NUMBER 28
#define TIM5_IRQ_NUMBER 50

void ENABLE_IRQ(uint8_t IRQ_POSITION);
void DISABLE_IRQ(uint8_t IRQ_POSITION);
void CLEAR_PENDING_IRQ(uint8_t IRQ_POSITION);
void SET_PENDING_IRQ(uint8_t IRQ_POSITION);

void EXTI_CLEAR_PENDING_IRQ_REGISTER(uint8_t pinNumber);




#endif /* INTERRUPTCONTROL_H_ */


#endif /* INC_INTERRUPTCONTROL_H_ */
