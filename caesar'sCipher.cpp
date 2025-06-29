#include <iostream>
#include <string>

std::string encrypt_caesar(std::string text, int shift) {
    for (; shift >= 26; shift %= 26) {}
    for (int i = 0; i <= text.length(); i++) {
        char letter;
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int lettersEnd = int('Z') - text[i];
            int code = int('A') + (shift - lettersEnd - 1);
            shift > lettersEnd ? letter = (char)code : letter = text[i] + shift;
            for (; letter < 'A'; ) {
                letter = (int('Z') + shift) + 1;
                shift += 26;
            }
            text[i] = letter;
        }
        if (text[i] >= 'a' && text[i] <= 'z') {
            int lettersEnd = int('z') - text[i];
            int code = int('a') + (shift - lettersEnd - 1);
            shift > lettersEnd ? letter = (char)code : letter = text[i] + shift;
            for (; letter < 'a'; ) {
                letter = (int('z') + shift) + 1;
                shift += 26;
            }
            text[i] = letter;
        }
    }
    return text;    
}

int main() {
    std::cout << "\t\t****************\n"
			  << "\t\t* This program *\n"
			  << "\t\t*   encrypts   *\n"
			  << "\t\t*   the text   *\n"
			  << "\t\t****************\n";

    std::string text;
    std::cout << "Input the text: ";
    std::getline(std::cin, text);

    int code;
    std::cout << "Input the code: ";
    std::cin >> code;

    std::cout << encrypt_caesar(text, code) << std::endl;
}