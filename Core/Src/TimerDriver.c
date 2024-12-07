/*
 * TimerDriver.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Owner
 */
#include "TimerDriver.h"

void TIMERx_Init(GPTIMR_RegDef_t *TimerToEnable, GPtimer_Config_t TimerConfig){

	//uint32_t Bitmask = 1;
	Timx_Clock_Control(TimerToEnable, ENABLE);
	TimerToEnable->TIMx_CR1 &= ~(11<<8);//Clock Div BitField (Bits 9&8)
	TimerToEnable->TIMx_CR1 |=(TimerConfig.ClkDivSelect<<8);
	TimerToEnable->TIMx_CR1 &= ~(11<<5); //Center Aligned Mode BitField (Bits 5&6)
	TimerToEnable->TIMx_CR1 |=(TimerConfig.CenterAlignModeSelect<<5);
	TimerToEnable->TIMx_CR1 &= ~(1<<4); //Diection of Count UP or DOWN bits(4)
	TimerToEnable->TIMx_CR1 |=(TimerConfig.TimerCountDownModeEnable<<4);
	TimerToEnable->TIMx_CR1 &= ~(1<<7); //Reg buffered or not Bitfield (Bit 7)
	TimerToEnable->TIMx_CR1 |=(TimerConfig.AutoRelaodBuffEnable<<7);
	TimerToEnable->TIMx_CR1 &= ~(1<<3); //One Pulse Mode, If counter is stopped or not at update event (Bit 3)
	TimerToEnable->TIMx_CR1 |=(TimerConfig.OnePulseModeEnable<<3);
	TimerToEnable->TIMx_CR1 &= ~(1<<1); //UDIS update disable: Bit 1
	TimerToEnable->TIMx_CR1 |=(TimerConfig.DisableUpdateEvent<<1);
	TimerToEnable->TIMx_PSC = TimerConfig.PrescaleVal;
	TimerToEnable->TIMx_ARR = TimerConfig.AutoReloadVal;

	TimerEnableOrDisableInterrupt(TimerToEnable, ENABLE);
}

void CLEAR_STATUS_REG(GPTIMR_RegDef_t *timer){
	timer->TIMx_SR &= ~(1<<0);
}

void Timx_Clock_Control(GPTIMR_RegDef_t *TimerToEnable, uint8_t EnableorDisable){
	if (EnableorDisable == DISABLE){
		if (TimerToEnable == TIM2){
			TIM2_CLK_DISABLE();
		}
		if (TimerToEnable == TIM5){
			TIM5_CLK_DISABLE();
		}
	}
	if (EnableorDisable == ENABLE){
		if (TimerToEnable == TIM2){
			TIM2_CLK_ENABLE();
		}
		if (TimerToEnable == TIM5){
			TIM5_CLK_ENABLE();
		}
	}
}

void StartTimer(GPTIMR_RegDef_t *TimerOfInterest){
	TimerOfInterest->TIMx_CR1 |=(1<<0);//enabling clocks is bit 0, shift in 1 0 places}
}

void StopTimer(GPTIMR_RegDef_t *TimerOfInterest){
	TimerOfInterest->TIMx_CR1 &= ~(1<<0);//enabling clocks is bit 0, shift in 1 0 places}
}

void ResetTimer(GPTIMR_RegDef_t *TimerOfInterest){
	TimerOfInterest->TIMx_CNT = 0;//enabling clocks is bit 0, shift in 1 0 places}
}

uint32_t TimerARR_ValReturn(GPTIMR_RegDef_t *TimerOfInterest){
	return TimerOfInterest->TIMx_ARR;
}

uint32_t TimerValueReturn(GPTIMR_RegDef_t *TimerOfInterest){
	return TimerOfInterest->TIMx_CNT;
}

void TimerEnableOrDisableInterrupt(GPTIMR_RegDef_t *TimerOfInterest, uint8_t EnableorDisable){
	if (EnableorDisable == ENABLE){
		TimerOfInterest->TIMx_DIER |= (1<<0);

		if(TimerOfInterest == TIM2){
			ENABLE_IRQ(TIM2_IRQ_NUMBER);
		}
		if(TimerOfInterest == TIM5){
			ENABLE_IRQ(TIM5_IRQ_NUMBER);
		}

	}

	if (EnableorDisable == DISABLE){
		TimerOfInterest->TIMx_DIER &= ~(1<<0);

		if(TimerOfInterest == TIM2){
			DISABLE_IRQ(TIM2_IRQ_NUMBER);
		}
		if(TimerOfInterest == TIM5){
			DISABLE_IRQ(TIM5_IRQ_NUMBER);
		}
	}
}





