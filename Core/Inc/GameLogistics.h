/*
 * GameLogistics.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Owner
 */

#ifndef INC_GAMELOGISTICS_H_
#define INC_GAMELOGISTICS_H_

#include "stm32f4xx_hal.h"
#include "ili9341.h"
#include "fonts.h"
#include "stmpe811.h"
#include "RngDriver.h"

void LCD_DrawSingleSquare(uint16_t Xpos, uint16_t Ypos, uint16_t color); //0 rotations
void LCD_DrawLShape(uint16_t Xpos, uint16_t Ypos, uint16_t color); //3 more rotations
void LCD_DrawIShape(uint16_t Xpos, uint16_t Ypos, uint16_t color); //1 more rotation
void LCD_DrawJShape(uint16_t Xpos, uint16_t Ypos, uint16_t color); //3 more rotations
void LCD_DrawHatShape(uint16_t Xpos, uint16_t Ypos, uint16_t color); //3 more rotations
void LCD_DrawZShape(uint16_t Xpos, uint16_t Ypos, uint16_t color);   //1 more rotation
void LCD_DrawSShape(uint16_t Xpos, uint16_t Ypos, uint16_t color);	//1 more rotations

//Rotations, a total of = 23
void LCD_DrawLShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color); //done
void LCD_DrawLShapeRotCWTwice(uint16_t Xpos, uint16_t Ypos, uint16_t color); //done
void LCD_DrawLShapeRotCWThrice(uint16_t Xpos, uint16_t Ypos, uint16_t color);

void LCD_DrawIShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color);

void LCD_DrawJShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color);
void LCD_DrawJShapeRotCWTwice(uint16_t Xpos, uint16_t Ypos, uint16_t color);
void LCD_DrawJShapeRotCWThrice(uint16_t Xpos, uint16_t Ypos, uint16_t color);

void LCD_DrawHatShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color);
void LCD_DrawHatShapeRotCWTwice(uint16_t Xpos, uint16_t Ypos, uint16_t color);
void LCD_DrawHatShapeRotCWThrice(uint16_t Xpos, uint16_t Ypos, uint16_t color);

void LCD_DrawZShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color);

void LCD_DrawSShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color);


void DrawRandomShape(uint16_t x, uint16_t y, uint16_t color);
void DrawRandomShape(uint16_t x, uint16_t y, uint16_t color);

//void (*Shapes[7])(uint16_t, uint16_t, uint16_t);






#endif /* INC_GAMELOGISTICS_H_ */
