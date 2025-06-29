#include <iostream>

int number_of_ways(int n, int k = 3) {
    if (n == 0) 
        return 1;
    int sum = 0;
    for (int i = 1; i <= k && i <= n; ++i)
        sum += number_of_ways(n - i);
    return sum;
}

int main() {
    std::cout << "\t\t******************************************\n"
              << "\t\t* This program uses a recursive function *\n"
              << "\t\t*  to return the number of ways a rabbit *\n"
              << "\t\t*       can jump to the n-th step        *\n"
              << "\t\t******************************************\n";

    int n = 0;
    while (true) {
        std::cout << "Input number of steps: ";
        std::cin >> n;
    
        while (n <= 0) {
            std::cerr << "The number of steps can not be zero or a negative number." << std::endl;
            std::cout << "Input number of steps: ";
            std::cin >> n;
        }

        std::cout << "The number of ways a rabbit can jump up to the " << n << " step: " << number_of_ways(n) << std::endl;
    }
}