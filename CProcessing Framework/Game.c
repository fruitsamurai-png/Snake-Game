#include "CProcessing.h"
#include "Game.h"
#include "food.h"

CP_Vector snakeWidth[MAXTRAIL];
int snakeLength = 1;

float timer = 0;
float interval = 0.5f;

void Snake_wall(int a, int b) {// Wall collision. Bound x and y are the coordinates of the wall
	int bound_x1 = 0, bound_y1 = 0;
	if (a < bound_x1 || a > maxx || b < bound_y1 || b > maxy) {
		CP_Engine_Terminate();//Safinah change this to changegamestate
	}
}

void Snake_init(void)//Initial snake spawn and shape
{
	snake.x = 10;
	snake.y = 10;
	//CP_Graphics_DrawRect((float)snake.x * 10, (float)snake.y * 10, 10, 10);
}

void Snake_update(void)
{
	Snake_wall(snake.x, snake.y);

	if (CP_System_GetFrameCount() % 1 == 0)
	{
		CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	}

	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	CP_Graphics_DrawRect((float)snake.x * 10, (float)snake.y * 10, 10, 10);

	for (int i = 0; i < snakeLength; i++)
	{
		CP_Graphics_DrawRect(snakeWidth[i].x * 10, snakeWidth[i].y * 10, 10, 10);
	}

	for (int i = snakeLength - 1; i > 0; i--)
	{
		snakeWidth[i] = snakeWidth[i - 1];

	}
	snakeWidth[0] = CP_Vector_Set((float)snake.x, (float)snake.y);

	if (CP_Input_KeyTriggered(KEY_W) && snake.dir != 2)//to choose the direction of the snake
		snake.dir = 0;
	else if (CP_Input_KeyTriggered(KEY_A) && snake.dir != 3)
		snake.dir = 1;
	else if (CP_Input_KeyTriggered(KEY_S) && snake.dir != 0)
		snake.dir = 2;
	else if (CP_Input_KeyTriggered(KEY_D) && snake.dir != 1)
		snake.dir = 3;

	if (snake.dir == 0 && CP_System_GetFrameCount() % 10 == 0)
		snake.y -= 1;//speed of the snake 
	else if (snake.dir == 1 && CP_System_GetFrameCount() % 10 == 0)
		snake.x -= 1;
	else if (snake.dir == 2 && CP_System_GetFrameCount() % 10 == 0)
		snake.y += 1;
	else if (snake.dir == 3 && CP_System_GetFrameCount() % 10 == 0)
		snake.x += 1;

	timer += CP_System_GetDt();

	if (timer >= interval)
	{
		timer -= interval;
		if (snake.x == food.x && snake.y == food.y)
		{
			food.foodcount -= 1;
		}
	}

	if (snake.x == food.x && snake.y == food.y)
	{
		snakeLength++;
	}

}
void Snake_exit(void)
{
	
}
