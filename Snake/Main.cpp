#include <iostream>
#include <chrono> // delays
#include <thread> // delays

#include "SnekManager.h"
#include "Game.h"
#include "DrawConsole.h"
#include "UI.h"
#include "CLI.h"

const unsigned int PROGRAM_UPDATE_STEP = 175; //ms

Snek::Player player;

unsigned short Snek::CLI::WIDTH = 12;
unsigned short Snek::CLI::HEIGHT = 6;
unsigned short Snek::CLI::LANGUAGE = 0;

int main(int argc, const char** argv)
{
	Snek::CLI cli(argc, argv); 

	Snek::UI ui;
	SnekDraw::DrawConsole draw(Snek::CLI::WIDTH, Snek::CLI::HEIGHT);
	Snek::SnekManager snek_manager(&draw, &ui);

	auto game = snek_manager.GetGame();
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		switch(game->m_game_state)
		{
		case Snek::GameState::RUNNING:
				game->Update();
				std::this_thread::sleep_for(std::chrono::milliseconds(PROGRAM_UPDATE_STEP));
				break;
			case Snek::GameState::GAME_OVER_OUT_OF_BOUNDS:
				system("cls");
				std::cout << "snek hit the wall";
				std::this_thread::sleep_for(std::chrono::milliseconds(PROGRAM_UPDATE_STEP));
				break;
			case Snek::GameState::GAME_OVER_TOUCH_SELF:
				system("cls");
				std::cout << "snek crazy";
				std::this_thread::sleep_for(std::chrono::milliseconds(PROGRAM_UPDATE_STEP));
				break;
			case Snek::GameState::MENU:
				break;
			default:
				break;
		}
	}
	system("cls");
	return 0;
}