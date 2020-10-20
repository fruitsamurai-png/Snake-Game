#include "CProcessing.h"
#include "Main.h"
#include "food.h"
void collide_wall(int x, int y) {// Wall collision. Bound x and y are the coordinates of the wall
	int bound_x1 = 0, bound_y1 = 0;
	if (x < bound_x1 || x > maxx || y < bound_y1 || y > maxy) {
		CP_Engine_Terminate();//Safinah change this to changegamestate
	}
}
void snakelength(void)
{
	for (int i = 0; i < food.foodcount; ++i)
	{
		snake.length[food.foodcount - 1] = snake.x * 20;
		snake.length[food.foodcount] = snake.y * 20;
		CP_Graphics_DrawRect((float)snake.x + snake.length[food.foodcount - 1], (float)snake.y + snake.length[food.foodcount], 20, 20);
	}
}
void game_init(void)//Initial snake spawn and shape
{
	CP_System_SetWindowSize(maxx, maxy);
	food_init();
	snake.x = 100;
	snake.y = 100;
	CP_Graphics_DrawRect((float)snake.x, (float)snake.y, 20, 20);//initial snake shape
}
void game_update(void)
{
	if (CP_System_GetFrameCount() % 20 == 0)
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));//refresh the scene with the background.

	collide_wall(snake.x, snake.y);//collide wall function

	if (CP_Input_KeyTriggered(KEY_W) && snake.dir!=2)//to choose the direction of the snake
		snake.dir = 0;
	else if (CP_Input_KeyTriggered(KEY_A) && snake.dir !=3)
		snake.dir = 1;
	else if (CP_Input_KeyTriggered(KEY_S) && snake.dir != 0)
		snake.dir = 2;
	else if (CP_Input_KeyTriggered(KEY_D) && snake.dir != 1)
		snake.dir = 3;

		if (snake.dir==0 && CP_System_GetFrameCount()%20==0)
			snake.y -= 20;//speed of the snake 
		else if (snake.dir==1 && CP_System_GetFrameCount() % 20 == 0)
			snake.x -= 20;
		else if (snake.dir == 2 && CP_System_GetFrameCount() % 20 == 0)
			snake.y += 20;
		else if (snake.dir == 3 && CP_System_GetFrameCount() % 20 == 0)
			snake.x += 20;
		CP_Graphics_DrawRect((float)snake.x, (float)snake.y, 20, 20);
		food_update();
}
void game_exit(void)
{
	food_exit();
}
int main(void)
{
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}