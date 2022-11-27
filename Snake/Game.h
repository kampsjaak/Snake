#pragma once
#include <windows.h>
#include <vector>

#include "Forward.h"
#include "Enums.h"

class Game {
public:
	Game() {};
	Game(SnekManager*, Player*);

	void Update();
	void SpawnApple();
	void SpawnApple(COORD*, COORD);
	COORD RandomPosition();

	GameState m_gameState = GameState::RUNNING;

	std::vector<COORD> m_apples = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 } };
	
	SnekManager* m_snekManager{};
	Player* m_player{};
private:
	bool PlayerOutOfBounds(Player*);
	bool PlayerTouchesSelf(Player*);
};
