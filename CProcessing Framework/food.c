#include "cprocessing.h"
#include "food.h"
#include "Main.h"

void food_init(void)
{
	
	food.x = 60;
	food.y = 60;
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Graphics_DrawRect((float)food.x, (float)food.y, 20, 20);
	
}

void food_update(void)
{
	if (snake.x == food.x && snake.y == food.y)//collision for the food and the snake
	{
		food.x = CP_Random_RangeInt(0, maxx/42)*20;//so that the food will spawn in the coordinates of multiple 20
		food.y = CP_Random_RangeInt(0, maxy/42)*20;
		food.foodcount+=2;// to be implemented in the array of the snake length
	}
	CP_Graphics_DrawRect((float)food.x, (float)food.y, 20, 20);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
}

void food_exit(void)
{

}