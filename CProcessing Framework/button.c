#include "button.h"
#include "Cprocessing.h"
#include "main.h"
#include "mainmenu.h"
#include "gameover.h"
#include "howtoplay.h"
#include <stdio.h>

void play(Button button)
{
	if (CP_Input_MouseClicked())
	{
		if (CP_Input_GetMouseX() >= button.xposition - button.sizex / 2 &&
			CP_Input_GetMouseX() <= button.xposition + button.sizex / 2 &&
			CP_Input_GetMouseY() >= button.yposition - button.sizey / 2 &&
			CP_Input_GetMouseY() <= button.yposition + button.sizey / 2)
		{
			printf("play");
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);
		}
	}
}

void howtoplay(Button button)
{
	if (CP_Input_MouseClicked())
	{
		if (CP_Input_GetMouseX() >= button.xposition - button.sizex / 2 &&
			CP_Input_GetMouseX() <= button.xposition + button.sizex / 2 &&
			CP_Input_GetMouseY() >= button.yposition - button.sizey / 2 &&
			CP_Input_GetMouseY() <= button.yposition + button.sizey / 2)
		{
			printf("how to play");
			CP_Engine_SetNextGameState(howtoplay_init, howtoplay_update, howtoplay_exit);
		}
	}
}

void exitgame(Button button)
{
	if (CP_Input_MouseClicked())
	{
		if (CP_Input_GetMouseX() >= button.xposition - button.sizex / 2 &&
			CP_Input_GetMouseX() <= button.xposition + button.sizex / 2 &&
			CP_Input_GetMouseY() >= button.yposition - button.sizey / 2 &&
			CP_Input_GetMouseY() <= button.yposition + button.sizey / 2)
		{
			printf("exit");
			CP_Engine_Terminate();
		}
	}
}	

void menu(Button button)
{
	if (CP_Input_MouseClicked())
	{
		if (CP_Input_GetMouseX() >= button.xposition - button.sizex / 2 &&
			CP_Input_GetMouseX() <= button.xposition + button.sizex / 2 &&
			CP_Input_GetMouseY() >= button.yposition - button.sizey / 2 &&
			CP_Input_GetMouseY() <= button.yposition + button.sizey / 2)
		{
			printf("menu");
			CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
		}
	}
}

void restart(Button button)
{
	if (CP_Input_MouseClicked())
	{
		if (CP_Input_GetMouseX() >= button.xposition - button.sizex / 2 &&
			CP_Input_GetMouseX() <= button.xposition + button.sizex / 2 &&
			CP_Input_GetMouseY() >= button.yposition - button.sizey / 2 &&
			CP_Input_GetMouseY() <= button.yposition + button.sizey / 2)
		{
			printf("game");
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);
		}
	}
}

void init_button(void) //mainmenu
{
	playButton.image = CP_Image_Load("./Assets/Snake_PLAY.png");
	playButton.xposition = WINDOW_WIDTH / 2;
	playButton.yposition = WINDOW_HEIGHT / 2;
	playButton.sizex = 50;
	playButton.sizey = 50;

	howtoplayButton.image = CP_Image_Load("./Assets/Snake_HOWTOPLAY.png");
	howtoplayButton.xposition = WINDOW_WIDTH / 2;
	howtoplayButton.yposition = WINDOW_HEIGHT * 3 / 5;
	howtoplayButton.sizex = 100;
	howtoplayButton.sizey = 50;

	exitButton.image = CP_Image_Load("./Assets/Snake_EXIT.png");
	exitButton.xposition = WINDOW_WIDTH / 2;
	exitButton.yposition = WINDOW_HEIGHT * 5 / 7;
	exitButton.sizex = 50;
	exitButton.sizey = 50;
}

void init_button2(void) //howtoplay
{
	playButton.image = CP_Image_Load("./Assets/Snake_PLAY.png");
	playButton.xposition = WINDOW_WIDTH / 2;
	playButton.yposition = WINDOW_HEIGHT * 3 / 4;
	playButton.sizex = 100;
	playButton.sizey = 100;

	menuButton.image = CP_Image_Load("./Assets//Snake_MAINMENU.png");
	menuButton.xposition = WINDOW_WIDTH / 2;
	menuButton.yposition = WINDOW_HEIGHT * 7 / 8;
	menuButton.sizex = 100;
	menuButton.sizey = 100;
}

void init_button3(void) //gameover
{
	restartButton.image = CP_Image_Load("./Assets/Snake_RESTART.png");
	restartButton.xposition = WINDOW_WIDTH / 2;
	restartButton.yposition = WINDOW_HEIGHT / 2;
	restartButton.sizex = 100;
	restartButton.sizey = 100;

	menuButton.image = CP_Image_Load("./Assets/Snake_MAINMENU.png");
	menuButton.xposition = WINDOW_WIDTH / 2;
	menuButton.yposition = WINDOW_HEIGHT * 3 / 4;
	menuButton.sizex = 100;
	menuButton.sizey = 100;
}
