// Student Record Management Project
// 2410299 - Nguyễn Xuân Hiển - Group 2
#include<stdio.h>
#include <stdlib.h>
#include "student.h"
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "Ex4.h"
#include "Ex5.h"

int main()
{
   int n=studentamt();
   studentinfo(students, n);
   tableprint(students, n);
   tableprint_file(students, n,"student_table.txt");
   gradesort(students, n);
}