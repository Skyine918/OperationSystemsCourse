//
// Created by trov on 12.09.2018.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int main() {
    char command[512];

    void read(char *command) {
        scanf("%s", command);
    }
    while (1) {
        read(command);
        if (strncmp(command, "exit", strlen("exit")) == 0) {
            printf("[Session closed]");
            break;
        }
        system(command);
    }

    return 0;
}
