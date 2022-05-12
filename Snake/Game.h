#pragma once
#include <windows.h>

#include "Player.h"
#include "Draw.h"

class Game {
public:
	Game() {};
	Game(Player* thePlayer);

	void Update();
	void SpawnApple();

	Player* m_player{};
	
	COORD m_apple = { 0, 1 };
private:
};
