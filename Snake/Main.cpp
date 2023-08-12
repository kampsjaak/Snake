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
#include "Localisation.h"

#include <lua.hpp>

const unsigned int PROGRAM_UPDATE_STEP = 175; //ms
const unsigned short LANGUAGE = 0;

consoleSize cs = GetConsoleSize();
unsigned short Draw::m_screen_colums = 20;
unsigned short Draw::m_screen_rows = 20;
Draw draw;
Player player;

void HandleGameplayInputs();

int main()
{
	SnekManager snek_manager(&draw);
	player = Player(&snek_manager);
	Game game(&snek_manager, &player, LANGUAGE);

	//Pickup::Initialise(&d);
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		switch(game.m_gameState)
		{
			case GameState::RUNNING:
				HandleGameplayInputs();
				game.Update();
				std::this_thread::sleep_for(std::chrono::milliseconds(PROGRAM_UPDATE_STEP));
				break;
			case GameState::GAME_OVER:
				system("cls");
				std::cout << "sry bro snek ded";
				std::this_thread::sleep_for(std::chrono::milliseconds(PROGRAM_UPDATE_STEP));
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

void HandleGameplayInputs() {
	if (GetAsyncKeyState(0x41)) {
		if (player.m_previous_heading == Heading::Right) return;
		player.m_heading = Heading::Left;
		return;
	}
	else if (GetAsyncKeyState(0x44)) {
		if (player.m_previous_heading == Heading::Left) return;
		
		player.m_heading = Heading::Right;
		return;
	}
	else if (GetAsyncKeyState(0x57)) {
		if (player.m_previous_heading == Heading::Down) return;
		
		player.m_heading = Heading::Top;
		return;
	}
	else if (GetAsyncKeyState(0x53)) {
		if (player.m_previous_heading == Heading::Top) return;
		
		player.m_heading = Heading::Down;
		return;
	}
}