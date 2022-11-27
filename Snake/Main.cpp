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
#include "Draw.h"
#include "Enums.h"

const unsigned int programUpdateStep = 175; //ms
Player thePlayer;
Game theGame;

// save/load states and serialisation layer?

void HandleInputs(Player* p) {
	if (GetAsyncKeyState(0x41)) {
		if (p->m_previousHeading == Heading::Right) return;
		p->m_heading = Heading::Left;
		return;
	}
	else if (GetAsyncKeyState(0x44)) {
		if (p->m_previousHeading == Heading::Left) return;
		p->m_heading = Heading::Right;
		return;
	}
	else if (GetAsyncKeyState(0x57)) {
		if (p->m_previousHeading == Heading::Down) return;
		p->m_heading = Heading::Top;
		return;
	}
	else if (GetAsyncKeyState(0x53)) {
		if (p->m_previousHeading == Heading::Top) return;
		p->m_heading = Heading::Down;
		return;
	}
}

unsigned short Game::s_height = 40;
unsigned short Game::s_width = 10;

int main(int argc, char* argv[])
{
	{
		char** p = argv;
		argc = 0;
		while (*p++ != NULL) {
			argc++;
		}

		unsigned short len = 0;
		
		for (int i = 0; i < argc; i++) {
			//printf("argv[%d] = %s~\n", i, argv[i]);
			if (strcmp(argv[i], "jemoeder") == 0) {
				auto value = argv[i];
				if (len <= i + 1) {
					value = argv[i + 1];
				}
				printf("jemoeder: %d", value);
			}
		}
	}

	// drawing logic
	consoleSize cs = GetConsoleSize();
	Draw d(cs.w, cs.h);
	SnekManager snekManager(&d, Game::s_width, Game::s_height);

	//
	Player thePlayer(&snekManager);
	Game theGame(&snekManager, &thePlayer);
	
	//Pickup::Initialise(&d);

	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		switch(theGame.m_gameState)
		{
			case GameState::RUNNING:
				HandleInputs(&thePlayer);
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

