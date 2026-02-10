#include <iostream>
using namespace std;

class Calculator {
public:
    int multiply(int a, int b) {
        return a * b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
};

int main() {
    Calculator calc;
    cout << calc.multiply(3, 5) << endl;
    cout << calc.multiply(2.5, 4.1) << endl;
    return 0;
} 