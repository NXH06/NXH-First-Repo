// Task 7: Find the oldest student
#include <stdio.h>
#include <string.h>
#include "student.h"

// Helper function to convert date from DD/MM/YYYY to YYYYMMDD
int dateToInt(const char *date) {
    int d, m, y;
    sscanf(date, "%d/%d/%d", &d, &m, &y);
    return y * 10000 + m * 100 + d;
}

void findOldestStudent(Student students[], int n) {
    int oldest = 0;
    for (int i = 1; i < n; i++) {
        if (dateToInt(students[i].birthdate) < dateToInt(students[oldest].birthdate)) {
            oldest = i;
        }
    }
    printf("Oldest Student: %s %s, ID: %s, Birthdate: %s\n",
           students[oldest].lastName, students[oldest].firstName,
           students[oldest].studentID, students[oldest].birthdate);
}
