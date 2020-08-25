#include <stdio.h>

void _swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
int main(int argc, char const *argv[])
{
	printf("Enter 2 numbers: ");
	int a, b;
	scanf("%d %d", &a, &b);


	_swap(&a, &b);

	printf("Output: %d %d\n", a, b);

	

	return 0;
}