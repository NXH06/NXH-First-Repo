
#include <stdio.h>
#include "student.h"
#include "task07_oldest.h"
#include "task08_youngest.h"

extern int inputStudentCount();
extern void inputStudents(Student[], int);
extern void printStudents(Student[], int);
extern void saveToFile(Student[], int, const char*);
extern void processGrades(Student[], int);
extern void printFirstNames(Student[], int);
extern void searchByID(Student[], int, char*);
extern void sortByGPA(Student[], int);

int main() {
    int n = inputStudentCount();
    Student students[MAX_STUDENTS];
    inputStudents(students, n);

    printStudents(students, n);
    saveToFile(students, n, "students.txt");
    processGrades(students, n);
    printFirstNames(students, n);

    char searchID[15];
    printf("Enter ID to search: ");
    scanf("%s", searchID);
    searchByID(students, n, searchID);

    sortByGPA(students, n);
    printf("\nSorted by GPA:\n");
    printStudents(students, n);

    findOldestStudent(students, n);
    findYoungestStudent(students, n);

    return 0;
}
