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

CP_Vector snakeWidth[MAXTRAIL];
char characterBuffer[100];
int foodtimer = 0;
double delta = 0;

void Snake_wall(int a, int b) {// Wall and snake collision. Bound x and y are the coordinates of the wall
	int bound_x1 = 0, bound_y1 = 0;
	if (a < bound_x1 || a > maxx || b < bound_y1 || b > maxy) {
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
	memset(characterBuffer, 0, 100* sizeof(char));//reset the array to zero
	foodtimer = food.foodcount+snake.score;
	_itoa_s(foodtimer, characterBuffer,100,10);//convert the int to string
	CP_Font_DrawText(characterBuffer, 0, 450);
	CP_Settings_Fill(CP_Color_Create(0, 255, 255, 255));
}
void main_init(void)//Initial snake spawn and shape
{
	delta = 0;
	Food_init();
	snake.length = 1;//reset the snakelength.
	foodtimer = 0;//reset the food score
	snake.score = 0;//reset the timer to 0
	snake.x = 20;//initial x coordinate of the snake
	snake.y = 20;//initial y coordinate of the snake
}

void main_update(void)
{
	score();
	Food_update();
	Snake_wall(snake.x, snake.y);
	if (CP_Input_KeyTriggered(KEY_W) && snake.dir != 2)//to choose the direction of the snake
		snake.dir = 0;
	else if (CP_Input_KeyTriggered(KEY_A) && snake.dir != 3)
		snake.dir = 1;
	else if (CP_Input_KeyTriggered(KEY_S) && snake.dir != 0)
		snake.dir = 2;
	else if (CP_Input_KeyTriggered(KEY_D) && snake.dir != 1)
		snake.dir = 3;
	if (delta>=0.5)
	{
		double vel = 0;
		vel = 20;
		snake.movement = vel * delta;
		if (snake.dir == 0)
			snake.y -= (int)snake.movement;
		else if (snake.dir == 1)
			snake.x -= (int)snake.movement;
		else if (snake.dir == 2)
			snake.y += (int)snake.movement;
		else if (snake.dir == 3)
			snake.x += (int)snake.movement;
		for (int i = snake.length - 1; i > 0; i--)
		{
			snakeWidth[i] = snakeWidth[i - 1];
		}
		snakeWidth[0] = CP_Vector_Set((float)snake.x, (float)snake.y);
		CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_Fill(CP_Color_Create(0, 255, 255, 255));
		for (int i = 0; i < snake.length; i++)
		{
			CP_Graphics_DrawRect((float)(snakeWidth[i].x), (float)(snakeWidth[i].y ), 10, 10);
		}
		delta = 0;//resets the delta time after each frame
		snake.score += 1;//increment the score by 1 each deltatime
	}
	delta += CP_System_GetDt();
}
void main_exit(void)
{
	Food_exit();
}
int main(void)
{
	CP_System_SetWindowSize(400, 500);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	CP_Engine_Run();
	return 0;
}