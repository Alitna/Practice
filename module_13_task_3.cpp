#include <iostream>
#include <vector>

int main() {
    std::cout << "\t\t*******************************************************\n"
              << "\t\t*          This program simulates storage             *\n"
              << "\t\t* for integer values in an embedded operating system. *\n"
              << "\t\t*   The storage cannot contain more than 20 items     *\n"
              << "\t\t*******************************************************\n";

    std::vector<int> vec(20);
    int num;
    int i = 0, j;
    while (num != -2) {
        std::cout << "Input number: ";
        std::cin >> num;
        if (num == -1) {
            std::cout << "Output: ";
            for (int i = 0; i < vec.size(); i++)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
        } else {
            if (i < 20) {
                vec[i] = num;
                i++;
            } else {
                for (int j = 0; j < vec.size(); j++)
                    vec[j] = vec [j + 1];
                vec.back() = num;
            }
        }   
    }
    std::cout << std::endl << vec.capacity() << std::endl;
}