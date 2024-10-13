#include <iostream>
#include "Dictionary.h"
#include <windows.h>

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add word\n";
    std::cout << "2. Remove word\n";
    std::cout << "3. Sort words\n";
    std::cout << "4. Print words\n";
    std::cout << "5. Find word\n";
    std::cout << "6. Exit\n";
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int capacity = 100; // Максимальна кількість слів у словнику
    Dictionary dictionary(capacity);

    int choice;
    std::string ua, en;
    Word word;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter Ukrainian word: ";
            std::cin >> ua;
            std::cout << "Enter English translation: ";
            std::cin >> en;
            dictionary.addWord(Word(ua, en));
            break;
        case 2:
            std::cout << "Enter Ukrainian word to remove: ";
            std::cin >> ua;
            dictionary.removeWord(Word(ua, ""));
            break;
        case 3:
            dictionary.sortWords();
            std::cout << "Words sorted.\n";
            break;
        case 4:
            dictionary.printWords();
            break;
        case 5:
            std::cout << "Enter Ukrainian word to find: ";
            std::cin >> ua;
            try {
                word = dictionary.findWord(ua);
                std::cout << "Found: " << word.ukrainian << " - " << word.english << "\n";
            }
            catch (std::invalid_argument& e) {
                std::cout << e.what() << "\n";
            }
            break;
        case 6:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);

    return 0;
}
