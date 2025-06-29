#include <iostream>

void merge(float numbers[], int start, int end, int middle);

void mergeSort(float numbers[], int start, int end) {
    int middle;
    if (start < end) {
        middle = (start + end) / 2;
        mergeSort(numbers, start, middle);
        mergeSort(numbers, middle + 1, end);
        merge(numbers, start, end, middle);
    }
}

void merge(float numbers[], int start, int end, int middle) {
    float mergedNumbers[15];
    int i, j, k;
    i = start;
    k = start;
    j = middle + 1;

    while (i <= middle && j <= end) {
        if (numbers[i] > numbers[j]) {
            mergedNumbers[k] = numbers[i];
            k++;
            i++;
        } else {
            mergedNumbers[k] = numbers[j];
            k++;
            j++;
        }
    }

    while (i <= middle) {
        mergedNumbers[k] = numbers[i];
        k++;
        i++;
    }

    while (j <= end) {
        mergedNumbers[k] = numbers[j];
        k++;
        j++; 
    }

    for (i = start; i < k; i++) {
        numbers[i] = mergedNumbers[i];
    }
}

int main() {
    std::cout << "\t\t****************************\n"
              << "\t\t*       This program       *\n"
              << "\t\t* sorts fractional numbers *\n"
              << "\t\t*  from larger to smaller  *\n"
              << "\t\t****************************\n";

    float numbers[15];
    std::cout << "Input numbers: ";
    for (int i = 0; i < 15; i++)
        std::cin >> numbers[i];

    mergeSort(numbers, 0, 14);

    std::cout << "\nConclusion:    ";
    for (int i = 0; i < 15; i++)
        std::cout << numbers[i] << " ";
}