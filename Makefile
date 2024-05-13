all: main

main: src/main.cpp src/board.cpp src/utils.cpp src/game.cpp src/minimax.cpp
	g++ src/main.cpp src/board.cpp src/utils.cpp src/game.cpp src/minimax.cpp -lncurses -o main
