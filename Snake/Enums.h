#pragma once

namespace Snek {
enum class GameState : unsigned short {
	MENU,
	RUNNING,
	GAME_OVER_OUT_OF_BOUNDS,
	GAME_OVER_TOUCH_SELF
};
}