# include <stdio.h>
int main(int argc, char *argv[]){
int i;
printf(" %d parameters \n",argc-1);
for(;argc>0;argc--){
    printf(" %d ",argc);
    for(i=0;argv[argc-1][i]!=0;i++)
    putchar(argv[argc-1][i]);
    putchar('\n') ;
}
return 22;
}