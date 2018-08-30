//
// Created by trov on 30.08.2018.
//

#import <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("Size of INT: [%zu], MAX: %d\n",  sizeof(a), a);
    printf("Size of INT: [%zu], MAX: %f\n",  sizeof(b), b);
    printf("Size of INT: [%zu], MAX: %lf\n", sizeof(c), c);

    return 0;
}