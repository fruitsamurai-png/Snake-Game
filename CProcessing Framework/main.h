#pragma once
#define maxx 400//x boundaries
#define maxy 400//y boundaries
#define MAXTRAIL 40

struct snake
{
	double movement;
	int x, y, dir,length,score;//array of the body of the snake
}snake;

void main_init(void);
void main_update(void);
void main_exit(void);

