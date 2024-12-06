/*
 * GameLogistics.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Owner
 */
#include "LCD_Driver.h"

void LCD_DrawSingleSquare(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 30; //adds 30 from wherever you start on x axis
	uint16_t endY = 30; //makes it longer
	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
	}} //no need for rotation

void LCD_DrawLShape(uint16_t Xpos, uint16_t Ypos, uint16_t color){

	uint16_t endX = Xpos + 30;
	uint16_t endY = Ypos + 30;
	uint16_t endXX = endX + 1;
	uint16_t endYY = endY + 30;
	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);
	}
	for (;endX < endXX ;endX++){
		LCD_DrawSingleSquare(endX, endYY, color);
	}
}


void LCD_DrawIShape(uint16_t Xpos, uint16_t Ypos, uint16_t color){

	uint16_t endX = Xpos + 30;

	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);

	}
}

void LCD_DrawJShape(uint16_t Xpos, uint16_t Ypos, uint16_t color){

	uint16_t endX = Xpos + 30;
	uint16_t endY = Ypos + 30;
	uint16_t endXX = endX + 1;
	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);
	}
	for (;endX < endXX ;endX++){
		LCD_DrawSingleSquare(endX, Ypos, color);
	}
}

void LCD_DrawHatShape(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 30;
	uint16_t endY = Ypos + 30;
	uint16_t endXX = endX + 1;
	//	uint16_t endYY = endY + 30;
	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);
	}
	for (;endX < endXX ;endX++){
		LCD_DrawSingleSquare(endX, endY, color);
	}
}
void LCD_DrawZShape(uint16_t Xpos, uint16_t Ypos, uint16_t color){

	uint16_t endX = Xpos + 30;
	uint16_t endY = Ypos + 30;
	uint16_t endXX = endX + 1;
	uint16_t endYY = endY + 30;
	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);
		LCD_DrawSingleSquare((Xpos-30), Ypos, color);
	}
	for (;endX < endXX ;endX++){
		LCD_DrawSingleSquare(endX, endYY, color);
	}
}
void LCD_DrawSShape(uint16_t Xpos, uint16_t Ypos, uint16_t color){

	uint16_t endX = Xpos + 30;
	uint16_t endY = Ypos + 30;
	uint16_t endXX = endX + 1;
	uint16_t endYY = endY + 30;
	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);
		LCD_DrawSingleSquare(endX, Ypos, color);
	}
	for (;endX < endXX ;endX++){
		LCD_DrawSingleSquare((Xpos-60), endYY, color);
	}
}

//***********************Beginnig of Rotations
void LCD_DrawLShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
		uint16_t endY = 30; //makes it longer
		uint16_t endYY = Ypos + 30;

		for(;Xpos<endX;Xpos++){
			LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
		}
		for(;Ypos<endYY;Ypos++){
		LCD_DrawSingleSquare(Xpos - 90, endYY, color);
	}
}

void LCD_DrawLShapeRotCWTwice(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	 	uint16_t endX = Xpos + 30;
	    uint16_t endY = Ypos + 60;
	    for (; Xpos < endX; Xpos++) {
	        LCD_DrawSingleSquare(Xpos, Ypos, color);
	    }

	    for (;Ypos < endY; Ypos++) {
	        LCD_DrawSingleSquare(Xpos , Ypos, color);
	    }
}

void LCD_DrawLShapeRotCWThrice(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
				uint16_t endY = 30; //makes it longer
				uint16_t endYY = Ypos + 30;

				for(;Xpos<endX;Xpos++){
					LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
				}
				for(;Ypos<endYY;Ypos++){
				LCD_DrawSingleSquare(Xpos-30, Ypos-30, color);
			}

}

void LCD_DrawIShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
				uint16_t endY = 30; //makes it longer
				for(;Xpos<endX;Xpos++){
					LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
				}
}

void LCD_DrawJShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
			uint16_t endY = 30; //makes it longer
			uint16_t endYY = Ypos + 30;

			for(;Xpos<endX;Xpos++){
				LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
			}
			for(;Ypos<endYY;Ypos++){
			LCD_DrawSingleSquare(Xpos - 90, Ypos - 30, color);
		}
}
void LCD_DrawJShapeRotCWTwice(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 30;
		    uint16_t endY = Ypos + 60;
		    for (; Xpos < endX; Xpos++) {
		        LCD_DrawSingleSquare(Xpos, Ypos, color);
		    }

		    for (;Ypos < endY; Ypos++) {
		        LCD_DrawSingleSquare(Xpos - 30 , Ypos, color);
		    }
}
void LCD_DrawJShapeRotCWThrice(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
				uint16_t endY = 30; //makes it longer
				uint16_t endYY = Ypos + 30;

				for(;Xpos<endX;Xpos++){
					LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
				}
				for(;Ypos<endYY;Ypos++){
				LCD_DrawSingleSquare(Xpos-30, endYY, color);
			}
}

void LCD_DrawHatShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
			uint16_t endY = 30; //makes it longer
			uint16_t endYY = Ypos + 30;

			for(;Xpos<endX;Xpos++){
				LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
			}
			for(;Ypos<endYY;Ypos++){
			LCD_DrawSingleSquare(Xpos - 60, endYY, color);
		}


}
void LCD_DrawHatShapeRotCWTwice(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 30;
		uint16_t endY = Ypos + 30;
		uint16_t endXX = endX + 1;
		//	uint16_t endYY = endY + 30;
		for(;Xpos<endX;Xpos++){
			LCD_Draw_Vertical_Line(Xpos, Ypos, 90, color);
		}
		for (;Ypos < endY ;Ypos++){
			LCD_DrawSingleSquare(Xpos-60, endY, color);
		}
}
void LCD_DrawHatShapeRotCWThrice(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
			uint16_t endY = 30; //makes it longer
			uint16_t endYY = Ypos + 30;

			for(;Xpos<endX;Xpos++){
				LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
			}
			for(;Ypos<endYY;Ypos++){
			LCD_DrawSingleSquare(Xpos - 60, Ypos-30, color);
		}

}

void LCD_DrawZShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
uint16_t endY = 30; //makes it longer
uint16_t endYY = Ypos + 30;

for(;Xpos<endX;Xpos++){
	LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
}
for(;Ypos<endYY;Ypos++){
LCD_DrawSingleSquare(Xpos - 90, endYY, color);
LCD_DrawSingleSquare(Xpos-30, Ypos - 30, color);
}
}

void LCD_DrawSShapeRotCWOnce(uint16_t Xpos, uint16_t Ypos, uint16_t color){
	uint16_t endX = Xpos + 90; //adds 30 from wherever you start on x axis
	uint16_t endY = 30; //makes it longer
	uint16_t endYY = Ypos + 30;

	for(;Xpos<endX;Xpos++){
		LCD_Draw_Vertical_Line(Xpos, Ypos, endY, color);
	}
	for(;Ypos<endYY;Ypos++){
	LCD_DrawSingleSquare(Xpos - 90,Ypos - 30 , color);
	LCD_DrawSingleSquare(Xpos-30, endYY, color);
	}
}

