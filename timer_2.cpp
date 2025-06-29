#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

int main() {
    std::cout << "\t\t*******************************\n"
              << "\t\t*        Implementation       *\n"
              << "\t\t* of the vesual timer program *\n"
              << "\t\t*******************************\n";

    std::cout << "Input the number of minutes and seconds (MM:SS): ";
    
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
    std::cin >> std::get_time(&local, "%M:%S");

    std::cout << "The countdown:\n";
    while (true) {
        std::cout << std::put_time(&local, "%M:%S") << std::endl;
        if (local.tm_min == 0) {
            local.tm_sec--;
        } else {
            local.tm_sec--;
            if (local.tm_sec == 0) {
                std::cout << std::put_time(&local, "%M:%S") << std::endl;
                local.tm_min--;
                local.tm_sec = 59;
            }    
        }
        
        if (local.tm_sec == 0) {
            std::cout << std::put_time(&local, "%M:%S") << std::endl;
            break;
        }
        Sleep(1000);
    }
    std::cout << "DING! DING! DING!";
}