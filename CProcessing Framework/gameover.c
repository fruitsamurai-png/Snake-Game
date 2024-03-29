#include "gameover.h"
#include "Cprocessing.h"
#include "button.h"
#include "mainmenu.h"
#include "food.h"
#include "main.h"
#include <stdio.h>

CP_Image gameover;
CP_Image theend;

float WINDOW_HEIGHT;
float WINDOW_WIDTH;

void gameover_init(void)
{
	WINDOW_HEIGHT = (float) CP_System_GetWindowHeight();
	WINDOW_WIDTH = (float) CP_System_GetWindowWidth();

	gameover = CP_Image_Load("./Assets/DigiPen_BLACK.png");
	theend = CP_Image_Load("./Assets/Snake_GAMEOVER.png");
	init_button3();
}

void gameover_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(gameover, WINDOW_WIDTH / 2, WINDOW_HEIGHT *1/ 6, 100, 100, 255);
	CP_Image_Draw(theend, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 1 / 3, 150, 100, 255);
	CP_Image_Draw(restartButton.image, restartButton.xposition, restartButton.yposition, restartButton.sizex, restartButton.sizey, 255);
	CP_Image_Draw(menuButton.image, menuButton.xposition, menuButton.yposition, menuButton.sizex, menuButton.sizey, 255);

	restart(restartButton);
	menu(menuButton);
}

void gameover_exit(void)
{

}

