#include <iostream>
#include <vector>

int main() {
    std::cout << "\t\t**************************************************\n"
              << "\t\t*      This program displays the total cost      *\n"
              << "\t\t*  of purchases from the list of product prices  *\n"
              << "\t\t* and the shopping list (in the form of indexes) *\n"
              << "\t\t**************************************************\n";
    
    std::vector<float> price {2.5, 4.25, 3.0, 10.0};
    std::vector<int> items {1, 1, 0, 3};

    float sum = 0.00f;

    for (int i = 0; i < price.size(); i++)
        sum += price[items[i]]; 

    std::cout << "The total cost is equal to " << sum << std::endl;
}