//---------------------------------------------------------
// file:	main.c
// author:	Keith Chng
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "CProcessing.h"
#include "main.h"
#include "food.h"
#include "gameover.h"
#include <stdio.h>
#include <stdlib.h>
#include "mainmenu.h"


char characterBuffer[100];
int foodtimer = 0;
double delta = 0;

void Snake_wall(int a, int b) {// Wall and snake collision. Bound x and y are the coordinates of the wall
	if (a < blocksize || a > (window-blocksize) || b < blocksize || b > (window-blocksize)){
		CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
	}
	for (int i = 1; i < snake.length; i++)
	{
		if (snakeWidth[i].x == snake.x && snakeWidth[i].y == snake.y)//if the snake head collides with any part of snakewidth,gameover
		{
			CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
		}
	}
}
void score()
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));//black
	memset(characterBuffer, 0, 100* sizeof(char));//reset the array to zero
	foodtimer = food.foodcount;
	_itoa_s(foodtimer, characterBuffer,100,10);//convert the int to string
	CP_Font_DrawText(characterBuffer, 220, maxy+90);
	_itoa_s(snake.score, characterBuffer, 100, 10);
	CP_Font_DrawText(characterBuffer, 220, maxy+80);
}
void main_init(void)//Initial snake spawn and shape
{
	delta = 0;//reset the delta
	Food_init();
	snake.length = 2;//reset the snakelength.
	foodtimer = 0;//reset the food score
	snake.score = 0;//reset the timer to 0
	snake.x = maxx/10;//initial x coordinate of the snake
	snake.y = maxy/2;//initial y coordinate of the snake
	snake.dir = 3;//intial snake direction
	//Background colour
}

void main_update(void)
{
	for (int i = snake.length - 1; i > 0; i--)//allow snake to bend
	{
		snakeWidth[i] = snakeWidth[i - 1];
	}
	snakeWidth[0] = CP_Vector_Set((float)snake.x, (float)snake.y);//move snake.x and snake.y to the position based on the snake direction

	Food_update();

	//Draw snake length
	for (int i = 0; i < snake.length; ++i)
	{
		CP_Settings_Fill(CP_Color_Create(147, 112, 219, 255));
		CP_Graphics_DrawRect((float)(snakeWidth[i].x), (float)(snakeWidth[i].y), blocksize, blocksize);
	}
	if ((CP_Input_KeyTriggered(KEY_W)|| CP_Input_KeyTriggered(KEY_UP)) && snake.dir != 2)//to choose the direction of the snake
		snake.dir = 0;//UP
	else if ((CP_Input_KeyTriggered(KEY_A)|| CP_Input_KeyTriggered(KEY_LEFT)) && snake.dir != 3)
		snake.dir = 1;//LEFT
	else if ((CP_Input_KeyTriggered(KEY_S)|| CP_Input_KeyTriggered(KEY_DOWN)) && snake.dir != 0)
		snake.dir = 2;//DOWN
	else if ((CP_Input_KeyTriggered(KEY_D)|| CP_Input_KeyTriggered(KEY_RIGHT)) && snake.dir != 1)
		snake.dir = 3;//RIGHT
	
	if (delta>=0.3)
	{
		snake.movement = 40;

		switch (snake.dir) {//speed of the snake after direction is chosen
		case 0:
			snake.y -= (int)snake.movement; break;
		case 1:
			snake.x -= (int)snake.movement; break;
		case 2:
			snake.y += (int)snake.movement; break;
		default://3
			snake.x += (int)snake.movement;
		}

		Snake_wall(snake.x, snake.y);

		//draw out the border
		CP_Settings_Fill(CP_Color_Create(250, 235, 215, 255));//border color
		CP_Graphics_DrawRect(0, 0, 500, blocksize);//Top border
		CP_Graphics_DrawRect(0, 470, 500, blocksize);//Down
		CP_Graphics_DrawRect(0, blocksize, blocksize, 440);//Left
		CP_Graphics_DrawRect(470, blocksize, blocksize, 440);//Right
		
		score();

		delta = 0;//resets the delta time after each frame
		snake.score++;//increment the score by 1 each deltatime
		CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));// refresh the scene with the background
	}
	delta += CP_System_GetDt();//get the delta time of each frame
}
void main_exit(void)
{
	Food_exit();
}
int main(void)
{
	CP_System_SetWindowSize(window, window);
	CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	CP_Engine_Run();
	return 0;
}