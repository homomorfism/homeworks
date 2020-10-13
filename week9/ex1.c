//
// Created by shamil on 13.10.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

#define N 10

// Частота обн. счетчитов в miss/hit
#define REF_COUNER 10

// Кол-во записей в файле
#define SIZE_INPUT 1000


struct Page {
    int counter;
    int status; // zero if empty, n if buzy with i-th page
};

// Returns id of free place for process or -1 if all busy
int id_free_place_for_process(struct Page* PageTable, int id) {
    for (int i = 0; i < N; ++i) {
        if (PageTable[i].status == 0) return i;
    }
    return -1;
}

int have_process_in_table(struct Page* PageTable, int id) {
    for (int i = 0; i < N; ++i) {
        if (PageTable[i].status == id) return i;
    }
    return -1;
}

void auto_decrementing(struct Page* PageTable) {
    for (int i = 0; i < N; ++i) {
        PageTable[i].counter >>=1;
    }
    return;
}

int find_smallest_age(struct Page* PageTable) {
    int min_age = INT_MAX;
    int id = 0;

    for (int i = 0; i < N; ++i) {
        if (PageTable[i].counter < min_age) {
            min_age = PageTable[i].counter;

            // Sanity check that all pages are buzy
            assert(PageTable[i].status != 0);
            id = i;
        }
    }
    return id;
}


void page_frames_info(struct Page* PageTable) {
    printf("\nIndex, status, age\n");
    for (int i = 0; i < N; ++i) {
        printf("%d %d %d\n", i, PageTable[i].status, PageTable[i].counter);
    }
    printf("\n");
}

int main() {
//    printf("%lu bit\n", sizeof(int));
//    printf("%d", (unsigned int)1<<30);
    FILE* input = fopen("week9/input.txt", "r");
    assert(input != NULL);
    struct Page* PageTable = (struct Page*)malloc(sizeof(struct Page) * N);
    for (int i = 0; i < N; ++i) {
        PageTable[i].counter = PageTable[i].status = 0;
    }

    int num_hits = 0;
    int num_misses = 0;


    for (int i = 0; i < SIZE_INPUT; ++i) {
        int n;
        fscanf(input, "%d", &n);
        printf("%d ", n);
        auto_decrementing(PageTable);

        if (have_process_in_table(PageTable, n) != -1) {
            int place = have_process_in_table(PageTable, n);
            num_hits += 1;
            PageTable[place].counter += 1<<30;
            printf(" is in the table\n");
        } else {
            num_misses += 1;
            printf(" is not at table,");
            int free_place = id_free_place_for_process(PageTable, n);

            if (free_place != -1) {
                printf(" but now at %d free place\n", free_place);
                PageTable[free_place].status = n;
                PageTable[free_place].counter += 1<<30;

            } else {
                int place = find_smallest_age(PageTable);
                printf(" but now at %d free(now swapped) place\n", place);

                PageTable[place].status = n;
                PageTable[place].counter += 1<<30;
            }
        }
        page_frames_info(PageTable);

    }

    fclose(input);
    return 0;

}
