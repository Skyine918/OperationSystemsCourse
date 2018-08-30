//
// Created by trov on 30.08.2018.
//

#import <stdio.h>
#include <memory.h>


int main() {
    char my_string[256];
    scanf("%s", my_string);

    for (int i = (int) strlen(my_string)-1; i >= 0 ; i--) {
        printf("%c", my_string[i]);
    }
}