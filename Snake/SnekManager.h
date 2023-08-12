#pragma once 
#include <stdint.h>

#include "Draw.h"
#include "Interface.h"

class SnekManager {
public:
	SnekManager(Draw*);
	Draw* GetDraw() { return m_draw; };
	Interface* GetInterface();
	short m_width = 0;
	short m_height = 0;
private:
	Interface m_interface = Interface();
	Draw* m_draw;
};