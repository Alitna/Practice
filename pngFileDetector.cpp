#include <iostream>
#include <fstream>
#include <string>

std::string checking_extension(std::string &path) {
    int count = 0;
    for (int i = path.length(); path[i] != '.'; i--) {
        if (path[i] != '.')
        count++;
    }
    std::string extension = path.substr(path.length() - count);
    return extension;
}

void checking_path_and_internals(std::string &path) {

    std::string expansion = checking_extension(path); 

    std::ifstream picture;
    picture.open(path, std::ios::binary);
    if (picture.is_open()) {
        char buffer[8];
        picture.read(buffer, 4);
        
        expansion == ".png" && buffer[0] < 0 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G' 
        ? std::cout << "Yes, this file is a PNG image." << std::endl 
        : std::cout << "No, this file is not a PNG image." << std::endl;
    
    } else std::cerr << "File opening error!" << std::endl;
    picture.close();
}

int main() {
    std::cout << "\t\t*********************************\n"
              << "\t\t*    This program determines    *\n"
              << "\t\t* whether a file is a PNG image *\n"
              << "\t\t*********************************\n";

    std::string path;
    std::cout << "Input path: ";
    std::cin >> path;

    checking_path_and_internals(path);
}