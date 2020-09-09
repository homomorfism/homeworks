//
// Created by Arslanov Shamil on 01.09.2020.
// Description: dll
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    struct Node *prev, *next;
    int value;
};

struct List {
    struct Node *head, *tail;
    int size;
};


void print_list(struct List* list) {
    struct Node* current = list->head;

    while (current->next != list->tail) {
        current = current->next;
        printf("%d ", current->value);
    }
    printf("\n");
}

void insert(struct List* list, int val) {
    struct Node* current = list->head;
    list->size++;

    while (current->next != list->tail) {
        current = current->next;
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
    node->value = val;
    node->next = list->tail;
    current->next = node;
    node->prev = current;
    list->tail->prev = node;

    list->size += 1;
}

void delete(struct List* list, int val) {
    struct Node* current = list->head;
    list->size--;

    while (current->next != list->tail) {

        if (current->next->value == val) {
            struct Node* tmp = current->next;

            current->next = current->next->next;
            current->next->prev = current;
            free(tmp);
            return;
        }
        current = current->next;
    }
}

int main() {
    struct List* list = (struct List*)malloc(sizeof(struct List*));
    list->size = 0;
    list->head = (struct Node*)malloc(sizeof(struct Node*));
    list->tail = (struct Node*)malloc(sizeof(struct Node*));
    list->head->next = list->tail;
    list->tail->prev = list->head;

    assert(list != NULL && list->head != NULL && list->tail != NULL);

    print_list(list);

    int values[5] = {4, 6, 2, 8, 9};
    for (int i = 0 ; i < sizeof(values) / sizeof(int); ++i) {
        insert(list, values[i]);
    }

    print_list(list);

    delete(list, 6);
    print_list(list);
    for (int i = 0 ; i < sizeof(values) / sizeof(int); ++i) {
        insert(list, values[i]);
    }
    print_list(list);

}




