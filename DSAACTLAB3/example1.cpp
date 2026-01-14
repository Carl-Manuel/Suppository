#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> actions;

    actions.push("Open File");
    actions.push("Edit File");
    actions.push("Save File");

    cout << "Last action: " << actions.top() << endl;
    actions.pop();
    cout << "After undo, current action: " << actions.top() << endl;

    return 0;
}
