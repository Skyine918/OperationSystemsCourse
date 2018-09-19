#include <pthread.h>
#include <stdio.h>
#include <zconf.h>

#define max_size = 10
int counter = 0;
int enable = 1;

void *producer() {



    while (1) {
        if (enable == 1) {
            if (counter < 10) {
                counter++;
                printf("counter = %d\n", counter);
                sleep(1);
            } else {
                printf("Producer sleep\n");
                sleep(60);
            }
        } else {
            break;
        }
    }
}

void *consumer() {

    while (1) {
        if (enable == 1) {
            if (counter > 0) {
                counter--;
                printf("counter = %d\n", counter);
                sleep(1);
            } else {
                printf("Consumer Sleep\n");
                sleep(60);
            }
        } else {
            break;
        }

    }
}


int main() {

    pthread_t tid[2];
    {
        pthread_create(&tid[0], NULL, producer, NULL);
        pthread_create(&tid[1], NULL, consumer, NULL);
    }
    {
        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);
    }
    return 0;
}