#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int main() {
    char command[1024];

    void read(char *command) {
        scanf("%[^\t\n]%*c", command);
    }
    while (1) {
        read(command);
        if (strncmp(command, "exit", strlen("exit")) == 0) { break;}
        system(command);
    }

    return 0;
}

