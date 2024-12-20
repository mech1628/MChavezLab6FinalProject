
/* Includes ------------------------------------------------------------------*/
#include "main.h"



/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void SystemClockOverride(void);
// static void MX_GPIO_Init(void);

 I2C_HandleTypeDef hi2c3;
 RNG_HandleTypeDef hrng;
 LTDC_HandleTypeDef hltdc;
 SPI_HandleTypeDef hspi5;
 //TIM_HandleTypeDef htim7;
/*
  * @brief  The application entry point.
  * @retval int
  */
 static void MX_GPIO_Init(void);
 static void MX_I2C3_Init(void); //
 static void MX_LTDC_Init(void);
 static void MX_RNG_Init(void); //
 static void MX_SPI5_Init(void);
 static void MX_TIM7_Init(void);



//
// void DrawRandomShape(uint16_t x, uint16_t y, uint16_t color) {
//     uint32_t ShapeIndex;
//
//     // Generate a random index for the shape
//     ShapeIndex = GenerateTetrisShape();
//
//     // Call the corresponding shape function from the Shapes array
//     if (ShapeIndex < 7) { // Ensure the index is within bounds
//         Shapes[ShapeIndex](x, y, color);
//     } else {
//         // Handle error or unexpected index (should not occur with proper modulo logic)
//         printf("Error: Invalid shape index %lu\n", ShapeIndex);
//     }
// }





int main(void)
{

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  SystemClockOverride();
  MX_GPIO_Init();
  MX_I2C3_Init();
  MX_LTDC_Init();
  MX_RNG_Init();
  MX_SPI5_Init();
  //MX_TIM7_Init();

  ApplicationInit();
//  LCD_SetTextColor(LCD_COLOR_BLACK);
//  LCD_SetFont(&Font16x24);
//  //LCD_DisplayChar(Xpos, Ypos, Ascii)
//  LCD_DisplayChar(40, 20, 'M');
//  HAL_Delay(2000);
//
//  LCD_Clear(0, LCD_COLOR_CYAN);
//  LCD_Draw_Circle_Fill(50, 75, 4, LCD_COLOR_RED);
//  HAL_Delay(500);
//
//
//  LCD_Clear(0, LCD_COLOR_CYAN);
//  LCD_Draw_Circle_Fill(50, 100, 10, LCD_COLOR_RED);
//  HAL_Delay(500);
//
//  LCD_Clear(0, LCD_COLOR_CYAN);
//  LCD_Draw_Circle_Fill(50, 145, 20, LCD_COLOR_RED);
//  HAL_Delay(500);

  // The default system configuration function is "suspect" so we need to make our own clock configuration
  // Note - You, the developer, MAY have to play with some of this coniguration as you progress in your project


//  LCD_Start_Screen();
  LCD_Start_Screen();

//  HAL_Delay(5000);

  // DO NOT CALL THIS FUNCTION WHEN INTERRUPT MODE IS SELECTED IN THE COMPILE SWITCH IN stmpe811.h
  // Un-comment the below function after setting COMPILE_TOUCH to 1 in stmpe811.h
  //LCD_Touch_Polling_Demo(); // This function Will not return

// for(;;){

//
//  		uint32_t eventsToRun = getScheduledEvents();
//
//  		if((eventsToRun & (InitiateGamePlay_EVENT))!= 0){ //scheduled events doesnt equal zero if at least one event is scheduled
//  			Initiate_GamePlay();
//  			removeSchedulerEvent(InitiateGamePlay_EVENT);
//  		}
//  		if((eventsToRun & (ButtonPressed_RotateBlock)) != 0){
//  			AppDelay(DELAY);
//  		}
//  		if((eventsToRun & (PlayEnded_ReturnTime)) != 0){
//  			//printf("Your format string here: %d\n", your_variable);
////  			uint16_t Temperature = 0;
////  			Temperature = GYRO_TEMP_RETURN();
////  			printf("TEMPERATURE = %d\n", Temperature);
////  			removeSchedulerEvent(PRINT_TEMP);
//
//	}
  while (1)
  {

  }

}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
static void MX_RNG_Init(void){
	 hrng.Instance = RNG;
	 if (HAL_RNG_Init(&hrng) != HAL_OK){
		 Error_Handler();
	 }
}

