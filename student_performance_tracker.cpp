#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

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

// Function to sort students by GWA ascending
bool compareByGWA(const Student &a, const Student &b)
{
    return a.gwa < b.gwa;
}

// Function to display results for a year level
void displayYearLevel(const std::vector<Student> &students, YearLevel year)
{
    if (students.empty())
        return;

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

int main()
{
    std::vector<Student> allStudents;
    std::vector<std::vector<Student>> studentsByYear(5); // Index 1-4 for years

    // ===== INPUT STUDENT DATA HERE =====
    // Add your student data below. Format: createStudent("Name", "StudentNumber", "Email", YEAR_LEVEL, {grade1, grade2, ...})

    // 1st Year Students (6 subjects)
    studentsByYear[1].push_back(createStudent("Zuriel Ethan Yambao", "20231128975", "yambao.zurielethan@ue.edu.ph", FIRST, {2.50, 2.00, 1.25, 1.25, 2.00, 1.75}));
    studentsByYear[1].push_back(createStudent("Lev Ryan Macalintal", "20131155389", "macalintal.levryan@ue.edu.ph", FIRST, {2.50, 2.00, 1.50, 1.25, 2.00, 1.75}));
    studentsByYear[1].push_back(createStudent("Axel Audrey Ignacio", "20231137748", "ignacio.axelaudrey@eu.edu.ph", FIRST, {3.0, 2.25, 1.50, 1.50, 4, 1.75}));
    studentsByYear[1].push_back(createStudent("Christian Arvy Pasion", "20251123225", "pasion.christianarvy@eu.edu.ph", FIRST, {2.75, 2.00, 1.75, 1.75, 2.00, 1.75}));
    studentsByYear[1].push_back(createStudent("Euken Rosario", "20251123861", "rosario.euken@eu.edu.ph", FIRST, {2.75, 1.75, 1.25, 2.25, 2.00, 1.75}));
    studentsByYear[1].push_back(createStudent("Toby Unciano", "20231101396", "unciano.toby@eu.edu.ph", FIRST, {3.00, 1.75, 1.50, 1.25, 2.75, 1.75}));
    studentsByYear[1].push_back(createStudent("Princess Roque", "20251120566", "roque.princessangeline@eu.edu.ph", FIRST, {2.75, 1.75, 1.25, 2.25, 3.00, 1.50}));
    studentsByYear[1].push_back(createStudent("Jophielle Gunabe", "20251131278", "gunabe.jophielle@eu.edu.ph", FIRST, {3.00, 1.75, 1.25, 2.25, 3.00, 1.50}));
    studentsByYear[1].push_back(createStudent("Emmanuel Patrick Acuna", "202311052112", "acuna.emmanuelpatrick@eu.edu.ph", FIRST, {2.50, 2.00, 1.75, 2.00, 2.00, 1.75}));
    studentsByYear[1].push_back(createStudent("Manuel Marquez", "20191132646", "marquez.manuelalexander@eu.edu.ph", FIRST, {2.50, 1.50, 1.25, 1.25, 1.75, 1.75}));
    studentsByYear[1].push_back(createStudent("Aaron Bernabe", "20251114564", "bernabe.marxaaron@eu.edu.ph", FIRST, {2.00, 1.50, 2.00, 1.75, 2.25, 2.00}));
    studentsByYear[1].push_back(createStudent("Eros Lamamigo", "2025113850", "lamamigo.erosmatthew@eu.edu.ph", FIRST, {2.50, 2.00, 1.50, 1.50, 2.25, 1.75}));
    studentsByYear[1].push_back(createStudent("Bryce Gabriel Abordo", "20251107412", "abordo.brycebengabriel@eu.edu.ph", FIRST, {1.75, 2.00, 1.75, 1.25, 1.75, 1.75}));
    studentsByYear[1].push_back(createStudent("Zionah Rae Javier", "20251121161", "javier.zionahrae@eu.edu.ph", FIRST, {2.25, 2.25, 1.50, 1.75, 1.75, 1.75}));
    studentsByYear[1].push_back(createStudent("Maxine Aliyah Alcazar", "20251123963", "alcazar.maxinealiyah@eu.edu.ph", FIRST, {1.25, 1.25, 1.00, 1.00, 1.00, 1.25}));
    studentsByYear[1].push_back(createStudent("Rhian Zyrelle Ramos", "20231123345", "ramos.rhjianzyrelle@eu.edu.ph", FIRST, {2.50, 1.50, 1.25, 1.75, 1.25, 1.25}));
    studentsByYear[1].push_back(createStudent("Sean Russel Cruz", "20251130106", "cruz.seanrussel@eu.edu.ph", FIRST, {2.75, 2.50, 1.25, 1.50, 2.25, 1.25}));
    studentsByYear[1].push_back(createStudent("Clayton Kelsey Grande", "20251104485", "grande.claytonkelsey@eu.edu.ph", FIRST, {2.50, 2.00, 2.25, 1.50, 2.75, 2.00}));
    // Add more 1st year students here if needed

    // 2nd Year Students (9 subjects)
    studentsByYear[2].push_back(createStudent("Gwen Lopez", "20241130029", "gwengelynn@gmail.com", SECOND, {1.25, 1.00, 1.00, 1.25, 1.25, 1.50, 1.00, 1.50, 1.50}));
    studentsByYear[2].push_back(createStudent("Chang Park", "20181114136", "park.changhyun@ue.edu.ph", SECOND, {1.25, 1.00, 1.25, 1.50, 1.25, 1.75, 1.00, 1.50, 1.75}));
    studentsByYear[2].push_back(createStudent("Angela Tolentino", "202411245746", "tolentino.angela@eu.edu.ph", SECOND, {1.25, 1.00, 1.00, 1.50, 1.25, 1.75, 1.00, 1.25, 1.25}));
    studentsByYear[2].push_back(createStudent("Alexandrina Timbol", "20251120809", "timbol.alexandrina@eu.edu.ph", SECOND, {1.25, 1.25, 1.25, 1.25, 2.25, 2.00, 1.50, 1.25, 1.25}));
    // Add more 2nd year students here if needed

    // 3rd Year Students (10 subjects)
    studentsByYear[3].push_back(createStudent("James Coco", "20231110057", "coco.james@ue.edu.ph", THIRD, {1.75, 1.25, 1.00, 1.75, 1.00, 1.50, 1.00, 1.25, 1.25, 1.00}));
    studentsByYear[3].push_back(createStudent("John Carlo Bauzon", "20231125874", "bauzon.johncarlo@ue.edu.ph", THIRD, {1.75, 1.50, 1.00, 1.75, 1.25, 1.75, 1.00, 1.25, 1.25, 1.50}));
    studentsByYear[3].push_back(createStudent("Rhamuel Gamboa", "20231150122", "gamboa.rhamuel@ue.edu.ph", THIRD, {1.25, 1.50, 1.00, 1.50, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00}));
    studentsByYear[3].push_back(createStudent("Ralph Daniel Bayona", "20231135618", "bayona.ralph@ue.edu.ph", THIRD, {1.75, 1.25, 1.25, 1.50, 1.75, 1.75, 1.00, 1.25, 1.00, 1.00}));
    studentsByYear[3].push_back(createStudent("Elija Brent Tarog", "20231127024", "tarog.elijabrent@ue.edu.ph", THIRD, {2.5, 4.00, 3.00, 1.75, 1.25, 1.75, 1.25, 2.25, 1.00, 1.00}));
    studentsByYear[3].push_back(createStudent("Timothy P. Villegas", "2023131990", "villegas.timothy@ue.edu.ph", THIRD, {3.00, 1.75, 1.25, 1.75, 1.5, 1.75, 1.25, 3.00, 1.00, 1.00}));
    studentsByYear[3].push_back(createStudent("Pharrell Morgan Basalo", "2023113924", "basalo.pharrellmorgan@ue.edu.ph", THIRD, {1.5, 2.00, 1.00, 1.50, 1.75, 1.75, 1.00, 2.00, 1.00, 1.00}));
    studentsByYear[3].push_back(createStudent("Marc Andrew Pitalo", "20231123083", "pitalo.marcandrew@ue.edu.ph", THIRD, {1.5, 1.25, 1.25, 1.75, 1.25, 1.5, 1.25, 1.00, 1.25, 1.5}));
    studentsByYear[3].push_back(createStudent("Hyryl Tibay", "2011135939", "tibay.hyryltibay@ue.edu.ph", THIRD, {1.5, 1.25, 1.00, 1.25, 1.25, 1.00, 1.00, 2.00, 1.00, 1.5}));
    studentsByYear[3].push_back(createStudent("Arto Francis Simbulan", "2023114933", "simbulan.artofrancis@ue.edu.ph", THIRD, {1.25, 1.00, 1.00, 1.25, 1.00, 1.75, 1.25, 1.75, 1.25, 1.25}));
    // 4th Year Students (11 subjects)
    studentsByYear[4].push_back(createStudent("Kurt Regala", "20221106190", "regala.kurt@ue.edu.ph", FOURTH, {1.25, 1.50, 2.50, 1.75, 1.25, 1.75, 1.75, 1.50, 1.50, 2.00, 1.50}));
    studentsByYear[4].push_back(createStudent("William Monzon", "20191110200", "monzon.william@ue.edu.ph", FOURTH, {1.00, 1.25, 1.75, 1.50, 1.00, 1.50, 1.50, 1.25, 1.50, 1.00, 1.50}));
    studentsByYear[4].push_back(createStudent("Liam Concepcion", "20221119159", "concepcion.liam@ue.edu.ph", FOURTH, {1.00, 1.50, 1.25, 1.00, 1.25, 1.50, 1.25, 1.25, 1.75, 1.00, 1.50}));
    studentsByYear[4].push_back(createStudent("Al Francis B. Buenaventura", "20201124961", "buenaventura.alfrancis@ue.edu.ph", FOURTH, {1.00, 1.25, 1.25, 1.50, 1.25, 1.50, 1.50, 1.00, 1.50, 1.00, 1.50}));
    studentsByYear[4].push_back(createStudent("Bryan G. Bernardino", "20221112410", "bernardino.bryan@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.50, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[4].push_back(createStudent("Ernest Dimaunahan", "20221117448", "dimaunahan.ernest@ue.edu.ph", FOURTH, {1.00, 1.25, 1.25, 1.00, 1.25, 1.50, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[4].push_back(createStudent("Harold Orbita", "20161140083", "orbita.harold@ue.edu.ph", FOURTH, {1.00, 1.00, 1.50, 1.50, 1.25, 1.25, 1.00, 1.25, 1.25, 1.25, 1.00}));
    studentsByYear[4].push_back(createStudent("Trisha Baylon", "20211132228", "baylon.trisha@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[4].push_back(createStudent("Junabel Payam", "20221131244", "payam.junabel@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[4].push_back(createStudent("Jasmine Rose Pajarillaga", "20221130354", "pajarillaga.jasminerose@ue.edu.ph", FOURTH, {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00}));
    studentsByYear[4].push_back(createStudent("Ryl Cruz", "20221124626", "cruz.ryl@ue.edu.ph", FOURTH, {1.00, 1.50, 1.75, 1.50, 1.25, 1.25, 1.25, 1.00, 2.50, 1.00, 1.00}));

    // ===== END OF STUDENT DATA INPUT =====

    // Add all students to allStudents vector
    for (int i = 1; i <= 4; ++i)
    {
        for (const auto &student : studentsByYear[i])
        {
            allStudents.push_back(student);
        }
    }

    // Sort and assign ranks for each year
    for (int i = 1; i <= 4; ++i)
    {
        std::sort(studentsByYear[i].begin(), studentsByYear[i].end(), compareByGWA);
        for (size_t j = 0; j < studentsByYear[i].size(); ++j)
        {
            studentsByYear[i][j].rank = j + 1;
        }
    }

    // Display results for each year
    for (int i = 1; i <= 4; ++i)
    {
        displayYearLevel(studentsByYear[i], static_cast<YearLevel>(i));
    }

    return 0;
}