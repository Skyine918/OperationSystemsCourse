//
// Created by trov on 26.09.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <sys/signal.h>

void signal_callback_handler(int signum) {

    printf("Signal proceeded: %d\n", signum);

    // Terminate program
    sleep(3);
    exit(signum);
}


int main() {

    signal(SIGINT, signal_callback_handler);

    while (0 != 1) {

        printf("Lolkek program\n");

        sleep(3);

    }

    return EXIT_SUCCESS;

}
