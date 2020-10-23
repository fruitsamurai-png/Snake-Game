#include "button.h"
#include "Cprocessing.h"
#include "main.h"
#include "mainmenu.h"

CP_Image controls;
CP_Image instructions;
CP_Image text;
CP_Image w;
CP_Image a;
CP_Image s;
CP_Image d;

void howtoplay_init(void)
{
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();

	controls = CP_Image_Load("./Assets/DigiPen_RED.png");

	instructions = CP_Image_Load("./Assets/Snake_HOWTOPLAY.png");

	text = CP_Image_Load("./Assets/Snake_TEXT.png");

	w = CP_Image_Load("./Assets/Snake_W.png");
	a = CP_Image_Load("./Assets/Snake_A.png");
	s = CP_Image_Load("./Assets/Snake_S.png");
	d = CP_Image_Load("./Assets/Snake_D.png");

	init_button2();									// Call function of init_button2 that is inside button.h to go to button.c


}

void howtoplay_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(controls, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 5, 250, 100, 255);
	CP_Image_Draw(instructions, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 1 / 3, 200, 50, 255);
	CP_Image_Draw(text, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 4 / 7, 250, 250, 255);
	CP_Image_Draw(w, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT * 6 / 8, 100, 50, 255);
	CP_Image_Draw(a, WINDOW_WIDTH * 2 / 5, WINDOW_HEIGHT * 6 / 8, 100, 50, 255);
	CP_Image_Draw(s, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT * 6 / 8, 100, 50, 255);
	CP_Image_Draw(d, WINDOW_WIDTH * 3 / 5, WINDOW_HEIGHT * 6 / 8, 100, 50, 255);
	CP_Image_Draw(playButton.image, playButton.xposition, playButton.yposition, playButton.sizex, playButton.sizey, 255);
	CP_Image_Draw(menuButton.image, menuButton.xposition, menuButton.yposition, menuButton.sizex, menuButton.sizey, 255);

	play(playButton);
	menu(menuButton);
}

void howtoplay_exit(void)
{

}