#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 1000

typedef struct {
    char studentID[15];
    char firstName[30];
    char lastName[30];
    char birthdate[11];
    float algebra;
    float calculus;
    float basicProg;
    float GPA;
} Student;

void printStudents(Student students[], int n);
void saveToFile(Student students[], int n, const char* filename);
void processGrades(Student students[], int n);
void printFirstNames(Student students[], int n);
void searchByID(Student students[], int n, char* targetID);
void sortByGPA(Student students[], int n);


void findOldestStudent(Student students[], int n);
void findYoungestStudent(Student students[], int n);
#endif
