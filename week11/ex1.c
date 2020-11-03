//
// Created by shamil on 27.10.2020.
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main() {
    struct stat buff;
    int des = open("ex1.txt", O_RDWR);
    assert(des >= 0);
    stat("ex1.txt", &buff);
    printf("Size of file: %ld", buff.st_size);

    char* line = "This is a good day";
    ftruncate(des, strlen(line));
    char* file = (char*)mmap(NULL, buff.st_size,
         PROT_READ | PROT_WRITE | PROT_EXEC | PROT_NONE,
         MAP_SHARED | MAP_ANONYMOUS, des, 0);

    //file = "This is a good day";
    strcpy(file, line);

    printf("\n%s", file);

    munmap(file, strlen(line));
    close(des);

    return 0;
}