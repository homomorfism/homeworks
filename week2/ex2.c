#include <stdio.h>
#include <string.h>

int main()
{
	char a[100];
	scanf("%s", a);

	for (int i = strlen(a); i >= 0; i = i - 1)
		printf("%c", *(a + i));
	printf("\n");

	return 0;
}