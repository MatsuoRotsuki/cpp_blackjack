#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <signal.h>
#include <mutex>
#include <iostream>
#include <memory>
#include <atomic>
#include "message.h"

void HandleInterrupt(int signal);
void HandleSendingThread(int client_socket);
void HandleReceivingThread(int client_socket);


void DispatchDisconnect();