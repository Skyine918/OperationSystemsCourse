//
// Created by trov on 26.09.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

int main(){
    int fd[2];
    _ssize_t size;
    char result[14];

    if(pipe(fd) < 0){
        printf("Can't create pipe\n");
        exit(-1);
    }

    int pid = fork();
    if(pid < 0){
        printf("Can't fork child\n");
        exit(-1);
    }

    if (pid == 0) {
        //child
        close(fd[1]);


        size = read(fd[0], result, 14);
        if(size < 0){
            printf("Cant read string\n");
            exit(-1);
        }
        close(fd[0]);

        printf("printed '%s' <- from child\n", result);
        printf("Child process finished\n");

    }

    if (pid > 0) {
        //parent process
        close(fd[0]);

        //write in pipe
        size = write(fd[1], "lolkek string", 14);
        if(size != 14){
            printf("Can't write all string\n");
            exit(-1);
        }

        close(fd[1]);
        printf("Parent process finished\n");

    }
    return 0;
}

