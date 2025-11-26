#ifndef STUDENT_H
#define STUDENT_H

// define Student structure
typedef struct {
   char ID[20];
   char lname[30];
   char fname[30];
   int day;
   int month;
   int year;
   float scoreA;
   float scoreC;
   float scoreBP;
   float GPA;
} Student;

int studentamt();
void studentinfo(Student students[], int n);
void tableprint(Student students[], int n);
void tableprint_file(Student students[], int n,const char* filename);
void gradesort(Student students[], int n);

#endif