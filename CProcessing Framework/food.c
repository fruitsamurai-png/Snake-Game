#include "cprocessing.h"
#include "food.h"
#include "move.h"

void food_init(void)
{
	food.a = 50;
	food.b = 50;
}

void food_update(void)
{
	food.a = 50;
	food.b = 50;
	CP_Graphics_DrawRect((float)food.a, (float)food.b, 10, 10);
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	if (snake.x == food.a && snake.y == food.b)
	{
		CP_Graphics_DrawRect((float)snake.x + 10, (float)snake.y - 10, 10, 10);
	}
}

void food_exit(void)
{

}