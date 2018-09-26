//
// Created by trov on 26.09.2018.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    int fd[2];
    _ssize_t size;
    char string1[] = "lolkek string";
    char string2[] = "";

    if(pipe(fd) < 0){
        printf("Cant create pipe\n");
        exit(-1);
    }

    //write in pipe
    size = write(fd[1], string1, 14);
    if(size != 14) {
        printf("Cant write all string\n");
        exit(-1);
    }

    //read from pipe
    size = read(fd[0], string2, 14);
    if(size < 0){
        printf("Can't read from pipe\n");
        exit(-1);
    }

    printf("%s\n", string2);

    //close pipe IO
    if(close(fd[0]) < 0){
        printf("Can't close pipe\n");
    }
    if(close(fd[1]) < 0){
        printf("Can't close output stream\n");
    }

    return 0;
}

