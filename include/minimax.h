#ifndef MINIMAX_H
#define MINIMAX_H

#include "game.h"
#include <vector>
int minimax(std::vector<int> gamestate, bool max, Game &game, int depth,
            int initialDepth);
#endif
