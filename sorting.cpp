#include <iostream>

int main() {
    std::cout << "\t\t****************************\n"
              << "\t\t*       This program       *\n"
              << "\t\t* sorts fractional numbers *\n"
              << "\t\t*  from larger to smaller  *\n"
              << "\t\t****************************\n";

    float numbers[15];
    std::cout << "Input numbers: ";
    for (int i = 0; i < 15; ++i)
        std::cin >> numbers[i];

    for (int i = 0; i < 15; ++i) {
        for (int j = i; j < 15; ++j) {
            if (numbers[j] > numbers[i]) 
                std::swap(numbers[j], numbers[i]);
        }
    }

    std::cout << "Conclusion:    ";
    for (int i = 0; i < 15; i++)
        std::cout << numbers[i] << " ";
}