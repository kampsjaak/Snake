#pragma once 
#include <stdint.h>

#include "Draw.h"

class SnekManager {
public:
	SnekManager(Draw*);
	Draw* GetDraw() { return m_draw; };
	short m_width = 0;
	short m_height = 0;
private:
	Draw* m_draw;
};