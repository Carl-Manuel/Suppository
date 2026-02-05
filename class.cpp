#include <iostream>
using namespace std;

// Class definition
class Car
{
public:
    string brand;
    string model;
    int valprice;
    int year;

    Car(string b, string m, int p, int y) : brand(b), model(m), valprice(p), year(y) {}
    // Member function
    void show()
    {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: " << valprice << ", Year: " << year << endl;
    }
    int getprice(int qty){
        return valprice * qty;
    }
};

int main()
{
    // Creating an object of class Car
    Car toyota("Toyota", "Camry", 24000, 2020);
    Car honda("Honda", "Civic", 32000, 2019);


    toyota.show();
    honda.show();

    cout << "The total price for 3 Toyota cars is $" << toyota.valprice * 3 << endl;
    cout << "The total price for 2 Honda cars is $" << honda.valprice * 2 << endl;
    return 0;
}
