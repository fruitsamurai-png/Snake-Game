#include "mainmenu.h"
#include "Cprocessing.h"
#include "button.h"

CP_Image mainmenu;
CP_Image snake;
CP_Image title;

void mainmenu_init(void)
{	
	WINDOW_HEIGHT = (float) CP_System_GetWindowHeight();
	WINDOW_WIDTH = (float) CP_System_GetWindowWidth();

	mainmenu = CP_Image_Load("./Assets/DigiPen_RED.png");

	snake = CP_Image_Load("./Assets/Snake_IMAGE.png");

	title = CP_Image_Load("./Assets/Snake_TITLE.png");

	init_button();

}

void mainmenu_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(mainmenu, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 5, 200, 100, 255);
	CP_Image_Draw(title, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 2 / 5, 150, 50, 255);
	CP_Image_Draw(snake, WINDOW_WIDTH * 1 / 5, WINDOW_HEIGHT * 3 / 5, -80, 150, 255);
	CP_Image_Draw(playButton.image, playButton.xposition, playButton.yposition, playButton.sizex, playButton.sizey, 255);
	CP_Image_Draw(exitButton.image, exitButton.xposition, exitButton.yposition, exitButton.sizex, exitButton.sizey, 255);
	CP_Image_Draw(howtoplayButton.image, howtoplayButton.xposition, howtoplayButton.yposition, howtoplayButton.sizex, howtoplayButton.sizey, 255);
	
	play(playButton);
	howtoplay(howtoplayButton);
	exitgame(exitButton);
	

}
void mainmenu_exit(void)
{

}