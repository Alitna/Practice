#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdlib>

const std::string FILE_NAME = "statement.bin";

struct person
{
    std::string name = "unknown";
    std::string surname = "unknown";
    std::string date = "unknown";
    int money = 0;
};

bool checking_string(const std::string &str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z') {
            std::cerr << "Incorrect data ";
            return false;
        }
    return true;
}

bool leap_year(int &year) {
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return true;
        }
    } else if (year % 4 == 0) {
        return true;
    }
    
    return false;
}

bool checking_data(const std::string &str) {
    int day = std::stoi(str.substr(0,2));
    int month = std::stoi(str.substr(3,2));
    int year = std::stoi(str.substr(6,4));

    if (day < 0   || day > 31   ||
        month < 0 || month > 12 ||
        year < 0  || year  > 2025) {
            std::cerr << "Incorrect data ";
            return false;
        }
    
    if (month == 2) {
        if (!leap_year(year)) {
            if (day > 28) {
                std::cerr << "Incorrect data ";
                return false;
            }
        } else {
            if (day > 29) {
                std::cerr << "Incorrect data ";
                return false;
            }
        }
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
        if (day > 30) {
            std::cerr << "Incorrect data ";
            return false;
        }

    return true;
}

bool checking_money(int &money) {
    char bufferMoney[10];
    sprintf(bufferMoney, "%d", money);
    for (int i = 0; i < strlen(bufferMoney); i++)
        if (bufferMoney[i] < '0' || bufferMoney[i] > '9')
            return false;
    return true;
}

void load_person(std::ifstream& file, person& human) {
    int lenName = human.name.length();
    file.read(reinterpret_cast<char*>(&lenName), sizeof(lenName));
    human.name.resize(lenName);
    //file.read(reinterpret_cast<char*>(human.name.c_str()), lenName);
    file.read((char*)human.name.c_str(), lenName);

    int lenSurname = human.surname.length();
    file.read(reinterpret_cast<char*>(&lenSurname), sizeof(lenSurname));
    human.surname.resize(lenSurname);
    file.read((char*)human.surname.c_str(), lenSurname);
    
    int lenDate = human.date.length();
    file.read(reinterpret_cast<char*>(&lenDate), sizeof(lenDate));
    human.date.resize(lenDate);
    file.read((char*)human.date.c_str(), lenDate);

    file.read(reinterpret_cast<char*>(&human.money), sizeof(human.money));
}

void save_person(std::ofstream& file, person& human) {
    int lenName = human.name.length();
    file.write(reinterpret_cast<char*>(&lenName), sizeof(lenName));
    //file.write((char*)&lenName, sizeof(lenName));
    file.write(human.name.c_str(), lenName);

    int lenSurname = human.surname.length();
    file.write(reinterpret_cast<char*>(&lenSurname), sizeof(lenSurname));
    file.write(human.surname.c_str(), lenSurname);

    int lenDate = human.date.length();
    file.write(reinterpret_cast<char*>(&lenDate), sizeof(lenDate));
    file.write(human.date.c_str(), lenDate);

    file.write(reinterpret_cast<char*>(&human.money), sizeof(human.money));
}

int main() {
    std::cout << "\t\t************************\n"
              << "\t\t* Accounting statement *\n"
              << "\t\t************************\n";

    std::cout << "Read  - command \"list\".\n";
    std::cout << "Write - command \"add\".\n";
    std::cout << "Exit  - command \"end\".\n";

    std::string command = "unknown";

    std::vector<person> people;

    while (command != "end") {
        
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "list") {
            std::ifstream in_file(FILE_NAME, std::ios::binary);
            if (in_file.is_open()) {
                std::vector<person> people_read;
                int i = 0;
                while (!in_file.eof()) {
                    people_read.emplace_back(person());
                    load_person(in_file, people_read[i]);
                    i++;
                }

                for (int i = 0; i < people_read.size() - 1; ++i)
                    std::cout << people_read[i].name << " " << people_read[i].surname << " " << people_read[i].date << " " << people_read[i].money << std::endl;
                
            } else std::cout << "The statement is empty." << std::endl;
            in_file.close();
        
        } else if (command == "add") {
            std::ofstream file(FILE_NAME, std::ios::binary | std::ios::app);
            if (file.is_open()) {
                int i = 0;
                while (true) {
                    std::string name = "unknown";

                    std::cout << "Input name, surname, date, money: " << std::endl;
                    std::cin >> name;

                    if (name == "end") break;

                    people.emplace_back(person());

                    people[i].name = name;

                    std::cin >> people[i].surname >> people[i].date >> people[i].money;

                    while (!checking_string(people[i].name)) {
                        std::cout << "name. Input again:" << std::endl;
                        std::cin >> people[i].name >> people[i].surname >> people[i].date >> people[i].money;
                    }

                    while (!checking_string(people[i].surname)) {
                        std::cout << "surname. Input again:" << std::endl;
                        std::cin >> people[i].name >> people[i].surname >> people[i].date >> people[i].money;
                    }

                    while (!checking_data(people[i].date)) {
                        std::cout << "date. Input again:" << std::endl;
                        std::cin >> people[i].name >> people[i].surname >> people[i].date >> people[i].money;
                    }

                    while (!checking_money(people[i].money)) {
                        std::cout << "money. Input again:" << std::endl;
                        std::cin >> people[i].name >> people[i].surname >> people[i].date >> people[i].money;
                    }

                    save_person(file, people[i]);
                    
                    i++;
                }
                std::cout << "You have completed the writing.\n";

            } else std::cerr << "File opening error!" << std::endl; 
            file.close();
        }
    }
    std::cout << "You have completed the program.\n";
}