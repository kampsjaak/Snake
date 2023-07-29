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
const unsigned short WIDTH = 40;
const unsigned short HEIGHT = 10;
const unsigned short LANGUAGE = 0;

Localisation localisation;
// drawing logic
consoleSize cs = GetConsoleSize();
Draw d(cs.w, cs.h);

void HandleInputs(GameState state);
Player player;

int main()
{
	SnekManager snek_manager(&d, WIDTH, HEIGHT);
	player = Player(&snek_manager);
	localisation = Localisation(LANGUAGE);
	Game game(&snek_manager, &player, &localisation, WIDTH, HEIGHT);

	//Pickup::Initialise(&d);
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		switch(game.m_gameState)
		{
			case GameState::RUNNING:
				HandleInputs(game.m_gameState);
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

void HandleInputs(GameState state) {
	if (GetAsyncKeyState(0x41)) {
		switch (state) {
		case GameState::RUNNING:
			if (player.m_previous_heading == Heading::Right) return;
			player.m_heading = Heading::Left;
			break;
		}
		return;
	}
	else if (GetAsyncKeyState(0x44)) {
		switch (state) {
		case GameState::RUNNING:
			if (player.m_previous_heading == Heading::Left) return;
			player.m_heading = Heading::Right;
			break;
		}
		return;
	}
	else if (GetAsyncKeyState(0x57)) {
		switch (state) {
		case GameState::RUNNING:
			if (player.m_previous_heading == Heading::Down) return;
			player.m_heading = Heading::Top;
			break;
		}
		return;
	}
	else if (GetAsyncKeyState(0x53)) {
		switch (state) {
		case GameState::RUNNING:
			if (player.m_previous_heading == Heading::Top) return;
			player.m_heading = Heading::Down;
			break;
		}return;
	}
}