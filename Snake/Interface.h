#pragma once

#include "SnekManager.h"

class Interface {
public: 
	Interface();
	void DrawMainMenu(SnekManager* sm);
	void DrawGameOver(SnekManager* sm);
	void DrawGameUI(SnekManager* sm);
	void UpdateGameUIScore(int);
};