static void MX_I2C3_Init(void)
{


 hi2c3.Instance = I2C3;
 hi2c3.Init.ClockSpeed = 100000;
 hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
 hi2c3.Init.OwnAddress1 = 0;
 hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
 hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
 hi2c3.Init.OwnAddress2 = 0;
 hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
 hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
 if (HAL_I2C_Init(&hi2c3) != HAL_OK)
 {
   Error_Handler();
 }

 /** Configure Analogue filter
 */
 if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
 {
   Error_Handler();
 }

 /** Configure Digital filter
 */
 if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
 {
   Error_Handler();
 }
 /* USER CODE BEGIN I2C3_Init 2 */

 /* USER CODE END I2C3_Init 2 */

}
static void MX_SPI5_Init(void)
{

 /* USER CODE BEGIN SPI5_Init 0 */

 /* USER CODE END SPI5_Init 0 */

 /* USER CODE BEGIN SPI5_Init 1 */

 /* USER CODE END SPI5_Init 1 */
 /* SPI5 parameter configuration*/
 hspi5.Instance = SPI5;
 hspi5.Init.Mode = SPI_MODE_MASTER;
 hspi5.Init.Direction = SPI_DIRECTION_2LINES;
 hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
 hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
 hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
 hspi5.Init.NSS = SPI_NSS_SOFT;
 hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
 hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
 hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
 hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
 hspi5.Init.CRCPolynomial = 10;
 if (HAL_SPI_Init(&hspi5) != HAL_OK)
 {
   Error_Handler();
 }
 /* USER CODE BEGIN SPI5_Init 2 */

 /* USER CODE END SPI5_Init 2 */

}

/**
 * @brief TIM7 Initialization Function
 * @param None
 * @retval None
 */
