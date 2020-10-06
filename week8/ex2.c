//
// Created by shamil on 06.10.2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>

int main() {

    for (int i = 0; i < 10; ++i) {
        int *a = (int *) malloc(1000 * 1024 * 1024);
        a = memset(a, 0, 1000 * 1024 * 1024);
        sleep(1);
    }
}