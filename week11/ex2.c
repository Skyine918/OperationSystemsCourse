#include <sys/fcntl.h>
#include <stdio.h>
#include <zconf.h>

int main() {

    char *buf[6];
    setvbuf(stdout, *buf, _IOLBF, (size_t) sizeof(char)*6);

    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);
    printf("\0");

    return 0;

};