#include <iostream>
#include <string>
#include <sstream>

enum switches {LIGHTS_INSIDE = 1,
               LIGHTS_OUTSIDE = 2,
               HEATERS = 4,
               WATER_PIPE_HEATING = 8,
               CONDITIONER = 16};

int main() {
    std::cout << "\t\t***************************************\n"
              << "\t\t* This program simulates a simplified *\n"
              << "\t\t*    model of a smart cottage home    *\n"
              << "\t\t***************************************\n";

    int day = 1;
    std::string time = "00:00";
    std::string statusMajorSensors;
    while (day < 3) {
        std::cout << "\nDay " << day << std::endl;

        int switches_state = 0;
        
        for (char j = '0'; j <= '2'; j++) {
            time[0] = j;
            for (char i = '0'; i <= '9'; i++) {
                time[1] = i;
                if (time == "24:00") break;

                std::cout << "\nTime " << time << std::endl;
                std::cout << "Temperature inside, temperature outside, movement, lights: " << std::endl;
                std::getline(std::cin, statusMajorSensors);
                std::stringstream temp_stream(statusMajorSensors);
                int temperatureInside;
                int temperatureOutside;
                std::string movement;
                std::string lights;
                temp_stream >> temperatureInside >> temperatureOutside >> movement >> lights;

                int colorTemperature = 5000;

                if (temperatureOutside < 0 && !(switches_state & WATER_PIPE_HEATING)) {
                    switches_state |= WATER_PIPE_HEATING;
                    std::cout << "Water pipe heating ON!" << std::endl;
                } else if (temperatureOutside > 5 && (switches_state & WATER_PIPE_HEATING)) {
                    switches_state &= ~WATER_PIPE_HEATING;
                    std::cout << "Water pipe heating OFF!" << std::endl;
                }

                if (((time[1] > '6' || time[0] > '1') || time[1] < '5') && movement == "yes"
                      && !(switches_state & LIGHTS_OUTSIDE)) {
                    switches_state |= LIGHTS_OUTSIDE;
                    std::cout << "Lights outside ON!" << std::endl;
                } else if (((time[1] < '6' || time[0] < '1') || time[1] > '5') && movement == "no"
                      && (switches_state & LIGHTS_OUTSIDE)) {
                    switches_state &= ~LIGHTS_OUTSIDE;
                    std::cout << "Lights outside OFF!" << std::endl;
                }

                if (temperatureInside < 22 && !(switches_state & HEATERS)) {
                    switches_state |= HEATERS;
                    std::cout << "Heaters ON!" << std::endl;
                } else if (temperatureInside >= 25 && (switches_state & HEATERS)) {
                    switches_state &= ~HEATERS;
                    std::cout << "Heaters OFF!" << std::endl;
                }

                if (temperatureInside >= 30 && !(switches_state & CONDITIONER)) {
                    switches_state |= CONDITIONER;
                    std::cout << "Conditioner ON!" << std::endl;
                } else if (temperatureInside <= 25 && (switches_state & CONDITIONER)) {
                    switches_state &= ~CONDITIONER;
                    std::cout << "Conditioner OFF!" << std::endl;
                }

                int timeInt = std::stoi(time);

                if (timeInt >= 0 && timeInt <= 16 && lights == "on")
                    colorTemperature = 5000;
                else if (timeInt == 17 && lights == "on")
                    colorTemperature = 4400;
                else if (timeInt == 18 && lights == "on")
                    colorTemperature = 3800;
                else if (timeInt == 19 && lights == "on")
                    colorTemperature = 3200;
                else if (timeInt >= 20 && lights == "on")
                    colorTemperature = 2700;
                
                std::cout << "Color temperature: " << colorTemperature << "K" << std::endl;
            }
        }
        day++;
    }
}