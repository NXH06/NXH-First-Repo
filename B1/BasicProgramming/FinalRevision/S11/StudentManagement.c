#include<stdio.h>
#include<stdlib.h>
int main()
{
    typedef struct {
        char* name;
        int age;
        char* major;
        char* ID;
    } Std;
    Std student1 = {
        "Nguyen Xuan Hien",
        19,
        "ICT-DD",
        "2410299"
    };
    Std* ptr1=&student1;
    printf("\nStudent: %s, %d years old, majoring in %s, student ID: %s",(*ptr1).name,(*ptr1).age,(*ptr1).major,(*ptr1).ID);
    return 0;
}