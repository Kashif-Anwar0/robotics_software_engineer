// RSE Assignment#1 Task#2
// Author: Kashif Anwar 
#include <iostream>
#include <string>
#include <array>

class Robot {
public:
    std::string name;
    double speed;

    struct Physical {
        double weight;
        double sizeH;
        double sizeW;
        double sizeL;
        int numberOfSensors;

        Physical(double w, double h, double wdt, double l, int nos) 
            : weight(w), sizeH(h), sizeW(wdt), sizeL(l), numberOfSensors(nos) {}
    };

    struct Sensors {
        std::array<double, 3> temperatures;
        std::array<double, 3> distances;

        Sensors(std::array<double, 3> temps, std::array<double, 3> dists) 
            : temperatures(temps), distances(dists) {}

        void displaySensorData(int index) {
            std::cout << "Temperature: " << temperatures[index] << "°C" << std::endl;
            std::cout << "Distance: " << distances[index] << " cm" << std::endl;
        }
    };

    Physical physical;
    Sensors sensors;

    Robot(std::string n, double s, double w, double h, double wdt, double l, int nos, std::array<double, 3> temps, std::array<double, 3> dists) 
        : name(n), speed(s), physical(w, h, wdt, l, nos), sensors(temps, dists) {}

    void moveForward() {
        std::cout << name << " is moving forward at speed " << speed << " m/s." << std::endl;
    }

    void moveBackward() {
        std::cout << name << " is moving backward at speed " << speed << " m/s." << std::endl;
    }

    void stop() {
        std::cout << name << " has stopped." << std::endl;
    }

    void displaySensorData(int index) {
        sensors.displaySensorData(index);
    }
};

namespace Burger {
    Robot createRobot() {
        return Robot("Burger", 0.22, 1.2, 138, 178, 192, 3, {20.0, 21.5, 20.0}, {100.0, 95.0, 100.0});
    }
}

int main() {
    Robot robot = Burger::createRobot();

    std::cout << "Sensor readings for " << robot.name << " before moving forward:\n";
    robot.displaySensorData(0);

    robot.moveForward();
    robot.stop();

    std::cout << "Sensor readings for " << robot.name << " after stopping:\n";
    robot.displaySensorData(1);

    robot.moveBackward();
    robot.stop();

    std::cout << "Sensor readings for " << robot.name << " after moving backward and stopping:\n";
    robot.displaySensorData(2);

    return 0;
}
