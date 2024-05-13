#ifndef GAME_H
#define GAME_H

#include "../include/board.h"
#include <vector>
class Game {
public:
  Game(std::vector<int> &inputState);
  std::vector<int> state;
  void play();
  int getMyMove(int myToken);

private:
};

std::vector<int> getAvailableMoves(std::vector<int> state);
bool hasEmptySquares(std::vector<int> state);
int checkWinner(std::vector<int> state);

#endif // !GAME_H
