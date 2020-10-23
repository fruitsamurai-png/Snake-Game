#pragma once
#define maxx 40//x boundaries
#define maxy 40//y boundaries
#define MAXTRAIL 40

float score_timer;

struct snake
{
	int x, y, dir;//array of the body of the snake
}snake;

void Snake_init(void);
void Snake_update(void);
void Snake_exit(void);

