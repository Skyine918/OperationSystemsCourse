#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char** argv){
    int randomData = open("/dev/urandom", O_RDONLY);

    FILE *output = fopen("../ex1.txt", "w"); // "../" to exit CMake-build-debug folder
    if (output == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    if (randomData < 0) printf("Error opening file");
    else
    {
        char randStr[50];
        ssize_t result = read(randomData, randStr, sizeof randStr);
        if (result < 0) printf("Error reading file random");

        for (int i = 0; i < 20; ++i) {
            fprintf(output, "%c", randStr[i]);
            printf("%c", randStr[i]);
        }
    }

    fclose(output);



    return 0;
}