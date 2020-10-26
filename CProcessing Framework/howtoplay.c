#include "button.h"
#include "Cprocessing.h"
#include "main.h"
#include "mainmenu.h"

CP_Image controls;
CP_Image instructions;
CP_Image text;
CP_Image wasd;
CP_Image arrow;

void howtoplay_init(void)
{
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();

	controls = CP_Image_Load("./Assets/DigiPen_RED.png");

	instructions = CP_Image_Load("./Assets/Snake_HOWTOPLAY.png");

	wasd = CP_Image_Load("./Assets/Controls.png");

	arrow = CP_Image_Load("./Assets/Arrow.png");
	

	init_button2();									// Call function of init_button2 that is inside button.h to go to button.c


}

void howtoplay_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(controls, WINDOW_WIDTH / 2, WINDOW_HEIGHT *0.15f, 250, 100, 255);
	CP_Image_Draw(instructions, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.35f, 150, 50, 255);
	CP_Image_Draw(wasd, WINDOW_WIDTH * 1 / 2, WINDOW_HEIGHT * 0.6f, 200, 200, 255);
	CP_Image_Draw(arrow, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT * 0.55f, 200, 200, 255);
	CP_Image_Draw(playButton.image, playButton.xposition, playButton.yposition, playButton.sizex, playButton.sizey, 255);
	CP_Image_Draw(menuButton.image, menuButton.xposition, menuButton.yposition, menuButton.sizex, menuButton.sizey, 255);

	play(playButton);
	menu(menuButton);
}

void howtoplay_exit(void)
{

}