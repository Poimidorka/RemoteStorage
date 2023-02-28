#include "../Connection/Connection.h"
#include "../Storages/ByteStorage.h"

#ifndef UNTITLED_EXECUTOR_H
#define UNTITLED_EXECUTOR_H

enum Type {put, get};

struct Query {
    Type type;
    ByteLine key;
    ByteLine value;
    Query() = default;
    Query(ByteLine key, ByteLine value, Type type);
};

struct Answer {
    bool isEmpty;
    ByteLine value;
    Answer();
    Answer(ByteLine value);
};

Answer run_command_to_storage(Query query, ByteStorage &storage);

void execute_connection(Connection connection);

void infinite_listen();

#endif  //UNTITLED_EXECUTOR_H
