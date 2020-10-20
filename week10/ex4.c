//
// Created by shamil on 20.10.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct CommonFiles {
    char node[20];
    char filenames[20][20];
    int num_files;
};

int contains(struct CommonFiles* array, int size, char* node) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(node, array[i].node) == 0) {
            return i;
        }
    }
    return -1;
}

void get_info(struct CommonFiles* commonFiles, int size) {
    for (int i = 0; i < size; ++i) {
        printf("i-node: %s, num_files: %d; ", commonFiles[i].node, commonFiles[i].num_files);
        for (int j = 0; j < commonFiles[i].num_files; ++j) {
            printf("%s ", commonFiles[i].filenames[j]);
        }
        printf(".\n");
    }
}

int main() {
    struct CommonFiles* commonFiles = (struct CommonFiles*)malloc(sizeof(struct CommonFiles) * 100);
    for (int i = 0; i < 100; ++i) {
        commonFiles->num_files = 0;
    }
    int size = 0;
    system("ls -i tmp > temp.txt");

    FILE* file = fopen("temp.txt", "r");
    assert(file != NULL);

    while(1) {
        char* i = (char*)malloc(sizeof(char) * 20);
        char* name = (char *)malloc(sizeof(char) * 20);
        int a = fscanf(file, "%s %s", i, name);
        if (a == EOF) {
            break;
        }
        printf("I have read: %s, %s\n", i, name);

        int status = (contains(commonFiles, size, i));

        if (status != -1) {
            int num = commonFiles[status].num_files++;
            strcpy(commonFiles[status].filenames[num], name);
        } else {
            commonFiles[size].num_files = 1;
            strcpy(commonFiles[size].filenames[0], name);
            strcpy(commonFiles[size].node, i);
            size++;
        }
    }
    get_info(commonFiles, size);

}
