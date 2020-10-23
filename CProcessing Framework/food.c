#include "cprocessing.h"
#include "food.h"
#include "Game.h"

void Food_init(void)
{
	food.foodcount = 0;
	food.x = CP_Random_RangeInt(0, maxx - 2) ;//so that the food will spawn in the coordinates of multiples
	food.y = CP_Random_RangeInt(0, maxy - 2) ;
}

void Food_update(void)
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	CP_Graphics_DrawRect((float)food.x*10, (float)food.y*10, 10, 10);

	if (snake.x == food.x && snake.y == food.y)//collision for the food and the snake
	{
		food.x = CP_Random_RangeInt(0, maxx - 2) ;//so that the food will spawn in the coordinates of multiples
		food.y = CP_Random_RangeInt(0, maxy -2) ;
		food.foodcount ++;// to be implemented in the score
		snake.length++;//for increasing the snakelength when food is consumed
	}
}

void Food_exit(void)
{
}