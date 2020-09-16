#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5

pthread_t thread_id[N];


void* print(int i) {
	printf("This is thread %d!\n", i);
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
	int status;

	for (int i = 0; i < N; ++i)
	{
		;
	
		status = pthread_create(&thread_id[i], NULL, print, i);

		if (status) {
			printf("Error!\n");
			exit(1);
		}
		printf("The thread %d was created!\n", i);

		pthread_join(thread_id[i], NULL);

	}

	
	pthread_exit(NULL);
}
