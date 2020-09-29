//
// Created by shamil on 29.09.2020.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    int N;
    scanf("%d", &N);

    int* a = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    free(a);

}