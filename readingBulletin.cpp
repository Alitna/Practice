#include <iostream>
#include <fstream>

int main () {
    std::cout << "\t\t********************************\n"
              << "\t\t*      This program reads      *\n"
              << "\t\t*     information from the     *\n"
              << "\t\t* payment accounting statement *\n"
              << "\t\t********************************\n";

    std::ifstream statement;
    statement.open("C:\\tutorial_skillbox\\statement.txt");

    std::string name, surname;
    int money;
    std::string date;
    std::string personMaxAmount;

    if (statement.is_open()) {
        int sum = 0;
        int maxAmount = 0;

        while (!statement.eof()) {
            statement >> name >> surname >> money >> date;
            sum += money;
            
            if (money > maxAmount) {
                maxAmount = money;
                personMaxAmount = name + " " + surname; 
            }
            
            std::cout << name << " " << surname << " " << money << " " << date << std::endl;
        }

        std::cout << "\nTotal amount of funds paid out: " << sum << std::endl;
        std::cout << "\nThe person with the maximum payout amount: " << personMaxAmount << std::endl;

    } else std::cerr << "File opening error!" << std::endl;

    statement.close();
}