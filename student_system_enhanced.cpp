#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>

// ANSI Color codes
#define COLOR_RESET     "\033[0m"
#define COLOR_BOLD      "\033[1m"
#define COLOR_CYAN      "\033[36m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_YELLOW    "\033[33m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_MAGENTA   "\033[35m"
#define COLOR_RED       "\033[31m"

// Enum for year levels
enum YearLevel { FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4 };

// Struct to represent a student
struct Student
{
    std::string name, studentNumber, email;
    YearLevel yearLevel;
    std::vector<double> grades;
    double gwa;
    std::string status;
    int rank;
};

// BST Node
struct BSTNode {
    Student data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Student s) : data(s), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    BSTNode* root;
    bool compareByGWA;

    void insertHelper(BSTNode*& node, Student student) {
        if (node == nullptr) { node = new BSTNode(student); return; }
        if (compareByGWA) {
            if (student.gwa < node->data.gwa) insertHelper(node->left, student);
            else insertHelper(node->right, student);
        } else {
            if (student.name < node->data.name) insertHelper(node->left, student);
            else insertHelper(node->right, student);
        }
    }

    void inOrderTraversal(BSTNode* node, std::vector<Student>& result) {
        if (node == nullptr) return;
        inOrderTraversal(node->left, result);
        result.push_back(node->data);
        inOrderTraversal(node->right, result);
    }

    void destroyTree(BSTNode* node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
public:
    BST(bool byGWA = true) : root(nullptr), compareByGWA(byGWA) {}
    ~BST() { destroyTree(root); }
    void insert(Student student) { insertHelper(root, student); }
    std::vector<Student> getSortedList() {
        std::vector<Student> result;
        inOrderTraversal(root, result);
        return result;
    }
};

int getNumSubjects(YearLevel year) {
    switch (year) { case FIRST: return 6; case SECOND: return 9; 
    case THIRD: return 10; case FOURTH: return 11; default: return 0; }
}

std::string getYearString(YearLevel year) {
    switch (year) { case FIRST: return "1st Year"; case SECOND: return "2nd Year";
    case THIRD: return "3rd Year"; case FOURTH: return "4th Year"; default: return ""; }
}

void computeGWA(Student &student) {
    double sum = 0.0;
    for (double grade : student.grades) sum += grade;
    student.gwa = sum / student.grades.size();
    student.status = (student.gwa <= 4.0) ? "Passed" : "Failed";
}

Student createStudent(std::string name, std::string studentNumber, std::string email,
                     YearLevel year, std::vector<double> grades) {
    Student student;
    student.name = name;
    student.studentNumber = studentNumber;
    student.email = email;
    student.yearLevel = year;
    student.grades = grades;
    computeGWA(student);
    return student;
}

void bubbleSort(std::vector<Student>& students, bool byGWA = true) {
    int n = students.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = byGWA ? (students[j].gwa > students[j + 1].gwa) :
                                      (students[j].name > students[j + 1].name);
            if (shouldSwap) std::swap(students[j], students[j + 1]);
        }
}

void selectionSort(std::vector<Student>& students, bool byGWA = true) {
    int n = students.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            bool isSmaller = byGWA ? (students[j].gwa < students[minIndex].gwa) :
                                     (students[j].name < students[minIndex].name);
            if (isSmaller) minIndex = j;
        }
        if (minIndex != i) std::swap(students[i], students[minIndex]);
    }
}

int linearSearch(const std::vector<Student>& students, const std::string& target, bool searchByName = true) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (searchByName) { if (students[i].name == target) return i; }
        else { if (students[i].studentNumber == target) return i; }
    }
    return -1;
}

int binarySearch(const std::vector<Student>& students, const std::string& targetStudentNumber) {
    int left = 0, right = students.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].studentNumber == targetStudentNumber) return mid;
        else if (students[mid].studentNumber < targetStudentNumber) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

bool compareByGWA(const Student &a, const Student &b) { return a.gwa < b.gwa; }
bool compareByName(const Student &a, const Student &b) { return a.name < b.name; }
bool compareByStudentNumber(const Student &a, const Student &b) { return a.studentNumber < b.studentNumber; }

