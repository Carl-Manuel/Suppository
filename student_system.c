#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define year levels as constants
#define FIRST  1
#define SECOND 2
#define THIRD  3
#define FOURTH 4

// Student structure
typedef struct {
    char name[100];
    char studentNo[20];
    char email[100];
    int yearLevel;
    double grades[15]; // Maximum subjects
    int numSubjects;
    double gwa;
    int rank;
} Student;

// Function to create a student
Student createStudent(const char* name, const char* studentNo, const char* email, int yearLevel, double grades[], int numSubjects) {
    Student s;
    strcpy(s.name, name);
    strcpy(s.studentNo, studentNo);
    strcpy(s.email, email);
    s.yearLevel = yearLevel;
    s.numSubjects = numSubjects;
    s.gwa = 0.0;
    s.rank = 0;

    double sum = 0.0;
    for (int i = 0; i < numSubjects; i++) {
        s.grades[i] = grades[i];
        sum += grades[i];
    }
    s.gwa = sum / numSubjects;

    return s;
}

// Function to compare students by GWA (for sorting)
int compareByGWA(const void* a, const void* b) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    if (s1->gwa < s2->gwa) return -1;
    if (s1->gwa > s2->gwa) return 1;
    return 0;
}

// Function to display students for a year level
void displayYearLevel(Student students[], int count, int yearLevel) {
    const char* yearNames[] = {"", "1st Year", "2nd Year", "3rd Year", "4th Year"};

    printf("\n=== %s Students ===\n", yearNames[yearLevel]);
    printf("Rank | Name                 | Student No   | Email                     | GWA    | Status\n");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        const char* status = (students[i].gwa <= 2.5) ? "Passed" : "Failed";
        printf("%-4d | %-20s | %-12s | %-25s | %-6.2f | %s\n",
               students[i].rank, students[i].name, students[i].studentNo,
               students[i].email, students[i].gwa, status);
    }
}

