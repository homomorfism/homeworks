#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_t consumer, producer;
unsigned long long int count = 0;


void* cons(void* arf) {
	while(1) {
	    if (count==0) sleep(0.1);

	    if (count == 1) {
	    	printf("Count is %lld\n", count);
	    }
	    
	    if (count > 0) {
	    	count--;
	    }
	}
}

void* prod(void* arf) {
	while(1) {
	    if (count == 10000000) sleep(0.1);

	    if (count==9999999) {
	    	printf("Count is %lld\n", count);
	    }
	    if (count < 10000000) {
	    	count++;
	    }
	}
}
/*
	This is example of race condition:
		printf gets incorrect value of var count when outputting, because the main thread gets blocked and when it activated, there lies another value
 */
int main(int argc, char const *argv[])
{
	pthread_create(&consumer, NULL, cons, NULL);
	pthread_create(&producer, NULL, prod, NULL);
	pthread_join(producer, NULL);
	return 0;
}