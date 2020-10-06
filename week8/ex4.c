//
// Created by shamil on 06.10.2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    int who = RUSAGE_SELF;
    for (int i = 0; i < 10; ++i) {
        int *a = (int *) malloc(100 * 1024 * 1024);
        a = memset(a, 0, 100 * 1024 * 1024);
        getrusage(who, &usage);
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }
}
/*
 * output:
[shamil@shamil week8]$ ./ex4
103460
206248
308416
410848
513280
615712
718144
820576
923008
1025440
 */