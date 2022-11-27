#pragma once 
#include <stdint.h>

#include "Forward.h"

class SnekManager {
public:
	SnekManager(Draw*, const unsigned short, const unsigned short);
	Draw* GetDraw() { return m_draw; };
	short width = 0;
	short height = 0;
private:
	Draw* m_draw;
};