//static void MX_TIM7_Init(void)
//{
//
// /* USER CODE BEGIN TIM7_Init 0 */
//
// /* USER CODE END TIM7_Init 0 */
//
// TIM_MasterConfigTypeDef sMasterConfig = {0};
//
// /* USER CODE BEGIN TIM7_Init 1 */
//
// /* USER CODE END TIM7_Init 1 */
// htim7.Instance = TIM7;
// htim7.Init.Prescaler = 0;
// htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
// htim7.Init.Period = 65535;
// htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
// if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
// {
//   Error_Handler();
// }
// sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
// sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
// if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
// {
//   Error_Handler();
// }
// /* USER CODE BEGIN TIM7_Init 2 */
//
// /* USER CODE END TIM7_Init 2 */
//
//}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
 GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

 /* GPIO Ports Clock Enable */
 __HAL_RCC_GPIOC_CLK_ENABLE();
 __HAL_RCC_GPIOF_CLK_ENABLE();
 __HAL_RCC_GPIOH_CLK_ENABLE();
 __HAL_RCC_GPIOA_CLK_ENABLE();
 __HAL_RCC_GPIOB_CLK_ENABLE();
 __HAL_RCC_GPIOG_CLK_ENABLE();
 __HAL_RCC_GPIOE_CLK_ENABLE();
 __HAL_RCC_GPIOD_CLK_ENABLE();

 /*Configure GPIO pin Output Level */
 HAL_GPIO_WritePin(GPIOC, NCS_MEMS_SPI_Pin|CSX_Pin|OTG_FS_PSO_Pin, GPIO_PIN_RESET);

 /*Configure GPIO pin Output Level */
 HAL_GPIO_WritePin(ACP_RST_GPIO_Port, ACP_RST_Pin, GPIO_PIN_RESET);

 /*Configure GPIO pin Output Level */
 HAL_GPIO_WritePin(GPIOD, RDX_Pin|WRX_DCX_Pin, GPIO_PIN_RESET);

 /*Configure GPIO pin Output Level */
 HAL_GPIO_WritePin(GPIOG, LD3_Pin|LD4_Pin, GPIO_PIN_RESET);

 /*Configure GPIO pins : A0_Pin A1_Pin A2_Pin A3_Pin
                          A4_Pin A5_Pin SDNRAS_Pin A6_Pin
                          A7_Pin A8_Pin A9_Pin */
 GPIO_InitStruct.Pin = A0_Pin|A1_Pin|A2_Pin|A3_Pin
                         |A4_Pin|A5_Pin|SDNRAS_Pin|A6_Pin
                         |A7_Pin|A8_Pin|A9_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
 GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
 HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

 /*Configure GPIO pin : SDNWE_Pin */
 GPIO_InitStruct.Pin = SDNWE_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
 GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
 HAL_GPIO_Init(SDNWE_GPIO_Port, &GPIO_InitStruct);

 /*Configure GPIO pins : NCS_MEMS_SPI_Pin CSX_Pin OTG_FS_PSO_Pin */
 GPIO_InitStruct.Pin = NCS_MEMS_SPI_Pin|CSX_Pin|OTG_FS_PSO_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

 /*Configure GPIO pins : B1_Pin MEMS_INT1_Pin MEMS_INT2_Pin TP_INT1_Pin */
 GPIO_InitStruct.Pin = B1_Pin|MEMS_INT1_Pin|MEMS_INT2_Pin|TP_INT1_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

 /*Configure GPIO pin : ACP_RST_Pin */
 GPIO_InitStruct.Pin = ACP_RST_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 HAL_GPIO_Init(ACP_RST_GPIO_Port, &GPIO_InitStruct);

 /*Configure GPIO pin : OTG_FS_OC_Pin */
 GPIO_InitStruct.Pin = OTG_FS_OC_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 HAL_GPIO_Init(OTG_FS_OC_GPIO_Port, &GPIO_InitStruct);

 /*Configure GPIO pin : BOOT1_Pin */
 GPIO_InitStruct.Pin = BOOT1_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

 /*Configure GPIO pins : A10_Pin A11_Pin BA0_Pin BA1_Pin
                          SDCLK_Pin SDNCAS_Pin */
 GPIO_InitStruct.Pin = A10_Pin|A11_Pin|BA0_Pin|BA1_Pin
                         |SDCLK_Pin|SDNCAS_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
 GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
 HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

 /*Configure GPIO pins : D4_Pin D5_Pin D6_Pin D7_Pin
                          D8_Pin D9_Pin D10_Pin D11_Pin
                          D12_Pin NBL0_Pin NBL1_Pin */
 GPIO_InitStruct.Pin = D4_Pin|D5_Pin|D6_Pin|D7_Pin
                         |D8_Pin|D9_Pin|D10_Pin|D11_Pin
                         |D12_Pin|NBL0_Pin|NBL1_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
 GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
 HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

 /*Configure GPIO pins : OTG_HS_ID_Pin OTG_HS_DM_Pin OTG_HS_DP_Pin */
 GPIO_InitStruct.Pin = OTG_HS_ID_Pin|OTG_HS_DM_Pin|OTG_HS_DP_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 GPIO_InitStruct.Alternate = GPIO_AF12_OTG_HS_FS;
 HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

 /*Configure GPIO pin : VBUS_HS_Pin */
 GPIO_InitStruct.Pin = VBUS_HS_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 HAL_GPIO_Init(VBUS_HS_GPIO_Port, &GPIO_InitStruct);

 /*Configure GPIO pins : D13_Pin D14_Pin D15_Pin D0_Pin
                          D1_Pin D2_Pin D3_Pin */
 GPIO_InitStruct.Pin = D13_Pin|D14_Pin|D15_Pin|D0_Pin
                         |D1_Pin|D2_Pin|D3_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
 GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
 HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

 /*Configure GPIO pin : TE_Pin */
 GPIO_InitStruct.Pin = TE_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 HAL_GPIO_Init(TE_GPIO_Port, &GPIO_InitStruct);

 /*Configure GPIO pins : RDX_Pin WRX_DCX_Pin */
 GPIO_InitStruct.Pin = RDX_Pin|WRX_DCX_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

 /*Configure GPIO pins : STLINK_RX_Pin STLINK_TX_Pin */
 GPIO_InitStruct.Pin = STLINK_RX_Pin|STLINK_TX_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
 GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
 HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

 /*Configure GPIO pins : LD3_Pin LD4_Pin */
 GPIO_InitStruct.Pin = LD3_Pin|LD4_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

 /*Configure GPIO pins : SDCKE1_Pin SDNE1_Pin */
 GPIO_InitStruct.Pin = SDCKE1_Pin|SDNE1_Pin;
 GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
 GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
 HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

 /** Initializes the CPU, AHB and APB buses clocks
 */