void displaySortedList(const std::vector<Student> &students, const std::string &sortType) {
    if (students.empty()) return;
    
    std::cout << "\n" << COLOR_CYAN << "══════════════════════════════════════════════════════════════════════════════════════════\n" << COLOR_RESET;
    std::cout << COLOR_GREEN << COLOR_BOLD << "  All Students - Sorted by " << sortType << "\n" << COLOR_RESET;
    std::cout << COLOR_CYAN << "══════════════════════════════════════════════════════════════════════════════════════════\n" << COLOR_RESET;
    std::cout << COLOR_BLUE << COLOR_BOLD;
    std::cout << std::left << std::setw(3) << "#" << " │ " << std::setw(20) << "Name" << " │ " 
              << std::setw(12) << "Student No" << " │ " << std::setw(10) << "Year" << " │ "
              << std::setw(6) << "GWA" << " │ Status\n" << COLOR_RESET;
    std::cout << COLOR_CYAN << "──────────────────────────────────────────────────────────────────────────────────────────\n" << COLOR_RESET;
    
    int counter = 1;
    for (const auto &student : students) {
        std::cout << std::left << std::setw(3) << counter << " │ " << std::setw(20) << student.name << " │ "
                  << std::setw(12) << student.studentNumber << " │ " << std::setw(10) << getYearString(student.yearLevel) << " │ "
                  << std::fixed << std::setprecision(2) << std::setw(6) << student.gwa << " │ ";
        if (student.status == "Passed") std::cout << COLOR_GREEN << "✓ PASS" << COLOR_RESET;
        else std::cout << COLOR_YELLOW << "✗ FAIL" << COLOR_RESET;
        std::cout << "\n";
        counter++;
    }
    std::cout << COLOR_CYAN << "══════════════════════════════════════════════════════════════════════════════════════════\n" << COLOR_RESET;
}

void displayYearLevel(const std::vector<Student> &students, YearLevel year) {
    if (students.empty()) return;
    std::cout << "\n" << COLOR_CYAN << "══════════════════════════════════════════════════════════════════════════════════════════\n" << COLOR_RESET;
    std::cout << COLOR_GREEN << COLOR_BOLD << "  " << getYearString(year) << " Students - Ranked by GWA\n" << COLOR_RESET;
    std::cout << COLOR_CYAN << "══════════════════════════════════════════════════════════════════════════════════════════\n" << COLOR_RESET;
    std::cout << COLOR_BLUE << COLOR_BOLD;
    std::cout << std::left << std::setw(4) << "Rank" << " │ " << std::setw(20) << "Name" << " │ " 
              << std::setw(12) << "Student No" << " │ " << std::setw(20) << "Email" << " │ " 
              << std::setw(6) << "GWA" << " │ Status\n" << COLOR_RESET;
    std::cout << COLOR_CYAN << "──────────────────────────────────────────────────────────────────────────────────────────\n" << COLOR_RESET;
    for (const auto &student : students) {
        std::cout << std::left << std::setw(4) << student.rank << " │ " << std::setw(20) << student.name << " │ "
                  << std::setw(12) << student.studentNumber << " │ " << std::setw(20) << student.email << " │ "
                  << std::fixed << std::setprecision(2) << std::setw(6) << student.gwa << " │ ";
        if (student.status == "Passed") std::cout << COLOR_GREEN << "✓ PASS" << COLOR_RESET;
        else std::cout << COLOR_YELLOW << "✗ FAIL" << COLOR_RESET;
        std::cout << "\n";
    }
    std::cout << COLOR_CYAN << "══════════════════════════════════════════════════════════════════════════════════════════\n" << COLOR_RESET;
}

YearLevel getYearLevelInput() {
    int year;
    while (true) {
        std::cout << COLOR_MAGENTA << "Enter year level (1-4) or 0 to go back: " << COLOR_RESET;
        std::cin >> year;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << COLOR_YELLOW << "Invalid input. Please enter a number.\n" << COLOR_RESET;
        } else if (year == 0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return static_cast<YearLevel>(-1);
        } else if (year < 1 || year > 4) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << COLOR_YELLOW << "Invalid input. Please enter 1, 2, 3, or 4.\n" << COLOR_RESET;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return static_cast<YearLevel>(year);
        }
    }
}

