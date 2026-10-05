extern int getchar();
extern int putchar(int);
# define EOF (-1)
int main(){
    int c;
    for (c=getchar();c!=EOF;c=getchar())
        putchar(c);
    return 0;
    /* ou aussi */
    while ((c=getchar())!=EOF)
        putchar(c);
    return 0;
}