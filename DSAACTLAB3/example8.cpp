#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    priority_queue<pair<int, string>> cpuScheduler;

    cpuScheduler.push({1, "Background Sync"});
    cpuScheduler.push({10, "System Update"});
    cpuScheduler.push({5, "User Application"});

    while (!cpuScheduler.empty()) {
        cout << "Executing: " << cpuScheduler.top().second << endl;
        cpuScheduler.pop();
    }

    return 0;
}
