#include "Draw.h"

// Drawing and updating game logic
class Interface {
public:
    Interface();
    void DrawMainMenu(Draw*);
    void DrawGameOver(Draw*);
    void DrawGameUI(Draw*, unsigned int, unsigned short, Localisation*);
    void UpdateGameUIScore(int);
    const unsigned short m_min_width = 12;
    const unsigned short m_hud_height = 2;
};