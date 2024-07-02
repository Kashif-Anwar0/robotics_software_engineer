// RSE Assignment#1 Task#1
// Author: Kashif Anwar 
#include <iostream>
#include <string>

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

    Physical physical;

    Robot(std::string n, double s, double w, double h, double wdt, double l, int nos) 
        : name(n), speed(s), physical(w, h, wdt, l, nos) {}

    void moveForward() {
        std::cout << name << " is moving forward at speed " << speed << " m/s." << std::endl;
    }

    void moveBackward() {
        std::cout << name << " is moving backward at speed " << speed << " m/s." << std::endl;
    }

    void stop() {
        std::cout << name << " has stopped." << std::endl;
    }
};

namespace Burger {
    Robot createRobot() {
        return Robot("Burger", 0.22, 1.2, 138, 178, 192, 3);
    }
}

namespace Husky {
    Robot createRobot() {
        return Robot("Husky", 1.0, 50.0, 430, 670, 990, 4);
    }
}

int main() {
    Robot robotA = Burger::createRobot(); //instatiating for Burger
    Robot robotB = Husky::createRobot(); //instatiating for Husky

    std::cout << "Simulating actions for " << robotA.name << ":\n";
    robotA.moveForward();
    robotA.stop();
    robotA.moveBackward();
    robotA.stop();

    std::cout << "\nSimulating actions for " << robotB.name << ":\n";
    robotB.moveForward();
    robotB.stop();
    robotB.moveBackward();
    robotB.stop();

    return 0;
}





















