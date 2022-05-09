#include "Game.h"
#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix

COORD applePos = { 5, 5 };

Game::Game() {
	std::cout << "new game! :-)";
};

void Game::SpawnApple() {
	return;
}

void Game::Update() { 
	std::cout << "@";
	return;
}
