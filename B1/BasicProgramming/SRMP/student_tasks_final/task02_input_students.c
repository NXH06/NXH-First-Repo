
// Task 2: Enter students’ information
#include <stdio.h>
#include "student.h"

void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter info for student %d:\n", i + 1);
        printf("ID: "); scanf("%s", students[i].studentID);
        printf("First name: "); scanf("%s", students[i].firstName);
        printf("Last name: "); scanf("%s", students[i].lastName);
        printf("Birthdate (DD/MM/YYYY): "); scanf("%s", students[i].birthdate);
        printf("Algebra: "); scanf("%f", &students[i].algebra);
        printf("Calculus: "); scanf("%f", &students[i].calculus);
        printf("Basic Programming: "); scanf("%f", &students[i].basicProg);
        students[i].GPA = (students[i].algebra + students[i].calculus + students[i].basicProg) / 3.0;
    }
}
