//
// Created by trov on 04.10.2018.
//
#include <stdlib.h>
#include "stdio.h"

int main() {
    int N;
    scanf("%d", &N);
    int* a = calloc((size_t) N, sizeof(int));

    for (int i = 0; i < N; ++i) {
        a[i] = i;
        printf("%d\n", a[i]);
    }

    printf("lol kek: %d", a[N-1]);

    free(a);
    return 0;
}

