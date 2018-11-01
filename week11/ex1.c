#include <sys/fcntl.h>
#include <stdio.h>
#include <zconf.h>
#include <sys/mman.h>


int main() {
    int fd;
    char *map;

    char *p = "This is a nice day";

    fd = open("./ex1.txt", O_RDWR);
    if (fd == -1) {
        printf("Error opening file\n");
    }

    struct stat st;
    stat("./ex1.txt", &st);

    map = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        close(fd);
        perror("Error mmapping the file");
    }

    for (int j = 0; j < 18; ++j) {
        map[j] = p[j];
    }

    if (munmap(map, (size_t) st.st_size) == -1) {
        perror("Error un-mmapping the file");
    }

    close(fd);
    return 0;




};