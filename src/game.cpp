#include "../include/game.h"

Game::Game() {}

int Game::game(Board *board) { return 0; }

int Game::checkWinner(int state[9]) {

  // check for rows
  for (int i = 0; i < 3; i += 3) {
    if ((state[i] == state[1 + i]) && (state[i] == state[2 + i])) {
      if (state[i] == -1)
        continue;
      return state[i];
    }
  }
  // check for columns
  for (int i = 0; i < 3; i++) {
    if ((state[i] == state[3 + i]) && (state[i] == state[6 + i])) {
      if (state[i] == -1)
        continue;
      return state[i];
    }
  }

  // check diagnoals
  if (((state[0] == state[4]) && (state[0] == state[8])) ||
      ((state[2] == state[4]) && (state[2] == state[6]))) {
    if (state[4] == -1)
      return -1;
    return state[4];
  }

  return -1;
}
