#include "include/system/network.hpp"

#define PORT htons(8080)

void Network::Server::initializeServer() {
    Network::Server::serverSoc = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = PORT;
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(Network::Server::serverSoc, (struct sockaddr*) &serverAddr, sizeof(struct sockaddr));

    listen(serverSoc, 1);

    sockaddr_in clientAddr;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    Network::Server::clientSoc = accept(Network::Server::serverSoc, (struct sockaddr*) &clientAddr, &sin_size);
}

void Network::Server::serverSend(const char * c) {
    strcpy(Network::Server::buffer, c);
    int n = write(Network::Server::clientSoc, Network::Server::buffer, strlen(Network::Server::buffer));
}

char* Network::Server::serverRecv() {
    bzero(Network::Server::buffer, 1024);
    int n = read(Network::Server::clientSoc, Network::Server::buffer, 512);
    return Network::Server::buffer;
}


void Network::Client::initializeClient() {
    Network::Client::soc = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = PORT; 
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    connect(Network::Client::soc, (struct sockaddr*) &serverAddr, sizeof(struct sockaddr));
}

void Network::Client::clientSend(const char * c) {
    strcpy(Network::Client::buffer, c);
    int n = write(Network::Client::soc, Network::Client::buffer, strlen(Network::Client::buffer));
}

char* Network::Client::clientRecv() {
    bzero(Network::Client::buffer, 1024);
    int n = read(Network::Client::soc, Network::Client::buffer, 512);
    return Network::Client::buffer;
}
