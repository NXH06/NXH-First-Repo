#include<stdio.h>
#include "student.h"

void tableprint(Student students[], int n)
{
   printf("==================== Student table ====================\n");
   printf("\n%-15s | %-20s | %-20s | %-12.2f | %-12.2f | %-12.2f | %-2d/%2d/%4d | %-15.2f | %-15.2f\n",
   "Student ID", "Last Name", "First Name", "Algebra", "Calculus", "BasicProg", "Date of Birth", "GPA");
   printf("========================================================================\n");
   int i;
   for (i=0; i<n; i++) 
   {
      printf("%-15s | %-20s | %-20s | %-12.2f | %-12.2f | %-12.2f | %-2d/%2d/%4d | %-15.2f | %-15.2f\n",
      students[i].ID, students[i].lname, students[i].fname,
      students[i].day, students[i].month, students[i].year,
      students[i].scoreA, students[i].scoreC, students[i].scoreBP, students[i].GPA);
   }
}