/*
 * InterruptControl.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Owner
 */

/*
 * InterruptControl.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Owner
 */
#include "InterruptControl.h"




void ENABLE_IRQ(uint8_t IRQ_POSITION){ //set IRQ
	if (IRQ_POSITION < LENGTH_OF_REGISTER){
		*NVIC_ISER0|=(0x1<<IRQ_POSITION);
	}
	else{
		uint32_t temp;
		temp = (IRQ_POSITION % LENGTH_OF_REGISTER);
		*NVIC_ISER1 |=(0x1<<temp);
	}
}



void DISABLE_IRQ(uint8_t IRQ_POSITION){ //Disable IRQ
	if (IRQ_POSITION < LENGTH_OF_REGISTER){
		*NVIC_ICER0|=(0x1<<IRQ_POSITION);
	}

	if (IRQ_POSITION > LENGTH_OF_REGISTER){
		uint32_t temp;
		temp = (IRQ_POSITION % LENGTH_OF_REGISTER);
		*NVIC_ICER1 =(0x1<<temp); //
	} //should this be NVIC ICER1 since interrupts greater than length of register are in icer1 and so on

}

void CLEAR_PENDING_IRQ(uint8_t IRQ_POSITION){
	if (IRQ_POSITION < LENGTH_OF_REGISTER){
		*NVIC_ICPR0 =(0x1<<IRQ_POSITION);
	}
	if (IRQ_POSITION > LENGTH_OF_REGISTER){
		uint32_t temp;
		temp = (IRQ_POSITION % LENGTH_OF_REGISTER);
		*NVIC_ICPR1 =(0x1<<temp);
	}
}

void SET_PENDING_IRQ(uint8_t IRQ_POSITION){
	if (IRQ_POSITION < LENGTH_OF_REGISTER){
		(*NVIC_ICPR0)|=(0x1<<IRQ_POSITION);
	}
	if (IRQ_POSITION > LENGTH_OF_REGISTER){
		uint32_t temp;
		temp = (IRQ_POSITION % LENGTH_OF_REGISTER);
		(*NVIC_ISPR1) |=(0x1<<temp);
	}
}

void EXTI_CLEAR_PENDING_IRQ_REGISTER(uint8_t pinNum){
	EXTI->EXTI_PR |= (0x1 << pinNum);
}

