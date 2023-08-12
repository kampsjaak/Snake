#pragma once

enum class Heading : unsigned short {
	Top,
	Down,
	Left,
	Right
};

enum class GameState : unsigned short { 
	MENU,
	RUNNING,
	GAME_OVER
};
