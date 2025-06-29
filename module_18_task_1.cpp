#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int* array) {
    for (int i = 0; i < 4; i++)
        std::swap(vec[i], *(array + i));
}

int main() {
    std::cout << "\t\t******************************************************\n"
              << "\t\t*     The function in this program  of variables     *\n"
              << "\t\t* accepts std::vector<int> and a pointer to an array *\n"
              << "\t\t*    of type int (of the same size) and exchanges    *\n"
              << "\t\t*            the values of these arrays              *\n"
              << "\t\t******************************************************\n";

    std::vector<int> a = {1, 2, 3, 4};
    
    int b[] = {2, 4, 6, 8};

    std::cout << "Vector:\t";
    for (int i = 0; i < 4; ++i)
        std::cout << a[i];

    std::cout << std::endl;

    std::cout << "Array:\t";
    for (int i = 0; i < 4; ++i)
        std::cout << b[i];

    std::cout << "\nSwapping places..." << std::endl;

    swapvec(a, b);

    std::cout << "Vector:\t";
    for (int i = 0; i < 4; ++i)
        std::cout << a[i];

    std::cout << std::endl;

    std::cout << "Array:\t";
    for (int i = 0; i < 4; ++i)
        std::cout << b[i];
}