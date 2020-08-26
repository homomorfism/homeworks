#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n;
	sscanf(argv[1], "%d", &n);

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < i + 1; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}