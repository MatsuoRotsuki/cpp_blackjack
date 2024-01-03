all:
	g++ -std=c++17 main.cpp card.cpp deck.cpp hand.cpp player.cpp game.cpp -o main

compile:
	g++ server.cpp dispatch_server.cpp message.cpp -o server
	g++ client.cpp dispatch_client.cpp message.cpp -o client

start-server:
	./server 5500

start-client:
	./client 127.0.0.1 5500

start:
	./main