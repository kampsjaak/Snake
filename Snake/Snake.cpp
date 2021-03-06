#include <iostream>
#include <chrono> // delays
#include <thread> // delays
#include <windows.h> // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#include <ctime> // random nummer generation

#include "Game.h"
#include "Player.h"

const unsigned int programUpdateStep = 175; //ms
unsigned long int tick = 0;
// drawing logic
Draw d(32, 20);

// classes that draw themselves
Player thePlayer(&d);

// manager of classes that draw themselves
Game theGame(&thePlayer);

void HandleInputs() {
	if (GetAsyncKeyState(0x41)) {
		thePlayer.m_heading = Heading::Left;
		return;
	} else if(GetAsyncKeyState(0x44)) {
		thePlayer.m_heading = Heading::Right;
		return;
	} else if(GetAsyncKeyState(0x57)) {
		thePlayer.m_heading = Heading::Top;
		return;
	} else if(GetAsyncKeyState(0x53)) {
		thePlayer.m_heading = Heading::Down;
		return;
	}
}

int main()
{
	// initialisation of classes is game logic by definition?

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