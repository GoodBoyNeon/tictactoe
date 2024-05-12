all: main

main: src/main.cpp src/board.cpp src/utils.cpp src/game.cpp
	g++ src/main.cpp src/board.cpp src/utils.cpp src/game.cpp -lncurses -o main
