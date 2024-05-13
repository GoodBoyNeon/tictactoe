#include "../include/minimax.h"
#include "../include/game.h"
#include <algorithm>
#include <vector>

int minimax(std::vector<int> gamestate, bool max, Game &game, int depth,
            int initialDepth) {
  std::vector<int> curState = gamestate;
  int bestScore;
  int winner = checkWinner(gamestate);

  std::vector<int> bestMove = {0};
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
    int maxEval = -10000;
    std::vector<int> possibleMoves = getAvailableMoves(gamestate);

    for (int i = 0; i < possibleMoves.size(); i++) {
      std::vector<int> newState = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
      for (int space = 0; space < 9; space++) {
        newState[space] = curState[space];
      }
      newState[possibleMoves[i]] = 1;

      int eval = minimax(newState, false, game, depth - 1, initialDepth);

      if (initialDepth == depth) {

        if (eval > maxEval) {
          bestMove.clear();
          bestMove.push_back(i);
        } else if (eval == maxEval) {
          bestMove.push_back(i);
        }
      }
      maxEval = std::max(maxEval, eval);
    }

    if (initialDepth == depth) {

      int move = possibleMoves[bestMove[0]];

      game.state[move] = 1;
    }

    return maxEval;

  } else {
    int minEval = 10000;
    std::vector<int> possibleMoves = getAvailableMoves(gamestate);

    for (int i = 0; i < possibleMoves.size(); i++) {
      std::vector<int> newState = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
      for (int space = 0; space < 9; space++) {
        newState[space] = curState[space];
      }
      newState[possibleMoves[i]] = 0;

      int eval = minimax(newState, true, game, depth - 1, initialDepth);

      if (initialDepth == depth) {

        if (eval < minEval) {
          bestMove.clear();
          bestMove.push_back(i);
        } else if (eval == minEval) {
          bestMove.push_back(i);
        }
      }
      minEval = std::min(minEval, eval);
    }

    std::vector<int> pMoves = getAvailableMoves(gamestate);

    if (initialDepth == depth) {

      int move = possibleMoves[bestMove[0]];

      game.state[move] = 0;
    }
    return minEval;
  }

  return 0;
  // if (max) {
  //   bestScore = -1000;
  // } else {
  //   bestScore = 1000;
  // }
  //
  // for (int posMove : game->getAvailableMoves()) {
  //   game->state[posMove] = !max; // make temp move
  //   MinimaxData result = minimax(game, !max);
  //   game->state[posMove] = -1; // undo move
  //
  //   if (max) {
  //     if (result.score > bestScore) {
  //       bestScore = result.score;
  //       bestMove = posMove;
  //     }
  //   } else {
  //     if (result.score < bestScore) {
  //       bestScore = result.score;
  //       bestMove = posMove;
  //     }
  //   }
  // }
  //
  // MinimaxData res = MinimaxData(bestScore, bestMove);
  // return res;
}
