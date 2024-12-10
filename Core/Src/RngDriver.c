/*
 * RngDriver.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Owner
 */
#include "RngDriver.h"

void RNG_Init(void) {
    // Enable RNG clock
    RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;

    // Enable the RNG peripheral
    RNG->CR |= RNG_CR_RNGEN;
}

// Function to generate a random number
uint32_t RNG_GetRandomNumber(void) {
    // Wait until random data is ready
    while ((RNG->SR & RNG_SR_DRDY) == 0) {
        // Optionally, implement a timeout mechanism to avoid infinite loops
    }

    // Check for errors (optional)
    if (RNG->SR & (RNG_SR_CECS | RNG_SR_SECS)) {
        // Handle clock error or seed error here
        return 0; // Return 0 or an error code
    }

    // Read and return the random number
    return RNG->DR;
}


