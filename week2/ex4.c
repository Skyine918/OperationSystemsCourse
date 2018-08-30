//
// Created by trov on 30.08.2018.
//

#include <stdio.h>

void swap(int* a, int* b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int a;
    int b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    swap(&a, &b);

    printf("First number: %d", a);
    printf("Second number: %d", b);
}

