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

    const unsigned short m_min_width = 12;
    const unsigned short m_hud_height = 2;

    static unsigned short Width() { return m_width; };
    static unsigned short Height() { return m_height; };
    static unsigned short m_width;
    static unsigned short m_height;
};
}