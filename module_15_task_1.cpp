#include <iostream>
#include <vector>

int main() {
    std::cout << "\t\t***************************\n"
              << "\t\t*     This program        *\n"
              << "\t\t*     finds the sum       *\n"
              << "\t\t* of consecutive elements *\n"
              << "\t\t***************************\n";

    std::vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int sum = 0;
    int maxSum = 0;
    int index_i = 0, index_j = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum = vec[i];
        for (int j = i + 1; j < vec.size(); j++) {
            sum += vec[j];
            if (sum > maxSum) {
                maxSum = sum;
                index_i = i;
                index_j = j;
            }
        }
    }
    std::cout << "index " << index_i << std::endl << "index " << index_j << std::endl << "sum = " << maxSum << std::endl;
}