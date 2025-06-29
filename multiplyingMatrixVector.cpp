#include <iostream>
#include <vector>

int main() {
    std::cout << "\t\t***********************\n"
              << "\t\t*     This program    *\n"
              << "\t\t* multiplies a vector *\n"
              << "\t\t*     by a matrix     *\n"
              << "\t\t***********************\n";
    
    float b[4];
    float a[4][4];
    std::vector<float> c(4);

    std::cout << "Input the vector elements: ";
    for (int i = 0; i < 4; i++)
        std::cin >> b[i];

    std::cout << "Input the elements of the matrix: ";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            std::cin >> a[i][j];

    for (int i = 0; i < 4; ++i) {
        float sum = 0;
        for (int j = 0; j < 4; ++j) 
            sum += a[i][j] * b[j];       
        c[i] = sum;
    }
        
    std::cout << "Final vector: ";
    for (int i = 0; i < c.size(); i++) 
        std::cout << c[i] << " ";
}