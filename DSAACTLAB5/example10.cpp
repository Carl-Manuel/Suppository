#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay() {
        cout << "Processing payment" << endl;
    }
    virtual ~Payment() {}
};

class CreditCard : public Payment {
public:
    void pay() override {
        cout << "Paid using Credit Card" << endl;
    }
};

class GCash : public Payment {
public:
    void pay() override {
        cout << "Paid using GCash" << endl;
    }
};

int main() {
    Payment* p1 = new CreditCard();
    Payment* p2 = new GCash();
    p1->pay();
    p2->pay();
    delete p1;
    delete p2;
    return 0;
} 
