#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void binary_picture(int &height, int &width) {
    std::srand(std::time(nullptr));
    
    int array[height][width];
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            array[i][j] = std::rand() % 2;

    std::ofstream file("pic.txt");
    if (file.is_open()) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j)
                file << array[i][j];
            file << std::endl;
        }
    } else std::cerr << "File opening error!" << std::endl;

    file.close();
}

int main() {
    std::cout << "\t\t****************************************\n"
              << "\t\t* This program uses a random generator *\n"
              << "\t\t*     to create binary pictures        *\n"
              << "\t\t****************************************\n";

        while (true) {
            int height = 0, width = 0;
            std::cout << "Input height and width: ";
            std::cin >> height >> width;

            while(height <= 0 || width <= 0) {
                std::cout << "Invalid data. Input again: ";
                std::cin >> height >> width;
            }

            binary_picture(height, width);
    }
}