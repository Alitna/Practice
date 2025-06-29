#include <iostream>
#include <vector>

std::vector<int> remove(std::vector<int> vec, int val) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == val) {
            for (int j = i; j < vec.size(); j++)
                vec[j] = vec[j + 1];
            vec.pop_back();
            i--;
        }
    }
    return vec;
}

int main() {
    std::cout << "\t\t********************************\n"
              << "\t\t*     This program removes     *\n"
              << "\t\t* the number X from the vector *\n"
              << "\t\t*    specified by the user     *\n"
              << "\t\t********************************\n";

    int n;
    std::cout << "Input vector size: ";
    std::cin >> n;
    
    std::vector<int> vec(n);

    std::cout << "Inpur numbers: ";
    for (int i = 0; i < vec.size(); i++)
        std::cin >> vec[i];

    int del;
    std::cout << "Input number to delete: ";
    std::cin >> del;

    vec = remove(vec, del);

    std::cout << "Result: ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
}