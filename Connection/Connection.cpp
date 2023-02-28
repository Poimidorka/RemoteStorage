#include "Connection.h"

Connection::Connection(std::string ipv4, std::string port) {
    this->ipv4 = ipv4;
    this->port = port;
    this->status = not_started;
}