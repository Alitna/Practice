#include <iostream>

int main() {
    std::cout << "\t\t***********************\n"
              << "\t\t*    This program     *\n"
              << "\t\t*  performs actions   *\n"
              << "\t\t* with array elements *\n"
              << "\t\t***********************\n";

    int tableware[2][6] = {{4, 3, 3, 3, 3, 3},
                           {4, 3, 3, 3, 3, 3}};

    int dishes[2][6] = {{3, 2, 2, 2, 2, 2},
                        {3, 2, 2, 2, 2, 2}};

    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};

    // Добавляем стул к пятому месту первого ряда:
    chairs[0][4]++;
    // Украли ложку с третьего метса во втором ряду:
    tableware[1][2]--;
    // VIP-персона поделилась ложкой:
    tableware[0][0]--;
    // Поделились ложкой с третьим местом во втором ряду:
    tableware[1][2]++;
    // Официант забрал тарелку у VIP-гостя:
    dishes[0][0]--;
    
    std::cout << "Tableware: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++)
            std::cout << tableware[i][j] << " ";
        std::cout << std::endl << "\t   ";
    }
    std::cout << std::endl;

    std::cout << "Dishes: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++)
            std::cout  << dishes[i][j] << " ";
        std::cout << std::endl << "\t";
    }
    std::cout << std::endl;

    std::cout << "Chairs: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++)
            std::cout  << chairs[i][j] << " ";
        std::cout << std::endl << "\t";
    }
}