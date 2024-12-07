/*
 * StartPlayAndTimeScreen.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Owner
 */

#include "StartPlayAndTimeScreen.h"

void GamePlatform(void){
	uint16_t endX = 240;
	uint16_t Xpos = 0;
	uint16_t Ypos = 300;
	uint32_t color = LCD_COLOR_BLACK;
		for(;Xpos<endX;Xpos++){
			LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);

		}

}


void StartScreen(void){
	// This for loop just illustrates how with using logic and for loops, you can create interesting things
		// this may or not be useful ;)
	//	for(y=0; y<LCD_PIXEL_HEIGHT; y++){
	//		for(x=0; x < LCD_PIXEL_WIDTH; x++){
	//			if (x & 32)
	//				frameBuffer[x*y] = LCD_COLOR_WHITE;
	//			else
	//				frameBuffer[x*y] = LCD_COLOR_BLACK;
	//		} //WEIRD BROKEN SCREEN IMAGE

	//	HAL_Delay(1500);
	//	LCD_Clear(0, LCD_COLOR_GREEN);
	//	HAL_Delay(1500);
	//	LCD_Clear(0, LCD_COLOR_RED);
	//	HAL_Delay(1500);
	//	LCD_Clear(0, LCD_COLOR_WHITE);
	//	LCD_Draw_Vertical_Line(10,10,250,LCD_COLOR_MAGENTA);
	//	HAL_Delay(1500);
	//	LCD_Draw_Vertical_Line(230,10,250,LCD_COLOR_MAGENTA);
	//	HAL_Delay(1500);

	//	LCD_Draw_Circle_Fill(125,150,20,LCD_COLOR_BLACK);
	//	HAL_Delay(100);
	//
		LCD_Clear(0,LCD_COLOR_WHITE);
		LCD_SetTextColor(LCD_COLOR_BLACK);
		LCD_SetFont(&Font16x24);
		//LCD_SetFont(LCD_Currentfonts);



	//	LCD_DisplayChar(Xpos, Ypos, Ascii)
		//total width is 240, total height is 320
		//                   x, y

			LCD_DisplayChar(76,17,'T');
			LCD_DisplayChar(93,17,'E'); //+18
			LCD_DisplayChar(108,17,'T'); //+15
			LCD_DisplayChar(125,17,'R'); //+17
			LCD_DisplayChar(136,17,'I'); //+11
			LCD_DisplayChar(146,17,'S'); //+10

			LCD_DisplayChar(10,260,'T');
			LCD_DisplayChar(25,260,'o');
			LCD_DisplayChar(40,260,'u');
			LCD_DisplayChar(55,260,'c');
			LCD_DisplayChar(70,260,'h');

			LCD_DisplayChar(100,260,'S');
			LCD_DisplayChar(115,260,'c');
			LCD_DisplayChar(130,260,'r');
			LCD_DisplayChar(145,260,'e');
		    LCD_DisplayChar(160,260,'e');
		    LCD_DisplayChar(175,260,'n');

		    LCD_DisplayChar(200,260,'t');
		    LCD_DisplayChar(210,260,'o');

		    LCD_DisplayChar(105,290,'P');
		    LCD_DisplayChar(120,290,'l');
		    LCD_DisplayChar(135,290,'a');
		    LCD_DisplayChar(150,290,'y');

		    //Shapes(X,Y,COLOR)
		    LCD_DrawSingleSquare(10, 50, LCD_COLOR_RED);
		    LCD_DrawLShape(10,160, LCD_COLOR_MAGENTA);
		    LCD_DrawHatShape(98, 50, LCD_COLOR_GREEN);
		    LCD_DrawZShape(175, 40,LCD_COLOR_BLUE);
		    LCD_DrawSShape(160, 160, LCD_COLOR_RED);
		    LCD_DrawJShape(80,160, LCD_COLOR_YELLOW);
		    LCD_DrawIShape(55,60, LCD_COLOR_CYAN);
//
//	    	LCD_DrawLShapeRotCWOnce(80, 160, LCD_COLOR_BLACK);
//	    	LCD_DrawLShapeRotCWTwice(50, 100, LCD_COLOR_RED);
//		    LCD_DrawLShapeRotCWThrice(80, 160, LCD_COLOR_BLACK);

//		    LCD_DrawIShapeRotCWOnce(80, 160, LCD_COLOR_BLACK)

//		    LCD_DrawJShapeRotCWOnce(100, 200, LCD_COLOR_BLACK);
//		    LCD_DrawJShapeRotCWTwice(80, 160, LCD_COLOR_BLACK);
//		    LCD_DrawJShapeRotCWThrice(80, 160, LCD_COLOR_BLACK);

//		    LCD_DrawHatShapeRotCWOnce(130, 160, LCD_COLOR_BLACK);
//		    LCD_DrawHatShapeRotCWTwice(120, 80, LCD_COLOR_BLACK);
//		    LCD_DrawHatShapeRotCWThrice(10, 160, LCD_COLOR_BLACK);

//		    LCD_DrawZShapeRotCWOnce(120, 80, LCD_COLOR_BLACK);

//		    LCD_DrawSShapeRotCWOnce(120, 80, LCD_COLOR_BLACK);

}
