#pragma once

#include "Draw.h"
#include "Localisation.h"

namespace Snek {
// Drawing and updating game logic
class UI {
public:
    UI() { return; };

    //void DrawMainMenu(SnekDraw::Draw*);
    //void DrawGameOver(SnekDraw::Draw*);
    void DrawGameUI(SnekDraw::Draw*, unsigned int, unsigned short, Snek::Localisation*);
    void UpdateGameUIScore(int);

    static const unsigned short m_min_width = 12;
    static const unsigned short m_hud_top_rows = 2;
    static const unsigned short m_hud_bottom_rows = 2;
    static const unsigned short m_border_column = 1;

    static unsigned short Width() { return CLI::WIDTH; };
    static unsigned short Height() { return CLI::HEIGHT; };
};
}