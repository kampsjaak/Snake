#include <iostream>
#include <chrono> // delays
#include <thread> // delays
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#include <ctime> // random nummer generation
#include "Game.h"

const unsigned int programUpdateStep = 75; //ms
unsigned long int tick = 0;
Game theGame;

int main()
{
	//system("cls");

	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		theGame.Update();
		std::this_thread::sleep_for(std::chrono::milliseconds(programUpdateStep));
		tick++;
	}
	system("cls");
	return 0;
}