#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int year;
    void display() {
        cout << "Name: " << name << ", Year: " << year << endl;
    }
};

int main() {
    Student s1;
    s1.name = "My Name";
    s1.year = 2006;
    s1.display();
    return 0;
} 
