//
// Created by shamil on 27.10.2020.
//


#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main() {
    char buf[5];
    int status = setvbuf(stdout, buf, _IOLBF, sizeof(char)*5);

    sleep(1);
    printf("S");
    sleep(1);
    printf("l");
    sleep(1);
    printf("e");
    sleep(1);
    printf("e");
    sleep(1);
    printf("p");


    for (int i = 0; i < strlen(buf); ++i) {
        printf("%c", buf[i]);
    }




}