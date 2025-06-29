#include <iostream>

void filling(bool array[][12]) {
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            array[i][j] = true;
}

void show(bool array_1[][12], char array_2[][12]) {
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            array_1[i][j] ? array_2[i][j] = 'o' : array_2[i][j] = 'x';
}

void to_burst(bool array_1[][12], int i, int j, int k, int l) {
    if (i < k)
        for (int a = i; a <= k; a++) {
            if (j < l)
                for (int b = j; b <= l; b++)
                    array_1[a][b] = false;
            else
                for (int b = l; b <= j; b++)
                    array_1[a][b] = false;
        }
    else
        for (int a = k; a <= i; a++)
            if (j < l)
                for (int b = j; b <= l; b++)
                    array_1[a][b] = false;
            else 
                for (int b = l; b <= j; b++)
                    array_1[a][b] = false;
}

bool check(bool array[][12]) {
    bool end = true;
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            if (array[i][j])
                end = false;
    return end;
}

int count(bool array[][12]) {
    int count = 0;
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            if (!(array[i][j]))
                count++;
    return count;
}

int main() {
    std::cout << "\t\t**************************\n"
              << "\t\t* This program simulates *\n"
              << "\t\t* the digging of bubbles *\n"
              << "\t\t*  on a packaging film   *\n"
              << "\t\t**************************\n";
    
    bool pupyrka_b[12][12];
    filling(pupyrka_b);

    char pupyrka_ch[12][12];

    int i = 0, j = 0, k = 0, l = 0;
    bool end = false;
    while (end == false) {   
        show(pupyrka_b, pupyrka_ch);
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 12; ++j)
                std::cout << pupyrka_ch[i][j] << " ";
            std::cout << std::endl;
        }

        std::cout << "Input the begining of the region: ";
        std::cin >> i >> j;
        std::cout << "Input the end of the region: ";
        std::cin >> k >> l;

        while (i < 0 || i > 11 || j < 0 || j > 11 ||
               k < 0 || k > 11 || l < 0 || l > 11) {
                std::cout << "Error. Please input again\n";
                std::cout << "Input the begining of the region: ";
                std::cin >> i >> j;
                std::cout << "Input the end of the region: ";
                std::cin >> k >> l;
        }

        to_burst(pupyrka_b, i, j, k, l);

        for (int m = 0; m < count(pupyrka_b); m++)
            std::cout << "Pop!";
        std::cout << std::endl;

        show(pupyrka_b, pupyrka_ch);

        end = check(pupyrka_b);
        if (end) {
            for (int i = 0; i < 12; ++i) {
                for (int j = 0; j < 12; ++j)
                    std::cout << pupyrka_ch[i][j] << " ";
                std::cout << std::endl;
            }
            std::cout << "The bubbles are over" << std::endl;
            break;
        }
    }
}