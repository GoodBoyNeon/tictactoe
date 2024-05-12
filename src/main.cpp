#include "../include/board.h"
#include "../include/game.h"
#include <cstdlib>
#include <ncurses.h>

int main(int argc, char **argv) {

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

  int state[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
  gameBoard.drawBoard(state, &gameBoard, gamewin, 18, 33);

  Game game = Game();

  int mytoken = (rand() % 2) + 1;

  int currentToken = 0;
  int winner = -1;

  while (winner == -1) {

    int input = mvwgetch(inputwin, 1, 1);

    if (!(input >= '1' && input <= '9')) {
      mvwprintw(infowin, 0, 0, "-> Invalid Input!");
      wrefresh(infowin);
    }
    int stateIndex = (input - '0') - 1;

    if (state[stateIndex] != -1) {
      mvwprintw(infowin, 0, 0, "-> That box is already filled!");
      wrefresh(infowin);
    } else {
      state[stateIndex] = currentToken;
      currentToken = !currentToken;
      werase(infowin);
      wrefresh(infowin);
    }

    gameBoard.drawBoard(state, &gameBoard, gamewin, 18, 33);

    winner = game.checkWinner(state);
  }

  char winnerStr;
  if (winner == 0)
    winnerStr = 'X';
  if (winner == 1)
    winnerStr = 'O';

  mvwprintw(infowin, 0, 0, "The winner is %c! Press any key to exit...",
            winnerStr);
  wrefresh(infowin);

  getch();
  endwin();

  return 0;
}
