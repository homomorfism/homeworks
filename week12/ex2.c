//
// Created by shamil on 03.11.2020.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{

    char *data = malloc(20000);
    int bytes = fread(data, 1, 20000, stdin);
    printf("Read number of bytes: %d", bytes);


    printf("File: %s", data);


    for (int i = 2; i < argc; ++i) {
        FILE * output = fopen(argv[i], "a");
        assert(output != NULL);

        fprintf(output, "%s", data);
        fclose(output);
    }


    return 0;
}