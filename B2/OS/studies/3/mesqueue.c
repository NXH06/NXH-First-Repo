#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
/* this exercise in incomplete */
typedef struct Message {
    long mtype;
    char mtext[50];
} Msg;

int main() {
    int msgid;
    key_t key = 2006;
    Msg msg;
    if (msgid = (msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("msgget");
        exit(1);
    }
    return 0;
}