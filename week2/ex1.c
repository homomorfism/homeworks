#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;

	printf("Max int: %d, size: %ld bytes\n", a, sizeof(a));
	printf("Max float: %f, size: %ld bytes\n", b, sizeof(b));
	printf("Max double: %f, size: %ld bytes\n", c, sizeof(c));

	return 0;
}