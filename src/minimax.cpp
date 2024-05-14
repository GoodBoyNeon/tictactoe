#include "../include/minimax.h"
#include "../include/game.h"
#include <algorithm>
#include <vector>

int minimax(std::vector<int> gamestate, bool max, Game &game, int depth,
            int initialDepth) {
  int bestScore, bestMove, eval;
  int winner = checkWinner(gamestate);

  if (depth == 0 || winner != -2) {
    if (winner == 1) {
      return 1;
    }
    if (winner == 0) {
      return -1;
    }
    if (winner == -1) {
      return 0;
    }
  }

  if (max) {
    eval = -10000;
  } else {
    eval = 10000;
  }

  std::vector<int> possibleMoves = getAvailableMoves(gamestate);

  for (int i = 0; i < possibleMoves.size(); i++) {
    // copy current state
    std::vector<int> newState = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    for (int space = 0; space < 9; space++) {
      newState[space] = gamestate[space];
    }

    // make new move
    newState[possibleMoves[i]] = max;
    int simEval = minimax(newState, !max, game, depth - 1, initialDepth);

    if (initialDepth == depth) {
      if (max) {
        if (simEval > eval) {
          bestMove = i;
        }
      } else {
        if (simEval < eval) {
          bestMove = i;
        }
      }
    }

    if (max) {
      eval = std::max(eval, simEval);
    } else {

      eval = std::min(eval, simEval);
    }
  }

  if (initialDepth == depth) {
    int move = possibleMoves[bestMove];
    game.state[move] = max;
  }
  return eval;
}
