#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> deadlines;

    deadlines.push(5);   // days
    deadlines.push(2);
    deadlines.push(10);

    cout << "Most Urgent Deadline (days): " << deadlines.top() << endl;

    return 0;
}
