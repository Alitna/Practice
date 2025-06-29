#include <iostream>
#include <vector>

int main(){
    std::cout << "\t\t*******************************\n"
              << "\t\t*    This program displays    *\n"
              << "\t\t* a sorted array in ascending *\n"
              << "\t\t*  order of the number module *\n"
              << "\t\t*******************************\n";

    std::vector<int> vec = {-100, -50, -5, 1, 10, 15};
    
    int beginning;
    for (int i = 0; i < vec.size(); i++) 
        if (vec[i] > 0) {
            beginning = i;
            break;
        }

    int j = beginning;
    for (int i = beginning - 1; i > 0; i--) {
        if (abs(vec[i]) > abs(vec[j]) && abs(vec[i]) < abs(vec[j + 1])) {
            std::swap(vec[i], vec[j]);
            std::cout << vec[i] << " " << vec[j] << " ";
            j++;
        } else {
            std::cout << vec[j] << " " << vec[j + 1] << " ";
            std::cout << vec[i] << " " << vec[i - 1] << " ";
        }
    }
}