#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[50];
    printf("Enter a string: ");
    scanf("%s",&str);
    // or: fgets(str,sizeof(str),stdin);
    int L=0, R=strlen(str)-1;
    while (L<R)
    {
        char temp=str[L];
        str[L]=str[R];
        str[R]=temp;
        L++; R--;
    }
    printf("\n%s",str);
    return 0;
}