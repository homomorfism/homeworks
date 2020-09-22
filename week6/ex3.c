//
// Created by shoma on 9/22/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double* arr_time,* burst_time,* time_left,*TAT, *WT, *CT;
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

double mean(const double* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / n;
}



int has_active_process_in_queue(int from, int to, const int start, double curr_time) {
    // Проверяет, можем лы мы запустить какойте процесс из очереди,
    // Если да - возвращает его индекс, нет - возвращает -1
    int flag = -1;
    int current = start;

    do {
        if (arr_time[current] <= curr_time && curr_time <= arr_time[current] + burst_time[current] && time_left[current] >= 0) {
            flag = current;
            break;
        }

        current++;
        if (current == to + 1) {
            current = from;
        }
    } while (current != start);

    return flag;
}

double time_until_next_process(int index, double curr_time) {
    return arr_time[index] - curr_time;
}

void increase_time(int from, int to, int wait_time) {
    for (int i = from; i <= to; ++i) {
        WT[i] += wait_time;
    }
}




int main() {
    read_data();

    TAT = (double *)malloc(sizeof(double ) * N);
    WT = (double *)malloc(sizeof(double ) * N);
    CT = (double *)malloc(sizeof(double ) * N);

    for (int i = 0; i < N; ++i) {
        TAT[i] = 0;
        WT[i] = 0;
    }

    int from = 0, to = 0, curr_process = 0;
    int finished_processes = 0;

    int curr_time = 0;

    while (finished_processes < N) {
        for (int i = curr_process; i <= to; ++i) {
            if (arr_time[curr_process] <= curr_time && curr_time <= arr_time[curr_process] + burst_time[curr_process] && time_left[curr_process] >= 0) {

            }
        }
    }



}


