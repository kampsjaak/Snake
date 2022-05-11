#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix

#include "Player.h"
#include "Game.h"

COORD applePos = { 5, 5 };

void Game::SpawnApple() {
	return;
}

Game::Game(Player player) {
	Game::m_player = player;
	return;
};

void Game::Update() {
	Game::m_player.Move();
	return;
}
