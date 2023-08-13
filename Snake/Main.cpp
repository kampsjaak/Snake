#include <iostream>
#include <chrono> // delays
#include <thread> // delays
#include <windows.h> // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix

#include "SnekManager.h"
#include "Game.h"
#include "Player.h"
#include "Pickup.h"
#include "util.h"
#include "DrawConsole.h"
#include "UI.h"
#include "Localisation.h"
#include "CLI.h"

const unsigned int PROGRAM_UPDATE_STEP = 175; //ms

void HandleGameplayInputs();
Snek::Player player;

unsigned short Snek::CLI::HEIGHT = 0;
unsigned short Snek::CLI::WIDTH = 0;
unsigned short Snek::CLI::LANGUAGE = 0;

int main(int argc, const char** argv)
{
	// https://www.bfgroup.xyz/Lyra/lyra.html
	Snek::CLI cli(argc, argv);

	Snek::CLI::WIDTH = 20;
	Snek::CLI::HEIGHT = 10;
	Snek::CLI::LANGUAGE = 0;

	Snek::UI ui;
	SnekDraw::DrawConsole draw(Snek::CLI::WIDTH, Snek::CLI::HEIGHT);
	Snek::SnekManager snek_manager(&draw, &ui);
	player = Snek::Player(&snek_manager);
	Snek::Game game(&snek_manager, &player);

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
		if (player.m_previous_heading == Snek::Heading::Right) return;
		player.m_heading = Snek::Heading::Left;
		return;
	}
	else if (GetAsyncKeyState(0x44)) {
		if (player.m_previous_heading == Snek::Heading::Left) return;
		
		player.m_heading = Snek::Heading::Right;
		return;
	}
	else if (GetAsyncKeyState(0x57)) {
		if (player.m_previous_heading == Snek::Heading::Down) return;
		
		player.m_heading = Snek::Heading::Top;
		return;
	}
	else if (GetAsyncKeyState(0x53)) {
		if (player.m_previous_heading == Snek::Heading::Top) return;
		
		player.m_heading = Snek::Heading::Down;
		return;
	}
}