#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* next;
	int value;
};


struct List {
	struct Node* head;
	struct Node* tail;
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
}

void delete_node(struct List* list, int val) {
	struct Node* current = list->head;
	list->size--;

	while (current->next != list->tail) {

		if (current->next->value == val) {
			struct Node* tmp = current->next;
			
			current->next = current->next->next;
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


	print_list(list);;

	insert(list, 3);
	insert(list, 2);
	insert(list, 9);
	insert(list, 7);
	insert(list, 5);
	insert(list, 2);
	print_list(list);
	delete_node(list, 9);
	print_list(list);
    insert(list, 5);
    insert(list, 2);
    print_list(list);



}