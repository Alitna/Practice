#include <iostream>
#include <map>
#include <string>

bool checking(const std::string& s1, const std::string& s2) {
    std::map<char, int> firstLine;
    std::map<char, int> secondLine;
    if (s1.length() != s2.length()) return false;
    else
        for (int i = 0; i < s1.length(); ++i) {
            std::pair<char, int> letterAndSizeFirstLine(s1[i], s1.length());
            std::pair<char, int> letterAndSizeSecondLine(s2[i], s2.length());
            firstLine.insert(letterAndSizeFirstLine);
            secondLine.insert(letterAndSizeSecondLine);
        }

    if (firstLine == secondLine) return true;
}

int main() {
    std::cout << "\t\t************\n"
              << "\t\t* Anagrams *\n"
              << "\t\t************\n";

    std::cout << "Exit - input \"end\"\n";

    std::string first, second;
    while (true) {
        std::cout << "Input the first line: ";
        std::cin >> first;
        if (first == "end") break;

        std::cout << "Input the second line: ";
        std::cin >> second;
        if (second == "end") break;

        checking(first, second) ? std::cout << "Yes, these are anagrams\n" : std::cout << "No, these are not anagrams\n";
    }
    std::cout << "You're out\n";
}