#include <stdio.h>
#include <sys/types.h>
/*
Each process that we create has his unique number, 
that's why pid of each created process is incrementing
 */

int main() {
	int n;
	pid_t p_id = fork();

	if (p_id == 0) {
		printf("Hello from child [%d - %d]\n", getpid(), n);
	} else {
		printf("Hello from parent [%d - %d]\n", getpid(), n);
	}
}