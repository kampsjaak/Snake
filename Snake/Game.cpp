#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix

#include "Player.h"
#include "Draw.h"
#include "Game.h"

COORD applePos = { 5, 5 };

void Game::SpawnApple() {
	return;
}

Game::Game(Player player, Draw draw) {
	m_player = player;
	m_draw = draw;
	return;
};

void Game::Update() {
	m_player.Move();
	return;
}