static void MX_LTDC_Init(void)
{

 /* USER CODE BEGIN LTDC_Init 0 */

 /* USER CODE END LTDC_Init 0 */

 LTDC_LayerCfgTypeDef pLayerCfg = {0};
 LTDC_LayerCfgTypeDef pLayerCfg1 = {0};

 /* USER CODE BEGIN LTDC_Init 1 */

 /* USER CODE END LTDC_Init 1 */
 hltdc.Instance = LTDC;
 hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
 hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
 hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
 hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
 hltdc.Init.HorizontalSync = 7;
 hltdc.Init.VerticalSync = 3;
 hltdc.Init.AccumulatedHBP = 14;
 hltdc.Init.AccumulatedVBP = 5;
 hltdc.Init.AccumulatedActiveW = 654;
 hltdc.Init.AccumulatedActiveH = 485;
 hltdc.Init.TotalWidth = 660;
 hltdc.Init.TotalHeigh = 487;
 hltdc.Init.Backcolor.Blue = 0;
 hltdc.Init.Backcolor.Green = 0;
 hltdc.Init.Backcolor.Red = 0;
 if (HAL_LTDC_Init(&hltdc) != HAL_OK)
 {
   Error_Handler();
 }
 pLayerCfg.WindowX0 = 0;
 pLayerCfg.WindowX1 = 0;
 pLayerCfg.WindowY0 = 0;
 pLayerCfg.WindowY1 = 0;
 pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
 pLayerCfg.Alpha = 0;
 pLayerCfg.Alpha0 = 0;
 pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
 pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
 pLayerCfg.FBStartAdress = 0;
 pLayerCfg.ImageWidth = 0;
 pLayerCfg.ImageHeight = 0;
 pLayerCfg.Backcolor.Blue = 0;
 pLayerCfg.Backcolor.Green = 0;
 pLayerCfg.Backcolor.Red = 0;
 if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
 {
   Error_Handler();
 }
 pLayerCfg1.WindowX0 = 0;
 pLayerCfg1.WindowX1 = 0;
 pLayerCfg1.WindowY0 = 0;
 pLayerCfg1.WindowY1 = 0;
 pLayerCfg1.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
 pLayerCfg1.Alpha = 0;
 pLayerCfg1.Alpha0 = 0;
 pLayerCfg1.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
 pLayerCfg1.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
 pLayerCfg1.FBStartAdress = 0;
 pLayerCfg1.ImageWidth = 0;
 pLayerCfg1.ImageHeight = 0;
 pLayerCfg1.Backcolor.Blue = 0;
 pLayerCfg1.Backcolor.Green = 0;
 pLayerCfg1.Backcolor.Red = 0;
 if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg1, 1) != HAL_OK)
 {
   Error_Handler();
 }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV8;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

void SystemClockOverride(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  __HAL_RCC_RNG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  // __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1); // not needed, power scaling consumption for when not running at max freq.

  /* Enable HSE Osc and activate PLL with HSE source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}

//uint32_t GenerateTetrisShape(void){
// 	uint32_t random32bit;
// 	 HAL_StatusTypeDef Status = HAL_RNG_GenerateRandomNumber(&hrng, &random32bit);
// 	 if (Status == HAL_OK){
// 		 uint32_t ShapeSelect = random32bit % 7;
// 		 return ShapeSelect;
// 	 }
// }

uint32_t GenerateTetrisShape(void){
	uint32_t random32bit;
	 HAL_StatusTypeDef Status = HAL_RNG_GenerateRandomNumber(&hrng, &random32bit);
	 if (Status == HAL_OK){
		 int ShapeSelect = random32bit % 7;
		 return ShapeSelect;
	 }
}

uint32_t GenerateRandomColor(void){
 	uint32_t random32bit;
 	 HAL_StatusTypeDef Status = HAL_RNG_GenerateRandomNumber(&hrng, &random32bit);
 	 if (Status == HAL_OK){
 		 int ShapeSelect = random32bit % 6;
 		 return ShapeSelect;
 	 }
 }




#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
