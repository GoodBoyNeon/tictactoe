#include "../include/game.h"
#include "../include/minimax.h"
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <string>
#include <vector>
using namespace std;
Game::Game(vector<int> &inputState) : state(inputState) {}

bool hasEmptySquares(vector<int> state) {
  for (int i = 0; i < 9; i++) {
    if (state[i] == -1) {
      return 1;
    }
  }
  return 0;
}

vector<int> getAvailableMoves(vector<int> state) {
  vector<int> availableMoves = {};

  for (int i = 0; i < 9; i++) {
    if (state[i] == -1)
      availableMoves.push_back(i);
  }

  return availableMoves;
}

int Game::getMyMove(int myToken) {
  int depth = 9;
  int result = minimax(this->state, myToken, *this, depth, depth);
  return result;
}

void Game::play() {
  int maxy, maxx;
  getmaxyx(stdscr, maxy, maxx);

  WINDOW *gamewin = newwin(maxy - 5, 0, 0, 0);
  WINDOW *inputwin = newwin(3, maxx - 12, maxy - 5, 5);
  WINDOW *infowin = newwin(2, maxx - 12, maxy - 2, 5);
  refresh();

  box(inputwin, 0, 0);
  wrefresh(inputwin);

  Board gameBoard = Board(maxy, maxx);
  gameBoard.drawBoard(state, &gameBoard, gamewin, 18, 33);

  srand(time(nullptr));
  int myToken = rand() % 2;

  int currentToken = 0;
  int winner = -2;

  if (myToken == 0) {
    mvwprintw(infowin, 0, 0, "I go first!");
  } else {
    mvwprintw(infowin, 0, 0, "You go first!");
  }
  wrefresh(infowin);

  while (winner == -2 && hasEmptySquares(state)) {

    if (myToken == currentToken) {
      this->getMyMove(myToken);

      // state[myMove] = currentToken;
      currentToken = !currentToken;
      werase(infowin);
      wrefresh(infowin);
    } else {
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
    }
    gameBoard.drawBoard(state, &gameBoard, gamewin, 18, 33);
    winner = checkWinner(this->state);
  }

  std::string gameStatus;
  if (winner == 0)
    gameStatus = "X wins!";
  else if (winner == 1)
    gameStatus = "O wins!";
  else if (winner == -1)
    gameStatus = "It's a Draw!";

  mvwprintw(infowin, 0, 0,
            "%s Press any key to play again, or press Ctrl+C to exit...",
            gameStatus.c_str());
  wrefresh(infowin);
  getch();
}

int checkWinner(std::vector<int> state) {

  // check for rows
  for (int i = 0; i < 7; i += 3) {
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
      return -2;
    return state[4];
  }

  bool empty = hasEmptySquares(state);

  if (!empty) {
    return -1;
  }

  return -2;
}
