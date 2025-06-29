#include <iostream> 

int main() {
    std::cout << "\t\t*******************************************\n"
              << "\t\t* This program, using a three-dimensional *\n"
              << "\t\t* array, outputs a horizontal  section of *\n"
              << "\t\t*  a square landscape to standard output  *\n"
              << "\t\t*******************************************\n";

    bool world[5][5][10];

    int height = 0;
    std::cout << "Input the height of the blocks: " << std::endl;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            std::cin >> height;
            for (int k = 0; k <= height; ++k) {
                while(height < 0 || height > 10) {
                    std::cout << "Error. Please input again: " << std::endl;
                    std::cin >> height;
                }
                world[i][j][k] = true;
            }
            for (int l = height + 1; l < 10; ++l)
                world[i][j][l] = false;
        }

    int slice = 0;
    std::cout << "Input slice: ";
    std::cin >> slice;
    while(slice < 0 || slice > 9) {
        std::cout << "Error. Please input again: " << std::endl;
        std::cin >> slice;
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            std::cout << world[i][j][slice] << " ";
        std::cout << std::endl;
    }
}