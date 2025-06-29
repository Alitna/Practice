#include <iostream>
#include <vector>

int main() {
    std::cout << "\t\t************************************\n"
              << "\t\t*  This program finds two numbers  *\n"
              << "\t\t*     in the array, the sum of     *\n"
              << "\t\t* which gives the specified result *\n"
              << "\t\t************************************\n";

    std::vector<int> vec = {2, 7, 11, 15};
    int result = 9;

    bool res = true;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] + vec[j] != result) {
                res = false;
            } else {
                std::cout << vec[i] << " and " << vec[j] << std::endl;
                res = true;
                break;
            }
        }
        if (res) break;
    }

    if (!res)
        std::cerr << "There are no matching pairs of numbers for this result" << std::endl;
}