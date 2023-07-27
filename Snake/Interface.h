#include "SnekManager.h"

class Interface {
public:
    Interface();
    void DrawMainMenu(SnekManager*);
    void DrawGameOver(SnekManager*);
    void DrawGameUI(SnekManager*);
    void UpdateGameUIScore(int);
    const unsigned short m_min_width = 12;
};