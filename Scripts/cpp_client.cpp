#include "cpp_include/network.cpp"

// compiler needs -lpthread as argument
#include <pthread.h>


Network::Client network;
bool bridge_running = false;


void * AsyncBridge(void *) {
    while (bridge_running) {
        std::string in;
        std::cout << "> ";
        std::cin >> in;

        network.send(in.c_str());
    }
}

int main()
{
    network.initialize();

    std::string in = "set client_id Commander";
    network.send(in.c_str());

    std::string s = "";
    while (true) {

        char * c = network.recv();
        std::string s( reinterpret_cast< char const* >(c) ) ;

        if (s == "exit") {
            bridge_running = false;
            break;
        }

        else if (s == "Bridge started") {
            bridge_running = true;
            pthread_t thread;
            pthread_create(&thread, NULL, AsyncBridge, NULL);
            pthread_detach(thread);
        }
        
        else {
            std::cout << "< " << s << "\n"; 
        }
    }
    
}