//
// Created by shamil on 03.11.2020.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
int main() {
    FILE * file = fopen("/dev/random", "r");
    FILE * output = fopen("ex1.txt", "w");
    assert(file != NULL && output != NULL);

    char * line = (char *)malloc(sizeof(char) * 20);

    int status = fscanf(file, "%s", line);
    assert(status != EOF);

    printf("Line: %s", line);
    fprintf(output, "%s", line);

}