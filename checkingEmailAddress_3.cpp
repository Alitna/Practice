#include <iostream>
#include <string>

std::string firstPart(std::string text) {
    std::string firstPart;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != '@') {
            firstPart += text[i];
        } else break;
    }
    return firstPart;
}

std::string secondPart(std::string text) {
    std::string secondPart;
    int firstPart = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != '@') {
            firstPart++;
        } else break;
    }
    for (int j = firstPart + 1; j < text.length(); j++) {
        secondPart += text[j];
    }
    return secondPart;
}

bool is_correct1(std::string text) {
    if (text.length() < 1 || text.length() > 64 || text[0] == '.') {
        return false;
    }
    int i = 0;
    std::string forbiddenChars1 = "\"(),:;<>@[\\]";
    for (; i < text.length(); i++) {
        if (text[i] == '.' && text[i + 1] == '.') return false;
        for (int k = 0; k < forbiddenChars1.length(); k++) {
            if (text[i] < 33 || text[i] > 126 || text[i] == forbiddenChars1[k]) return false;
        }
    }
    return text[i] != '.';
}

bool is_correct2(std::string text) {
if (text.length() < 1 || text.length() > 63 || text[text.length() - 1] == '.') {
    return false;
}
 int j = 0;
    std::string forbiddenChars2 = "/:;<=>?@[\\]^_`";
    for (; j < text.length(); j++) {
        if (text[j] == '.' && text[j + 1] == '.') return false;
        for (int n = 0; n < forbiddenChars2.length(); n++) {
            if (text[j] < 45 || text[j] > 122 || text[j] == forbiddenChars2[n]) return false;
        }
    }
    return text[j] != '.';
}

int main() {
    std::cout << "\t\t**************************\n"
              << "\t\t*      This program      *\n"
              << "\t\t* checks the correctness *\n"
              << "\t\t*  of the email address  *\n"
              << "\t\t**************************\n";

    while (true) {
        std::string address;
        std::cout << "Input email: ";
        std::cin >> address;

        std::string firstPartAddress = firstPart(address);
        std::string secondPartAddress = secondPart(address);

        is_correct1(firstPartAddress) && is_correct2(secondPartAddress) ? std::cout << "Yes\n" : std::cout << "No\n";
    }
}