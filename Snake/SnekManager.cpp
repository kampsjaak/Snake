#include "SnekManager.h"

SnekManager::SnekManager(Draw* d) {
	m_draw = d;
	m_width = Draw::Width();
	m_height = Draw::Height();
};