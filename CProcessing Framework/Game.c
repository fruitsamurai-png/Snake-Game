#include "CProcessing.h"
#include "Game.h"
#include "food.h"
#include "gameover.h"
#include <stdio.h>
#include <stdlib.h>

CP_Vector snakeWidth[MAXTRAIL];
char characterBuffer[100];
int foodtimer = 0, timer=0;

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
	foodtimer = food.foodcount;
	_itoa_s(foodtimer, characterBuffer,100,10);//convert the int to string
	CP_Font_DrawText(characterBuffer, 0, 300);
}
void Snake_init(void)//Initial snake spawn and shape
{
	snake.length = 1;//reset the snakelength.
	foodtimer = 0;//reset the food score
	timer = 0;//reset the timer to 0
	snake.x = 10;//initial x coordinate of the snake
	snake.y = 10;//initial y coordinate of the snake
}

void Snake_update(void)
{
	Snake_wall(snake.x, snake.y);
	
	if (CP_Input_KeyTriggered(KEY_W) && snake.dir != 2)//to choose the direction of the snake
		snake.dir = 0;
	else if (CP_Input_KeyTriggered(KEY_A) && snake.dir != 3)
		snake.dir = 1;
	else if (CP_Input_KeyTriggered(KEY_S) && snake.dir != 0)
		snake.dir = 2;
	else if (CP_Input_KeyTriggered(KEY_D) && snake.dir != 1)
		snake.dir = 3;

	if (CP_System_GetFrameCount() % 8 == 0)
	{
		if (snake.dir == 0)
			snake.y -=1;
		else if (snake.dir == 1)
			snake.x -=1;
		else if (snake.dir == 2)
			snake.y +=1;
		else if (snake.dir == 3)
			snake.x +=1;
		for (int i = snake.length - 1; i > 0; i--)
		{
			snakeWidth[i] = snakeWidth[i - 1];
		}
		snakeWidth[0] = CP_Vector_Set((float)snake.x, (float)snake.y);
		CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
		for (int i = 0; i < snake.length; i++)
		{
			CP_Graphics_DrawRect(snakeWidth[i].x * 10, snakeWidth[i].y * 10, 10, 10);
		}
		score();
	}
}
void Snake_exit(void)
{
	
}
