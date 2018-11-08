#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    FILE *fp;


    fp = popen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }


    if (strcmp(argv[3], "|") == 0) {
        if (strcmp(argv[4], "tee") == 0) {
            

            for (int i = 5; i < argc; i++) {


                char path[1035];
                while (fgets(path, sizeof(path)-1, fp) != NULL) {
                    fprintf(stdout, "%s\n", path);
                    for (int j = 5; j < argc; ++j) {
                        FILE *output = fopen(argv[j], "w"); // "../" to exit CMake-build-debug folder

                        if (output == NULL)
                        {
                            printf("Error opening file!\n");
                            exit(1);
                        }

                        fprintf(output, "%s", path);
                        fclose(output);
                    }

                }



            }

        }
    }





    /* close */


    return 0;
}