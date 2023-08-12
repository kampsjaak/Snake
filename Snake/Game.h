#pragma once
#include <windows.h>
#include <vector>

#include "SnekManager.h"
#include "Player.h"
#include "Enums.h"
#include "Localisation.h"

struct PlaySpace {
	short x;
	short y;
	bool snake;
	bool apple;
};

class Game {
public:
	Game() {};
	Game(SnekManager*, Player*, unsigned short);

	void Update();
	void SpawnApple();
	void SpawnApple(COORD*, COORD);
	COORD RandomPosition();

	std::vector<bool> freeSlots;
	unsigned int GetScore() { return m_score; }
	unsigned short GetLives() { return m_lives; }

	GameState m_gameState = GameState::RUNNING;
	Localisation* GetLocalisation() { return &m_localisation; };
	std::vector<PlaySpace>* GetPlayArea() { return &m_play_area; }
	std::vector<COORD> m_apples = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 } };
	
	SnekManager* m_snekManager{};
	Player* m_player{};
private:
	Localisation m_localisation;
	bool PlayerOutOfBounds(Player*);
	bool PlayerTouchesSelf(Player*);

	std::vector<PlaySpace> m_play_area;
	unsigned int m_score = 0;
	unsigned short m_lives = 3;
};
