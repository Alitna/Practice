#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

const std::string FILE_NAME = "ATM_Machine.bin";
const int MAX_BANKNOTES = 1000;

void current_ATM_status(int banknotes[]) {
    long long sum = 0;

    int count_100 = 0,  count_200 = 0,  count_500 = 0;
    int count_1000 = 0, count_2000 = 0, count_5000 = 0;
    
    for (int i = 0; i < MAX_BANKNOTES; ++i) {
        sum += banknotes[i];
    }
       
    for (int i = 0; i < MAX_BANKNOTES; ++i) {
        if (banknotes[i] == 100) count_100++;
        else if (banknotes[i] == 200) count_200++;
        else if (banknotes[i] == 500) count_500++;
        else if (banknotes[i] == 1000) count_1000++;
        else if (banknotes[i] == 2000) count_2000++;
        else if (banknotes[i] == 5000) count_5000++;
    }

    std::cout << "Current ATM status: " << std::endl;
    std::cout << "100  banknotes now: " << count_100 << std::endl;
    std::cout << "200  banknotes now: " << count_200 << std::endl;
    std::cout << "500  banknotes now: " << count_500 << std::endl;
    std::cout << "1000 banknotes now: " << count_1000 << std::endl;
    std::cout << "2000 banknotes now: " << count_2000 << std::endl;
    std::cout << "5000 banknotes now: " << count_5000 << std::endl;
    std::cout << "Total amount: \t" << sum << std::endl << std::endl;
}

void ATM_replenishment(int banknotes[]) {
    int countBanknotes = 0;
    
    for (int i = 0; i < MAX_BANKNOTES; ++i) {
        if (banknotes[i] == 100  || banknotes[i] == 200 ||
            banknotes[i] == 500  || banknotes[i] == 1000 ||
            banknotes[i] == 2000 || banknotes[i] == 5000)
                countBanknotes++;
    }

    if (countBanknotes == 1000) std::cout << "ATM is full." << std::endl;
    else {
        std::srand(std::time(nullptr));

        for (int i = 0; i < MAX_BANKNOTES; ++i) {
            if (banknotes[i] == 0) {

                int banknote = 0;
                while (true) {
                    banknote = rand() % 4901 + 100;
                    if (banknote == 100  || banknote == 200  || banknote == 500 ||
                        banknote == 1000 || banknote == 2000 || banknote == 5000) {
                            banknotes[i] = banknote;
                            break;
                    }
                }
            }
        }
    }

    std::ofstream ATM(FILE_NAME, std::ios::binary);
    if(!ATM) {
        std::cerr << "File opening error." << std::endl;
        return;
    }
    ATM.write(reinterpret_cast<char*>(banknotes), sizeof(int) * MAX_BANKNOTES);
    ATM.close();

    current_ATM_status(banknotes);
}


void remove_from_array(int &count, int &nominal, int banknotes[]) {
    for (int i = 0; i < MAX_BANKNOTES; i++) {
        if (banknotes[i] == nominal) {
            banknotes[i] = 0;
            count--;
        }
        if (count == 0) break;
    }
}

