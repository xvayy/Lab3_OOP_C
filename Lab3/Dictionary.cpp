#include "Dictionary.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

Dictionary::Dictionary(int capacity) {
    setlocale(LC_ALL, "Ukrainian");

    this->capacity = capacity;
    this->size = 0;
    this->words = new Word[capacity];

    this->addWord(Word("к≥т", "cat"));
    this->addWord(Word("пес", "dog"));
    this->addWord(Word("сонце", "sun"));
    this->addWord(Word("м≥с€ць", "moon"));
    this->addWord(Word("вода", "water"));
}

Dictionary::~Dictionary() {
    delete[] this->words;
}

void Dictionary::addWord(const Word& word) {
    if (this->size < this->capacity) {
        this->words[this->size++] = word;
    }
    else {
        throw std::out_of_range("Dictionary capacity exceeded");
    }
}

void Dictionary::removeWord(const Word& word) {
    for (int i = 0; i < this->size; ++i) {
        if (this->words[i].ukrainian == word.ukrainian) {
            for (int j = i; j < this->size - 1; ++j) {
                this->words[j] = this->words[j + 1];
            }
            this->size--;
            return;
        }
    }
    throw std::invalid_argument("Word not found");
}

void Dictionary::sortWords() {
    std::sort(this->words, this->words + this->size);
}

void Dictionary::printWords() const {
    setlocale(LC_ALL, "Ukrainian");

    for (int i = 0; i < this->size; ++i) {
        std::cout << this->words[i].ukrainian << " - " << this->words[i].english << std::endl;
    }
}

Word Dictionary::findWord(const std::string& ua) const {

    for (int i = 0; i < this->size; ++i) {
        if (this->words[i].ukrainian == ua) {
            return this->words[i];
        }
    }
    throw std::invalid_argument("Word not found");
}

void Dictionary::inputWords(int count) {
    setlocale(LC_ALL, "Ukrainian");

    for (int i = 0; i < count; ++i) {
        std::string ua, en;
        std::cout << "Enter Ukrainian word: ";
        std::cin >> ua;
        std::cout << "Enter English translation: ";
        std::cin >> en;
        this->addWord(Word(ua, en));
    }
}
