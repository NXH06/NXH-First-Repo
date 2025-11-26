// Task 6: Print student first names

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

// Function to print student first names
void printFirstNames(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("First name of student %s: %s\n", students[i].studentID, students[i].firstName);
    }
}

// Example usage
int main() {
    Student students[] = {
        {"S001", "Doe", "John", "2000-01-01", 85.5, 90.0, 88.0, 87.8},
        {"S002", "Smith", "Jane", "1999-05-15", 78.0, 82.5, 80.0, 80.2},
        {"S003", "Brown", "Alice", "2001-03-22", 92.0, 88.5, 95.0, 91.8}
    };
    int n = 3;

    printFirstNames(students, n);

    return 0;
}
