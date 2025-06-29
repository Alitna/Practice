#include <iostream>

void rearrange(int* pa, int* pb) {
    std::swap(*pa, *pb);     
}

int main() {
    std::cout << "\t\t***************************************\n"
              << "\t\t*     The function in this program    *\n"
              << "\t\t* takes two pointers to int and swaps *\n"
              << "\t\t*    the contents of these pointers   *\n"
              << "\t\t***************************************\n";

    int a = 10;
    int b = 20;

    int* pa = &a;
    int* pb = &b;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "Swapping places: " << std::endl;

    rearrange(pa, pb);
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
}