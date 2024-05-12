#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>
class Board {
public:
  //

  int x;
  int y;

  int maxy;
  int maxx;
  Board(int maxy, int maxx);

  // void drawChip(int *dest, char type, Board *gameBoard);
  void drawBoard(int gamestate[9], Board *gameBoard, WINDOW *win, int leny,
                 int lenx);

private:
  int lenx;
  int leny;
};

int putChip(int *dest, Board *gameBoard);

#endif // !BOARD_H
