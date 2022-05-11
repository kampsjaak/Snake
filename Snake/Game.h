#pragma once
#include <windows.h>
#include "Player.h"

class Game {
public:
	Game(Player thePlayer);
	void Update();
	void SpawnApple();
	COORD m_apple = { 0, 1 };
private:
	Player m_player;
};
