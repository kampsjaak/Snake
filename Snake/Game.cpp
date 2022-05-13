#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix

#include "Player.h"
#include "Draw.h"
#include "Game.h"

COORD applePos = { 5, 5 };

void Game::SpawnApple() {
	return;
}

Game::Game(SnekManager* sm, Player* player) {
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
	return;
}
