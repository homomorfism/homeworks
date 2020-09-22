//
// Created by shoma on 9/22/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "List.h"


double* arr_time,* burst_time,* time_left,*TAT, *WT, *CT;
struct List list;
int curr_process;
int N;
double quantum;

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void print_data(double* arr, int n,  const char* sign) {
    printf("%s", sign);
    for (int i = 0; i < n; ++i) {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

void read_data() {
    //printf("Enter num of processes:");
    scanf("%d", &N);
    scanf("%lf", &quantum);

    arr_time = (double*)malloc(sizeof(double) * N);
    burst_time = (double *)malloc(sizeof(double) * N);
    time_left = (double *)malloc(sizeof(double) * N);

    for (int i = 0; i < N; ++i) {
        scanf("%lf", &arr_time[i]);
        scanf("%lf", &burst_time[i]);
        time_left[i] = burst_time[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr_time[i] > arr_time[j]) {
                swap(&arr_time[i], &arr_time[j]);
                swap(&burst_time[i], &burst_time[j]);
            }
        }
    }

    printf("Outputting entered data\n");
    for (int i = 0; i < N; ++i) {
        printf("%d : %lf, %lf\n", i, arr_time[i], burst_time[i]);
    }
    printf("\n");
}


int main() {
    read_data();

    TAT = (double *)malloc(sizeof(double ) * N);
    WT = (double *)malloc(sizeof(double ) * N);
    CT = (double *)malloc(sizeof(double ) * N);

    int* state = (int*) malloc(sizeof(int) * N);
    // 0 - didn't started execution
    // 1 - is executing
    // 2 - have finished

    for (int i = 0; i < N; ++i) {
        TAT[i] = 0;
        WT[i] = 0;
        CT[i] = 0;
        state[i] = 0;
    }

    int curr_proc = 0, finished_process = 0;
    double curr_time = 0;


    while (finished_process < N) {

    }

}




