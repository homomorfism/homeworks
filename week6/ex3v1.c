//
// Created by shoma on 9/22/20.
// Description: implementation of robin algorithm
// Input:
//      num_processes quantum
//      ...
//      i-th_process_start i-th_process_end


/* Testing
3 1
1 2
1 2
2 3


3 10000
1 12
2 24
1 13


3 1
0 4
1 4
2 6
 */

#include <stdio.h>
#include <stdlib.h>

double *arr_time, *burst_time, *time_left, *TAT, *WT, *CT;
int curr_process = -1;
double curr_time = 0;
int num_finished_processes = 0;
int N;
double quantum;


void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

double min(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void print_data(double *arr, int n, const char *sign) {
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

    arr_time = (double *) malloc(sizeof(double) * N);
    burst_time = (double *) malloc(sizeof(double) * N);
    time_left = (double *) malloc(sizeof(double) * N);

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
    printf("N: %d, quantum: %lf\n", N, quantum);

    printf("Outputting entered data: index process, arrival_time, burst_time, time left\n");
    for (int i = 0; i < N; ++i) {
        printf("%d : %lf, %lf, %lf\n", i, arr_time[i], burst_time[i], time_left[i]);
    }
    printf("\n");
}

double mean(const double *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / n;
}

int can_take_next_process() {
    for (int i = curr_process + 1; i < N; ++i) {
        if (arr_time[i] <= curr_time && time_left[i] > 0) {
            return i;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (arr_time[i] <= curr_time && time_left[i] > 0) {
            return i;
        }
    }

    return -1;
}

void make_step() {

    int i = can_take_next_process();
    //printf("I: %d\n", i);
    if (i != -1) {
        double time = min(time_left[i], quantum);
        time_left[i] -= time;

        curr_process = i;

        if (time_left[i] == 0.0) {
            num_finished_processes++;
            CT[i] = curr_time + time;
            TAT[i] = CT[i] - arr_time[i];
            WT[i] = TAT[i] - burst_time[i];
        }

        curr_time += time;
        printf("Process %d worked for %lf seconds\n", i, time);

    } else {
        // No processes (not finished) have arr[i] <= curr_time
        // Let's pick the most earliest process and wait for him
        double min_wait_time = 1e7;
        for (int j = 0; j < N; ++j) {
            if (arr_time[j] > curr_time && time_left[j] > 0) {
                min_wait_time = min(min_wait_time, arr_time[j] - curr_time);
            }
        }
        curr_time += min_wait_time;

        printf("Waiting for %lf second for next process\n", min_wait_time);
    }

}

int main() {
    read_data();

    TAT = (double *) malloc(sizeof(double) * N);
    WT = (double *) malloc(sizeof(double) * N);
    CT = (double *) malloc(sizeof(double) * N);


    for (int i = 0; i < N; ++i) {
        TAT[i] = 0.0;
        WT[i] = 0.0;
        CT[i] = 0.0;
    }

    num_finished_processes = 0;


    int _step = 0;
    while (num_finished_processes < N) {
        make_step();
        printf("Step: %d, current process: %d, current time: %lf, num finished processes: %d\n", _step, curr_process,
               curr_time, num_finished_processes);
        printf("Time left for each process: ");
        for (int i = 0; i < N; ++i) {
            printf("%lf ", time_left[i]);
        }
        printf("\n\n");
        _step++;

        //if (_step > 10) exit(1);

    }


    double ATAT = mean(TAT, N);
    double AWT = mean(WT, N);

    print_data(CT, N, "Completion time: ");
    print_data(TAT, N, "Turn around time: ");
    print_data(WT, N, "Waiting time: ");
    printf("Average TAT: %lf\n", ATAT);
    printf("Average waiting time: %lf", AWT);

}


