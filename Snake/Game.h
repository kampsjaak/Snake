#pragma once
#include <windows.h>

#include "Player.h"
#include "Draw.h"

class Game {
public:
	Game() {};
	Game(Player thePlayer, Draw draw);
	Player m_player;
	Draw m_draw;

	void Update();
	void SpawnApple();
	COORD m_apple = { 0, 1 };
private:
};
