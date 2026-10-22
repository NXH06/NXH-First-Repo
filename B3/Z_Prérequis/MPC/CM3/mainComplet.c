#include <stdio.h>

int main(int argc, char *argv[], char *arge[]){
    while(*arge) {
        puts(*(arge++));
    }
    return 0;
}