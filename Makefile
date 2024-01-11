all:
	g++ -std=c++17 -w main.cpp blackjack.cpp -o main

compile:
	g++ -std=c++17 -w server.cpp server_controller.cpp UI/blackjack/message.cpp accountmanager.cpp md5.cpp clientmanager.cpp roommanager.cpp blackjack.cpp -o server -lcrypto -lssl -ljsoncpp
	g++ -std=c++17 -w client.cpp client_controller.cpp UI/blackjack/message.cpp blackjack.cpp -o client

debug:
	g++ -g -std=c++17 -w server.cpp server_controller.cpp UI/blackjack/message.cpp accountmanager.cpp md5.cpp clientmanager.cpp roommanager.cpp blackjack.cpp -o server_debug -lcrypto -lssl -ljsoncpp

start-server:
	./server 5500 

start-client:
	./client 127.0.0.1 5500

start:
	./main