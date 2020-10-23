#include "cprocessing.h"
#include "food.h"
#include "main.h"

void Food_init(void)
{
	food.foodcount = 0;
	food.x = CP_Random_RangeInt(0, 10) * 40;//so that the food will spawn in the coordinates of multiples 40
	food.y = CP_Random_RangeInt(0, 10) * 40;
}

void Food_update(void)
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	CP_Graphics_DrawRect((float)food.x, (float)food.y, 10, 10);

	if (snake.x == food.x && snake.y == food.y)//collision for the food and the snake
	{
		food.x = CP_Random_RangeInt(0, 10)*40 ;//so that the food will spawn in the coordinates of multiples 40
		food.y = CP_Random_RangeInt(0, 10)*40 ;
		food.foodcount+=10;// to be implemented in the score
		snake.length++;//for increasing the snakelength when food is consumed
	}
}

void Food_exit(void)
{
}