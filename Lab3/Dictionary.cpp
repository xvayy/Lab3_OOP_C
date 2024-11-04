#include "Dictionary.h"
#include <iostream>
#include <algorithm>
#include <locale>


Dictionary::Dictionary(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    words = new Word[this->capacity];
}

Dictionary::~Dictionary() {
    delete[] words;
}

void Dictionary::addWord(const Word& word) {
    if (size < capacity) {
        words[size++] = word;
    } else {
        cerr << "Capacity exceeded. Cannot add more words." << endl;
    }
}

void Dictionary::removeWord(const Word& word) {
    for (int i = 0; i < size; ++i) {
        if (words[i].getua() == word.getua()) {
            for (int j = i; j < size - 1; ++j) {
                words[j] = words[j + 1];
            }
            --size;
            break;
        }
    }
}

void Dictionary::sortByUkrainian() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (words[j + 1] < words[j]) {
                std::swap(words[j + 1], words[j]);
            }
        }
    }
}

void Dictionary::printWords() const {
    std::setlocale(LC_ALL, "Ukrainian");
    for (int i = 0; i < size; ++i) {
        cout << words[i].getua().c_str() << " - " << words[i].geteng().c_str() << endl;
    }
}

Dictionary& Dictionary::operator+(const Word& word) {
    addWord(word);
    return *this;
}

Dictionary& Dictionary::operator-(const Word& word) {
    removeWord(word);
    return *this;
}
