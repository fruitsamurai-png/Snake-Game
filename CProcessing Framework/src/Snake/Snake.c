void Snake_Init(void)
{
	//Initialize variables needed

	//Do everything that is required to happen only once
}

void Snake_Update(void)
{
	//Check user input
	Snake_UpdateInput();

	//Update Game
	Snake_UpdateMovement();

	//Draw
	Snake_Draw();
}

void Snake_Exit(void)
{
	CP_Engine_Terminate();
}

//Different state functions in separate files
	/*
	Main menu.c/MainMenu.h
	GameOver.c/GameOver.h
	etc
	*/