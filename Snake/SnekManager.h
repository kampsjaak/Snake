#pragma once 
#include <stdint.h>

#include "Forward.h"

class SnekManager {
public:
	SnekManager(Draw*, short, short);
	Draw* GetDraw() { return m_draw; };
	short width = 0;
	short height = 0;
private:
	Draw* m_draw;
};