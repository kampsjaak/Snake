#pragma once
#include <windows.h>
#include <vector>

#include "SnekManager.h"
#include "Player.h"

class Game {
public:
	Game() {};
	Game(SnekManager*, Player*);

	void Update();
	void SpawnApple();

	SnekManager* m_snekManager{};
	Player* m_player{};
	COORD m_apple = { 0, 1 };
private:
};
