#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::cout << "\t\t**********************************\n"
              << "\t\t*    This program calculates     *\n"
              << "\t\t* simple operations with numbers *\n"
              << "\t\t*     from user input into       *\n"
              << "\t\t*  a temporary variable string   *\n"
              << "\t\t**********************************\n";

    while (true) {
        std::string buffer;
        std::cout << "Input the command: ";
        std::cin >> buffer;

        std::stringstream buffer_stream(buffer);

        double firstNumber;
        char operation;
        double secondNumber;

        buffer_stream >> firstNumber >> operation >> secondNumber;

        double result = 0;

        if (secondNumber == 0) {
            std::cout << "It cannot be divided by 0" << std::endl;
        } else {

            if (operation == '+') {
                result = firstNumber + secondNumber;
            } else if (operation == '-') {
                result = firstNumber - secondNumber;
            } else if (operation == '/') {
                result = firstNumber / secondNumber;
            } else {
                result = firstNumber * secondNumber;
            }
            
            std::cout << "result: " << result << std::endl;
        }
    }
}