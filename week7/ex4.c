//
// Created by shamil on 29.09.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void* _realloc(void* ptr, int bytes_size) {
    printf("%zu\n", malloc_usable_size(ptr));

    if (ptr == NULL) {
        return malloc(sizeof(bytes_size));
    }

    if (bytes_size == 0) {

        free(ptr);
        return NULL;
    }

    void* new_ptr = malloc(sizeof(bytes_size));
    memcpy(new_ptr, ptr, bytes_size);

    free(ptr);
    return new_ptr;


    return ptr;
}



int main() {
    int* a = (int*)malloc(sizeof(int) * 9);
    for (int i = 0; i < 9; ++i) {
        a[i] = i * 2;
    }
    printf("Content of a: ");
    for (int i = 0; i < 9; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");


    a = (int*)_realloc(a, sizeof(int) * 6);
    printf("Content of a: ");
    for (int i = 0; i < 6; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}