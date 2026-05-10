#include<stdio.h>
#include "student.h"

void studentinfo(Student students[],int n)
{
   int i;
   for (i=0; i<n; i++)
   {
      printf("-----> Inputting information for student %d...",(i+1));
      printf("\nEnter student ID: ");
      scanf("%s",&students[i].ID);
      printf("\nEnter last name and first name: ");
      scanf("%s%s",&students[i].lname,&students[i].fname);
      printf("\nEnter date of birth (dd/mm/yyyy): ");
      scanf("%d/%d/%d",&students[i].day,&students[i].month,&students[i].year);
      printf("\nEnter scores for Algebra, Calculus and Basic Programming courses: ");
      scanf("%f %f %f",&students[i].scoreA,&students[i].scoreC,&students[i].scoreBP);
      students[i].GPA=(students[i].scoreA+students[i].scoreC+students[i].scoreBP)/3;
   }
}