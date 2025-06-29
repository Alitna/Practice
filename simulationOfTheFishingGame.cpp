#include <iostream>
#include <fstream>
#include <string>

void put_in_basket(const std::string& fish) {
    std::ofstream basket("basket.txt", std::ios::app);
    if (basket.is_open()) {
        basket << fish << std::endl;
    } else std::cerr << "File opening error!" << std::endl;
    basket.close();
}

int number_of_fish_caught(const std::string& fish) {
    std::ifstream river("river.txt");
    if (river.is_open()) {
        int count = 0;
        while (!river.eof()) {
            std::string typeFish;
            while (getline(river, typeFish))
                if (typeFish == fish) {
                    put_in_basket(typeFish);
                    count++;
                }
        }
        return count;
    } else std::cerr << "File opening error!" << std::endl;
    river.close();
}

int main() {
    std::cout << "\t\t**************************\n"
              << "\t\t* This program simulates *\n"
              << "\t\t*    a fishing game      *\n"
              << "\t\t**************************\n";

    std::string fish;

    while (fish != "end") {
        std::cout << "Input the type of fish: ";
        std::cin >> fish;
        std::cout << "You have caught " << number_of_fish_caught(fish) << " fish." << std::endl;
    }

    std::cout << "Are you done fishing.";
}