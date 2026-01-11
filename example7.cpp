#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<string> students;

    cout << "Queue empty? " << students.empty() << endl;

    students.push("MC Salas");
    students.push("Princess Rookie");

    cout << "Students waiting: " << students.size() << endl;

    if (!students.empty()) {
        cout << "Serving: " << students.front() << endl;
        students.pop();
    }

    cout << "Remaining students: " << students.size() << endl;

    return 0;
}