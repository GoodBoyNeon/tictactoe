#include "../include/board.h"
#include <ncurses.h>
#include <string>
#include <vector>
using namespace std;

#define XMAX 33
#define YMAX 18

Board::Board(int maxy, int maxx) {
  this->x = (maxx / 2) - 18;
  this->y = 1;
  this->maxx = maxx;
  this->maxy = maxy;
}

vector<int> tokenX = {0, 0, 0,  1, 0, 0,  0, 1, 0,  0, 0, -1, 0, 0, 0,
                      0, 1, 0,  1, 0, 0,  0, 0, -1, 0, 0, 0,  0, 0, 1,
                      0, 0, 0,  0, 0, -1, 0, 0, 0,  0, 1, 0,  1, 0, 0,
                      0, 0, -1, 0, 0, 0,  1, 0, 0,  0, 1, 0,  0, -2};

vector<int> tokenO = {0, 0, 0,  0, 2, 2,  2, 0, 0,  0, 0, -1, 0, 0, 0,
                      2, 0, 0,  0, 2, 0,  0, 0, -1, 0, 0, 0,  2, 0, 0,
                      0, 2, 0,  0, 0, -1, 0, 0, 0,  2, 0, 0,  0, 2, 0,
                      0, 0, -1, 0, 0, 0,  0, 2, 2,  2, 0, 0,  0, -2};

string tokenize(const std::vector<int> &arr, int index) {
  string out;

  for (int elem : arr) {
    if (elem == 0)
      out += " ";
    if (elem == 1)
      out += "X";
    if (elem == 2)
      out += "O";
    if (elem == -1)
      out += "\n";
    if (elem == -2)
      out += std::to_string(index);
  }

  return out;
}

void Board::drawBoard(int gamestate[], Board *gameBoard, WINDOW *win, int leny,
                      int lenx) {

  int line = 7, col = 12;
  int centering_factor = maxx / 2 - (36 / 2);
  int height_adjusting_factor = 1;

  WINDOW *box1 =
      newwin(line, col, line * 2 + height_adjusting_factor, centering_factor);

  if (gamestate[0] == 1) {
    mvwaddstr(box1, 1, 0, tokenize(tokenX, 1).c_str());
  }
  if (gamestate[0] == 2) {
    mvwaddstr(box1, 1, 0, tokenize(tokenO, 1).c_str());
  }
  box(box1, 0, 0);
  wrefresh(box1);

  WINDOW *box2 = newwin(line, col, line * 2 + height_adjusting_factor,
                        col + centering_factor);

  if (gamestate[1] == 1) {
    mvwaddstr(box2, 1, 0, tokenize(tokenX, 2).c_str());
  }
  if (gamestate[1] == 2) {
    mvwaddstr(box2, 1, 0, tokenize(tokenO, 2).c_str());
  }
  box(box2, 0, 0);
  wrefresh(box2);

  WINDOW *box3 = newwin(line, col, line * 2 + height_adjusting_factor,
                        col * 2 + centering_factor);

  if (gamestate[2] == 1) {
    mvwaddstr(box3, 1, 0, tokenize(tokenX, 3).c_str());
  }
  if (gamestate[2] == 2) {
    mvwaddstr(box3, 1, 0, tokenize(tokenO, 3).c_str());
  }
  box(box3, 0, 0);
  wrefresh(box3);

  WINDOW *box4 =
      newwin(line, col, line + height_adjusting_factor, centering_factor);

  if (gamestate[3] == 1) {
    mvwaddstr(box4, 1, 0, tokenize(tokenX, 4).c_str());
  }
  if (gamestate[3] == 2) {
    mvwaddstr(box4, 1, 0, tokenize(tokenO, 4).c_str());
  }
  box(box4, 0, 0);
  wrefresh(box4);

  WINDOW *box5 =
      newwin(line, col, line + height_adjusting_factor, col + centering_factor);

  if (gamestate[4] == 1) {
    mvwaddstr(box5, 1, 0, tokenize(tokenX, 5).c_str());
  }
  if (gamestate[4] == 2) {
    mvwaddstr(box5, 1, 0, tokenize(tokenO, 5).c_str());
  }
  box(box5, 0, 0);
  wrefresh(box5);

  WINDOW *box6 = newwin(line, col, line + height_adjusting_factor,
                        col * 2 + centering_factor);

  if (gamestate[5] == 1) {
    mvwaddstr(box6, 1, 0, tokenize(tokenX, 6).c_str());
  }
  if (gamestate[5] == 2) {
    mvwaddstr(box6, 1, 0, tokenize(tokenO, 6).c_str());
  }
  box(box6, 0, 0);
  wrefresh(box6);

  WINDOW *box7 = newwin(line, col, height_adjusting_factor, centering_factor);

  if (gamestate[6] == 1) {
    mvwaddstr(box7, 1, 0, tokenize(tokenX, 7).c_str());
  }
  if (gamestate[6] == 2) {
    mvwaddstr(box7, 1, 0, tokenize(tokenO, 7).c_str());
  }
  box(box7, 0, 0);
  wrefresh(box7);

  WINDOW *box8 =
      newwin(line, col, height_adjusting_factor, col + centering_factor);

  if (gamestate[7] == 1) {
    mvwaddstr(box8, 1, 0, tokenize(tokenX, 8).c_str());
  }
  if (gamestate[7] == 2) {
    mvwaddstr(box8, 1, 0, tokenize(tokenO, 8).c_str());
  }
  box(box8, 0, 0);
  wrefresh(box8);

  WINDOW *box9 =
      newwin(line, col, height_adjusting_factor, col * 2 + centering_factor);

  if (gamestate[8] == 1) {
    mvwaddstr(box9, 1, 0, tokenize(tokenX, 9).c_str());
  }
  if (gamestate[8] == 2) {
    mvwaddstr(box9, 1, 0, tokenize(tokenO, 9).c_str());
  }

  box(box9, 0, 0);
  wrefresh(box9);

  refresh();
};
