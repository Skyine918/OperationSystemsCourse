//
// Created by trov on 30.08.2018.
//

#import <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    printf("\n");
    printf("Height: %s\n", argv[1]);
    int n = atoi(argv[1]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (n-i); ++j) {
            printf(" ");
        }
        for (int j = 0; j < (2*i)+1; ++j) {
            printf("*");
        }
        for (int j = 0; j < (n-i); ++j) {
            printf(" ");
        }
        printf("\n");
    }
}

