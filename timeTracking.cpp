#include <iostream>
#include <ctime>
#include <string>
#include <vector>

const int SECONDS = 3600;
const int MINUTES = 60;

#define HOURS_MINUTES_SECONDS(numberSeconds) int hours = numberSeconds / SECONDS; \
                                             int minutes = (numberSeconds - (hours * SECONDS)) / MINUTES; \
                                             int seconds = numberSeconds - ((hours * SECONDS) + (minutes * SECONDS)); \
                                             std::cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";

#define CURRENT_TASK(vecTasks) if (vecTasks[vecTasks.size() - 1].condition) \
                                std::cout << "Current task: " << vecTasks[vecTasks.size() - 1].taskName << std::endl;

struct Task {
    bool condition = false;
    std::string taskName = "uncnown";
    std::time_t beginning;
    std::time_t end;
    double timeSpent = 0;
};

void create_task(Task& task) {
    std::cin.ignore();
    std::cout << "Input the task name: ";
    std::getline(std::cin, task.taskName);
    task.condition = true;
    task.beginning = std::time(nullptr);
}

void finish_task(Task& task) {
    task.end = std::time(nullptr);
    task.timeSpent = std::difftime(task.end, task.beginning);
    task.condition = false;
}

int main() {
    std::cout << "\t\t******************************\n"
              << "\t\t* Implementation of the time *\n"
              << "\t\t*     tracking program       *\n"
              << "\t\t******************************\n";

    std::cout << "Exit - input \"exit\"\n";

    std::string command;
    std::vector<Task> vecTasks;

    while (command != "exit") {
        std::cout << "Input command: ";
        std::cin >> command;

        Task task;
        if (command == "begin") {
            if (vecTasks.empty() || vecTasks[vecTasks.size() - 1].condition == false) {
                create_task(task);
                vecTasks.emplace_back(task);
            } else {
                finish_task(vecTasks[vecTasks.size() - 1]);
                create_task(task);
                vecTasks.emplace_back(task);
            }

        } else if (command == "end") {
            if (vecTasks[vecTasks.size() - 1].condition) 
                finish_task(vecTasks[vecTasks.size() - 1]);
            
        } else if (command == "status") {
            int size = 0;

            (vecTasks[vecTasks.size() - 1].condition) ? size = vecTasks.size() - 1 : size = vecTasks.size();

            std::cout << "Completed tasks:\n";
            for (int i = 0; i < size; ++i) {
                std::cout << "\t" << vecTasks[i].taskName << std::endl;
                #if 0
                std::cout << "\ttime spent: " << vecTasks[i].timeSpent << " seconds" << std::endl;
                #endif
                std::cout << "\ttime spent: ";
                HOURS_MINUTES_SECONDS(vecTasks[i].timeSpent);
            }

            CURRENT_TASK(vecTasks);

        } else if (command != "exit")
            std::cerr << "Invalid command. Input again.\n"; 
    }
    std::cout << "You have logged out of the prodram\n";
}