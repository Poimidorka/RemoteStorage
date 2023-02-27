#include <stdexcept>

#ifndef UNTITLED_BYTE_STORAGE_H
#define UNTITLED_BYTE_STORAGE_H

class ByteStorage {
};

class ByteLine {
   private:
    char* str;
    size_t length;
   public:
    ByteLine(size_t length);
    size_t size() const;
    char& operator[](size_t index);
    const char& operator[] (size_t index) const;
    ~ByteLine() {
        delete[](str);
    }
};

struct ByteHash {
    const static size_t X = 157;
    size_t operator() (const ByteLine& byteLine);
};

#endif  //UNTITLED_BYTE_STORAGE_H
