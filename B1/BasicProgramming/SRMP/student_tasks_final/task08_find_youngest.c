// Task 8: Find the youngest student
#include <stdio.h>
#include <string.h>
#include "student.h"

int dateToInt(const char *date); // Declaration from task 7

void findYoungestStudent(Student students[], int n) {
    int youngest = 0;
    for (int i = 1; i < n; i++) {
        if (dateToInt(students[i].birthdate) > dateToInt(students[youngest].birthdate)) {
            youngest = i;
        }
    }
    printf("Youngest Student: %s %s, ID: %s, Birthdate: %s\n",
           students[youngest].lastName, students[youngest].firstName,
           students[youngest].studentID, students[youngest].birthdate);
}
