#include <iostream>

int main() {
    std::cout << "\t\t******************************\n"
              << "\t\t* This program initializes a *\n"
              << "\t\t*   two-dimensional array    *\n"
              << "\t\t*       with a snake         *\n"
              << "\t\t******************************\n";

    int digits[5][5];
    int number = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            digits[i][j + (i % 2) * (4 - 2 * j)] = number;
            number++;
        }
    }

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j)
            std::cout << digits[i][j] << " ";
         std::cout << std::endl;
    }
}