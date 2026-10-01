#include <iostream>
#include <string>

class Car {
private:
    int yearModel;
    std::string make;
    int speed;

public:
    // Constructor
    Car(int year, std::string carMake) {
        yearModel = year;
        make = carMake;
        speed = 0;
    }

    // Accessor functions (Getters)
    int getYearModel() const {
        return yearModel;
    }

    std::string getMake() const {
        return make;
    }

    int getSpeed() const {
        return speed;
    }

    // Mutator functions for speed
    void accelerate() {
        speed += 5;
    }

    void brake() {
        speed -= 5;
        if (speed < 0) { // Safety guard to prevent negative speed
            speed = 0;
        }
    }
};

int main() {
    // Create two Car objects
    Car car1(2022, "Toyota");
    Car car2(2024, "Ford");

    // Print year model and make for both cars
    std::cout << "Car 1: " << car1.getYearModel() << " " << car1.getMake() << std::endl;
    std::cout << "Car 2: " << car2.getYearModel() << " " << car2.getMake() << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    // Accelerate the second car 5 times
    std::cout << "\nAccelerating Car 2..." << std::endl;
    for (int i = 1; i <= 5; i++) {
        car2.accelerate();
        std::cout << "Current Speed after acceleration " << i << ": " << car2.getSpeed() << " mph" << std::endl;
    }

    // Brake the second car 5 times
    std::cout << "\nBraking Car 2..." << std::endl;
    for (int i = 1; i <= 5; i++) {
        car2.brake();
        std::cout << "Current Speed after braking " << i << ": " << car2.getSpeed() << " mph" << std::endl;
    }

    return 0;
}