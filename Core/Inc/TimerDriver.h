/*
 * TimerDriver.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Owner
 */

#ifndef INC_TIMERDRIVER_H_
#define INC_TIMERDRIVER_H_

#include "Stm32F429.h"
#include "InterruptControl.h"

#define MAX_COUNT 0xFFFFFFFF

typedef struct {
	uint32_t AutoReloadVal; //
	uint32_t MasterModeSelect; //
	uint32_t ClkDivSelect; ///
	uint32_t PrescaleVal; //
	uint32_t CenterAlignModeSelect; ///
	bool AutoRelaodBuffEnable; //
	bool TimerCountDownModeEnable; //
	bool InterruptUpdateEnable; //this is bit 0
	bool DisableUpdateEvent;
	bool OnePulseModeEnable; //

}GPtimer_Config_t;

void TIMERx_Init(GPTIMR_RegDef_t *TimerToEnable, GPtimer_Config_t TimerConfig);
void Timx_Clock_Control(GPTIMR_RegDef_t *TimerToEnable, uint8_t EnableorDisable);
void StartTimer(GPTIMR_RegDef_t *TimerOfInterest);
void StopTimer(GPTIMR_RegDef_t *TimerOfInterest);
void ResetTimer(GPTIMR_RegDef_t *TimerOfInterest);
uint32_t TimerValueReturn(GPTIMR_RegDef_t *TimerOfInterest);
void TimerEnableOrDisableInterrupt(GPTIMR_RegDef_t *TimerOfInterest, uint8_t EnableorDisable);
uint32_t TimerARR_ValReturn(GPTIMR_RegDef_t *TimerOfInterest);
void CLEAR_STATUS_REG(GPTIMR_RegDef_t *timer);




#define MasterModeSelectReset 0
#define MasterModeSelectEnable 1
#define MasterModeSelectUpdate 2
#define MasterModeSelectComparePulse 3
#define MasterModeSelectResetOC1REF 4
#define MasterModeSelectResetOC2REF 5
#define MasterModeSelectResetOC3REF 6
#define MasterModeSelectResetOC4REF 7

#define ClkDivSelect0 00 //This bit-field indicates the division ratio between the timer clock (CK_INT) frequency and sampling clock used by the digital filters (ETR, TIx),
#define ClkDivSelect1 1 //2*t(clk_int)
#define ClkDivSelect2 2 //4*t(clk_int)
#define ClkDivSelect3 3 //reserved

#define EdgeAligModeSel0 00 //Edge Aligned Mode
#define CenterAligModeSel1 1 //Center Aligned Mode 1
#define CenterAligModeSel2 2 //Center Aligned Mode 2
#define CenterAligModeSel3 3 //Center Aligned Mode 3

#define Upcounter 0
#define DownCounter 1



#endif /* TIMER_DRIVER_H_ */
