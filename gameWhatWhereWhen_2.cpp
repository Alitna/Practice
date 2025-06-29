#include <iostream>
#include <fstream>
#include <string>

int find_active_sector(bool sectors[], int currentSector) {
    if (!sectors[currentSector - 1]) {
        currentSector++;
        if (currentSector > 13) currentSector = 1;
        currentSector = find_active_sector(sectors, currentSector);
    }
    return currentSector;
}

int rotate_snipping_top(int currentSector, int offset, bool sectors[]) {
    for (; offset >= 13; offset %= 13) {}
    currentSector += offset;
    if (currentSector > 13) currentSector %= 13;
    //if (currentSector == 0) currentSector = 13; //Если номер сектора становится 0, то это последний сектор
    currentSector = find_active_sector(sectors, currentSector);
    return currentSector;
}

void question(int currentSector) {
    std::string textQuestion;
    std::ifstream questionText;
    questionText.open("Questions.txt");
    if (questionText.is_open()) {
        while (!questionText.eof()) {
            std::cout << "Question " << currentSector << " of the sector: ";
            int i = 1;
            while (getline(questionText, textQuestion)) {
                if (i == currentSector)
                    std::cout << textQuestion << std::endl;
                i++;
            }
        }
    } else std::cerr << "File opening error!" << std::endl;
    questionText.close();
}

bool answer(const std::string& connoisseurAnswer, int currentSector) {
    std::string textAnswer;
    std::ifstream answerText;
    answerText.open("Answers.txt");
    if (answerText.is_open()) {
        while (!answerText.eof()) {
            int i = 1;
             while (getline(answerText, textAnswer)) {
                if (i == currentSector) {
                    std::cout << "Right answer: " << textAnswer << std::endl;
                    return connoisseurAnswer == textAnswer ? true : false;
                }
                i++;
            }
        }
    } else std::cerr << "File opening error!" << std::endl;
    answerText.close();
}

int main() {
    std::cout << "\t\t***********************************\n"
              << "\t\t* This program simulates the game *\n"
              << "\t\t*      \"What? Where? When?\"       *\n"
              << "\t\t***********************************\n";

    bool sectors[13];
    for (int i = 0; i < 13; i++)
        sectors[i] = true;

    int currentSector = 1;
    int offset = 0;

    int connoisseurPoints = 0;
    int viewersPoints = 0;

    std::cout << "Current sector > " << currentSector << std::endl;

    while (connoisseurPoints < 6) {    
        std::cout << "Spin the spinning top: ";
        std::cin >> offset;

        currentSector = rotate_snipping_top(currentSector, offset, sectors);
        std::cout << std::endl << "Current sector > " << currentSector << std::endl;

        question(currentSector);

        std::string connoisseurAnswer;
        std::cout << "Your answer: ";
        std::cin >> connoisseurAnswer;
        std::cout << std::endl;

        answer(connoisseurAnswer, currentSector) ? connoisseurPoints++ : viewersPoints++;
        
        std::cout << "\nConnoisseur " << connoisseurPoints << " points." << std::endl;
        std::cout << "Viewers " << viewersPoints << " points." << std::endl;

        if (viewersPoints >= 6) break;

        sectors[currentSector - 1] = false;  
    
    }
    connoisseurPoints == 6 ? std::cout << "Connoisseur won! \nThe connoisseur gets a crystal owl!" << std::endl
    : std::cout << "Viewers won! \nThe viewers gets a crystal owl!" << std::endl;
}