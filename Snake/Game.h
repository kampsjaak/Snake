#pragma once
#include <windows.h>

class Game {
public:
	Game();
	void Update();
	void SpawnApple();
	COORD m_apple = { 0, 1 };
private:
};
