#include "../include/utils.h"
#include "../include/board.h"
#include <ncurses.h>

#define XMAX 33
#define YMAX 18

void putCursor(int *orig, int *dest, Board *gameBoard) {
  int i, j;
  int y, x;

  for (i = 0; i < 5; i++) {
    // Clean the last cursor
    y = YMAX / 3 * orig[0] + i + gameBoard->y + 1;
    x = XMAX / 3 * orig[1] + gameBoard->x + 1;
    mvaddch(y, x, ' ');
    x = x + 9;
    mvaddch(y, x, ' ');

    // Set the new cursor
    y = YMAX / 3 * dest[0] + i + gameBoard->y + 1;
    x = XMAX / 3 * dest[1] + gameBoard->x + 1;

    attron(COLOR_PAIR(3) | A_BLINK);
    mvaddch(y, x, ACS_DIAMOND);
    x = x + 9;
    mvaddch(y, x, ACS_DIAMOND);
    attroff(COLOR_PAIR(3) | A_BLINK);
  }
}
