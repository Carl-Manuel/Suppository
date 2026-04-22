#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::ifstream file("students.dat");
    if (!file.is_open()) {
        std::cout << "File not open" << std::endl;
        return 1;
    }
    
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        count++;
        if (count > 5) break; // Just read first 5 lines
        std::cout << "Line " << count << ": " << line << std::endl;
    }
    file.close();
    std::cout << "Read " << count << " lines" << std::endl;
    return 0;
}
