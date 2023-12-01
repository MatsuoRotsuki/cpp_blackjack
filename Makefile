all:
	g++ -std=c++17 main.cpp card.cpp deck.cpp hand.cpp player.cpp game.cpp -o main

start:
	./main