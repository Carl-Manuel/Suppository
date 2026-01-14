#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> printQueue;

    printQueue.push("Document_A.pdf");
    printQueue.push("Report_B.docx");
    printQueue.push("Image_C.png");

    cout << "Printing: " << printQueue.front() << endl;
    printQueue.pop();
    cout << "Next in line: " << printQueue.front() << endl;

    return 0;
}
