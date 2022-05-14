#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix

#include "Player.h"
#include "Draw.h"
#include "Game.h"
#include <ctime>

void Game::SpawnApple() {
	int rng = rand();
	COORD pos = { rng % m_snekManager->width, 0 % m_snekManager->height };
	//while(Game::m_player->IsAtPosition(pos)) {
	//	// evaluate, reroll
	//}
	m_snekManager->GetDraw()->DrawCharacter('o', pos);
	return;
}

Game::Game(SnekManager* sm, Player* player) {
	// member variable assignment
	m_snekManager = sm;
	m_player = player;

	// initialise gameplay systems
	m_player->Initialise();
	
	SpawnApple();

	srand(time(0));
	return;
};

void Game::Update() {
	m_player->Move();
	return;
}
