#include "Draw.h"

class SnekManager {
public:
	SnekManager(Draw* d);
	Draw* GetDraw() { return m_draw; };
private:
	Draw* m_draw;
};