#include "cprocessing.h"
#include "food.h"
#include "Game.h"

void Food_init(void)
{
	food.foodcount = 0;
	food.x = CP_Random_RangeInt(2, maxx - 2);//so that the food will spawn in the coordinates of multiple 20
	food.y = CP_Random_RangeInt(2, maxy - 2);

}

void Food_update(void)
{

	CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	CP_Graphics_DrawRect((float)food.x * 10, (float)food.y * 10, 10, 10);

	if (food.foodcount < 0)//collision for the food and the snake
	{
		food.x = CP_Random_RangeInt(2, maxx - 2);//so that the food will spawn in the coordinates of multiple 20
		food.y = CP_Random_RangeInt(2, maxy - 2);
		food.foodcount += 1;// to be implemented in the array of the snake length
	}
	
}

void Food_exit(void)
{

}