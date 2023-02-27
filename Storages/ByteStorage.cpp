//
// Created by Mark Kanafeev on 27.02.2023.
//

#include "ByteStorage.h"

size_t ByteLine::size() const {
    return this->length;
}

ByteLine::ByteLine(size_t length) {
    this->length = length;
    this->str = new char[length];
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

size_t ByteHash::operator()(const ByteLine &byteLine) {
    size_t answer = 0;
    for (size_t index = 0; index < byteLine.size(); index++) {
        answer = ByteHash::X * answer + byteLine[index];
    }
    return answer;
}