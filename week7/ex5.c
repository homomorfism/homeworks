//
// Created by shamil on 29.09.2020.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    char **s = (char**)malloc(sizeof(char*)); // <- Allocated memory for pointer to string
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n",*s); // <- added * for correctly outputting information %s asks for char*, not for char**
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
}