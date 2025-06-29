#include <iostream>
#include <string>

std::string parts(std::string text, int number) {
    std::string firstPart;
    std::string secondPart;
    std::string thirdPart;
    std::string fourthPart;
    int numberSymbols = 1;

    for(int i = 0; i < text.length(); i++) {
        if (text[i] != '.') {
            firstPart += text[i];
            numberSymbols++;
        } else break;
    }

    for (int j = numberSymbols; j < text.length(); j++) {
        if (text[j] != '.') {
            secondPart += text[j];
            numberSymbols++;
        } else {
            numberSymbols++;
            break;
        }
    }

    for (int n = numberSymbols; n < text.length(); n++) {
        if (text[n] != '.') {
            thirdPart += text[n];
            numberSymbols++; 
        } else {
            numberSymbols++;
            break;
        }
    }

    for (int k = numberSymbols; k < text.length(); k++) {
        if (text[k] != '.') {
            fourthPart += text[k];
            numberSymbols++;
        } else break;
    }

    return (number == 1) ? firstPart : (number == 2) ? secondPart : (number == 3) ? thirdPart : fourthPart;
}

int string_to_number(std::string text) {
    int number = 0;
    if (text.length() == 3) {
        number = 100 * (text[0] - '0') + 10 * (text[1] - '0') + (text[2] - '0');
    } else if (text.length() == 2) {
        number = 10 * (text[0] - '0') + (text[1] - '0');
    } else if (text.length() == 1) {
        number = text[0] - '0';
    }
    return number;
}
    
int main() {
    std::cout << "\t\t****************************\n"
              << "\t\t*       This program       *\n"
              << "\t\t* validates the IP address *\n"
              << "\t\t****************************\n";

    while (true) {
        std::string address;
        std::cout << "Input IP address: ";
        std::cin >> address;

        bool correct = true;

        for (int i = 0; i < address.length(); i++) {
            if (address[i] < '.' ||
                address[i] > '.' && address[i] < '0' ||
                address[i] > '9'
                ||
                address[i] == '.' && address[i + 1] == '.'
                ||
                address[address.length() - 1] == '.') {
                    correct = false;
                    break;
            }
        }

        std::string firstPart  = parts(address, 1);
        std::string secondPart = parts(address, 2);
        std::string thirdPart  = parts(address, 3);
        std::string fourthPart = parts(address, 4);

        if (firstPart.length()  > 1 && firstPart[0]  == '0' ||
            secondPart.length() > 1 && secondPart[0] == '0' ||
            thirdPart.length()  > 1 && thirdPart[0]  == '0' ||
            fourthPart.length() > 1 && fourthPart[0] == '0') {
                correct = false;
        }

        if (string_to_number(firstPart)  < 0 || string_to_number(firstPart)  > 255 ||
            string_to_number(secondPart) < 0 || string_to_number(secondPart) > 255 ||
            string_to_number(thirdPart)  < 0 || string_to_number(thirdPart)  > 255 ||
            string_to_number(fourthPart) < 0 || string_to_number(fourthPart) > 255) {
                correct = false;
        }

        correct ? std::cout << "Valid\n" : std::cout << "Invalid\n";
    }
}