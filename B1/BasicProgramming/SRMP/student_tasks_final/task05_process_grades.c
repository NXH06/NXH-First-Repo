// Task 5: Process grades (highest GPA, lowest GPA, highest BP)

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

// Function to process grades and print results
void processGrades(Student students[], int n) {
    int maxGPA = 0, minGPA = 0, maxBP = 0;

    for (int i = 1; i < n; i++) {
        if (students[i].GPA > students[maxGPA].GPA) maxGPA = i;
        if (students[i].GPA < students[minGPA].GPA) minGPA = i;
        if (students[i].basicProg > students[maxBP].basicProg) maxBP = i;
    }

    printf("Highest GPA: %s (%.2f)\n", students[maxGPA].studentID, students[maxGPA].GPA);
    printf("Lowest GPA: %s (%.2f)\n", students[minGPA].studentID, students[minGPA].GPA);
    printf("Highest Basic Programming Grade: %s (%.2f)\n", students[maxBP].studentID, students[maxBP].basicProg);
}

// Example usage
int main() {
    Student students[] = {
        {"S001", "Doe", "John", "2000-01-01", 85.5, 90.0, 88.0, 87.8},
        {"S002", "Smith", "Jane", "1999-05-15", 78.0, 82.5, 80.0, 80.2},
        {"S003", "Brown", "Alice", "2001-03-22", 92.0, 88.5, 95.0, 91.8}
    };
    int n = 3;

    processGrades(students, n);

    return 0;
}
