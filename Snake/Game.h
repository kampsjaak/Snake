#pragma once
#include <windows.h>
#include <vector>

#include "SnekManager.h"
#include "Player.h"

enum class GameState { MENU, RUNNING, GAME_OVER };

class Game {
public:
	Game() {};
	Game(SnekManager*, Player*);

	void Update();
	void SpawnApple();
	void SpawnApple(COORD);

	GameState m_gameState = GameState::RUNNING;
	SnekManager* m_snekManager{};
	Player* m_player{};
	COORD m_apple = { 0, 1 };
private:
	bool PlayerWithinBounds(Player*);
};
