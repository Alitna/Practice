#include <iostream>
#include <string>
#include <cmath>

int current(std::string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++)
        count++;
    return count;
}

int main() {
    std::cout << "\t\t*****************************************************\n"
              << "\t\t*        This program consists of the integer       *\n"
              << "\t\t*         and fractional parts of a number,         *\n"
              << "\t\t*    which are individually entered by the user,    *\n"
              << "\t\t* to form a new floating-point number (type double) *\n"
              << "\t\t*****************************************************\n";

    std::string wholePart;
    std::cout << "Input whole part number: ";
    std::cin >> wholePart;

    std::string fractionalPart;
    std::cout << "Input fractional part number: ";
    std::cin >> fractionalPart;

    double newNumber = (std::stod(wholePart) * pow(10, current(fractionalPart)) + std::stod(fractionalPart)) / pow(10, current(fractionalPart));

    std::cout << newNumber;
}