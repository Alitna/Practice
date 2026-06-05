#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cstdlib>

class Track {
    std::tm dateOfCreation{};
    int recordingDuration = 0;
public:
    std::string name;
    int dateCheck(int &setDate, int date) {
        while (setDate > date) {
            std::cout << "The time machine has not yet been invented.\nInput year again: ";
            std::cin >> setDate;
        }
        return setDate;
    }

    void setSimulatingLoadingTrack() {
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        int year = now->tm_year + 1900;
        int month = now->tm_mon +=1;
        int day = now->tm_mday;

        std::cout << "Uploading a track...\n";
        std::cout << "Name: ";
        std::cin >> name;

        std::cout << "Date of creation: \n";
        std::cout << "Year: ";
        std::cin >> dateOfCreation.tm_year;

        dateCheck(dateOfCreation.tm_year, year);
        
        std::cout << "Month: ";
        std::cin >> dateOfCreation.tm_mon;

        if (dateOfCreation.tm_year == year)
             dateCheck(dateOfCreation.tm_mon, month);

        std::cout << "Day: ";
        std::cin >> dateOfCreation.tm_mday;

        if (dateOfCreation.tm_mon == month)
             dateCheck(dateOfCreation.tm_mday, day);

        std::cout << "Hour: ";
        std::cin >> dateOfCreation.tm_hour;
        std::cout << "Minutes: ";
        std::cin >> dateOfCreation.tm_min;
        std::cout << "Second: ";
        std::cin >> dateOfCreation.tm_sec;
        std::mktime(&dateOfCreation);

        std::cout << "Recording duration in sec.: ";
        std::cin >> recordingDuration;

        dateOfCreation.tm_year -= 1900;
        dateOfCreation.tm_mon -= 1;
    }

    void showDateOfCreation() {
        std::cout << std::asctime(&dateOfCreation);
    }
    int getRecordingDuration() {
        return recordingDuration;
    }
};

class Player {
    bool boolPlay;
    bool boolPause;
    int currentTrack;
    std::vector<Track> trackList;
public:
    bool getBoolPlay() {
        return boolPlay;
    }
    void setBoolPlay() {
        boolPlay ? boolPlay = false : boolPlay = true;
    }
    bool getBoolPause() {
        return boolPause;
    }
    void setBoolPause() {
        boolPause ? boolPause = false : boolPause = true;
    }
    int getCurrentTrack() {
        return currentTrack;
    }
    void setCurrentTrack(int i) {
        currentTrack = i;
    }
    void uploadTrack() {
        Track track;
        track.setSimulatingLoadingTrack();
        trackList.emplace_back(track);
        std::cout << "Audio recording added.\n\n";
    }
    void showInfo(Track &track) {
        std::cout << track.name << std::endl;
        track.showDateOfCreation();               
        std::cout << "Recording duration " << track.getRecordingDuration() << " seconds"<< std::endl;
    }
    void play() {
        bool playOn = getBoolPlay();
        bool pauseOn = getBoolPause();
        if (!playOn) {
            std::cout << "Input the name of the audio recording: ";
            std::string nameAudio;
            std::cin >> nameAudio;
            bool coincidence = false;
            for (int i = 0; i < trackList.size(); i++) {
                if (nameAudio == trackList[i].name) {
                    showInfo(trackList[i]);
                    setBoolPlay();
                    coincidence = true;
                    setCurrentTrack(i);
                }
            }
            if (!coincidence)
                std::cout << "There is no such audio recording\n";
        } else if (pauseOn) {
            std::cout << "Continue playback:\n";
            showInfo(trackList[getCurrentTrack()]);
            setBoolPause();
        }
    }
    void pause() {
        bool playOn = getBoolPlay();
        bool pauseOn = getBoolPause();
        if (playOn && !pauseOn) {
            setBoolPause();
            std::cout << "Recording on pause ||\n";
        }
    }
    void stop() {
        bool playOn = getBoolPlay();
        bool pauseOn = getBoolPause();
        if (playOn) setBoolPlay();
        if (pauseOn) setBoolPause();
        std::cout << "Recording on stop\n";
    }
    void next() {
        stop();
        int countTracks = trackList.size();
        int nextTrack = std::rand() % countTracks;
        std::cout << "The next track in shuffle mode:\n";
        showInfo(trackList[nextTrack]);
        setBoolPlay();
        setBoolPause();
        setCurrentTrack(nextTrack);
    }
};

int main() {
    std::cout << "\t\t******************************************************\n"
              << "\t\t*               Imitation of an audio                *\n"
              << "\t\t*                       player                       *\n"
              << "\t\t* -------------------------------------------------- *\n"
              << "\t\t* Commands for working with the player:              *\n"
              << "\t\t* \"add\" - add an audio recording;                    *\n"
              << "\t\t* \"play\" - record playback;                          *\n"
              << "\t\t* \"pause\" - pauses thr recording;                    *\n"
              << "\t\t* \"next\" - moves on the next random entry;           *\n"
              << "\t\t* \"stop\" - stop playback of the current recording.   *\n"
              << "\t\t* To exit the programm, enter \"exit\"                 *\n"
              << "\t\t******************************************************\n";

    std::string command;

    Player* player = new Player();

    while (command != "exit") {
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "add")
            player->uploadTrack();
        else if (command == "play")
            player->play();
        else if (command == "pause")
            player->pause();
        else if (command == "next")
            player->next();
        else if (command == "stop")
            player->stop();
        else if (command != "exit")
            std::cout << "Invalid command name. Input again.\n";
    }
    std::cout << "Exiting the programm...";
    delete player;
    player = nullptr;
}
