#include<iostream>

bool comparison(int matrixA[][4], int matrixB[][4]) {
    bool compare = true;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (matrixA[i][j] != matrixB[i][j])
                compare = false;
    return compare;
}

void matrix_to_diagonal(int matrix[][4]) {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (i != j) 
                matrix[i][j] = 0;
}

int main() {
    std::cout << "\t\t**********************************\n"
              << "\t\t* This program compares matrices *\n"
              << "\t\t*     and brings the matrix      *\n"
              << "\t\t*       to a diagonal form       *\n"
              << "\t\t**********************************\n";

    int matrixA[4][4];
    int matrixB[4][4];

    std::cout << "Input the elements of the matrix: ";

    int num = 0;

    while (num <= 4) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                std::cin >> matrixA[i][j];
                std::cin >> matrixB[i][j];
            }
            num++;
        }

        bool compare = comparison(matrixA, matrixB);

        if (compare) {
            matrix_to_diagonal(matrixA);
            std::cout << std::endl;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j)
                    std::cout << matrixA[i][j] << " ";
                std::cout << std::endl;
            }
            std::cout << std::endl;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j)
                    std::cout << matrixB[i][j] << " ";
                std::cout << std::endl;
            }
        } else { 
            std::cout << "The matrices are not equal" << std::endl;
            break;
        }
    }
}