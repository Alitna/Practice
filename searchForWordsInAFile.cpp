#include <iostream>
#include <fstream>
#include <string>

int word_search(const std::string& word) {
    std::string documentWord;
    std::ifstream document;
    document.open("words.txt");

    int count = 0;
    if (document.is_open()) {
        char ch;
        while (!document.eof()) {     
            document.get(ch);
            if (ch != ' ' && ch != '\0' && ch != '\n' && !document.eof())
                documentWord += ch;
            else {
                if (documentWord == word)
                    count++;
                documentWord = "";    
            }
        } 
    } else
        std::cerr << "Error" << std::endl;
    
    document.close();
    return count;
}

int main() {
    std::cout << "\t\t**********************\n"
              << "\t\t*    This program    *\n"
              << "\t\t* searches for words *\n"
              << "\t\t*     in a file      *\n"
              << "\t\t**********************\n";

        std::string userWord;
        while (userWord != "0") {
            std::cout << "Input word: ";
            std::cin >> userWord;

            std::cout << word_search(userWord) << std::endl; 
    }
}