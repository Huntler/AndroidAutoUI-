#include "include/system/clientworker.h"
#include "include/system/network.hpp"


Network::Client * network = new Network::Client;

void ClientWorker::awaitBridge(QString param)
{
    QString result;
    std::string command = param.toStdString();

    if (!bridge_running)
    {
        network->initializeClient();

        // 'login' into server as commander
        std::string in = "set client_id Commander";
        network->clientSend(in.c_str());

        // wait for a server respond (will be 'Bridge started')
        network->clientRecv();
        bridge_running = true;
    }

    // send commands while the bridge is online
    network->clientSend(command.c_str());

    // wait for an answer
    char * c = network->clientRecv();
    std::string input( reinterpret_cast< char const * >(c) );

    // set a signal with the result
    emit gotResult(QString::fromStdString(input));
}
