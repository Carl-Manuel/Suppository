#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<char> letterStack;
    queue<string> nameQueue;

    letterStack.push('A');
    letterStack.push('B');
    letterStack.push('C');

    nameQueue.push("Alice");
    nameQueue.push("Bob");
    nameQueue.push("Charlie");

    cout << "Stack Top Letter: " << letterStack.top() << endl;
    cout << "Queue Front Name: " << nameQueue.front() << endl;
    cout << "Queue Back Name: " << nameQueue.back() << endl;

    return 0;
}
