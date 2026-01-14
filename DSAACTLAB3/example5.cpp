#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> grades;

    grades.push(85);
    grades.push(92);
    grades.push(78);

    cout << "Highest Grade: " << grades.top() << endl;

    return 0;
}
