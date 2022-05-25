#pragma once
#include <windows.h>
#include <vector>

#include "SnekManager.h"
#include "Player.h"
#include "Enums.h"

class Game {
public:
	Game() {};
	Game(SnekManager*, Player*);

	void Update();
	void SpawnApple();
	void SpawnApple(COORD);
	COORD RandomPosition();

	GameState m_gameState = GameState::RUNNING;

	COORD m_apple = { 0, 1 };
	
	SnekManager* m_snekManager{};
	Player* m_player{};
private:
	bool PlayerOutOfBounds(Player*);
	bool PlayerTouchesSelf(Player*);
};
