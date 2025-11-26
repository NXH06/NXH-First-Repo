// Task 10: Sort students by GPA descending

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

// Function to sort students by GPA in descending order
void sortStudentsByGPA(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].GPA < students[j].GPA) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to print the sorted student list
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
        {"S002", "Smith", "Jane", "1999-05-15", 78.0, 82.5, 80.0, 80.2},
        {"S003", "Brown", "Alice", "2001-03-22", 92.0, 88.5, 95.0, 91.8}
    };
    int n = 3;

    printf("Before sorting:\n");
    printStudents(students, n);

    sortStudentsByGPA(students, n);

    printf("\nAfter sorting by GPA (descending):\n");
    printStudents(students, n);

    return 0;
}
