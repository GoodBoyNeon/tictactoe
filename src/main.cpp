#include "../include/game.h"
#include <ncurses.h>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

  /* Start ncurses */
  initscr();
  cbreak();

  while (1) {
    vector<int> startingState = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    Game game = Game(startingState);
    game.play();
  }
  endwin();

  return 0;
}
