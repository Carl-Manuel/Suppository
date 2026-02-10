#include <iostream>
using namespace std;

class Computer {
public:
    class CPU {
    public:
        void process() {
            cout << "CPU is processing data" << endl;
        }
    };
    void start() {
        CPU cpu;
        cpu.process();
    }
};

int main() {
    Computer pc;
    pc.start();
    return 0;
} 
