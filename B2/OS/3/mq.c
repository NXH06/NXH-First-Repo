#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

struct Message {
    long type;
    char text[20];
} msg;
int main() {
    int mqid;
    int key = 1234;
    struct Message my_msg;
    mqid = msgget(key, 0666);
    my_msg.type = 1;
    // msgrcv(mqid);
    if (msgget(key, IPC_CREAT | 0666) < 0) {
        perror("msgget failed!");
        exit(1);
    }
    return 0;
}