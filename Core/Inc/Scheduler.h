/*
 * Scheduler.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Owner
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>
//
#define InitiateGamePlay_EVENT (1<<0) //this bitmask changes nothing,"shift 1 0 places"
#define ButtonPressed_RotateBlock (1<<1)
#define PlayEnded_ReturnTime (1<<2)
#define DropBlockOnePixel (1<<3)

uint32_t getScheduledEvents(); //retuns scheduled events
void addSchedulerEvent(uint32_t event);
void removeSchedulerEvent(uint32_t eventremoved);



#endif /* INC_SCHEDULER_H_ */
