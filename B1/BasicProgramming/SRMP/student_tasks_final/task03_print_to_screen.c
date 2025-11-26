// Task 3: Print student list to screen

#include <stdio.h>

// Define the Student structure
typedef struct {
    char studentID[20];
    char lastName[50];
    char firstName[50];
    char birthdate[15];
    float algebra;
    float calculus;
    float basicProg;
    float GPA;
} Student;

// Function to print student list
void printStudents(Student students[], int n) {
    printf("ID\tName\t\tBirthdate\tAlgebra\tCalculus\tBasicProg\tGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s %s\t%s\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",
               students[i].studentID, students[i].lastName, students[i].firstName,
               students[i].birthdate, students[i].algebra, students[i].calculus,
               students[i].basicProg, students[i].GPA);
    }
}

// Example usage
int main() {
    Student students[] = {
        {"S001", "Doe", "John", "2000-01-01", 85.5, 90.0, 88.0, 87.8},
        {"S002", "Smith", "Jane", "1999-05-15", 78.0, 82.5, 80.0, 80.2}
    };
    int n = 2;

    printStudents(students, n);

    return 0;
}
