// Task 9: Search student by ID

#include <stdio.h>
#include <string.h>

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

// Function to search for a student by ID
void searchStudentByID(Student students[], int n, char* targetID) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].studentID, targetID) == 0) {
            printf("Student found:\n");
            printf("%s\t%s %s\t%s\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",
                   students[i].studentID, students[i].lastName, students[i].firstName,
                   students[i].birthdate, students[i].algebra, students[i].calculus,
                   students[i].basicProg, students[i].GPA);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No student found with ID %s\n", targetID);
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

    char targetID[20];
    printf("Enter student ID to search: ");
    scanf("%s", targetID);

    searchStudentByID(students, n, targetID);

    return 0;
}
