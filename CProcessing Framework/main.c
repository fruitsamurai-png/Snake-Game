//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "Game.h"
#include "food.h"
#include "mainmenu.h"
#include "gameover.h"
#include "main.h"
#include <stdio.h>

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void game_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
	Snake_init();
	Food_init();
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void)
{
	// check input, update simulation, render etc.
	Snake_update();			//I HIGHLY SUGGEST ONLY USING ONE GAMESTATE AT ONCE, BECAUSE RUNNING 2 GAMESTATES AT ONCE LIKE THIS MAY CAUSE ISSUES WITH YOUR DATA, AND YOU MUST REALLY KNOW EXACTLY WHAT'S HAPPENING IN EACH FRAME
	Food_update();			//AND WITH 2 UPDATES RUNNING AT ONCE YOU NEEDA WORRY ABOUT WHATS HAPPENING IN EACH FRAME IN EACH UPDATE AT ONCE WHICH MAY BE A BIT HARD UNLESS YOUR CODING IS SUPER STRONG OK BYE
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
	Snake_exit();
	Food_exit();
}

// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{
	CP_System_SetWindowSize(400, 400);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	CP_Engine_Run();
	return 0;
}