int main() {
    // Arrays to hold students for each year
    Student firstYear[20];
    Student secondYear[10];
    Student thirdYear[15];
    Student fourthYear[15];

    int firstCount = 0, secondCount = 0, thirdCount = 0, fourthCount = 0;

    // 1st Year Students (6 subjects)
    double grades1[] = {2.50, 2.00, 1.25, 1.25, 2.00, 1.75};
    firstYear[firstCount++] = createStudent("Zuriel Ethan Yambao", "20231128975", "yambao.zurielethan@ue.edu.ph", FIRST, grades1, 6);

    double grades2[] = {2.50, 2.00, 1.50, 1.25, 2.00, 1.75};
    firstYear[firstCount++] = createStudent("Lev Ryan Macalintal", "20131155389", "macalintal.levryan@ue.edu.ph", FIRST, grades2, 6);

    double grades3[] = {3.0, 2.25, 1.50, 1.50, 4, 1.75};
    firstYear[firstCount++] = createStudent("Axel Audrey Ignacio", "20231137748", "ignacio.axelaudrey@eu.edu.ph", FIRST, grades3, 6);

    double grades4[] = {2.75, 2.00, 1.75, 1.75, 2.00, 1.75};
    firstYear[firstCount++] = createStudent("Christian Arvy Pasion", "20251123225", "pasion.christianarvy@eu.edu.ph", FIRST, grades4, 6);

    double grades5[] = {2.75, 1.75, 1.25, 2.25, 2.00, 1.75};
    firstYear[firstCount++] = createStudent("Euken Rosario", "20251123861", "rosario.euken@eu.edu.ph", FIRST, grades5, 6);

    double grades6[] = {3.00, 1.75, 1.50, 1.25, 2.75, 1.75};
    firstYear[firstCount++] = createStudent("Toby Unciano", "20231101396", "unciano.toby@eu.edu.ph", FIRST, grades6, 6);

    double grades7[] = {2.75, 1.75, 1.25, 2.25, 3.00, 1.50};
    firstYear[firstCount++] = createStudent("Princess Roque", "20251120566", "roque.princessangeline@eu.edu.ph", FIRST, grades7, 6);

    double grades8[] = {3.00, 1.75, 1.25, 2.25, 3.00, 1.50};
    firstYear[firstCount++] = createStudent("Jophielle Gunabe", "20251131278", "gunabe.jophielle@eu.edu.ph", FIRST, grades8, 6);

    double grades9[] = {2.50, 2.00, 1.75, 2.00, 2.00, 1.75};
    firstYear[firstCount++] = createStudent("Emmanuel Patrick Acuna", "202311052112", "acuna.emmanuelpatrick@eu.edu.ph", FIRST, grades9, 6);

    double grades10[] = {2.50, 1.50, 1.25, 1.25, 1.75, 1.75};
    firstYear[firstCount++] = createStudent("Manuel Marquez", "20191132646", "marquez.manuelalexander@eu.edu.ph", FIRST, grades10, 6);

    double grades11[] = {2.00, 1.50, 2.00, 1.75, 2.25, 2.00};
    firstYear[firstCount++] = createStudent("Aaron Bernabe", "20251114564", "bernabe.marxaaron@eu.edu.ph", FIRST, grades11, 6);

    double grades12[] = {2.50, 2.00, 1.50, 1.50, 2.25, 1.75};
    firstYear[firstCount++] = createStudent("Eros Lamamigo", "2025113850", "lamamigo.erosmatthew@eu.edu.ph", FIRST, grades12, 6);

    double grades13[] = {1.75, 2.00, 1.75, 1.25, 1.75, 1.75};
    firstYear[firstCount++] = createStudent("Bryce Gabriel Abordo", "20251107412", "abordo.brycebengabriel@eu.edu.ph", FIRST, grades13, 6);

    double grades14[] = {2.25, 2.25, 1.50, 1.75, 1.75, 1.75};
    firstYear[firstCount++] = createStudent("Zionah Rae Javier", "20251121161", "javier.zionahrae@eu.edu.ph", FIRST, grades14, 6);

    double grades15[] = {1.25, 1.25, 1.00, 1.00, 1.00, 1.25};
    firstYear[firstCount++] = createStudent("Maxine Aliyah Alcazar", "20251123963", "alcazar.maxinealiyah@eu.edu.ph", FIRST, grades15, 6);

    double grades16[] = {2.50, 1.50, 1.25, 1.75, 1.25, 1.25};
    firstYear[firstCount++] = createStudent("Rhian Zyrelle Ramos", "20231123345", "ramos.rhjianzyrelle@eu.edu.ph", FIRST, grades16, 6);

    double grades17[] = {2.75, 2.50, 1.25, 1.50, 2.25, 1.25};
    firstYear[firstCount++] = createStudent("Sean Russel Cruz", "20251130106", "cruz.seanrussel@eu.edu.ph", FIRST, grades17, 6);

    double grades18[] = {2.50, 2.00, 2.25, 1.50, 2.75, 2.00};
    firstYear[firstCount++] = createStudent("Clayton Kelsey Grande", "20251104485", "grande.claytonkelsey@eu.edu.ph", FIRST, grades18, 6);

    // 2nd Year Students (9 subjects)
    double grades2nd1[] = {1.25, 1.00, 1.00, 1.25, 1.25, 1.50, 1.00, 1.50, 1.50};
    secondYear[secondCount++] = createStudent("Gwen Lopez", "20241130029", "gwengelynn@gmail.com", SECOND, grades2nd1, 9);

    double grades2nd2[] = {1.25, 1.00, 1.25, 1.50, 1.25, 1.75, 1.00, 1.50, 1.75};
    secondYear[secondCount++] = createStudent("Chang Park", "20181114136", "park.changhyun@ue.edu.ph", SECOND, grades2nd2, 9);

    double grades2nd3[] = {1.25, 1.25, 1.25, 1.25, 2.25, 2.00, 1.50, 1.25, 1.25};
    secondYear[secondCount++] = createStudent("Angela Tolentino", "202411245746", "tolentino.angela@eu.edu.ph", SECOND, grades2nd3, 9);

    double grades2nd4[] = {1.25, 1.25, 1.25, 1.25, 2.25, 2.00, 1.50, 1.25, 1.25};
    secondYear[secondCount++] = createStudent("Alexandrina Timbol", "20251120809", "timbol.alexandrina@eu.edu.ph", SECOND, grades2nd4, 9);

    // 3rd Year Students (10 subjects)
    double grades3rd1[] = {1.75, 1.25, 1.00, 1.75, 1.00, 1.50, 1.00, 1.25, 1.25, 1.00};
    thirdYear[thirdCount++] = createStudent("James Coco", "20231110057", "coco.james@ue.edu.ph", THIRD, grades3rd1, 10);

    double grades3rd2[] = {1.75, 1.50, 1.00, 1.75, 1.25, 1.75, 1.00, 1.25, 1.25, 1.50};
    thirdYear[thirdCount++] = createStudent("John Carlo Bauzon", "20231125874", "bauzon.johncarlo@ue.edu.ph", THIRD, grades3rd2, 10);

    double grades3rd3[] = {1.25, 1.50, 1.00, 1.50, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00};
    thirdYear[thirdCount++] = createStudent("Rhamuel Gamboa", "20231150122", "gamboa.rhamuel@ue.edu.ph", THIRD, grades3rd3, 10);

    double grades3rd4[] = {1.75, 1.25, 1.25, 1.50, 1.75, 1.75, 1.00, 1.25, 1.00, 1.00};
    thirdYear[thirdCount++] = createStudent("Ralph Daniel Bayona", "20231135618", "bayona.ralph@ue.edu.ph", THIRD, grades3rd4, 10);

    double grades3rd5[] = {2.5, 4.00, 3.00, 1.75, 1.25, 1.75, 1.25, 2.25, 1.00, 1.00};
    thirdYear[thirdCount++] = createStudent("Elija Brent Tarog", "20231127024", "tarog.elijabrent@ue.edu.ph", THIRD, grades3rd5, 10);

    double grades3rd6[] = {3.00, 1.75, 1.25, 1.75, 1.5, 1.75, 1.25, 3.00, 1.00, 1.00};
    thirdYear[thirdCount++] = createStudent("Timothy P. Villegas", "2023131990", "villegas.timothy@ue.edu.ph", THIRD, grades3rd6, 10);

    double grades3rd7[] = {1.5, 2.00, 1.00, 1.50, 1.75, 1.75, 1.00, 2.00, 1.00, 1.00};
    thirdYear[thirdCount++] = createStudent("Pharrell Morgan Basalo", "2023113924", "basalo.pharrellmorgan@ue.edu.ph", THIRD, grades3rd7, 10);

    double grades3rd8[] = {1.5, 1.25, 1.25, 1.75, 1.25, 1.5, 1.25, 1.00, 1.25, 1.5};
    thirdYear[thirdCount++] = createStudent("Marc Andrew Pitalo", "20231123083", "pitalo.marcandrew@ue.edu.ph", THIRD, grades3rd8, 10);

    double grades3rd9[] = {1.5, 1.25, 1.00, 1.25, 1.25, 1.00, 1.00, 2.00, 1.00, 1.5};
    thirdYear[thirdCount++] = createStudent("Hyryl Tibay", "2011135939", "tibay.hyryltibay@ue.edu.ph", THIRD, grades3rd9, 10);

    double grades3rd10[] = {1.25, 1.00, 1.00, 1.25, 1.00, 1.75, 1.25, 1.75, 1.25, 1.25};
    thirdYear[thirdCount++] = createStudent("Arto Francis Simbulan", "2023114933", "simbulan.artofrancis@ue.edu.ph", THIRD, grades3rd10, 10);

    // 4th Year Students (11 subjects)
    double grades4th1[] = {1.25, 1.50, 2.50, 1.75, 1.25, 1.75, 1.75, 1.50, 1.50, 2.00, 1.50};
    fourthYear[fourthCount++] = createStudent("Kurt Regala", "20221106190", "regala.kurt@ue.edu.ph", FOURTH, grades4th1, 11);

    double grades4th2[] = {1.00, 1.25, 1.75, 1.50, 1.00, 1.50, 1.50, 1.25, 1.50, 1.00, 1.50};
    fourthYear[fourthCount++] = createStudent("William Monzon", "20191110200", "monzon.william@ue.edu.ph", FOURTH, grades4th2, 11);

    double grades4th3[] = {1.00, 1.50, 1.25, 1.00, 1.25, 1.50, 1.25, 1.25, 1.75, 1.00, 1.50};
    fourthYear[fourthCount++] = createStudent("Liam Concepcion", "20221119159", "concepcion.liam@ue.edu.ph", FOURTH, grades4th3, 11);

    double grades4th4[] = {1.00, 1.25, 1.25, 1.50, 1.25, 1.50, 1.50, 1.00, 1.50, 1.00, 1.50};
    fourthYear[fourthCount++] = createStudent("Al Francis B. Buenaventura", "20201124961", "buenaventura.alfrancis@ue.edu.ph", FOURTH, grades4th4, 11);

    double grades4th5[] = {1.00, 1.00, 1.25, 1.50, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00};
    fourthYear[fourthCount++] = createStudent("Bryan G. Bernardino", "20221112410", "bernardino.bryan@ue.edu.ph", FOURTH, grades4th5, 11);

    double grades4th6[] = {1.00, 1.25, 1.25, 1.00, 1.25, 1.50, 1.00, 1.00, 1.00, 1.00, 1.00};
    fourthYear[fourthCount++] = createStudent("Ernest Dimaunahan", "20221117448", "dimaunahan.ernest@ue.edu.ph", FOURTH, grades4th6, 11);

    double grades4th7[] = {1.00, 1.00, 1.50, 1.50, 1.25, 1.25, 1.00, 1.25, 1.25, 1.25, 1.00};
    fourthYear[fourthCount++] = createStudent("Harold Orbita", "20161140083", "orbita.harold@ue.edu.ph", FOURTH, grades4th7, 11);

    double grades4th8[] = {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00};
    fourthYear[fourthCount++] = createStudent("Trisha Baylon", "20211132228", "baylon.trisha@ue.edu.ph", FOURTH, grades4th8, 11);

    double grades4th9[] = {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00};
    fourthYear[fourthCount++] = createStudent("Junabel Payam", "20221131244", "payam.junabel@ue.edu.ph", FOURTH, grades4th9, 11);

    double grades4th10[] = {1.00, 1.00, 1.25, 1.25, 1.00, 1.25, 1.00, 1.00, 1.00, 1.00, 1.00};
    fourthYear[fourthCount++] = createStudent("Jasmine Rose Pajarillaga", "20221130354", "pajarillaga.jasminerose@ue.edu.ph", FOURTH, grades4th10, 11);

    double grades4th11[] = {1.00, 1.50, 1.75, 1.50, 1.25, 1.25, 1.25, 1.00, 2.50, 1.00, 1.00};
    fourthYear[fourthCount++] = createStudent("Ryl Cruz", "20221124626", "cruz.ryl@ue.edu.ph", FOURTH, grades4th11, 11);

    // Sort and assign ranks for each year
    qsort(firstYear, firstCount, sizeof(Student), compareByGWA);
    qsort(secondYear, secondCount, sizeof(Student), compareByGWA);
    qsort(thirdYear, thirdCount, sizeof(Student), compareByGWA);
    qsort(fourthYear, fourthCount, sizeof(Student), compareByGWA);

    for (int i = 0; i < firstCount; i++) firstYear[i].rank = i + 1;
    for (int i = 0; i < secondCount; i++) secondYear[i].rank = i + 1;
    for (int i = 0; i < thirdCount; i++) thirdYear[i].rank = i + 1;
    for (int i = 0; i < fourthCount; i++) fourthYear[i].rank = i + 1;

    // Display results for each year
    displayYearLevel(firstYear, firstCount, FIRST);
    displayYearLevel(secondYear, secondCount, SECOND);
    displayYearLevel(thirdYear, thirdCount, THIRD);
    displayYearLevel(fourthYear, fourthCount, FOURTH);

    return 0;
}