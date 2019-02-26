#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

class Network 
{
    public: 
        class Server {
            char buffer[1024];
            int buffer_size;

            int clientSoc;
            int serverSoc;

            public:
                void initializeServer();
                void serverSend(const char * c);
                char* serverRecv();
        };

        class Client {
            char buffer[1024];
            int buffer_size;

            int soc;

            public:
                void initializeClient();
                void clientSend(const char * c);
                char* clientRecv();
        };

};
