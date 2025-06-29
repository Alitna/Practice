#include <iostream>
#include <map>
#include <string>

int count(const std::string & text) {
    int count = 0;
    if (text.length() > 0 && text[0] != ' ')
        count++;
    for (int i = 1; i < text.length(); ++i)
        if(text[i - 1] == ' ' && text[i] != ' ')
            count++;
    return count;
}

std::string word_num(const std::string & text) {
    std::string word;
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == ' ')
            break;
        word += text[i];
    }
    return word;
}

std::string word_sur(const std::string & number, const std::string & text) {
    std::string word;
    for (int i = number.length() + 1; i < text.length(); ++i)
        word += text[i];
    return word;
}

int main() {
    std::cout << "\t\t*******************\n"
              << "\t\t* Phone Directory *\n"
              << "\t\t*******************\n";

    std::cout << "Exit - input \"end\"\n";

    std::map<std::string, std::string> phoneDirectory;

    std::string request;

    while (true) {
        std::cout << "Input request: ";
        std::getline(std::cin, request);

        if (request == "end") break;

        int countWord = count(request);

        if (countWord == 2) {
            std::string number = word_num(request);
            //----------------------Checking--------------------------------------
            while (number.length() != 8 || number[2] != '-' || number[5] != '-' ||
                   number[0] < '0' || number[0] > '9' ||
                   number[1] < '0' || number[1] > '9' ||
                   number[3] < '0' || number[3] > '9' ||
                   number[4] < '0' || number[4] > '9' ||
                   number[6] < '0' || number[6] > '9' ||
                   number[7] < '0' || number[7] > '9') {
                    std::cout << "Incorrect number input\nInput again: ";
                    std::getline(std::cin, request);
                    number = word_num(request);
            }
            //--------------------------------------------------------------------

            std::string surname = word_sur(number, request);
            //----------------------Checking------------------------------------------
            int i = 0;
            while (i < surname.length()) {
                if (surname[i] < 'A' || (surname[i] > 'Z' && surname[i] < 'a') ||
                    surname[i] > 'z') {
                        std::cout << "Incorrect surname input\nInput surname again: ";
                        std::getline(std::cin, request);
                        surname = word_sur(number, request);
                }
                i++;
            }
            //------------------------------------------------------------------------

            std::pair<std::string, std::string> oPair(number, surname);
            phoneDirectory.insert(oPair);

        } else {
            if (request[0] >= '0' && request[0] <= '9') {
                //----------Checking-----------------------
                while (request.length() > 8) {
                    std::cout << "Incorrect number input\nInput number again: ";
                    std::getline(std::cin, request);
                }
                //-----------------------------------------
            
                //----------------------Checking--------------------------------------
                while (request.length() != 8 || request[2] != '-' || request[5] != '-' ||
                       request[0] < '0' || request[0] > '9' ||
                       request[1] < '0' || request[1] > '9' ||
                       request[3] < '0' || request[3] > '9' ||
                       request[4] < '0' || request[4] > '9' ||
                       request[6] < '0' || request[6] > '9' ||
                       request[7] < '0' || request[7] > '9') {
                        std::cout << "Incorrect number input\nInput again: ";
                        std::getline(std::cin, request);
                }
                //--------------------------------------------------------------------

                if (phoneDirectory.find(request) != phoneDirectory.end())
                    std::cout << phoneDirectory[request] << std::endl;
                else std::cout << "This number is not in the phone directory\n";

            } else {
                //----------------------Checking------------------------------------------
                int i = 0;
                while (i < request.length()) {
                    if (request[i] < 'A' || (request[i] > 'Z' && request[i] < 'a') ||
                        request[i] > 'z') {
                            std::cout << "Incorrect surname input\nInput surname again: ";
                            std::getline(std::cin, request);
                    }
                    i++;
                }
                //------------------------------------------------------------------------

                bool coincidence = false;
                for (std::map<std::string, std::string>::iterator it = phoneDirectory.begin(); it != phoneDirectory.end(); ++it)
                    if (request == it -> second) {
                        coincidence = true;
                        std::cout << it -> first << std::endl;
                    }
                
                if (!coincidence)
                    std::cout << "There is no person with that surname in the phone directory\n";
            }
        }
    }
}