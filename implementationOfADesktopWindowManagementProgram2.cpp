#include <iostream>
#include <string>

void checkingVector(int& moveX, int& moveY) {
    std::cout << "Move the window by the x: ";
    std::cin >> moveX;
    std::cout << "Move the window by the y: ";
    std::cin >> moveY;
    while ((moveX <= -80 || moveX >= 80) || (moveY <=-50 || moveY >= 50)) {
        std::cerr << "The window offset cannot be larger than the screen size.\nInput again\n";
        std::cout << "Move the window by the x: ";
        std::cin >> moveX;
        std::cout << "Move the window by the y: ";
        std::cin >> moveY;
    }
}

void checkingResize (unsigned short& newWidth, unsigned short& newHeight) {
    std::cout << "Input the width: ";
    std::cin >> newWidth;
    std::cout << "Input the height: ";
    std::cin >> newHeight;
    while (newWidth >= 80 || newHeight >= 50) {
        std::cerr << "The window size cannot be larger than the screen size.\nInput again\n";
        std::cout << "Input the width: ";
        std::cin >> newWidth;
        std::cout << "Input the height: ";
        std::cin >> newHeight;
    }
}

class Point {
    unsigned short x = 0;
    unsigned short y = 0;
public:
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void setCoordinates(int& currentX, int& currentY) {
        x = currentX;
        y = currentY;
    }
};

class Window {
    Point upperLeftCorner;
    unsigned short width = 1;
    unsigned short height = 1;
public: 
    void checkingCoordinates(int& currentX, int& currentY) {
        while ((currentX < 0 || currentX > 79) || (currentY < 0 || currentY > 49)) {
            std::cerr << "The coordinates cannot go beyond the screen area.\nInput again\n";
            checkingVector(currentX, currentY);
        } 
    }
    void move(int& moveX, int& moveY) {
        int currentX = upperLeftCorner.getX();
        int currentY = upperLeftCorner.getY();
        currentX += moveX;
        currentY += moveY;
        checkingCoordinates(currentX, currentY);
        upperLeftCorner.setCoordinates(currentX, currentY);
        std::cout << "The new coordinates:\nX: " << upperLeftCorner.getX()
                  << "\nY: " << upperLeftCorner.getY() << std::endl; 
    }
    void resize(unsigned short& newWidth, unsigned short& newHeight) {
        width = newWidth;
        height = newHeight;
        std::cout << "The new width: " << width << std::endl
                  << "The new height: " << height << std::endl;
    }
    Point getUpperLeftCorner() {
        return upperLeftCorner;
    }
    unsigned short getWidth() {
        return width;
    }
    unsigned short getHeight() {
        return height;
    }
};

class Screen {
    bool screen[50][80];
    Window window;
public:
    void filling() {
        for (int i = 0; i < 50; ++i)
            for (int j = 0; j < 80; ++j)
                screen[i][j] = false;
    }
    void moveWindow(int& moveX, int& moveY) {
        window.move(moveX, moveY);
    }
    void resizeWindow(unsigned short& newWidth, unsigned short& newHeight) {
        window.resize(newWidth, newHeight);
    }
    void display() {
        filling();
        for (int i = window.getUpperLeftCorner().getY(); i < window.getUpperLeftCorner().getY() + window.getWidth(); ++i)
            for (int j = window.getUpperLeftCorner().getX(); j < window.getUpperLeftCorner().getX() + window.getHeight(); ++j)
                screen[i][j] = true;
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 80; ++j)
                std::cout << screen[i][j];
            std::cout << std::endl;
        }
    }
};

int main() {
    std::cout << "\t\t********************************************************\n"
              << "\t\t*   Implementation of a desktop window management      *\n"
              << "\t\t*                       program                        *\n"
              << "\t\t* ---------------------------------------------------- *\n"
              << "\t\t* Commands for controlling the desktop window:         *\n"
              << "\t\t* \"move\" - move the window;                            *\n"
              << "\t\t* \"resize\" - set the window size;                      *\n"
              << "\t\t* \"display\" - display the current monitor image;       *\n"
              << "\t\t* \"close\" - close the window, exit the programm.       *\n"
              << "\t\t******************************************************** \n";
    
    Screen* screen = new Screen();
    screen->filling();
    std::string command;
    while (command != "close") {
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "move") {
            int moveX = 0;
            int moveY = 0;
            checkingVector(moveX, moveY);
            screen->moveWindow(moveX, moveY);
        }
        else if (command == "resize") {
            unsigned short newWidth = 0;
            unsigned short newHeight = 0;
            checkingResize(newWidth, newHeight);
            screen->resizeWindow(newWidth, newHeight);
        } 
        else if (command == "display") screen->display();
        else if (command != "close")   std::cerr << "Invalid command name. Input again.\n";
    }
    std::cout << "Closing the window...\nExiting the programm...";
    delete screen;
    screen = nullptr;
}