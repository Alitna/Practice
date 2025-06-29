#include <iostream>
#include <string>

enum note {DO = 1, RE = 2, MI = 4, FA = 8, SOL = 16, LA = 32, SI = 64};

int main() {
    std::cout << "\t\t******************************\n"
              << "\t\t* This program outputs notes *\n"
              << "\t\t*   from the entered chord   *\n"
              << "\t\t******************************\n";

    std::string chord;
    std::cout << "Input chord: ";
    std::cin >> chord;

    int notes = 0;

    for (int i = 0; i < chord.length(); i++) {
        notes = chord[i] - '0';
        if (notes < 1 || notes > 7) {
            std::cerr << "Wrong notes ";
            break;
        }

    int maska = 0;
    for (int i = 0; i < 7; i++)
        if (notes >= 1 && notes <= 7)
            maska |= (1 << (notes - 1));

    if (maska & DO) 
        std::cout << "DO ";
    else if (maska & RE) 
        std::cout << "RE ";
    else if (maska & MI) 
        std::cout << "MI ";
    else if (maska & FA) 
        std::cout << "FA ";
    else if (maska & SOL) 
        std::cout << "SOL ";
    else if (maska & LA) 
        std::cout << "LA ";
    else if (maska & SI) 
        std::cout << "SI ";

    }
}