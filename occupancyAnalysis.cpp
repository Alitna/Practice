#include <iostream>
#include <vector>

#define FILL(array, begin, end) { for (int i = begin; i < end; ++i) { \
                                    std::cout << "Input the number of passengers in the " << i + 1 << " carriage: "; \
                                    std::cin >> array[i]; } }

#define OUTPUT(array, begin, end) { for (int i = begin; i < end; ++i) std::cout << array[i] << " "; }

#define ANALYSIS(func) { func(train); }

void number_people(const int (&array)[10]) {
    int countCrowdedWagons = 0;
    int countFilledWagons = 0;
    int countUnfilledWagons = 0;
    std::vector<int> crowdedWagons;
    std::vector<int> filledWagons;
    std::vector<int> unfilledWagons;
    for (int i = 0; i < 10; ++i) {
        if (array[i] > 20) {
            crowdedWagons.push_back(i + 1);
            countCrowdedWagons++;
        } else if (array[i] == 20) {
            filledWagons.push_back(i + 1);
            countFilledWagons++;
        } else {
            unfilledWagons.push_back(i + 1);
            countUnfilledWagons++;
        }
    }

    std::cout << "In the train:\n";
    std::cout << "\t" << countCrowdedWagons << " crowded wagons: ";
    OUTPUT(crowdedWagons, 0, crowdedWagons.size());
    std::cout << "\n\t" << countFilledWagons << " filled wagons: ";
    OUTPUT(filledWagons, 0, filledWagons.size());
    std::cout << "\n\t" << countUnfilledWagons << " unfilled wagons: ";
    OUTPUT(unfilledWagons, 0, unfilledWagons.size());
}

int main() {
    std::cout << "\t\t***********************\n"
              << "\t\t* Time of year output *\n"
              << "\t\t***********************\n";

    int train[10];
    FILL(train, 0, 10);
#if 0
    OUTPUT(train, 0, 10);
#endif
    ANALYSIS(number_people);
}