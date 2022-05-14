#pragma once 
#include <stdint.h>

#include "Draw.h"

class SnekManager {
public:
	SnekManager(Draw*, uint32_t, uint32_t);
	Draw* GetDraw() { return m_draw; };
	unsigned int width = 0;
	unsigned int height = 0;
private:
	Draw* m_draw;
};