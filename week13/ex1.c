//
// Created by shamil on 10.11.2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int num_processes, num_resources;

struct Process {
    int running;

    int *allocated;
    int *requested;

};
struct Process *ProcessTable;

int *resource_exist, *resource_available;

void print_array(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
}

void print_matrix(struct Process *_ProcessTable, const char *name, int len_x, int len_y) {
    printf("%s allocation\n", name);
    for (int i = 0; i < len_x; ++i) {
        print_array(_ProcessTable[i].allocated, len_y);
        printf("\n");
    }
    printf("%s requested\n", name);
    for (int i = 0; i < len_x; ++i) {
        print_array(_ProcessTable[i].requested, len_y);
        printf("\n");
    }

}

void read_input(const char *input_file_name) {
    FILE *input_file = fopen(input_file_name, "r");
    assert(input_file != NULL);
    fscanf(input_file, "%d %d", &num_processes, &num_resources);
    printf("Processes: %d, resources: %d\n", num_processes, num_resources);

    resource_exist = (int *) malloc(sizeof(int) * num_resources);
    resource_available = (int *) malloc(sizeof(int) * num_resources);
    ProcessTable = (struct Process *) malloc(sizeof(struct Process) * num_processes);

    assert(ProcessTable != NULL && resource_exist != NULL && resource_available != NULL);

    for (int i = 0; i < num_resources; ++i) {
        fscanf(input_file, "%d", resource_exist + i);
    }
    printf("Existance: ");
    print_array(resource_exist, num_resources);


    for (int i = 0; i < num_resources; ++i) {
        fscanf(input_file, "%d", resource_available + i);
    }
    printf("\nAvailable: ");
    print_array(resource_available, num_resources);


    for (int i = 0; i < num_processes; ++i) {
        ProcessTable[i].running = 1;
        ProcessTable[i].allocated = (int *) malloc(sizeof(int) * num_resources);

        for (int j = 0; j < num_resources; ++j) {
            fscanf(input_file, "%d", ProcessTable[i].allocated + j);
        }
    }
    for (int i = 0; i < num_processes; ++i) {
        ProcessTable[i].requested = (int *) malloc(sizeof(int) * num_resources);

        for (int j = 0; j < num_resources; ++j) {
            fscanf(input_file, "%d", ProcessTable[i].requested + j);
        }
    }

    for (int i = 0; i < num_processes; ++i) {
        ProcessTable[i].running = 1;
    }
    print_matrix(ProcessTable, "\nProcess table", num_processes, num_resources);

}

bool can_fulfill_request(int process_id) {
    for (int i = 0; i < num_resources; ++i) {
        if (ProcessTable[process_id].requested[i] > resource_available[i]) return false;
    }
    return true;
}

bool can_fulfill_some_request() {
    for (int i = 0; i < num_processes; ++i) {
        if (ProcessTable[i].running == 1) {
            if (can_fulfill_request(i)) return true;
        }
    }
    return false;
}

void has_deadlock(const char *output_file_name) {
    int num_finished_processes = 0;
    FILE *output_file = fopen(output_file_name, "w");

    while (num_finished_processes < num_processes) {
        if (can_fulfill_some_request()) {
            for (int i = 0; i < num_processes; ++i) {
                if (can_fulfill_request(i)) {
                    ++num_finished_processes;
                    ProcessTable[i].running = 0;

                    // stash all free resources
                    for (int j = 0; j < num_resources; ++j) {
                        resource_available[j] += ProcessTable[i].allocated[j];
                    }
                }
            }
        } else {

            fprintf(output_file, "Deadlock on: ");
            printf("Deadlock on: ");
            for (int i = 0; i < num_processes; ++i) {
                if (ProcessTable[i].running == 1) {
                    printf("%d ", i);
                    fprintf(output_file, "%d ", i);
                }
            }
            printf("\n");
            fprintf(output_file, "\n");
            exit(0);
        }
    }

    printf("No deadlocks, thanks prof. Gucci!\n");
    fprintf(output_file, "No deadlocks, thanks prof. Gucci!\n");

}

int main() {
    const char *input_file_name = "input_dl.txt", *output_file_name = "output_dl.txt";

    read_input(input_file_name);

    has_deadlock(output_file_name);

}