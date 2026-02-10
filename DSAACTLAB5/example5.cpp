#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void move() {
        cout << "Vehicle is moving" << endl;
    }
};

class Car : public Vehicle {
public:
    void move() override {
        cout << "Car is driving on the road" << endl;
    }
};

int main() {
    Vehicle* v = new Car();
    v->move();
    return 0;
} 
