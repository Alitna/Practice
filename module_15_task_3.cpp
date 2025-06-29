#include <iostream>
#include <vector>

std::vector<int> sorting(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++)
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[i] > vec[j])
                std::swap(vec[i], vec[j]);
    return vec;
}

int main() {
    std::cout << "\t\t****************************\n"
              << "\t\t*  This program displays   *\n"
              << "\t\t* the fifth highest number *\n"
              << "\t\t*  among the entered ones  *\n"
              << "\t\t****************************\n";

    std::vector<int> vec;
    int num = 0;
    std::cout << "Input numbers: ";

    while (num != -2) {
        std::cin >> num;
        if (num != -1) {
            if (vec.size() < 5) {
                vec.push_back(num);
                vec = sorting(vec);
            } else {
                if (num < vec.back()) {
                    vec.push_back(num);
                    vec = sorting(vec);
                    vec.pop_back();
                }
            }

        } else if (num == -1 && vec.size() < 5) {
            std::cerr << "You must enter at least 5 numbers" << std::endl;
        
        } else {
            vec = sorting(vec);
            std::cout << vec.back() << std::endl;
            for (int i = 0; i < vec.size(); i++)
                std::cout << vec[i] << " ";
        }
    }
}