//
// Created by shoma on 9/22/20.
//

#include <stdio.h>
#include <stdlib.h>

double* arr_time;
double* burst_time;
int N;

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

    arr_time = (double*)malloc(sizeof(double) * N);
    burst_time = (double *)malloc(sizeof(double) * N);

    for (int i = 0; i < N; ++i) {
        scanf("%lf", &arr_time[i]);
        scanf("%lf", &burst_time[i]);
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

int main() {
    read_data();
    double CT;

    double* TAT = (double *)malloc(sizeof(double ) * N);
    double* WT = (double *)malloc(sizeof(double ) * N);
    for (int i = 0; i < N; ++i) {
        TAT[i] = 0;
        WT[i] = 0;
    }


    double prev_time_stop = 0;
    for (int i = 0; i < N; ++i) {
        double next_time_start;
        if (arr_time[i] < prev_time_stop) {
            next_time_start = prev_time_stop;
            WT[i] = prev_time_stop - arr_time[i];
        } else {
            next_time_start = arr_time[i];
        }

        TAT[i] = WT[i] + burst_time[i];

        prev_time_stop = next_time_start + burst_time[i];
        CT = prev_time_stop;
    }

    double ATAT = mean(TAT, N);
    double AWT = mean(WT, N);

    printf("CT: %lf\n", CT);
    print_data(TAT, N, "Turn around time: ");
    print_data(WT, N, "Waiting time: ");
    printf("Average TAT: %lf\n", ATAT);
    printf("Average waiting time: %lf", AWT);

}


/* Enter data:
6
1 5
2 8
7 10
7 45
6 30
5 40


2
1 10
20 1 - passed

2
0 1
0 1 - passed
*/
