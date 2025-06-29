#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const std::string FILE_NAME = "ATM_Mach.bin";
const int MAX_BANKNOTES = 1000;
const std::vector<int> DENOMINATIONS = {100, 200, 500, 1000, 2000, 5000};

void update_ATM_status(const std::vector<int>& banknotes) {
    std::ofstream file(FILE_NAME, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(banknotes.data()), banknotes.size() * sizeof(int));
    file.close();
}

std::vector<int> load_ATM_state() {
    std::ifstream file(FILE_NAME, std::ios::binary);
    std::vector<int> banknotes(MAX_BANKNOTES, 0);
    if (file) {
        file.read(reinterpret_cast<char*>(banknotes.data()), MAX_BANKNOTES * sizeof(int));
        file.close();
    }
    return banknotes;
}

void current_ATM_status(const std::vector<int>& banknotes) {
    long long sum = 0;
    std::vector<int> count(6, 0);

    for (int note : banknotes) {
        auto it = std::find(DENOMINATIONS.begin(), DENOMINATIONS.end(), note);
        if (it != DENOMINATIONS.end()) {
            count[it - DENOMINATIONS.begin()]++;
            sum += note;
        }
    }

    std::cout << "Current ATM status:\n";
    for(size_t i = 0; i < DENOMINATIONS.size(); ++i) {
        std::cout << DENOMINATIONS[i] << " RUB: " << count[i] << " notes\n";
    }
    std::cout << "Total amount: " << sum << " RUB\n\n";
}

void ATM_replenishment(std::vector<int>& banknotes) {
    std::srand(std::time(nullptr));
    for (int& note : banknotes) {
        if (note == 0) {
            note = DENOMINATIONS[std::rand() % DENOMINATIONS.size()];
        }
    }
    update_ATM_status(banknotes);
    current_ATM_status(banknotes);
}

bool can_withdraw(int amount, const std::vector<int>& banknotes) {
    std::vector<int> temp = banknotes;
    for (int denom : DENOMINATIONS) {
        int count = std::count(temp.begin(), temp.end(), denom);
        while (amount >= denom && count > 0) {
            amount -= denom;
            count--;
        }
    }
    return amount == 0;
}

void withdrawing_money(int amount, std::vector<int>& banknotes) {
    if (amount <= 0 || amount % 100 != 0) {
        std::cerr << "Invalid amount. Must be a multiple of 100.\n";
        return;
    }
    
    if (!can_withdraw(amount, banknotes)) {
        std::cerr << "Cannot dispense the requested amount due to note avalability.\n";
        return;
    }

    for (int denom : {5000, 2000, 1000, 500, 200, 100}) {
        for (size_t i = 0; i < banknotes.size() && amount >= denom; ++i) {
            if (banknotes[i] == denom) {
                banknotes[i] = 0;
                amount -= denom;
            }
        }
    }
    update_ATM_status(banknotes);
    current_ATM_status(banknotes);
}

int main() {
    std::cout << "\t\t******************************\n"
              << "\t\t*   This program simulates   *\n"
              << "\t\t* the operation of an ATM in *\n"
              << "\t\t*      a simplified way      *\n"
              << "\t\t******************************\n";

    std::vector<int> banknotes = load_ATM_state();
    current_ATM_status(banknotes);

    char operation;
    do {
        std::cout << "Enter operation (+ to refill, - to withdraw, 0 to exit): ";
        std::cin >> operation;

        if (operation == '+') {
            ATM_replenishment(banknotes);
        } else if (operation == '-') {
            int amount;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            withdrawing_money(amount, banknotes);
        }
    }while (operation != '0');
    
    update_ATM_status(banknotes);
    std::cout << "ATM state saved. Goodbay!\n";
    return 0;
}