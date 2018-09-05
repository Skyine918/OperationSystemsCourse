#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble_sort(int* array, int size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            int temp = 0;
            if (array[j] > array[j+1]) {
                //swap
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

            }
        }
    }
    printf("\n\n\n");

}

void generate_array(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        *(array+i) = rand() % 200;
        printf("a[%d] = %d\n", i, array[i]);
    }
    printf("\n--------------------------\n");
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("a[%d] = %d\n", i, array[i]);
    }
}

int main() {

    int* array;
    int n = 100;
    array = malloc(sizeof(int)*n);


    generate_array(array, n);

    bubble_sort(array, n);

    print_array(array, n);

    return 0;
}
