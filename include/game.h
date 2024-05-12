#ifndef GAME_H
#define GAME_H

#include "../include/board.h"
class Game {
public:
  Game();
  int state[9];
  int game(Board *gamestate);

private:
};

#endif // !GAME_H
