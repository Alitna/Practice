#include <iostream>
#include <climits>

bool compare(double value, double reference, double epsilon) {
    return (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main() {
    std::cout << "\t\t*****************************\n"
              << "\t\t*  This program implements  *\n"
              << "\t\t* a digital car speedometer *\n"
              << "\t\t*****************************\n";

    char speed_str[5] = "0";

    double speed_value = 0.0;
    double speedDelta = 0.00;

    do {
        std::cout << "Speed: " << speed_str << " km/h" << std::endl;

        std::cout << "Speed delta: ";
        std::cin >> speedDelta;

        if (speed_value < 150) {
            speed_value += speedDelta;
        } else {
            while (speed_value == 150) {
                std::cerr << "The maximum speed of the car is 150 km/h." << std::endl;
                std::cout << "Speed delta: ";
                std::cin >> speedDelta;
                if (speedDelta < 0) {
                    speed_value += speedDelta;
                    std::sprintf(speed_str, "%.1f", speed_value);
                } else continue;
            }
        }

        std::sprintf(speed_str, "%.1f", speed_value);

    } while (!compare(speed_value, 0.0, 0.01));

    std::cout << "The car stopped.";
}