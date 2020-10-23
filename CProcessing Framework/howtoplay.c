#include "button.h"
#include "Cprocessing.h"
#include "main.h"
#include "mainmenu.h"

CP_Image controls;

float WINDOW_HEIGHT;
float WINDOW_WIDTH;

void howtoplay_init(void)
{
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();

	controls = CP_Image_Load("./Assets//DigiPen_RED.png");

	init_button2();

}

void howtoplay_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(controls, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 5, 100, 100, 255);
	CP_Image_Draw(playButton.image, playButton.xposition, playButton.yposition,playButton.sizex, playButton.sizey, 255);
	CP_Image_Draw(menuButton.image, menuButton.xposition, menuButton.yposition, menuButton.sizex, menuButton.sizey, 255);

	play(playButton);
	menu(menuButton);
}

void howtoplay_exit(void)
{

}