#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "\t\t**********************\n"
              << "\t\t*    This program    *\n"
              << "\t\t* scans the simplest *\n"
              << "\t\t*     text files     *\n"
              << "\t\t**********************\n";

    std::string path;
    std::cout << "Input path: ";
    std::cin >> path;

    int size = 40;
    char buffer[size];
    
    std::ifstream document;
    document.open(path, std::ios::binary);
    if (document.is_open()) {
        while (!document.eof()) {
            document.read(buffer, sizeof(buffer));
            buffer[document.gcount()] = 0;
            std::cout << buffer << std::endl;
        }
    } else 
        std::cerr << "File opening error!" << std::endl;
    document.close();
}