#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix

#include "Player.h"
#include "Draw.h"
#include "Game.h"
#include <ctime>

void Game::SpawnApple() {
	int rng = rand();
	COORD pos = { rng % m_snekManager->width, rng % m_snekManager->height };
	//while(Game::m_player->IsAtPosition(pos)) {
	//	// evaluate, reroll
	//}
	m_apple = pos;
	m_snekManager->GetDraw()->DrawCharacter('o', m_apple);
	return;
}

Game::Game(SnekManager* sm, Player* player) {
	srand(time(0));

	// member variable assignment
	m_snekManager = sm;
	m_player = player;

	// initialise gameplay systems
	m_player->Initialise();
	
	SpawnApple();

	return;
};

void Game::Update() {
	m_player->Move();
	if(m_player->m_head.X == m_apple.X && m_player->m_head.Y == m_apple.Y) {
		m_player->Redraw(true);
		SpawnApple();
	} else {
		m_player->Redraw(false);
	}
	return;
}
