#include <iostream>

#define DAY_1 "Monday"
#define DAY_2 "Tuesday"
#define DAY_3 "Wednesday"
#define DAY_4 "Thursday"
#define DAY_5 "Friday"
#define DAY_6 "Saturday"
#define DAY_7 "Sunday"

#define DAY(number) std::cout << DAY ## _ ## number << std::endl

#define CHECKING(number) while (number < 0 || number > 7) {\
                            std::cerr << "Incorrect input, input again: ";\
                            std::cin >> number;\
                        }

int main() {
    std::cout << "\t\t****************************************\n"
              << "\t\t*      Implementation of advanced      *\n"
              << "\t\t* input and output of days of the week *\n"
              << "\t\t****************************************\n";

    std::cout << "Exit - input \"0\"\n";

    int day_number = 1;
    
    while (day_number != 0) {
        std::cout << "Input the day of the week number: ";
        std::cin >> day_number;

        CHECKING(day_number);

        if (day_number == 1) DAY(1);
        else if (day_number == 2) DAY(2);
        else if (day_number == 3) DAY(3);
        else if (day_number == 4) DAY(4);
        else if (day_number == 5) DAY(5);
        else if (day_number == 6) DAY(6);
        else if (day_number == 7) DAY(7);
    }
}