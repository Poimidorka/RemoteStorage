#include <stdexcept>
#include "StorageInterface.h"
#include <unordered_map>

#ifndef UNTITLED_BYTE_STORAGE_H
#define UNTITLED_BYTE_STORAGE_H


class ByteLine {
   private:
    char* str;
    size_t length;
   public:
    ByteLine();
    ByteLine(size_t length);
    ByteLine(const ByteLine &other);
    size_t size() const;
    char& operator[](size_t index);
    const char& operator[] (size_t index) const;
    bool operator==(const ByteLine& other) const;
    bool operator!=(const ByteLine& other) const;
    ByteLine& operator=(const ByteLine& other);
    ~ByteLine() {
        delete[](str);
    }
};

struct ByteHash {
    const static size_t X = 157;
    size_t operator() (const ByteLine &byteLine) const;
};

class ByteStorage: public StorageInterface<ByteLine, ByteLine> {
   private:
    std::unordered_map<ByteLine, ByteLine, ByteHash> data;
    void put(ByteLine key, ByteLine value) override;
    void put(ByteLine key, ByteLine&& value) override;
    ByteLine& get(const ByteLine &key) override;
    [[nodiscard]] const ByteLine& get(const ByteLine &key) const override;
};


#endif  //UNTITLED_BYTE_STORAGE_H
