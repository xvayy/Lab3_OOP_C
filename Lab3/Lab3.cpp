#include <iostream>
#include "Dictionary.h"

using namespace std;


int main() {
    try {
        std::setlocale(LC_ALL, "Ukrainian");
        Dictionary dict(10);

        Word word1("кіт", "cat");
        Word word2("пес", "dog");
        Word word3("вода", "water");
        Word word4("яблуко", "apple");
        Word word5("ноутбук", "laptop");
        Word word6("телефон", "phone");
        Word word7("навушники", "headphones");


        dict + word1 + word2 + word3 + word4 + word5 + word6 + word7;
        cout << "Слова в словнику після додавання:" << endl;
        dict.printWords();

        dict - word2;
        cout << "\nСлова в словнику після видалення слова 'пес':" << endl;
        dict.printWords();

        dict.sortByUkrainian();
        cout << "\nСлова в словнику після сортування за українським перекладом:" << endl;
        dict.printWords();

        return 0;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
