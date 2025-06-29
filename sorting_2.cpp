#include <iostream>

void heapify(float numbers[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && numbers[left] < numbers[largest])
        largest = left;

    if (right < n && numbers[right] < numbers[largest])
        largest = right;

    if (largest != i) {
        std::swap(numbers[i], numbers[largest]);
        heapify(numbers, n, largest);
    }
}

void heapSort(float numbers[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(numbers, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(numbers[0], numbers[i]);
        heapify(numbers, i, 0);
    }
}

void printNumbers(float numbers[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << numbers[i] << " ";
        std::cout << std::endl;
}

int main() {
    std::cout << "\t\t****************************\n"
              << "\t\t*       This program       *\n"
              << "\t\t* sorts fractional numbers *\n"
              << "\t\t*  from larger to smaller  *\n"
              << "\t\t****************************\n";

    float numbers[15];
    std::cout << "Input numbers: ";
    for (int i = 0; i < 15; ++i)
        std::cin >> numbers[i];

    int n = sizeof(numbers) / sizeof(numbers[0]);

    heapSort(numbers, n);

    std::cout << "Sorted:    ";
    printNumbers(numbers, n);
}