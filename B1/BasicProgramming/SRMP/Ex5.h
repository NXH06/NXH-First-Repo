#include<stdio.h>
#include "student.h"

void gradesort(Student students[], int n)
{
   float H_GPA = -1;
   float L_GPA = 100; 
   int H_GPA_index, L_GPA_index;
   float H_BP=-1;
   int H_BP_index;
   float GPA;
   int i;
   for (i=0; i<n; i++) 
   {
      GPA = students[i].GPA;
      if (GPA>H_GPA) 
      {
         H_GPA = GPA;
         H_GPA_index = i;
      }
      if (GPA<L_GPA) 
      {
         L_GPA = GPA;
         L_GPA_index = i;
      }
      if (students[i].scoreBP>H_BP) 
      {
         H_BP = students[i].scoreBP;
         H_BP_index = i;
      }
   }
   printf("\nHighest GPA: %.2f",H_GPA,"from student: %s %s",students[H_GPA_index].lname, students[H_GPA_index].fname);
   printf("\nLowest GPA: %.2f",L_GPA,"from student: %s %s",students[L_GPA_index].lname, students[L_GPA_index].fname);
   printf("\nHighest BP score: %.2f",H_BP,"from student: %s %s",students[H_BP_index].lname, students[H_BP_index].fname);
}