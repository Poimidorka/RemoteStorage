#include <string>

#ifndef UNTITLED_STORAGE_INTERFACE_H
#define UNTITLED_STORAGE_INTERFACE_H

template<class K = std::string, class V = std::string>
class StorageInterface {
   public:
    virtual V get(const K &key) = 0;
    virtual void put(K key, V value) = 0;
    virtual void put(K key, V&& value) = 0;
};

#endif  //UNTITLED_STORAGE_INTERFACE_H
