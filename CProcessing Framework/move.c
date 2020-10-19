#include "CProcessing.h"
#include "move.h"
struct snake
{
	int x, y, dir;
}snake;
void collide_wall(int x, int y) {// Wall collision. Bound x and y are the coordinates of the wall
	int bound_x1 = 0, bound_x2 = 370, bound_y1 = 0, bound_y2 = 390;
	if (x <= bound_x1 || x > bound_x2 || y <= bound_y1 || y >= bound_y2) {
		CP_Engine_Terminate();//Safinah change this to changegamestate
	}
}
void move_init(void)//Initial snake spawn and shape
{
	snake.x = 100;
	snake.y = 100;
	CP_Graphics_DrawRect((float)snake.x, (float)snake.y, 20, 20);//initial snake shape
}
void move_update(void)
{
	double delta = 0.8;//delta time to reduce the speed of the snake. Xuan u need to implement this delta time to your power up.
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));//refresh the scene with the background.
	if (CP_Input_KeyTriggered(KEY_W) && snake.dir!=2)//to choose the direction of the snake
		snake.dir = 0;
	else if (CP_Input_KeyTriggered(KEY_A) && snake.dir !=3)
		snake.dir = 1;
	else if (CP_Input_KeyTriggered(KEY_S) && snake.dir != 0)
		snake.dir = 2;
	else if (CP_Input_KeyTriggered(KEY_D) && snake.dir != 1)
		snake.dir = 3;
		if (snake.dir==0)
		{
			snake.y -= (int)(5 * delta);// net speed of the snake 
			CP_Graphics_DrawRect((float)snake.x, (float)snake.y, 10, 10);//shape of the snake 
		}
		else if (snake.dir==1)
		{
			snake.x -= (int)(5 * delta);
			CP_Graphics_DrawRect((float)snake.x, (float)snake.y, 10, 10);
		}
		else if (snake.dir == 2)
		{
			snake.y += (int)(5 * delta);
			CP_Graphics_DrawRect((float)snake.x, (float)snake.y, 10, 10);
		}
		else if (snake.dir == 3)
		{
			snake.x += (int)(5 * delta);
			CP_Graphics_DrawRect((float)snake.x, (float)snake.y, 10, 10);
		}

		collide_wall(snake.x, snake.y);
}
void move_exit(void)
{

}