std::vector<double> getGradesInput(int numSubjects) {
    std::vector<double> grades;
    std::cout << COLOR_MAGENTA << "Enter " << numSubjects << " grades (separated by spaces): " << COLOR_RESET;
    for (int i = 0; i < numSubjects; ++i) {
        double grade;
        std::cin >> grade;
        grades.push_back(grade);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return grades;
}

void addStudent(std::vector<Student>& allStudents, std::map<YearLevel, std::vector<Student>>& studentsByYear) {
    std::string name, studentNumber, email;
    std::cout << "\n" << COLOR_CYAN << COLOR_BOLD << "╔══════════════════════════════════════╗\n"
              << "║      ADD NEW STUDENT                 ║\n"
              << "╚══════════════════════════════════════╝\n" << COLOR_RESET;
    std::cout << COLOR_GREEN << "Enter student name (or type 'back' to cancel): " << COLOR_RESET;
    std::getline(std::cin, name);
    if (name == "back" || name == "BACK") {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    std::cout << COLOR_GREEN << "Enter student number: " << COLOR_RESET;
    std::getline(std::cin, studentNumber);
    if (studentNumber == "back" || studentNumber == "BACK") {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    std::cout << COLOR_GREEN << "Enter email: " << COLOR_RESET;
    std::getline(std::cin, email);
    if (email == "back" || email == "BACK") {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    YearLevel yearLevel = getYearLevelInput();
    if (yearLevel == static_cast<YearLevel>(-1)) {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    int numSubjects = getNumSubjects(yearLevel);
    std::vector<double> grades = getGradesInput(numSubjects);

    Student newStudent = createStudent(name, studentNumber, email, yearLevel, grades);
    allStudents.push_back(newStudent);
    studentsByYear[yearLevel].push_back(newStudent);

    std::cout << COLOR_GREEN << COLOR_BOLD << "\n✓ Student added successfully!\n" << COLOR_RESET;
}

void displayAllStudents(const std::map<YearLevel, std::vector<Student>>& studentsByYear) {
    for (int i = 1; i <= 4; ++i) {
        YearLevel year = static_cast<YearLevel>(i);
        auto it = studentsByYear.find(year);
        if (it != studentsByYear.end()) displayYearLevel(it->second, year);
    }
}

void searchStudent(const std::vector<Student>& allStudents) {
    int choice;
    std::cout << "\n" << COLOR_CYAN << COLOR_BOLD << "╔══════════════════════════════════════╗\n"
              << "║      SEARCH STUDENT                  ║\n"
              << "╚══════════════════════════════════════╝\n" << COLOR_RESET;
    std::cout << COLOR_GREEN << "1. Search by Name (Linear Search)\n"
              << "2. Search by Student Number (Binary Search)\n"
              << "0. Go Back\n" << COLOR_RESET;
    std::cout << COLOR_MAGENTA << "Enter choice: " << COLOR_RESET;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 0) {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    if (choice == 1) {
        std::string name;
        std::cout << COLOR_GREEN << "Enter student name (or type 'back' to cancel): " << COLOR_RESET;
        std::getline(std::cin, name);
        if (name == "back" || name == "BACK") {
            std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
            return;
        }
        int index = linearSearch(allStudents, name, true);
        if (index != -1) {
            std::cout << COLOR_GREEN << "\n✓ Student found:\nName: " << allStudents[index].name 
                      << "\nStudent Number: " << allStudents[index].studentNumber 
                      << "\nEmail: " << allStudents[index].email 
                      << "\nYear Level: " << getYearString(allStudents[index].yearLevel) 
                      << "\nGWA: " << std::fixed << std::setprecision(2) << allStudents[index].gwa 
                      << "\nStatus: " << allStudents[index].status << "\n" << COLOR_RESET;
        } else std::cout << COLOR_YELLOW << "✗ Student not found.\n" << COLOR_RESET;
    } else if (choice == 2) {
        std::vector<Student> sortedStudents = allStudents;
        std::sort(sortedStudents.begin(), sortedStudents.end(), compareByStudentNumber);
        std::string studentNumber;
        std::cout << COLOR_GREEN << "Enter student number (or type 'back' to cancel): " << COLOR_RESET;
        std::getline(std::cin, studentNumber);
        if (studentNumber == "back" || studentNumber == "BACK") {
            std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
            return;
        }
        int index = binarySearch(sortedStudents, studentNumber);
        if (index != -1) {
            std::cout << COLOR_GREEN << "\n✓ Student found:\nName: " << sortedStudents[index].name 
                      << "\nStudent Number: " << sortedStudents[index].studentNumber 
                      << "\nEmail: " << sortedStudents[index].email 
                      << "\nYear Level: " << getYearString(sortedStudents[index].yearLevel) 
                      << "\nGWA: " << std::fixed << std::setprecision(2) << sortedStudents[index].gwa 
                      << "\nStatus: " << sortedStudents[index].status << "\n" << COLOR_RESET;
        } else std::cout << COLOR_YELLOW << "✗ Student not found.\n" << COLOR_RESET;
    } else std::cout << COLOR_YELLOW << "Invalid choice.\n" << COLOR_RESET;
}

void sortStudents(std::vector<Student>& allStudents, std::map<YearLevel, std::vector<Student>>& studentsByYear) {
    int choice;
    std::cout << "\n" << COLOR_CYAN << COLOR_BOLD << "╔══════════════════════════════════════╗\n"
              << "║      SORT STUDENTS                   ║\n"
              << "╚══════════════════════════════════════╝\n" << COLOR_RESET;
    std::cout << COLOR_GREEN << "1. Sort by GWA (Bubble Sort)\n"
              << "2. Sort by Name (Selection Sort)\n"
              << "0. Go Back\n" << COLOR_RESET;
    std::cout << COLOR_MAGENTA << "Enter choice: " << COLOR_RESET;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 0) {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    std::string sortType;
    if (choice == 1) {
        bubbleSort(allStudents, true);
        sortType = "GWA (Ascending) - Bubble Sort";
        std::cout << COLOR_GREEN << COLOR_BOLD << "✓ Students sorted by GWA using Bubble Sort.\n" << COLOR_RESET;
    } else if (choice == 2) {
        selectionSort(allStudents, false);
        sortType = "Name (Alphabetical) - Selection Sort";
        std::cout << COLOR_GREEN << COLOR_BOLD << "✓ Students sorted by Name using Selection Sort.\n" << COLOR_RESET;
    } else {
        std::cout << COLOR_YELLOW << "Invalid choice.\n" << COLOR_RESET;
        return;
    }

    // Display the sorted list
    displaySortedList(allStudents, sortType);

    // Update rankings for each year
    for (auto& pair : studentsByYear) {
        std::sort(pair.second.begin(), pair.second.end(), compareByGWA);
        for (size_t j = 0; j < pair.second.size(); ++j) {
            pair.second[j].rank = j + 1;
        }
    }
}

void displayTopNStudents(const std::map<YearLevel, std::vector<Student>>& studentsByYear) {
    int n;
    std::cout << "\n" << COLOR_CYAN << COLOR_BOLD << "╔══════════════════════════════════════════╗\n"
              << "║      TOP N STUDENTS PER YEAR          ║\n"
              << "╚══════════════════════════════════════════╝\n" << COLOR_RESET;
    std::cout << COLOR_MAGENTA << "Enter N (or 0 to go back): " << COLOR_RESET;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (n == 0) {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    for (int i = 1; i <= 4; ++i) {
        YearLevel year = static_cast<YearLevel>(i);
        auto it = studentsByYear.find(year);
        if (it != studentsByYear.end() && !it->second.empty()) {
            std::vector<Student> topStudents;
            int count = std::min(n, static_cast<int>(it->second.size()));
            for (int j = 0; j < count; ++j) topStudents.push_back(it->second[j]);
            displayYearLevel(topStudents, year);
        }
    }
}

void demonstrateBST(const std::vector<Student>& allStudents) {
    if (allStudents.empty()) { 
        std::cout << COLOR_YELLOW << "No students to demonstrate BST.\n" << COLOR_RESET; 
        return; 
    }

    int choice;
    std::cout << "\n" << COLOR_CYAN << COLOR_BOLD << "╔══════════════════════════════════════════╗\n"
              << "║      BST DEMONSTRATION                ║\n"
              << "╚══════════════════════════════════════════╝\n" << COLOR_RESET;
    std::cout << COLOR_GREEN << "1. Sort by GWA using BST\n"
              << "2. Sort by Name using BST\n"
              << "0. Go Back\n" << COLOR_RESET;
    std::cout << COLOR_MAGENTA << "Enter choice: " << COLOR_RESET;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 0) {
        std::cout << COLOR_YELLOW << "✗ Operation cancelled.\n" << COLOR_RESET;
        return;
    }

    BST bst(choice == 1);
    for (const auto& student : allStudents) bst.insert(student);
    std::vector<Student> sortedStudents = bst.getSortedList();

    std::cout << "\n" << COLOR_CYAN << COLOR_BOLD << "Students sorted using BST:\n" << COLOR_RESET;
    std::cout << COLOR_BLUE << COLOR_BOLD;
    std::cout << std::left << std::setw(20) << "Name" << " │ " << std::setw(12) << "Student No" << " │ " << std::setw(6) << "GWA" << "\n" << COLOR_RESET;
    std::cout << COLOR_CYAN << "────────────────────────────────────────────────────────\n" << COLOR_RESET;
    for (const auto& student : sortedStudents) {
        std::cout << std::left << std::setw(20) << student.name << " │ " << std::setw(12) << student.studentNumber 
                  << " │ " << std::fixed << std::setprecision(2) << std::setw(6) << student.gwa << "\n";
    }
    std::cout << COLOR_CYAN << "────────────────────────────────────────────────────────\n" << COLOR_RESET;
}

void displayWelcomeBanner() {
    std::cout << COLOR_CYAN << COLOR_BOLD;
    std::cout << "╔════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                                                                ║\n";
    std::cout << "║" << COLOR_GREEN << COLOR_BOLD << "        ✨ STUDENT GWA RANKING SYSTEM ✨" << COLOR_RESET << COLOR_CYAN << COLOR_BOLD << "               ║\n";
    std::cout << "║" << COLOR_YELLOW << "           Manage & Track Student Performance" << COLOR_RESET << COLOR_CYAN << COLOR_BOLD << "           ║\n";
    std::cout << "║                                                                ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════╝\n" << COLOR_RESET;
}

void displayMenu() {
    std::cout << "\n" << COLOR_CYAN << "╔═══════════════════════════════════════════════════════════╗\n" << COLOR_RESET;
    std::cout << COLOR_BLUE << COLOR_BOLD << "               MAIN MENU - SELECT AN OPTION\n" << COLOR_RESET;
    std::cout << COLOR_CYAN << "║\n" << COLOR_RESET;
    std::cout << COLOR_GREEN << "║ " << COLOR_BOLD << "1." << COLOR_RESET << COLOR_GREEN << " Add New Student\n"
              << "║ " << COLOR_BOLD << "2." << COLOR_RESET << COLOR_GREEN << " Display All Students (Grouped by Year Level)\n"
              << "║ " << COLOR_BOLD << "3." << COLOR_RESET << COLOR_GREEN << " Search Student\n"
              << "║ " << COLOR_BOLD << "4." << COLOR_RESET << COLOR_GREEN << " Sort Students\n"
              << "║ " << COLOR_BOLD << "5." << COLOR_RESET << COLOR_GREEN << " Display Top N Students per Year\n"
              << "║ " << COLOR_BOLD << "6." << COLOR_RESET << COLOR_GREEN << " Demonstrate BST\n" << COLOR_RESET;
    std::cout << COLOR_YELLOW << "║ " << COLOR_BOLD << "7." << COLOR_RESET << COLOR_YELLOW << " Exit\n" << COLOR_RESET;
    std::cout << COLOR_CYAN << "║\n╚═══════════════════════════════════════════════════════════╝\n" << COLOR_RESET;
    std::cout << COLOR_MAGENTA << COLOR_BOLD << "Enter your choice (1-7): " << COLOR_RESET;
}

int main() {
    std::vector<Student> allStudents;
    std::map<YearLevel, std::vector<Student>> studentsByYear;

    // 1st Year Students (6 subjects)
    studentsByYear[FIRST].push_back(createStudent("Zuriel Ethan Yambao", "20231128975", "yambao.zurielethan@ue.edu.ph", FIRST, {2.50, 2.00, 1.25, 1.25, 2.00, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Lev Ryan Macalintal", "20131155389", "macalintal.levryan@ue.edu.ph", FIRST, {2.50, 2.00, 1.50, 1.25, 2.00, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Axel Audrey Ignacio", "20231137748", "ignacio.axelaudrey@eu.edu.ph", FIRST, {3.0, 2.25, 1.50, 1.50, 4, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Christian Arvy Pasion", "20251123225", "pasion.christianarvy@eu.edu.ph", FIRST, {2.75, 2.00, 1.75, 1.75, 2.00, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Euken Rosario", "20251123861", "rosario.euken@eu.edu.ph", FIRST, {2.75, 1.75, 1.25, 2.25, 2.00, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Toby Unciano", "20231101396", "unciano.toby@eu.edu.ph", FIRST, {3.00, 1.75, 1.50, 1.25, 2.75, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Princess Roque", "20251120566", "roque.princessangeline@eu.edu.ph", FIRST, {2.75, 1.75, 1.25, 2.25, 3.00, 1.50}));
    studentsByYear[FIRST].push_back(createStudent("Jophielle Gunabe", "20251131278", "gunabe.jophielle@eu.edu.ph", FIRST, {3.00, 1.75, 1.25, 2.25, 3.00, 1.50}));
    studentsByYear[FIRST].push_back(createStudent("Emmanuel Patrick Acuna", "202311052112", "acuna.emmanuelpatrick@eu.edu.ph", FIRST, {2.50, 2.00, 1.75, 2.00, 2.00, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Manuel Marquez", "20191132646", "marquez.manuelalexander@eu.edu.ph", FIRST, {2.50, 1.50, 1.25, 1.25, 1.75, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Aaron Bernabe", "20251114564", "bernabe.marxaaron@eu.edu.ph", FIRST, {2.00, 1.50, 2.00, 1.75, 2.25, 2.00}));
    studentsByYear[FIRST].push_back(createStudent("Eros Lamamigo", "2025113850", "lamamigo.erosmatthew@eu.edu.ph", FIRST, {2.50, 2.00, 1.50, 1.50, 2.25, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Bryce Gabriel Abordo", "20251107412", "abordo.brycebengabriel@eu.edu.ph", FIRST, {1.75, 2.00, 1.75, 1.25, 1.75, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Zionah Rae Javier", "20251121161", "javier.zionahrae@eu.edu.ph", FIRST, {2.25, 2.25, 1.50, 1.75, 1.75, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Maxine Aliyah Alcazar", "20251123963", "alcazar.maxinealiyah@eu.edu.ph", FIRST, {1.25, 1.25, 1.00, 1.00, 1.00, 1.25}));
    studentsByYear[FIRST].push_back(createStudent("Rhian Zyrelle Ramos", "20231123345", "ramos.rhjianzyrelle@eu.edu.ph", FIRST, {2.50, 1.50, 1.25, 1.75, 1.25, 1.25}));
    studentsByYear[FIRST].push_back(createStudent("Sean Russel Cruz", "20251130106", "cruz.seanrussel@eu.edu.ph", FIRST, {2.75, 2.50, 1.25, 1.50, 2.25, 1.25}));
    studentsByYear[FIRST].push_back(createStudent("Clayton Kelsey Grande", "20251104485", "grande.claytonkelsey@eu.edu.ph", FIRST, {2.50, 2.00, 2.25, 1.50, 2.75, 2.00}));

    // 2nd Year Students (9 subjects)
    studentsByYear[SECOND].push_back(createStudent("Gwen Lopez", "20241130029", "gwengelynn@gmail.com", SECOND, {1.25, 1.00, 1.00, 1.25, 1.25, 1.50, 1.00, 1.50, 1.50}));
    studentsByYear[SECOND].push_back(createStudent("Chang Park", "20181114136", "park.changhyun@ue.edu.ph", SECOND, {1.25, 1.00, 1.25, 1.50, 1.25, 1.75, 1.00, 1.50, 1.75}));
    studentsByYear[SECOND].push_back(createStudent("Angela Tolentino", "202411245746", "tolentino.angela@eu.edu.ph", SECOND, {1.25, 1.00, 1.00, 1.50, 1.25, 1.75, 1.00, 1.25, 1.25}));
    studentsByYear[SECOND].push_back(createStudent("Alexandrina Timbol", "20251120809", "timbol.alexandrina@eu.edu.ph", SECOND, {1.25, 1.25, 1.25, 1.25, 2.25, 2.00, 1.50, 1.25, 1.25}));

    // 3rd Year Students (10 subjects)
    studentsByYear[THIRD].push_back(createStudent("James Coco", "20231110057", "coco.james@ue.edu.ph", THIRD, {1.75, 1.25, 1.00, 1.75, 1.00, 1.50, 1.00, 1.25, 1.25, 1.00}));
    studentsByYear[THIRD].push_back(createStudent("John Carlo Bauzon", "20231125874", "bauzon.johncarlo@ue.edu.ph", THIRD, {1.75, 1.50, 1.00, 1.75, 1.25, 1.75, 1.00, 1.25, 1.25, 1.50}));
    studentsByYear[THIRD].push_back(createStudent("Rhamuel Gamboa", "20231150122", "gamboa.rhamuel@ue.edu.ph", THIRD, {1.25, 1.50, 1.00, 1.50, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00}));
    studentsByYear[THIRD].push_back(createStudent("Ralph Daniel Bayona", "20231135618", "bayona.ralph@ue.edu.ph", THIRD, {1.75, 1.25, 1.25, 1.50, 1.75, 1.75, 1.00, 1.25, 1.00, 1.00}));
    studentsByYear[THIRD].push_back(createStudent("Elija Brent Tarog", "20231127024", "tarog.elijabrent@ue.edu.ph", THIRD, {2.5, 4.00, 3.00, 1.75, 1.25, 1.75, 1.25, 2.25, 1.00, 1.00}));
    studentsByYear[THIRD].push_back(createStudent("Timothy P. Villegas", "2023131990", "villegas.timothy@ue.edu.ph", THIRD, {3.00, 1.75, 1.25, 1.75, 1.5, 1.75, 1.25, 3.00, 1.00, 1.00}));
    studentsByYear[THIRD].push_back(createStudent("Pharrell Morgan Basalo", "2023113924", "basalo.pharrellmorgan@ue.edu.ph", THIRD, {1.5, 2.00, 1.00, 1.50, 1.75, 1.75, 1.00, 2.00, 1.00, 1.00}));
    studentsByYear[THIRD].push_back(createStudent("Marc Andrew Pitalo", "20231123083", "pitalo.marcandrew@ue.edu.ph", THIRD, {1.5, 1.25, 1.25, 1.75, 1.25, 1.5, 1.25, 1.00, 1.25, 1.5}));
    studentsByYear[THIRD].push_back(createStudent("Hyryl Tibay", "2011135939", "tibay.hyryltibay@ue.edu.ph", THIRD, {1.5, 1.25, 1.00, 1.25, 1.25, 1.00, 1.00, 2.00, 1.00, 1.5}));
    studentsByYear[THIRD].push_back(createStudent("Arto Francis Simbulan", "2023114933", "simbulan.artofrancis@ue.edu.ph", THIRD, {1.25, 1.00, 1.00, 1.25, 1.00, 1.75, 1.25, 1.75, 1.25, 1.25}));

    // 4th Year Students (11 subjects)
    studentsByYear[FOURTH].push_back(createStudent("Kurt Regala", "20221106190", "regala.kurt@ue.edu.ph", FOURTH, {1.25, 1.50, 2.50, 1.75, 1.25, 1.75, 1.75, 1.50, 1.50, 2.00, 1.50}));
    studentsByYear[FOURTH].push_back(createStudent("William Monzon", "20191110200", "monzon.william@ue.edu.ph", FOURTH, {1.00, 1.25, 1.75, 1.50, 1.00, 1.50, 1.50, 1.25, 1.50, 1.00, 1.50}));
    studentsByYear[FOURTH].push_back(createStudent("Liam Concepcion", "20221119159", "concepcion.liam@ue.edu.ph", FOURTH, {1.00, 1.50, 1.25, 1.00, 1.25, 1.50, 1.25, 1.25, 1.75, 1.00, 1.50}));
    studentsByYear[FOURTH].push_back(createStudent("Al Francis B. Buenaventura", "20201124961", "buenaventura.alfrancis@ue.edu.ph", FOURTH, {1.00, 1.25, 1.25, 1.50, 1.25, 1.50, 1.50, 1.00, 1.50, 1.00, 1.50}));
    studentsByYear[FOURTH].push_back(createStudent("Bryan G. Bernardino", "20221112410", "bernardino.bryan@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.50, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[FOURTH].push_back(createStudent("Ernest Dimaunahan", "20221117448", "dimaunahan.ernest@ue.edu.ph", FOURTH, {1.00, 1.25, 1.25, 1.00, 1.25, 1.50, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[FOURTH].push_back(createStudent("Harold Orbita", "20161140083", "orbita.harold@ue.edu.ph", FOURTH, {1.00, 1.00, 1.50, 1.50, 1.25, 1.25, 1.00, 1.25, 1.25, 1.25, 1.00}));
    studentsByYear[FOURTH].push_back(createStudent("Trisha Baylon", "20211132228", "baylon.trisha@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[FOURTH].push_back(createStudent("Junabel Payam", "20221131244", "payam.junabel@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[FOURTH].push_back(createStudent("Jasmine Rose Pajarillaga", "20221130354", "pajarillaga.jasminerose@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[FOURTH].push_back(createStudent("Ryl Cruz", "20221124626", "cruz.ryl@ue.edu.ph", FOURTH, {1.00, 1.50, 1.75, 1.50, 1.25, 1.25, 1.25, 1.00, 2.50, 1.00, 1.00}));

    // Add all students to allStudents vector
    for (const auto &year : {FIRST, SECOND, THIRD, FOURTH})
        for (const auto &student : studentsByYear[year])
            allStudents.push_back(student);

    // Sort and assign ranks for each year
    for (const auto &year : {FIRST, SECOND, THIRD, FOURTH}) {
        std::sort(studentsByYear[year].begin(), studentsByYear[year].end(), compareByGWA);
        for (size_t j = 0; j < studentsByYear[year].size(); ++j)
            studentsByYear[year][j].rank = j + 1;
    }

    // Display welcome banner
    displayWelcomeBanner();

    // Main interactive menu loop
    int choice = 0;
    while (choice != 7) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: addStudent(allStudents, studentsByYear); break;
        case 2: displayAllStudents(studentsByYear); break;
        case 3: searchStudent(allStudents); break;
        case 4: sortStudents(allStudents, studentsByYear); break;
        case 5: displayTopNStudents(studentsByYear); break;
        case 6: demonstrateBST(allStudents); break;
        case 7:
            std::cout << COLOR_MAGENTA << COLOR_BOLD << "\n╔════════════════════════════════════════════╗\n"
                      << "║  Thank you for using Student GWA System!  ║\n"
                      << "║              See you next time!           ║\n"
                      << "╚════════════════════════════════════════════╝\n" << COLOR_RESET;
            break;
        default:
            std::cout << COLOR_YELLOW << "\n⚠  Invalid choice! Please enter 1-7.\n" << COLOR_RESET;
        }
    }

    return 0;
}
