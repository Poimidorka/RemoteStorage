#include <string>

#ifndef UNTITLED_CONNECTION_H
#define UNTITLED_CONNECTION_H

enum Status {in_progress, not_started, finished};

class Connection {
private:
    std::string ipv4;
    std::string port;
public:
    Status status;
    Connection(std::string ipv4, std::string port);
};


#endif //UNTITLED_CONNECTION_H
