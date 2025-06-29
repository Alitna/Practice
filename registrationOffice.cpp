#include <iostream>
#include <map>
#include <string>

int main () {
    std::cout << "\t\t***********************\n"
              << "\t\t* Registration office *\n"
              << "\t\t***********************\n";

    std::cout << "Exit - input \"end\"\n";
    std::string request;
    std::map<std::string, std::string> queue;
    int i = 0;

    while (request != "end") {
        std::cout << "Input a request: ";
        std::cin >> request;

        //----------------------Checking------------------------------------------
        int j = 0;
        while (j < request.length()) {
                if (request[j] < 'A' || (request[j] > 'Z' && request[j] < 'a') ||
                    request[j] > 'z') {
                        std::cerr << "Incorrect surname input\nInput surname again: ";
                        std::cin >> request;
                }
                j++;
        }
        //------------------------------------------------------------------------
  
        std::string key = request;

        if (request != "Next") {
            if (queue.find(request) != queue.end()) {
                std::pair<std::string, std::string> oPair(key, request);
                queue.insert(oPair);
            } else {
                std::pair<std::string, std::string> oPair(key + std::to_string(i + 1), request);
                i++;
                queue.insert(oPair);
            }            
        } else {
            std::cout << queue.begin() -> second << std::endl;
            queue.erase(queue.begin() -> first);
        }

        if (queue.empty()) {
            std::cout << "The queue is over\n";
            break;
        }
    }
    if (request == "end")
        std::cout << "You have logged out of the program\n";
}