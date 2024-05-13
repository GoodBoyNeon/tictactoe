#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>
#include <vector>
class Board {
public:
  //

  int x;
  int y;

  int maxy;
  int maxx;

  int state[9];

  Board(int maxy, int maxx);

  // void drawChip(int *dest, char type, Board *gameBoard);
  void drawBoard(std::vector<int> gamestate, Board *gameBoard, WINDOW *win,
                 int leny, int lenx);

private:
  int lenx;
  int leny;
};

#endif // !BOARD_H
