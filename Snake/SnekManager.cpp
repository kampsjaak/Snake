#include "SnekManager.h"
#include "Draw.h"

SnekManager::SnekManager(Draw* d, uint32_t w, uint32_t h) {
	m_draw = d;
	width = w;
	height = h;
};