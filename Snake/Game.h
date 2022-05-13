#pragma once
#include <windows.h>

#include "SnekManager.h"
#include "Player.h"
#include "Draw.h"

class Game {
public:
	Game() {};
	Game(SnekManager* sm, Player* thePlayer);

	void Update();
	void SpawnApple();

	SnekManager* m_snekManager{};
	Player* m_player{};
	
	COORD m_apple = { 0, 1 };
private:
};
