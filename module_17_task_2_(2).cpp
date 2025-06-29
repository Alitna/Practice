#include <iostream>

void revers_order(int* p_array) {
    for (int i = 0; i < 5; i++) {
        int t = *(p_array + i);
        *(p_array + i) = *(p_array + 9 - i);
        *(p_array + 9 - i) = t;
    }

    int j = 0;
    while (j < 10) {
        std::cout << *(p_array + j) << " ";
        j++;
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