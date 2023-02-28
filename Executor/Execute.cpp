#include "Execute.h"

Query::Query(ByteLine key, ByteLine value, Type type) {
    this->key = key;
    this->value = value;
    this->type = type;
}

Answer::Answer() {
    this->isEmpty = true;
    this->value = ByteLine();
}

Answer::Answer(ByteLine value) {
    this->isEmpty = false;
    this->value = ByteLine();
}

Answer run_command_to_storage(Query query, ByteStorage &storage) {
    switch (query.type) {
        case put : {
            storage.put(query.key, query.value);
            return Answer();
        }
        case get : {
            storage.get(query.key);

        }
    }
}
