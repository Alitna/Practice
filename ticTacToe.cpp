#include<iostream>

int main(){
    std::cout << "\t\t***********************\n"
              << "\t\t*    This program     *\n"
              << "\t\t* simulates a game of *\n"
              << "\t\t*    tic tac toe      *\n"
              << "\t\t***********************\n";

    char playingField[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool freeCells[3][3] = {{false, false, false}, {false, false, false}, {false, false, false}};

    bool playerWon_1 = false;
    bool playerWon_2 = false;

    int l, m;

    std::cout << "Player number 1 input coordinates for X: ";
    std::cin >> l >> m;
    while (l < 0 || l > 2 || m < 0 || m > 2 || freeCells[l][m] == true /*(клетка занята)*/) {
        std::cout << "Incorrect input. Please input again: ";
        std::cin >> l >> m;
    }
    freeCells[l][m] -= 1;
    playingField[l][m] = 'X';

    /*вывод игрового поля*/
    std::cout << "  ___________" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << " | ";
        for (int j = 0; j < 3; j++) 
            std::cout << playingField[i][j] << " | ";
        std::cout << std::endl;
    }
    std::cout << "  -----------" << std::endl;
    
    for (int k = 0; k <= 3; ++k) {
        std::cout << "Player number 2 input coordinates for O: ";
        std::cin >> l >> m;
        while (l < 0 || l > 2 || m < 0 || m > 2 || freeCells[l][m] == true /*(клетка занята)*/) {
            std::cout << "Incorrect input. Please input again: ";
            std::cin >> l >> m;
        }
        freeCells[l][m] -= 1;
        playingField[l][m] = 'O';

        /*вывод игрового поля*/
        std::cout << "  ___________" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << " | ";
            for (int j = 0; j < 3; j++)
                std::cout << playingField[i][j] << " | ";
            std::cout << std::endl;
        }
        std::cout << "  -----------" << std::endl;

        /*Проверка на победу*/
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (playingField[i][j] == 'O' && playingField[i][j + 1] == 'O' && playingField[i][j + 2] == 'O' ||
                    playingField[i][j] == 'O' && playingField[i + 1][j] == 'O' && playingField[i + 2][j] == 'O')
                    playerWon_2 = true;

        if (playerWon_2) {
            std::cout << "Player number 2 won!";
            break;
        }

        std::cout << "Player number 1 input coordinates for X: ";
        std::cin >> l >> m;
        while (l < 0 || l > 2 || m < 0 || m > 2 || freeCells[l][m] == true /*(клетка занята)*/) {
            std::cout << "Incorrect input. Please input again: ";
            std::cin >> l >> m;
        }
        freeCells[l][m] -= 1;
        playingField[l][m] = 'X';

        /*вывод игрового поля*/
        std::cout << "  ___________" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << " | ";
            for (int j = 0; j < 3; j++)
                std::cout << playingField[i][j] << " | ";
            std::cout << std::endl;
        }
        std::cout << "  -----------" << std::endl;

        /*Проверка на победу*/
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (playingField[i][j] == 'X' && playingField[i][j + 1] == 'X' && playingField[i][j + 2] == 'X' ||
                    playingField[i][j] == 'X' && playingField[i + 1][j] == 'X' && playingField[i + 2][j] == 'X')
                    playerWon_1 = true;
            
        if (playerWon_1) {
            std::cout << "Player number 1 won!";
            break;
        }
    }
    
    if (!playerWon_1 && !playerWon_2)
        std::cout << "Draw";/*(ничья)*/
}