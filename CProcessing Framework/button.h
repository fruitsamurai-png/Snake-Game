#pragma once
#include "cprocessing.h"

typedef struct Button 
{
	CP_Image image;
	char* text;
	float xposition;
	float yposition;
	float sizex;
	float sizey;

}Button;

Button playButton;
Button howtoplayButton;
Button exitButton;
Button restartButton;
Button menuButton;

float WINDOW_HEIGHT;
float WINDOW_WIDTH;

//prototypes
void play(Button button);

void howtoplay(Button button);

void exitgame(Button button);

void restart(Button button);

void menu(Button button);

void init_button(void);

void init_button2(void);

void init_button3(void);