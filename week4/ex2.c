#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * 	We are creating recursively in total 8 processes:
 * 	when creating each process the instructions are also copied, so:
 * 		"main" process in loop creates 3 process:
 * 			first process creates 2 child processes (first iteration is completes, needed 2), and first child create also another process
 * 			second process created 1 child process (two iterations are gone), and this child also created one more child process (thrird iteration)
 * 			third process does not create anything (three interations are gone)
 * 	
 */

int main() {
	for (int i = 0; i < 3; ++i)
	{
		fork();
		sleep(5);
	}
}