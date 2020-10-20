#pragma once
#define maxx 420//x boundaries
#define maxy 420//y boundaries
struct snake
{
	int x, y, dir;
	int length[420];//array of the body of the snake
}snake;

void game_init(void);
void game_update(void);
void game_exit(void);