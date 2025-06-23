#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int maxSpeed;
public:
    Vehicle(string b, int s) : brand(b), maxSpeed(s) {}

    void getInfo() {
        cout << "Brand: " << brand << ", Max Speed: " << maxSpeed << " km/h" << endl;
    }
};

class Car : public Vehicle {
public:
    Car(string b, int s) : Vehicle(b, s) {}

    void Honk() {
        cout << "Car honks: Beep Beep!" << endl;
    }
};

class Motorbike : public Vehicle {
public:
    Motorbike(string b, int s) : Vehicle(b, s) {}

    void RevEngine() {
        cout << "Motorbike revs engine: Vroom Vroom!" << endl;
    }
};

int main() {
    Car myCar("Toyota", 200);
    Motorbike myBike("Yamaha", 180);

    cout << "Car info:" << endl;
    myCar.getInfo();
    myCar.Honk();

    cout << "\nMotorbike info:" << endl;
    myBike.getInfo();
    myBike.RevEngine();

    return 0;
}

