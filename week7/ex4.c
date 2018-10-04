//
// Created by trov on 04.10.2018.
//
#include <stdlib.h>
#include <stdio.h>

void* myrealloc(void* ptr, int new_size) {
    free(ptr);
    ptr = malloc(new_size);
    return ptr;
}

int main() {
    int N1;
    int N2;
    printf("First size in [int]'s ");
    scanf("%d", &N1);
    printf("\nSecond size in [int]'s ");
    scanf("%d", &N2);
    int* a = malloc(sizeof(int)*N1);

    for (int i = 0; i < N1; ++i) {
        *(a+i) = i*i;
        printf("%d, ", *(a+i));
    }

    myrealloc(a, sizeof(int)*N2);
    printf("\n");

    for (int i = 0; i < N2; ++i) {
        printf("%d, ", *(a+i));
    }
}