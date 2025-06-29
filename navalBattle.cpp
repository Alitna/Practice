#include <iostream>

void filling(bool array[][10]) {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            array[i][j] = false;
}

void initialization(char array[][10]) {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            array[i][j] = ' ';
}

void arrangement_small_ships(int start_j, int start_k, bool field[][10]) {
    for (int j = 0; j < 1; ++j)
        for (int k = 0; k < 1; ++k)
            field[start_j][start_k] = true;
}

void arrangement_large_ships(int start_j, int start_k, int end_j, int end_k, bool field[][10]) {
    if (start_j == end_j) {
        if (start_k < end_k)
            for (int i = start_k; i <= end_k; ++i)
                field[start_j][i] = true;
        else
            for (int i = start_k; i >= end_k; --i)
                field[start_j][i] = true;
    } else {
        if (start_j > end_j)
            for (int i = start_j; i >= end_j; --i)
                field[i][start_k] = true;
        else
            for (int i = start_j; i <= end_j; ++i)
                field[i][start_k] = true;
    }
}

void shot(int i, int j, bool array[][10]) {
    if (array[i][j]) {
        array[i][j] = false;
        std::cout << "Hit" << std::endl;
    } else std::cout << "Away" << std::endl;
}

bool check(bool array[][10]) {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (array[i][j]) return false;
    return true;
}

void vizualization(bool array_1[][10], char array_2[][10]) {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            array_1[i][j] ? array_2[i][j] = '*' : array_2[i][j] = ' ';
}

void arrange_ship(int size, bool field[][10]) {
    int start_j, start_k, end_j, end_k;
    std::cout << "Input the coordinates of the start and end of the ship with size " << size << ":\n";
    std::cout << " - the beginning of the ship: ";
    std::cin >> start_j >> start_k;
    while (start_j < 0 || start_j > 9 || start_k < 0 || start_k > 9 ||
           field[start_j][start_k]) {
        std::cout << "Incorrect coordinates \nPlease input again: ";
        std::cin >> start_j >> start_k;
    }
    if (size > 1) {
        std::cout << " - the end of the ship: ";
        std::cin >> end_j >> end_k;
        while (end_j < 0 || end_j > 9 || end_k < 0 || end_k > 9 || field[end_j][end_k] ||
               !(abs(end_j - start_j) == size - 1 && end_k == start_k ||
               abs(end_k - start_k) == size - 1 && end_j == start_j)) {
            std::cout << "Incorrect coordinates \nPlease input again: ";
            std::cin >> end_j >> end_k;
        }
        arrangement_large_ships(start_j, start_k, end_j, end_k, field);
    } else {
        arrangement_small_ships(start_j, start_k, field);
    }
}

void print_field(const char field[][10], const std::string& title) {
    std::cout << title << std::endl;
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "  --------------------" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << i << "|";
        for (int j = 0; j < 10; ++j)
            std::cout << field[i][j] << " ";
        std::cout << "|" << std::endl;
    }
    std::cout << "  --------------------" << std::endl << std::endl;
}

int main() {
    std::cout << "\t\t**************************\n"
              << "\t\t* This program simulates *\n"
              << "\t\t*   a sea battle game    *\n"
              << "\t\t**************************\n";

    bool field_1[10][10];
    bool field_2[10][10];

    char field_3[10][10];
    char field_4[10][10];

    filling(field_1);
    filling(field_2);

    initialization(field_3);
    initialization(field_4);

    std::cout << "The ship must be positioned strictly vertically or horizontally\n" << std::endl;

    int start_j, start_k, end_j, end_k;
    int sizeShip;
    int numberShips_1 = 0, numberShips_2 = 0;

    std::cout << "Player 1 sets up the ships" << std::endl;
    while (numberShips_1 < 10) {
        std::cout << "\nInput the size of the ship you plan to place: ";
        std::cin >> sizeShip;
        while (sizeShip < 1 || sizeShip > 4) {
            std::cout << "The size of the ship can be 1, 2, 3 or 4.\nPlease input again: ";
            std::cin >> sizeShip;
        }
        if (sizeShip == 1) {
            for (int i = 0; i < 4; i++) {
                arrange_ship(sizeShip, field_1);
                numberShips_1++;
            }
        } else if (sizeShip == 2) {
            for (int i = 0; i < 3; i++) {
                arrange_ship(sizeShip, field_1);
                numberShips_1++;
            }
        } else if (sizeShip == 3) {
            for (int i = 0; i < 2; i++) {
                arrange_ship(sizeShip, field_1);
                numberShips_1++;
            }
        } else {
            for (int i = 0; i < 1; i++) {
                arrange_ship(sizeShip, field_1);
                numberShips_1++;
            }
        }
    }

    std::cout << "\nPlayer 2 sets up the ships" << std::endl;
    while (numberShips_2 < 10) {
        std::cout << "\nInput the size of the ship you plan to place: ";
        std::cin >> sizeShip;
        while (sizeShip < 1 || sizeShip > 4) {
            std::cout << "The size of the ship can be 1, 2, 3 or 4.\nPlease input again: ";
            std::cin >> sizeShip;
        }
        if (sizeShip == 1) {
            for (int i = 0; i < 4; i++) {
                arrange_ship(sizeShip, field_2);
                numberShips_2++;
            }
        } else if (sizeShip == 2) {
            for (int i = 0; i < 3; i++) {
                arrange_ship(sizeShip, field_2);
                numberShips_2++;
            }
        } else if (sizeShip == 3) {
            for (int i = 0; i < 2; i++) {
                arrange_ship(sizeShip, field_2);
                numberShips_2++;
            }
        } else {
            for (int i = 0; i < 1; i++) {
                arrange_ship(sizeShip, field_2);
                numberShips_2++;
            }
        }
    }

    std::cout << std::endl;

    // Вывод игровых полей
    vizualization(field_1, field_3);
    vizualization(field_2, field_4);

    print_field(field_3, "Ships of 1 player");
    print_field(field_4, "Ships of 2 player");

    std::cout << std::endl << "\t***Game start***" << std::endl << std::endl;

    bool victore = false;
    while (victore == false) {
        int shot_i, shot_j;
        std::cout << "Player 1 input coordinates of the shot: ";
        std::cin >> shot_i >> shot_j;
        while (shot_i < 0 || shot_i > 9 || shot_j < 0 || shot_j > 9) {
            std::cout << "Incorrect coordinates \nPlease input again: ";
            std::cin >> shot_i >> shot_j;
        }
        shot(shot_i, shot_j, field_2);
        vizualization(field_2, field_4);
        print_field(field_4, "Ships of 2 player");
        victore = check(field_2);
        if (victore) {
            std::cout << "Player 1 vin!" << std::endl;
            break;
        } else std::cout << "Game continues" << std::endl << std::endl;

        std::cout << "Player 2 input coordinates of the shot: ";
        std::cin >> shot_i >> shot_j;
        while (shot_i < 0 || shot_i > 9 || shot_j < 0 || shot_j > 9) {
            std::cout << "Incorrect coordinates \nPlease input again: ";
            std::cin >> shot_i >> shot_j;
        }
        shot(shot_i, shot_j, field_1);
        vizualization(field_1, field_3);
        print_field(field_3, "Ships of 1 player");
        victore = check(field_1);
        if (victore) {
            std::cout << "Player 1 vin!" << std::endl;
            break;
        } else std::cout << "Game continues" << std::endl << std::endl;
    }
}