#pragma once 
#include <stdint.h>

#include "Draw.h"
#include "Interface.h"

class SnekManager {
public:
	SnekManager(Draw*, short, short);
	Draw* GetDraw() { return m_draw; };
	Interface* GetInterface() { return &m_interface; };
	short width = 0;
	short height = 0;
private:
	Draw* m_draw;
	Interface m_interface;
};