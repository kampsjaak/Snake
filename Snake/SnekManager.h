#pragma once 
#include <stdint.h>

#include "Draw.h"
#include "UI.h"

namespace Snek {
// house all globals here
class SnekManager {
public:
	SnekManager(SnekDraw::Draw*, UI*);
	SnekDraw::Draw* GetDraw() { return m_draw; };
	UI* GetUI() { return m_ui; };
private:
	UI* m_ui;
	SnekDraw::Draw* m_draw;
};
}