void withdrawing_money(int amount, int banknotes[]) {
    while (amount <= 0 || amount % 100 != 0) {
        std::cerr << "Invalid amount. Must be a multiple of 100.\n"
                  << "Input again: ";
        std::cin >> amount;        
        return;
    }

    long long sum = 0;

    int count_100  = 0,  count_200 = 0,  count_500 = 0;
    int count_1000 = 0, count_2000 = 0, count_5000 = 0;

    int nominal_5000 = 5000, nominal_2000 = 2000, nominal_1000 = 1000;
    int nominal_500  = 500,  nominal_200  = 200,  nominal_100  = 100;

    for (int i = 0; i < MAX_BANKNOTES; i++) {
        if      (banknotes[i] == 100) count_100++;
        else if (banknotes[i] == 200) count_200++;
        else if (banknotes[i] == 500) count_500++;      
        else if (banknotes[i] == 1000) count_1000++;    
        else if (banknotes[i] == 2000) count_2000++;    
        else if (banknotes[i] == 5000) count_5000++;
        sum += banknotes[i];
    }

    if (sum == 0) std::cout << "No money in the ATM." << std::endl;
    
    while (amount > sum) {
        std::cerr << "There is not enough money in the ATM.\n"
                  << "Input again: ";
        std::cin >> amount;
    }

    if (amount >= 5000) {
        int countBills_5000 = amount / 5000;
        if (countBills_5000 <= count_5000) { 
            remove_from_array(countBills_5000, nominal_5000, banknotes);
            amount %= 5000;
        } else {
            amount -= count_5000 * nominal_5000;
            remove_from_array(count_5000, nominal_5000, banknotes);
        }
    }
    
    if (amount >= 2000) {
        int countBills_2000 = amount / 2000; 
        if (countBills_2000 <= count_2000) { 
            remove_from_array(countBills_2000, nominal_2000, banknotes);
            amount %= 2000;
        } else {
            amount -= count_2000 * nominal_2000; 
            remove_from_array(count_2000, nominal_2000, banknotes); 
        }
    }

    if (amount >= 1000) {
        int countBills_1000 = amount / 1000; 
        if (countBills_1000 <= count_1000) { 
            remove_from_array(countBills_1000, nominal_1000, banknotes);
            amount %= 1000;
        }  else {
            amount -= count_1000 * nominal_1000;
            remove_from_array(count_1000, nominal_1000, banknotes);
        }
    }

    if (amount >= 500) {
        int countBills_500 = amount / 500; 
        if (countBills_500 <= count_500) {  
            remove_from_array(countBills_500, nominal_500, banknotes);
            amount %= 500;
        }  else {
            amount -= count_500 * nominal_500; 
            remove_from_array(count_500, nominal_500, banknotes);
        }
    }

    if (amount >= 200) {
        int countBills_200 = amount / 200;
        if (countBills_200 <= count_200) { 
            remove_from_array(countBills_200, nominal_200, banknotes);
            amount %= 200;
        }  else {
            amount -= count_200 * nominal_200;
            remove_from_array(count_200, nominal_200, banknotes);
        }
    }
   
    if (amount >= 100) {
        int countBills_100 = amount / 100; 
        if (countBills_100 <= count_100) { 
            remove_from_array(countBills_100, nominal_100, banknotes);
            amount %= 100;
        } else {
          amount -= count_100 * nominal_100;
          remove_from_array(count_100, nominal_100, banknotes);
        }
    }

    if (amount > 0)
        std::cout << "The amount cannot be issued due to the lack of the necessary bills.\n";
    else {

        std::ofstream ATM(FILE_NAME, std::ios::binary);
        if(!ATM) {
            std::cerr << "File opening error." << std::endl;
            return;
        }
        ATM.write(reinterpret_cast<char*>(banknotes), sizeof(int) * MAX_BANKNOTES);
        ATM.close();

        current_ATM_status(banknotes);
    }
}

int main() {
    std::cout << "\t\t******************************\n"
              << "\t\t*   This program simulates   *\n"
              << "\t\t* the operation of an ATM in *\n"
              << "\t\t*      a simplified way      *\n"
              << "\t\t******************************\n";

    
    std::ifstream in_ATM(FILE_NAME, std::ios::binary);
    int banknotes[MAX_BANKNOTES];
     
    for (int i = 0; i < MAX_BANKNOTES; ++i)
            banknotes[i] = 0;

    if (in_ATM.is_open()) {
        in_ATM.read(reinterpret_cast<char*>(banknotes), sizeof(banknotes));

        current_ATM_status(banknotes);
    
    } else {
        std::ofstream ATM(FILE_NAME, std::ios::binary);
        std::cout << "It is necessary to top up the ATM" << std::endl;

        for (int i = 0; i < MAX_BANKNOTES; ++i)
            banknotes[i] = 0;

        ATM.write(reinterpret_cast<char*>(banknotes), sizeof(int) * MAX_BANKNOTES);
        ATM.close();
    }
    in_ATM.close();

    char operation;
    do {
        std::cout << "Input operation: ";
        std::cin >> operation;

        if (operation == '+') {
            ATM_replenishment(banknotes);
        } else if (operation == '-') {
            long long amount = 0;
            std::cout << "Input the amount you want to withdraw: ";
            std::cin >> amount;
            withdrawing_money(amount, banknotes);
        }
    } while (operation != '0');

    std::ofstream ATM(FILE_NAME, std::ios::binary);
    if(!ATM) {
        std::cerr << "File opening error." << std::endl;
    }
    ATM.write(reinterpret_cast<char*>(banknotes), sizeof(int) * MAX_BANKNOTES);
    ATM.close();

    std::cout << "ATM state saved. Goodbye!\n";
    return 0;
}
