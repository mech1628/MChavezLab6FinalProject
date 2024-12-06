/*
 * Scheduler.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Owner
 */
#include "Scheduler.h"

static uint32_t scheduledEvents;

void addSchedulerEvent(uint32_t event_bitmask){
	scheduledEvents |= event_bitmask; //set the bit to schedule an event_bitmask
}

void removeSchedulerEvent(uint32_t eventremoved){
	scheduledEvents &= ~(eventremoved); //clearing the bit to remove event
}

uint32_t getScheduledEvents(){
	return scheduledEvents;

}

