all:
	g++ main.cpp card.cpp deck.cpp hand.cpp player.cpp game.cpp -o main

start:
	./main