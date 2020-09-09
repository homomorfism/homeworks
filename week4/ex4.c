//
// Created by Arslanov Shamil on 08.09.2020.
// Description: 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

char **read_cmd() {
    char** args = (char**)malloc(sizeof(char*) * 100);


    char buf[100];
    fgets(buf, 100, stdin);
    //printf("Entered string:%s, length:%llu", buf, strlen(buf));

    int curr_word = 0, curr_letter = 0;
    args[curr_word] = (char*)malloc(sizeof(char) * 100);

    for (int i = 0; i < strlen(buf); ++i) {
        char symbol = buf[i];

        if (symbol == ' ') {
            args[curr_word][curr_letter] = '\n';
            curr_word++;
            args[curr_word] = (char*)malloc(sizeof(char) * 100);
            curr_letter = 0;

            continue;
        }

        if (symbol == '\n') {
            args[curr_word][curr_letter] = '\n';
            args[curr_word + 1] = (char*)0;
            break;
        }

        args[curr_word][curr_letter] = symbol;
        curr_letter++;

    }
    return args;
}



int main() {


    char **args = read_cmd();
    
    int pid = fork();
    if (pid == 0) {
    	execve(args[0], args, (char*)0);
    }
    
}