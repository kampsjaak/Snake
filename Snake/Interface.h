#pragma once

#include "SnekManager.h"

class Interface {
public: 
	Interface(SnekManager*);
	void DrawMainMenu();
	void DrawGameOver();
	void DrawGameUI();
	void UpdateGameUIScore(int);
private:
	SnekManager* m_snekManager{};
};