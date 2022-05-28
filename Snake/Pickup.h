#pragma once

#include <windows.h>

class Pickup {
public:
	Pickup();
	void SetCoord(COORD c) { m_position = c; };
	COORD GetCoord() { return m_position; };
private:
	COORD m_position = {0, 0};
};