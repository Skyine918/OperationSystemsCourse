#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n = 1;
    int PID= fork();
    if (PID>0) {
        printf("Hello from parent [%d - %d]\n",PID,n);
    }
    else if(PID==0) {
        printf("Hello from child [%d - %d]\n",PID,n);
    }
    else {
	printf("Error\n");
    }
}
