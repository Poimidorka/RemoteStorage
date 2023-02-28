#include "ByteStorage.h"

size_t ByteLine::size() const {
    return this->length;
}

ByteLine::ByteLine(size_t length) {
    this->length = length;
    this->str = new char[length];
}

ByteLine::ByteLine() {
    this->length = 0;
    this->str = nullptr;
}

const char& ByteLine::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("bad index while getting value from byte-line");
    }
    return str[index];
}

char& ByteLine::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("bad index while getting value from byte-line");
    }
    return str[index];
}

bool ByteLine::operator==(const ByteLine& other) const {
    if (other.size() != this->size()) {
        return false;
    }
    for (int i = 0; i < other.size(); i++) {
        if (other[i] != this->operator[](i)) {
            return false;
        }
    }
    return true;
}

bool ByteLine::operator!=(const ByteLine& other) const {
    return !ByteLine::operator==(other);
}

ByteLine::ByteLine(const ByteLine &other) {
    this->length = other.length;
    this->str = other.str;
}

ByteLine& ByteLine::operator=(const ByteLine& other) {
    this->length = other.length;
    delete[](this->str);
    this->str = new char[length];
    for (int i = 0; i < length; i++) {
        this->operator[](i) = other[i];
    }
}

size_t ByteHash::operator()(const ByteLine &byteLine) const {
    size_t answer = 0;
    for (size_t index = 0; index < byteLine.size(); index++) {
        answer = ByteHash::X * answer + byteLine[index];
    }
    return answer;
}

void ByteStorage::put(ByteLine key, ByteLine value) {
    data[key] = value;
}

void ByteStorage::put(ByteLine key, ByteLine&& value) {
    data[key] = ByteLine(value);
}

ByteLine& ByteStorage::get(const ByteLine &key) {
    return data.at(key);
}