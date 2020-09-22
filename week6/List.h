//
// Created by shoma on 9/22/20.
//

#ifndef HOMEWORKS_LIST_H
#define HOMEWORKS_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct List {
    int size;
    int* array;
};


void push(struct List* lst, int val) {
    assert(lst != NULL);
    lst->array[lst->size - 1] = val;
    lst->size++;
}

void delete(struct List* lst, int val) {
    assert(lst != NULL);
    for (int i = 0; i < lst->size; ++i) {
        if (lst->array[i] == val) {
            for (int j = i+1; j < lst->size; ++j) {
                lst->array[j] = lst->array[j + 1];
            }
        }
    }
}

void print_list(struct List* lst) {
    printf("Content of list: ");
    for (int i = 0; i < lst->size; ++i) {
        printf("%d ", lst->array[i]);
    }
    printf("\n");
}


#endif //HOMEWORKS_LIST_H
