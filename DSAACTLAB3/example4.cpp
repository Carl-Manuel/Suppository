#include <iostream>
#include <stack>
using namespace std;

void showHistory(stack<string> history) {
    while (!history.empty()) {
        cout << history.top() << endl;
        history.pop();
    }
}

int main() {
    stack<string> commandHistory;

    commandHistory.push("Login");
    commandHistory.push("Upload File");
    commandHistory.push("Logout");

    cout << "Command History (Latest First):\n";
    showHistory(commandHistory);

    return 0;
}
