
// task08_youngest.c
#include <stdio.h>
#include <string.h>
#include "task07_oldest.h"  // for dateToInt
#include "task08_youngest.h"

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
