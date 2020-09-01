//
// Created by Arslanov Shamil on 01.09.2020.
// Description: quick sort
//
#include <stdio.h>


void swap(int *pInt, int i, int j) {
    int temp = pInt[i];
    pInt[i] = pInt[j];
    pInt[j] = temp;
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (array[j] < pivot) {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, high);

    return i + 1;
}

void qsort(int* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        qsort(array, low, pi - 1);
        qsort(array, pi + 1, high);
    }
}


int main() {
    int array[10] = {1, 6, 4, 3, 9, 8, 8, 7, 5, 6};
    int size = 10;
    qsort(array, 0, size - 1);

    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
}









