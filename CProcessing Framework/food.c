#include "cprocessing.h"
#include "food.h"
#include "main.h"

void Food_init(void)
{
	food.foodcount = 0; //spawn at the middle of the screen
		food.x = 200;
		food.y = 200;
		CP_Settings_Fill(CP_Color_Create(0, 139, 139, 255));
}

void Food_update(void)
{
	int check=0;
	if (snake.x == food.x && snake.y == food.y)//collision for the food and the snake
	{
		for (int i = 0; i < snake.length; ++i)
		{
			if (snakeWidth[i].x == food.x && snakeWidth[i].y == food.y)
			{
				check = 1;
				food.x = CP_Random_RangeInt(1, 9) * 40;//so that the food will spawn in the coordinates of multiples 40
				food.y = CP_Random_RangeInt(1, 9) * 40;
					break;
			}
		}
		while(check)
		{
			check = 0;
			for (int i = 0; i < snake.length; ++i)
			{
				if (snakeWidth[i].x == food.x && snakeWidth[i].y == food.y)//to prevent the food from spawning on the snake body
				{
					check = 1;
					food.x = CP_Random_RangeInt(1, 9) * 40;//so that the food will spawn in the coordinates of multiples 40
					food.y = CP_Random_RangeInt(1, 9) * 40;
					break;
				}
			}
		}
		food.foodcount++;// to be implemented in the score
		snake.length++;//for increasing the snakelength when food is consumed
	}
	CP_Settings_Fill(CP_Color_Create(0, 139, 139, 255));//dark green
	CP_Graphics_DrawRect((float)food.x, (float)food.y, 30, 30);
}

void Food_exit(void)
{
}