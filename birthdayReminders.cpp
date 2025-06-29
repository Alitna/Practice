#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <string>

struct Friend {
    std::string name;
    std::time_t time;
    std::tm birthday;
};

int main() {
    std::cout << "\t\t********************\n"
              << "\t\t*   The birthday   *\n"
              << "\t\t* reminder program *\n"
              << "\t\t********************\n";

    std::cout << "Exit - input \"end\"\n";
    std::cout << "Input information about your friends' birthdays:\n";

    std::vector<Friend> vecFriends;
    Friend myFriend;

    while(true) {
        std::cout << "Friend's name: ";
        std::cin >> myFriend.name;
        if (myFriend.name == "end") break;
        std::cout << "Birthday (year/month/day): ";
        myFriend.time = std::time(nullptr);
        myFriend.birthday = *std::localtime(&myFriend.time);
        std::cin >> std::get_time(&myFriend.birthday, "%Y/%m/%d");

        vecFriends.emplace_back(myFriend);
    }

    std::time_t currentTime = std::time(nullptr);
    std::tm* local = std::localtime(&currentTime);

    std::cout << std::endl;
    std::vector<Friend> vecUpcomingBirthdays;
    for (int i = 0; i < vecFriends.size(); ++i) {
        if (1 + local -> tm_mon == 1 + vecFriends[i].birthday.tm_mon &&
            local -> tm_mday == vecFriends[i].birthday.tm_mday)
            std::cout << vecFriends[i].name << " is celebrating birthday today!\n";

        else if (1 + local -> tm_mon == 1 + vecFriends[i].birthday.tm_mon &&
                 local -> tm_mday < vecFriends[i].birthday.tm_mday)
            vecUpcomingBirthdays.emplace_back(vecFriends[i]);   

        else if (1 + local -> tm_mon < 1 + vecFriends[i].birthday.tm_mon)
            vecUpcomingBirthdays.emplace_back(vecFriends[i]); 
    }

    for (int i = 0; i < vecUpcomingBirthdays.size(); ++i) 
        for (int j = 0; j < vecUpcomingBirthdays.size(); ++j)
            if (1 + vecUpcomingBirthdays[i].birthday.tm_mon < 1 + vecUpcomingBirthdays[j].birthday.tm_mon)
                std::swap(vecUpcomingBirthdays[i], vecUpcomingBirthdays[j]);

    for (int i = 0; i < vecUpcomingBirthdays.size(); ++i)
        for (int j = 0; j < vecUpcomingBirthdays.size(); ++j)
            if (1 + vecUpcomingBirthdays[i].birthday.tm_mon == 1 + vecUpcomingBirthdays[j].birthday.tm_mon &&
                vecUpcomingBirthdays[i].birthday.tm_mday < vecUpcomingBirthdays[j].birthday.tm_mday)
                    std::swap(vecUpcomingBirthdays[i], vecUpcomingBirthdays[j]);    

    std::cout << "\nUpcoming bithdays:\n";
    for (int i = 0; i < vecUpcomingBirthdays.size(); ++i) {
        std::cout << std::put_time(&vecUpcomingBirthdays[i].birthday, "%B") << " ";
        std::cout << vecUpcomingBirthdays[i].birthday.tm_mday << " ";
        std::cout << vecUpcomingBirthdays[i].name << std::endl;
    }
}