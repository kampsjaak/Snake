#include "Forward.h"

class Interface {
public:
    Interface();
    void DrawMainMenu(SnekManager*);
    void DrawGameOver(SnekManager*);
    void DrawGameUI(SnekManager*);
    void UpdateGameUIScore(int);
};