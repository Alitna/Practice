#include <iostream>

void evendigits(long long n, int& ans) {
    if (n > 0) {
        int remain = n % 10;
        if (remain == 0) ans++;
        else if (remain % 2 == 0) ans++;
        //int newNumber = n / 10;           //почему так не срабатывает? 
        evendigits(/*newNumber*/n/10, ans);
    }
}

int main() {
    std::cout << "\t\t***************************************\n"
              << "\t\t* The function in this program counts *\n"
              << "\t\t*     the number of even numbers      *\n"
              << "\t\t*   in the record of the number n     *\n"
              << "\t\t***************************************\n";

    int ans = 0;
    evendigits(9223372036854775806, ans);
    std::cout << ans << std::endl; 
}