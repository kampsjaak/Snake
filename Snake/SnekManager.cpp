#include "SnekManager.h"

SnekManager::SnekManager(Draw* d) {
	m_draw = d;

	m_width = Draw::Width();
	m_height = Draw::Height();
	//m_interface = Interface();
	//m_playarea_height = Draw::Height() - Interface::m_hud_height;
};

Interface* SnekManager::GetInterface() {
	Interface* i = &m_interface;
	return i;
}