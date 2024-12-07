/*
 * Stm32F229.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Owner
 */

#ifndef INC_STM32F429_H_
#define INC_STM32F429_H_

#include <stdint.h>
#include <stdbool.h>

#ifndef STM32F429I_H_
#define STM32F429I_H_

#define GPIO_AHB1_BASE_ADDR 0x40020000 //defining the gpio adress,an offset of the bus address
#define APB2_BASE_ADDR 0x40010000
#define RCC_AHB1_BASE_ADDR 0x40023800
#define APB1_BASE_ADDR 0x40000000

#define TIM2_APB1_BASE_ADDR (APB1_BASE_ADDR + 0x00000000)
#define TIM5_APB1_BASE_ADDR (APB1_BASE_ADDR + 0x00000C00)

#define GPIOG_AHB1_BASE_ADDR (GPIO_AHB1_BASE_ADDR + 0x00001800) //defining specific gpio address on the bus, rather than entire bus
#define GPIOA_AHB1_BASE_ADDR (GPIO_AHB1_BASE_ADDR + 0x00000000)
#define SYSCFG_APB2_BASE_ADDR (APB2_BASE_ADDR + 0x00003800)
#define EXTI_APB2_BASE_ADDR (APB2_BASE_ADDR + 0x00003C00)

//#define TIM2_CLOCK_OFFSET 0
//#define TIM5_CLOCK_OFFSET 3

#define GPIOA ((GPIO_RegDef_t*) GPIOA_AHB1_BASE_ADDR)
#define GPIOG ((GPIO_RegDef_t*) GPIOG_AHB1_BASE_ADDR)
#define RCC ((RCC_RegDef_t*) RCC_AHB1_BASE_ADDR) //pointer of rcc_regdef type, accessing rcc_ahb1 address as defined above
#define TIM2 ((GPTIMR_RegDef_t*) TIM2_APB1_BASE_ADDR)
#define TIM5 ((GPTIMR_RegDef_t*) TIM5_APB1_BASE_ADDR)

#define SYSCFG ((SYSCFG_RegDef_t*) SYSCFG_APB2_BASE_ADDR)
//#define EXTI ((EXTI_RegDef_t*) EXTI_APB2_BASE_ADDR)
#define EXTI ((EXTI_RegDef_t*) 0x40013C00)

#define ACTIVE 1    //COMMON
#define NON_ACTIVE 0
#define SET 1
#define RESET 0
#define ENABLE SET
#define DISABLE RESET

#define RCC_GPIOA_CLK_BITMAKS (1<<0)
#define RCC_GPIOG_CLK_BITMASK (1<<6)


#define NVIC_ISER0 ((volatile uint32_t*)0xE000E100)
#define NVIC_ICER0 ((volatile uint32_t*)0xE000E180)

#define NVIC_ISPR0 ((volatile uint32_t*)0xE000E200)
#define NVIC_ICPR0 ((volatile uint32_t*)0xE000E280) //base address of each register

#define NVIC_IABR0 ((volatile uint32_t*)0xE000E300)
#define NVIC_IPR0  ((volatile uint32_t*)0xE000E4EF)

#define NVIC_ISER1    ((volatile uint32_t*) 0xE000E104)
#define NVIC_ICER1    ((volatile uint32_t*) 0xE000E184)
#define NVIC_ISPR1    ((volatile uint32_t*) 0xE000E204)
#define NVIC_ICPR1    ((volatile uint32_t*) 0xE000E284)
#define NVIC_IABR1    ((volatile uint32_t*) 0xE000E304)
#define NVIC_IPR1     ((volatile uint32_t*) 0xE000E404)
#define NVIC_STIR1    ((volatile uint32_t*) 0xE000EF04)

typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t GLCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct {
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVED_1;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;

	volatile uint32_t RESERVED_2[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED_3;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED_4[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;

	volatile uint32_t AHB3LPENR;
	volatile uint32_t RESERVED_5;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RESERVED_6[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVED_7[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;

	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCKCFGR;
}RCC_RegDef_t;

typedef struct {
	volatile uint32_t SYSCFG_MEMRMP;
	volatile uint32_t SYSCFG_PMC;
	volatile uint32_t SYSCFG_EXTICR[4];
	volatile uint32_t SYSCFG_CMPCR; //FOUND ON PG 301
}SYSCFG_RegDef_t;

typedef struct{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR; //FOUND ON PG 387
}EXTI_RegDef_t;

typedef struct //This here is the driver, that clients will use to configure gpio . client is what utilities the driver
{
	volatile uint32_t TIMx_CR1;			//Control Reg 1
	volatile uint32_t TIMx_CR2;			//Control Reg 2
	volatile uint32_t TIMx_SMCR;			//Slave Mode Control Reg
	volatile uint32_t TIMx_DIER;			//DMA/Interrupt Enable Reg
	volatile uint32_t TIMx_SR;			//Status Reg
	volatile uint32_t TIMx_EGR;			//Event Generation Reg
	volatile uint32_t TIMx_CCMR1;		//Capture/Compare Mode Reg 1
	volatile uint32_t TIMx_CCMR2;		//Capture/Compare Mode Reg 2
	volatile uint32_t TIMx_CCER;			//Capture/Compare Enable Reg
	volatile uint32_t TIMx_CNT;			//Counter Reg

	volatile uint32_t TIMx_PSC;			//Prescaler Reg
	volatile uint32_t TIMx_ARR;			//Auto Reload Reg
	volatile uint32_t TIMx_RESERVED;
	volatile uint32_t TIMx_CCR1;			//Capture/Compare Reg 1
	volatile uint32_t TIMx_CCR2;			//Capture/Compare Reg 2
	volatile uint32_t TIMx_CCR3;			//Capture/Compare Reg 3
	volatile uint32_t TIMx_CCR4; 		// Capture/Compare Reg 4
	volatile uint32_t TIMx_RESERVED2;
	volatile uint32_t TIMx_DCR; 			//DMA Control
	volatile uint32_t TIMx_DMAR; 		//Direct Memory Access
	volatile uint32_t TIM2_OR_TIM5_OR; 	//Option Register

}GPTIMR_RegDef_t;



//#define GPIOx_CLK_ENABLE(Bitmask);
//void GPIOx_CLK_ENABLE(Bitmask){
//(RCC->AHB1ENR |=(RCC_GPIO))
//}h
//#define TIM2_CLOCK_OFFSET 0
//#define TIM5_CLOCK_OFFSET 3
//
//#define TIM2_CLK_ENABLE()(RCC->APB1ENR |= (1 << TIM2_CLOCK_OFFSET))
//#define TIM2_CLK_DISABLE()(RCC->APB1ENR &= ~(1 << TIM2_CLOCK_OFFSET))
//
//#define TIM5_CLK_ENABLE()(RCC->APB1ENR |= (1 << TIM5_CLOCK_OFFSET))
//#define TIM5_CLK_DISABLE()(RCC->APB1ENR &= ~(1 << TIM5_CLOCK_OFFSET))
//
//#define GPIOA_CLK_ENABLE() (RCC->AHB1ENR |= (1<<0)) //setting bits
//#define GPIOG_CLK_ENABLE() (RCC->AHB1ENR |=(1<<6)) //accesses RCC macro, which is pointing to an address that is the beggining of the struct , the arrow shows us what part of the struct we're acessing, and boolean logic sets or clears a bit in the appropriate register responsible for doing what we want like setting a clock
//#define SYSCFG_CLK_ENABLE() (RCC->APB2ENR |=(1<<14))//found on page 178-179
//
//#define GPIOA_CLK_DISABLE() (RCC->AHB1ENR &= ~(1<<0))//clearing bits
//#define GPIOG_CLK_DISABLE() (RCC->AHB1ENR &= ~(1<<6))//this methods called "passing by reference" (&~ will always return whats in the register except clear the bit in interest
//#define SYSCFG_CLK_DISABLE() (RCC->APB2ENR &= ~(1<<14)


#endif


#endif /* INC_STM32F429_H_ */
