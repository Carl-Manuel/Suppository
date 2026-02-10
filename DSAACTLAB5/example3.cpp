#include <iostream>
using namespace std;

class Appliance {
public:
	virtual void turnOn() = 0; // pure virtual function
    virtual void turnOff() = 0;
	virtual ~Appliance() = default;
};

class ElectricFan : public Appliance {
public:
	void turnOn() {
		cout << "Electric fan is now ON" << endl;
	}
    void turnOff() {
		cout << "Electric fan is now OFF" << endl;
	}
};

int main() {
	Appliance* a = new ElectricFan();
	a->turnOff();
	delete a;
	return 0;
}
