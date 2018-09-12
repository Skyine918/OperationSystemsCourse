//
// Created by trov on 12.09.2018.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for (i = 0; i < 3; ++i) {
        fork();
        sleep(5);
    }

    return 0;
}


