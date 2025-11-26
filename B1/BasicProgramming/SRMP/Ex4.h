#include<stdio.h>
#include "student.h"

void tableprint_file(Student students[], int n,const char* filename)
{
   FILE *fp = fopen(filename,"w");
   fprintf(fp,"\n%-15s %-20s %-20s %-12s %-12s %-12s %-20s %-15s\n",
   "Student ID", "Last Name", "First Name", "Algebra", "Calculus", "BasicProg", "Date of Birth", "GPA");
   fprintf(fp, "========================================================================\n");
   int i;
   for (i=0; i<n; i++) 
   {
      fprintf(fp,"%-15s | %-20s | %-20s | %-12.2f | %-12.2f | %-12.2f | %-2d/%2d/%4d | %-15.2f | %-15.2f\n",
      students[i].ID, students[i].lname, students[i].fname,
      students[i].day, students[i].month, students[i].year,
      students[i].scoreA, students[i].scoreC, students[i].scoreBP, students[i].GPA);
   }
   fclose(fp);
}