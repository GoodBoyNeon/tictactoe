#include "../include/board.h"
#include "../include/game.h"
#include <cstdlib>
#include <ncurses.h>

int main(int argc, char **argv) {

  int winner, keyPressed;

  /* Start ncurses */
  initscr();
  cbreak(); // default behavior

  start_color();
  noecho();
  curs_set(FALSE);      // Disable the console cursor.
  keypad(stdscr, TRUE); // Enable the keyboard arrows.

  int maxy, maxx;
  getmaxyx(stdscr, maxy, maxx);

  Board gameBoard(maxy, maxx);

  // WINDOW *gamewin = newwin(maxy - 5, maxx - 12, 0, 5);
  WINDOW *gamewin = newwin(maxy - 5, 0, 0, 0);
  refresh();

  WINDOW *inputwin = newwin(3, maxx - 12, maxy - 5, 5);
  refresh();

  box(inputwin, 0, 0);
  wrefresh(inputwin);

  WINDOW *infowin = newwin(2, maxx - 12, maxy - 2, 5);
  refresh();

  int state[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  gameBoard.drawBoard(state, &gameBoard, gamewin, 18, 33);

  Game game = Game();

  int mytoken = (rand() % 2) + 1;

  int currentToken = 1;

  while (1) {

    int input = mvwgetch(inputwin, 1, 1);

    if (!(input >= '1' && input <= '9')) {
      mvwprintw(infowin, 0, 0, "-> Invalid Input!");
      wrefresh(infowin);
    }
    state[(input - '0') - 1] = currentToken;
    currentToken = (currentToken % 2) + 1;

    gameBoard.drawBoard(state, &gameBoard, gamewin, 18, 33);
  }
  return 0;

  getch();
  endwin();

  return 0;
}
