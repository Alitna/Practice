#include <iostream>

void revers_order(int* p_array) {
    int i = 9;
    while (i >= 0) {
        std::cout << *(p_array + i) << " ";
        i--;
    }   
}

int main() {
    std::cout << "\t\t*****************************************************\n"
              << "\t\t*   The function in this program takes a pointer    *\n"
              << "\t\t* to the int type, which contains ten int variables *\n"
              << "\t\t*    and arranges the elements in reverse order     *\n"
              << "\t\t*****************************************************\n";

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    revers_order(array);
}