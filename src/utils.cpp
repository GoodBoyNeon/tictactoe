#include "../include/utils.h"
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

template <typename T> T randomVec(const std::vector<T> &vec) {
  srand(time(nullptr));

  int randIndex = rand() % vec.size();

  return vec[randIndex];
}

template int randomVec<int>(const std::vector<int> &vec);
