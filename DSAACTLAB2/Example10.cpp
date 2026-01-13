#include <iostream>
using namespace std;

int main() {
    int cube[2][2][2] = {
        { {1, 2}, {3, 4} },
        { {5, 6}, {7, 8} }
    };

    cout << cube[0][0][0] << endl;
    cout << cube[0][1][1] << endl;
    cout << cube[1][0][1] << endl;
    cout << cube[1][1][0];

    return 0;
}
