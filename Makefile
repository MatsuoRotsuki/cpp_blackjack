all:
	g++ -std=c++17 -w main.cpp card.cpp deck.cpp hand.cpp player.cpp game.cpp -o main

compile:
	g++ -std=c++17 -w server.cpp server_controller.cpp UI/blackjack/message.cpp accountmanager.cpp md5.cpp state.cpp -o server -lcrypto -lssl -ljsoncpp
	g++ -std=c++17 -w client.cpp client_controller.cpp UI/blackjack/message.cpp -o client

start-server:
	./server 5500

start-client:
	./client 127.0.0.1 5500

start:
	./main