#include <iostream>
#include <cstring>

bool substring(const char* s1, const char* s2) {
    bool find = false;
    std::cout.setf(std::cout.boolalpha);
    int i = 0;
    while (*(s1 + i) != '\0') {
        int j = 0;
        while (*(s2 + j) != '\0') {
            if (*(s1 + i) == *(s2 + j) &&
                *(s1 + i + 1) == *(s2 + j + 1) &&
                *(s1 + i + 2) == *(s2 + j + 2)) {
                    find = true;
                }
            j++;
        }
        i++;
    }
    return find ? true : false;
}

int main() {
    std::cout << "\t\t*************************************\n"
              << "\t\t*   The function in this program    *\n"
              << "\t\t* returns true if the second string *\n"
              << "\t\t*  is a substring of the first one  *\n"
              << "\t\t*************************************\n";

    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    std::cout << substring(a, b) << " " << substring(a, c) << std::endl;
}