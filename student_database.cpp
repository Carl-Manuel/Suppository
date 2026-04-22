#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

// Enum for year levels
enum YearLevel {
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4
};

// Struct to represent a student
struct Student {
    std::string name;
    std::string studentNumber;
    std::string email;
    YearLevel yearLevel;
    std::vector<double> grades;
    double gwa;
    std::string status;
    int rank;
};

// Function to get number of subjects based on year level
int getNumSubjects(YearLevel year) {
    switch (year) {
        case FIRST: return 6;
        case SECOND: return 9;
        case THIRD: return 10;
        case FOURTH: return 11;
        default: return 0;
    }
}

// Function to get year level string
std::string getYearString(YearLevel year) {
    switch (year) {
        case FIRST: return "1st Year";
        case SECOND: return "2nd Year";
        case THIRD: return "3rd Year";
        case FOURTH: return "4th Year";
        default: return "";
    }
}

// Function to compute GWA and status
void computeGWA(Student& student) {
    double sum = 0.0;
    for (double grade : student.grades) {
        sum += grade;
    }
    student.gwa = sum / student.grades.size();
    student.status = (student.gwa <= 4.0) ? "Passed" : "Failed";
}

// Function to create a student with given data
Student createStudent(std::string name, std::string studentNumber, std::string email, YearLevel year, std::vector<double> grades) {
    Student student;
    student.name = name;
    student.studentNumber = studentNumber;
    student.email = email;
    student.yearLevel = year;
    student.grades = grades;
    computeGWA(student);
    return student;
}


// Function to sort students by GWA ascending
bool compareByGWA(const Student& a, const Student& b) {
    return a.gwa < b.gwa;
}

// Function to display results for a year level
void displayYearLevel(const std::vector<Student>& students, YearLevel year) {
    if (students.empty()) return;

    std::cout << "\n=== " << getYearString(year) << " Students ===\n";
    std::cout << std::left << std::setw(4) << "Rank" << " | "
              << std::setw(20) << "Name" << " | "
              << std::setw(12) << "Student No" << " | "
              << std::setw(25) << "Email" << " | "
              << std::setw(6) << "GWA" << " | "
              << "Status\n";
    std::cout << std::string(80, '-') << "\n";

    for (const auto& student : students) {
        std::cout << std::left << std::setw(4) << student.rank << " | "
                  << std::setw(20) << student.name << " | "
                  << std::setw(12) << student.studentNumber << " | "
                  << std::setw(25) << student.email << " | "
                  << std::fixed << std::setprecision(2) << std::setw(6) << student.gwa << " | "
                  << student.status << "\n";
    }
}

int main() {
    std::vector<Student> allStudents;
    std::vector<std::vector<Student>> studentsByYear(5); // Index 1-4 for years

    // ===== INPUT STUDENT DATA HERE =====
    // Add your student data below. Format: createStudent("Name", "StudentNumber", "Email", YEAR_LEVEL, {grade1, grade2, ...})

    // 1st Year Students (6 subjects)
    studentsByYear[1].push_back(createStudent("Juan Dela Cruz", "2023001", "juan@email.com", FIRST, {1.5, 2.0, 1.75, 2.25, 1.0, 2.5}));
    studentsByYear[1].push_back(createStudent("Maria Santos", "2023002", "maria@email.com", FIRST, {2.0, 1.75, 2.5, 1.25, 2.75, 1.5}));
    studentsByYear[1].push_back(createStudent("Nigga Man", "20230032323232", "nigga@email.com", FIRST, {5.0, 5.0, 4.0, 4.0, 2.0, 3.0}));
    // Add more 1st year students here if needed

    // 2nd Year Students (9 subjects)
    studentsByYear[2].push_back(createStudent("Pedro Reyes", "2022001", "pedro@email.com", SECOND, {2.5, 2.0, 1.75, 2.25, 1.5, 2.75, 1.25, 2.0, 1.75}));
    studentsByYear[2].push_back(createStudent("Ana Garcia", "2022002", "ana@email.com", SECOND, {1.75, 2.25, 2.0, 1.5, 2.5, 1.25, 2.75, 1.0, 2.0}));
    // Add more 2nd year students here if needed

    // 3rd Year Students (10 subjects)
    studentsByYear[3].push_back(createStudent("Carlos Lopez", "2021001", "carlos@email.com", THIRD, {2.0, 1.75, 2.5, 1.25, 2.75, 1.5, 2.25, 1.0, 2.0, 1.75}));
    studentsByYear[3].push_back(createStudent("Sofia Martinez", "2021002", "sofia@email.com", THIRD, {1.5, 2.25, 2.0, 1.75, 2.5, 1.25, 2.75, 1.0, 2.0, 1.5}));
    // Add more 3rd year students here if needed

    // 4th Year Students (11 subjects)
    studentsByYear[4].push_back(createStudent("Miguel Torres", "2020001", "miguel@email.com", FOURTH, {2.25, 1.75, 2.0, 1.5, 2.5, 1.25, 2.75, 1.0, 2.0, 1.75, 2.25}));
    studentsByYear[4].push_back(createStudent("Isabella Flores", "2020002", "isabella@email.com", FOURTH, {1.75, 2.0, 2.25, 1.5, 2.5, 1.25, 2.75, 1.0, 2.0, 1.75, 2.25}));
    // Add more 4th year students here if needed

    // ===== END OF STUDENT DATA INPUT =====

    // Add all students to allStudents vector
    for (int i = 1; i <= 4; ++i) {
        for (const auto& student : studentsByYear[i]) {
            allStudents.push_back(student);
        }
    }

    // Sort and assign ranks for each year
    for (int i = 1; i <= 4; ++i) {
        std::sort(studentsByYear[i].begin(), studentsByYear[i].end(), compareByGWA);
        for (size_t j = 0; j < studentsByYear[i].size(); ++j) {
            studentsByYear[i][j].rank = j + 1;
        }
    }

    // Display results for each year
    for (int i = 1; i <= 4; ++i) {
        displayYearLevel(studentsByYear[i], static_cast<YearLevel>(i));
    }

    return 0;
}