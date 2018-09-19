//
// Created by trov on 19.09.2018.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *function_to_give(void *threadNumber) {
    int tid = (int) threadNumber;

    printf("Thread #%d executed.\n", tid);
    pthread_exit(NULL);
}

int main () {
    int N;
    scanf("%d",&N);
    pthread_t threads[N];

    int i;
    for (i=1; i<=N; i++) {
        printf("Thread #%d created\n", i);
        pthread_create(&threads[i], NULL, function_to_give, (void *) i);
        pthread_join(threads[i], NULL);
    }



    return 0;
}

