#include <iostream>
using namespace std;

class File {
public:
    File() {
        cout << "File opened" << endl;
    }
    ~File() {
        cout << "File closed" << endl;
    }
};

int moon() {
    File f;
    return 0;
}

int main() {
    moon();
    return 0;
}