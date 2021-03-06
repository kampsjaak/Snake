#include <iostream>
#include <chrono> // delays
#include <thread> // delays
#include <windows.h> // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#include <ctime> // random nummer generation

#include "SnekManager.h"
#include "Game.h"
#include "Player.h"
#include "Pickup.h"
#include "util.h"

const unsigned int programUpdateStep = 175; //ms

// drawing logic
consoleSize cs = GetConsoleSize();
Draw d(cs.w, cs.h);
SnekManager snekManager(&d, 40, 10);

// classes that draw themselves
Player thePlayer(&snekManager);


// manager of classes that draw themselves
Game theGame(&snekManager, &thePlayer);

// save/load states and serialisation layer?

void HandleInputs() {
	if (GetAsyncKeyState(0x41)) {
		if (thePlayer.m_previousHeading == Heading::Right) return;
		thePlayer.m_heading = Heading::Left;
		return;
	} else if(GetAsyncKeyState(0x44)) {
		if (thePlayer.m_previousHeading == Heading::Left) return;
		thePlayer.m_heading = Heading::Right;
		return;
	} else if(GetAsyncKeyState(0x57)) {
		if (thePlayer.m_previousHeading == Heading::Down) return;
		thePlayer.m_heading = Heading::Top;
		return;
	} else if(GetAsyncKeyState(0x53)) {
		if (thePlayer.m_previousHeading == Heading::Top) return;
		thePlayer.m_heading = Heading::Down;
		return;
	}
}

int main()
{
	Pickup::Initialise(&d);
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		switch(theGame.m_gameState)
		{
			case GameState::RUNNING:
				HandleInputs();
				theGame.Update();
				std::this_thread::sleep_for(std::chrono::milliseconds(programUpdateStep));
				break;
			case GameState::GAME_OVER:
				break;
			case GameState::MENU:
				break;
			default:
				break;
		}
	}
	system("cls");
	return 0;
}