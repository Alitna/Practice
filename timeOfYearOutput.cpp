#include <iostream>

#define SPRING "Spring"
#define SUMMER "Summer"
#define AUTUMN "Autumn"
#define WINTER "Winter"

//#if 0
int main() {
    std::cout << "\t\t***********************\n"
              << "\t\t* Time of year output *\n"
              << "\t\t***********************\n";

    std::string season;
#if 0
    season = SPRING;
    season = SUMMER;
    season = AUTUMN;
    season = WINTER;
#endif
    std::cout << season << std::endl;
#if 0
    std::cout << SPRING << std::endl;
    std::cout << SUMMER << std::endl;
    std::cout << AUTUMN << std::endl;
    std::cout << WINTER << std::endl;
#endif
}
//#endif