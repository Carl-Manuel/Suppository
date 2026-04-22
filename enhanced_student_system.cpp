#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>

// Enum for year levels
enum YearLevel
{
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4
};

// Struct to represent a student
struct Student
{
    std::string name;
    std::string studentNumber;
    std::string email;
    YearLevel yearLevel;
    std::vector<double> grades;
    double gwa;
    std::string status;
    int rank;
};

// Binary Search Tree Node
struct BSTNode
{
    Student data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Student s) : data(s), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST
{
private:
    BSTNode* root;
    bool compareByGWA;

    void insertHelper(BSTNode*& node, Student student)
    {
        if (node == nullptr)
        {
            node = new BSTNode(student);
            return;
        }

        if (compareByGWA)
        {
            if (student.gwa < node->data.gwa)
                insertHelper(node->left, student);
            else
                insertHelper(node->right, student);
        }
        else
        {
            if (student.name < node->data.name)
                insertHelper(node->left, student);
            else
                insertHelper(node->right, student);
        }
    }

    void inOrderTraversal(BSTNode* node, std::vector<Student>& result)
    {
        if (node == nullptr) return;
        inOrderTraversal(node->left, result);
        result.push_back(node->data);
        inOrderTraversal(node->right, result);
    }

    void destroyTree(BSTNode* node)
    {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BST(bool byGWA = true) : root(nullptr), compareByGWA(byGWA) {}
    ~BST() { destroyTree(root); }

    void insert(Student student) { insertHelper(root, student); }
    std::vector<Student> getSortedList()
    {
        std::vector<Student> result;
        inOrderTraversal(root, result);
        return result;
    }
    void clear() { destroyTree(root); root = nullptr; }
};

// Function to get number of subjects based on year level
int getNumSubjects(YearLevel year)
{
    switch (year)
    {
    case FIRST:
        return 6;
    case SECOND:
        return 9;
    case THIRD:
        return 10;
    case FOURTH:
        return 11;
    default:
        return 0;
    }
}

// Function to get year level string
std::string getYearString(YearLevel year)
{
    switch (year)
    {
    case FIRST:
        return "1st Year";
    case SECOND:
        return "2nd Year";
    case THIRD:
        return "3rd Year";
    case FOURTH:
        return "4th Year";
    default:
        return "";
    }
}

// Function to compute GWA and status
void computeGWA(Student &student)
{
    double sum = 0.0;
    for (double grade : student.grades)
    {
        sum += grade;
    }
    student.gwa = sum / student.grades.size();
    student.status = (student.gwa <= 4.0) ? "Passed" : "Failed";
}

// Function to create a student with given data
Student createStudent(std::string name, std::string studentNumber, std::string email, YearLevel year, std::vector<double> grades)
{
    Student student;
    student.name = name;
    student.studentNumber = studentNumber;
    student.email = email;
    student.yearLevel = year;
    student.grades = grades;
    computeGWA(student);
    return student;
}

// Bubble Sort implementation
void bubbleSort(std::vector<Student>& students, bool byGWA = true)
{
    int n = students.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            bool shouldSwap = byGWA ? (students[j].gwa > students[j + 1].gwa) :
                                      (students[j].name > students[j + 1].name);
            if (shouldSwap)
            {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(std::vector<Student>& students, bool byGWA = true)
{
    int n = students.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            bool isSmaller = byGWA ? (students[j].gwa < students[minIndex].gwa) :
                                     (students[j].name < students[minIndex].name);
            if (isSmaller)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(students[i], students[minIndex]);
        }
    }
}

// Linear Search implementation
int linearSearch(const std::vector<Student>& students, const std::string& target, bool searchByName = true)
{
    for (size_t i = 0; i < students.size(); ++i)
    {
        if (searchByName)
        {
            if (students[i].name == target) return i;
        }
        else
        {
            if (students[i].studentNumber == target) return i;
        }
    }
    return -1;
}

// Binary Search implementation (assumes sorted by student number)
int binarySearch(const std::vector<Student>& students, const std::string& targetStudentNumber)
{
    int left = 0;
    int right = students.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (students[mid].studentNumber == targetStudentNumber)
        {
            return mid;
        }
        else if (students[mid].studentNumber < targetStudentNumber)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

// Function to sort students by GWA ascending
bool compareByGWA(const Student &a, const Student &b)
{
    return a.gwa < b.gwa;
}

// Function to sort students by name
bool compareByName(const Student &a, const Student &b)
{
    return a.name < b.name;
}

// Function to sort students by student number
bool compareByStudentNumber(const Student &a, const Student &b)
{
    return a.studentNumber < b.studentNumber;
}

// Function to get valid year level input
YearLevel getYearLevelInput()
{
    int year;
    while (true)
    {
        std::cout << "Enter year level (1-4): ";
        std::cin >> year;
        if (std::cin.fail() || year < 1 || year > 4)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1, 2, 3, or 4.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return static_cast<YearLevel>(year);
        }
    }
}

// Function to get grades input
std::vector<double> getGradesInput(int numSubjects)
{
    std::vector<double> grades;
    std::cout << "Enter " << numSubjects << " grades (separated by spaces): ";
    for (int i = 0; i < numSubjects; ++i)
    {
        double grade;
        std::cin >> grade;
        grades.push_back(grade);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return grades;
}

// Function to add a new student
void addStudent(std::vector<Student>& allStudents, std::map<YearLevel, std::vector<Student>>& studentsByYear)
{
    std::string name, studentNumber, email;
    YearLevel yearLevel;

    std::cout << "\n=== Add New Student ===\n";
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    std::cout << "Enter student number: ";
    std::getline(std::cin, studentNumber);

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    yearLevel = getYearLevelInput();

    int numSubjects = getNumSubjects(yearLevel);
    std::vector<double> grades = getGradesInput(numSubjects);

    Student newStudent = createStudent(name, studentNumber, email, yearLevel, grades);
    allStudents.push_back(newStudent);
    studentsByYear[yearLevel].push_back(newStudent);

    std::cout << "Student added successfully!\n";
}

// Function to display results for a year level
void displayYearLevel(const std::vector<Student> &students, YearLevel year)
{
    if (students.empty())
    {
        std::cout << "\nNo students in " << getYearString(year) << ".\n";
        return;
    }

    std::cout << "\n=== " << getYearString(year) << " Students ===\n";
    std::cout << std::left << std::setw(4) << "Rank" << " | "
              << std::setw(20) << "Name" << " | "
              << std::setw(12) << "Student No" << " | "
              << std::setw(25) << "Email" << " | "
              << std::setw(6) << "GWA" << " | "
              << "Status\n";
    std::cout << std::string(80, '-') << "\n";

    for (const auto &student : students)
    {
        std::cout << std::left << std::setw(4) << student.rank << " | "
                  << std::setw(20) << student.name << " | "
                  << std::setw(12) << student.studentNumber << " | "
                  << std::setw(25) << student.email << " | "
                  << std::fixed << std::setprecision(2) << std::setw(6) << student.gwa << " | "
                  << student.status << "\n";
    }
}

// Function to display all students grouped by year
void displayAllStudents(const std::map<YearLevel, std::vector<Student>>& studentsByYear)
{
    for (int i = 1; i <= 4; ++i)
    {
        YearLevel year = static_cast<YearLevel>(i);
        auto it = studentsByYear.find(year);
        if (it != studentsByYear.end())
        {
            displayYearLevel(it->second, year);
        }
    }
}

// Function to search student
void searchStudent(const std::vector<Student>& allStudents)
{
    int choice;
    std::cout << "\n=== Search Student ===\n";
    std::cout << "1. Search by Name (Linear Search)\n";
    std::cout << "2. Search by Student Number (Binary Search)\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 1)
    {
        std::string name;
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);
        int index = linearSearch(allStudents, name, true);
        if (index != -1)
        {
            std::cout << "\nStudent found:\n";
            std::cout << "Name: " << allStudents[index].name << "\n";
            std::cout << "Student Number: " << allStudents[index].studentNumber << "\n";
            std::cout << "Email: " << allStudents[index].email << "\n";
            std::cout << "Year Level: " << getYearString(allStudents[index].yearLevel) << "\n";
            std::cout << "GWA: " << std::fixed << std::setprecision(2) << allStudents[index].gwa << "\n";
            std::cout << "Status: " << allStudents[index].status << "\n";
        }
        else
        {
            std::cout << "Student not found.\n";
        }
    }
    else if (choice == 2)
    {
        // Sort by student number for binary search
        std::vector<Student> sortedStudents = allStudents;
        std::sort(sortedStudents.begin(), sortedStudents.end(), compareByStudentNumber);

        std::string studentNumber;
        std::cout << "Enter student number: ";
        std::getline(std::cin, studentNumber);
        int index = binarySearch(sortedStudents, studentNumber);
        if (index != -1)
        {
            std::cout << "\nStudent found:\n";
            std::cout << "Name: " << sortedStudents[index].name << "\n";
            std::cout << "Student Number: " << sortedStudents[index].studentNumber << "\n";
            std::cout << "Email: " << sortedStudents[index].email << "\n";
            std::cout << "Year Level: " << getYearString(sortedStudents[index].yearLevel) << "\n";
            std::cout << "GWA: " << std::fixed << std::setprecision(2) << sortedStudents[index].gwa << "\n";
            std::cout << "Status: " << sortedStudents[index].status << "\n";
        }
        else
        {
            std::cout << "Student not found.\n";
        }
    }
    else
    {
        std::cout << "Invalid choice.\n";
    }
}

// Function to sort students
void sortStudents(std::vector<Student>& allStudents, std::map<YearLevel, std::vector<Student>>& studentsByYear)
{
    int choice;
    std::cout << "\n=== Sort Students ===\n";
    std::cout << "1. Sort by GWA (Bubble Sort)\n";
    std::cout << "2. Sort by Name (Selection Sort)\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 1)
    {
        bubbleSort(allStudents, true);
        std::cout << "Students sorted by GWA using Bubble Sort.\n";
    }
    else if (choice == 2)
    {
        selectionSort(allStudents, false);
        std::cout << "Students sorted by Name using Selection Sort.\n";
    }
    else
    {
        std::cout << "Invalid choice.\n";
        return;
    }

    // Update rankings for each year
    for (auto& pair : studentsByYear)
    {
        std::sort(pair.second.begin(), pair.second.end(), compareByGWA);
        for (size_t j = 0; j < pair.second.size(); ++j)
        {
            pair.second[j].rank = j + 1;
        }
    }
}

// Function to display top N students per year
void displayTopNStudents(const std::map<YearLevel, std::vector<Student>>& studentsByYear)
{
    int n;
    std::cout << "\n=== Display Top N Students per Year ===\n";
    std::cout << "Enter N: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 1; i <= 4; ++i)
    {
        YearLevel year = static_cast<YearLevel>(i);
        auto it = studentsByYear.find(year);
        if (it != studentsByYear.end() && !it->second.empty())
        {
            std::vector<Student> topStudents;
            int count = std::min(n, static_cast<int>(it->second.size()));
            for (int j = 0; j < count; ++j)
            {
                topStudents.push_back(it->second[j]);
            }
            displayYearLevel(topStudents, year);
        }
    }
}

// Function to demonstrate BST
void demonstrateBST(const std::vector<Student>& allStudents)
{
    if (allStudents.empty())
    {
        std::cout << "No students to demonstrate BST.\n";
        return;
    }

    int choice;
    std::cout << "\n=== BST Demonstration ===\n";
    std::cout << "1. Sort by GWA using BST\n";
    std::cout << "2. Sort by Name using BST\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    BST bst(choice == 1);
    for (const auto& student : allStudents)
    {
        bst.insert(student);
    }

    std::vector<Student> sortedStudents = bst.getSortedList();

    std::cout << "\nStudents sorted using BST:\n";
    std::cout << std::left << std::setw(20) << "Name" << " | "
              << std::setw(12) << "Student No" << " | "
              << std::setw(6) << "GWA" << "\n";
    std::cout << std::string(45, '-') << "\n";

    for (const auto& student : sortedStudents)
    {
        std::cout << std::left << std::setw(20) << student.name << " | "
                  << std::setw(12) << student.studentNumber << " | "
                  << std::fixed << std::setprecision(2) << std::setw(6) << student.gwa << "\n";
    }
}

// Function to display menu
void displayMenu()
{
    std::cout << "\n=== Student GWA Ranking System ===\n";
    std::cout << "1. Add New Student\n";
    std::cout << "2. Display All Students (Grouped by Year Level)\n";
    std::cout << "3. Search Student\n";
    std::cout << "4. Sort Students\n";
    std::cout << "5. Display Top N Students per Year\n";
    std::cout << "6. Demonstrate BST\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    std::vector<Student> allStudents;
    std::map<YearLevel, std::vector<Student>> studentsByYear;

    // Initialize with some sample data
    // 1st Year Students (6 subjects)
    studentsByYear[FIRST].push_back(createStudent("Zuriel Ethan Yambao", "20231128975", "yambao.zurielethan@ue.edu.ph", FIRST, {2.50, 2.00, 1.25, 1.25, 2.00, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Lev Ryan Macalintal", "20131155389", "macalintal.levryan@ue.edu.ph", FIRST, {2.50, 2.00, 1.50, 1.25, 2.00, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Axel Audrey Ignacio", "20231137748", "ignacio.axelaudrey@eu.edu.ph", FIRST, {3.0, 2.25, 1.50, 1.50, 4, 1.75}));
    studentsByYear[FIRST].push_back(createStudent("Christian Arvy Pasion", "20251123225", "pasion.christianarvy@eu.edu.ph", FIRST, {2.75, 2.00, 1.75, 1.75, 2.00, 1.75}));

    // 2nd Year Students (9 subjects)
    studentsByYear[SECOND].push_back(createStudent("Gwen Lopez", "20241130029", "gwengelynn@gmail.com", SECOND, {1.25, 1.00, 1.00, 1.25, 1.25, 1.50, 1.00, 1.50, 1.50}));
    studentsByYear[SECOND].push_back(createStudent("Chang Park", "20181114136", "park.changhyun@ue.edu.ph", SECOND, {1.25, 1.00, 1.25, 1.50, 1.25, 1.75, 1.00, 1.50, 1.75}));

    // 3rd Year Students (10 subjects)
    studentsByYear[THIRD].push_back(createStudent("James Coco", "20231110057", "coco.james@ue.edu.ph", THIRD, {1.75, 1.25, 1.00, 1.75, 1.00, 1.50, 1.00, 1.25, 1.25, 1.00}));
    studentsByYear[THIRD].push_back(createStudent("John Carlo Bauzon", "20231125874", "bauzon.johncarlo@ue.edu.ph", THIRD, {1.75, 1.50, 1.00, 1.75, 1.25, 1.75, 1.00, 1.25, 1.25, 1.50}));

    // 4th Year Students (11 subjects)
    studentsByYear[FOURTH].push_back(createStudent("Kurt Regala", "20221106190", "regala.kurt@ue.edu.ph", FOURTH, {1.25, 1.50, 2.50, 1.75, 1.25, 1.75, 1.75, 1.50, 1.50, 2.00, 1.50}));
    studentsByYear[FOURTH].push_back(createStudent("William Monzon", "20191110200", "monzon.william@ue.edu.ph", FOURTH, {1.00, 1.25, 1.75, 1.50, 1.00, 1.50, 1.50, 1.25, 1.50, 1.00, 1.50}));

    // Add all students to allStudents vector
    for (const auto& pair : studentsByYear)
    {
        for (const auto& student : pair.second)
        {
            allStudents.push_back(student);
        }
    }

    // Sort and assign ranks for each year
    for (auto& pair : studentsByYear)
    {
        std::sort(pair.second.begin(), pair.second.end(), compareByGWA);
        for (size_t j = 0; j < pair.second.size(); ++j)
        {
            pair.second[j].rank = j + 1;
        }
    }

    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addStudent(allStudents, studentsByYear);
            break;
        case 2:
            displayAllStudents(studentsByYear);
            break;
        case 3:
            searchStudent(allStudents);
            break;
        case 4:
            sortStudents(allStudents, studentsByYear);
            break;
        case 5:
            displayTopNStudents(studentsByYear);
            break;
        case 6:
            demonstrateBST(allStudents);
            break;
        case 7:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}