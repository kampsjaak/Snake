#include <iostream>
#include <chrono> // delays
#include <thread> // delays
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#include <ctime> // random nummer generation

#include "Game.h"
#include "Player.h"

const unsigned int programUpdateStep = 125; //ms
unsigned long int tick = 0;
Game theGame;
Player thePlayer;

void HandleInputs() {
	if (GetAsyncKeyState(0x41)) {
		// a left
		return;
	} else if(GetAsyncKeyState(0x44)) {
		// d right
		return;
	} else if(GetAsyncKeyState(0x58)) {
		// w up
		return;
	} else if(GetAsyncKeyState(0x53)) {
		// s down
		return;
	}
}

int main()
{
	//system("cls");
	thePlayer.Initialise();

	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		HandleInputs();
		theGame.Update();
		std::this_thread::sleep_for(std::chrono::milliseconds(programUpdateStep));
		tick++;
	}
	system("cls");
	return 0;
}