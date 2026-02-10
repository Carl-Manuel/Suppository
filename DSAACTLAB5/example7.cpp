#include <iostream>
using namespace std;

class Distance {
public:
    int meters;
    Distance(int m = 0) {
        meters = m;
    }
    Distance operator - (Distance d) {
        return Distance(meters - d.meters);
    }
};

int main() {
    Distance d1(50), d2(30);
    Distance d3 = d1 - d2;
    cout << "Total Distance: " << d3.meters << " meters" << endl;
    return 0;
} 
