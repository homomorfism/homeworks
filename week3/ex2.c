#include <stdio.h>

void bubble_sort(int* a, int size) {
	for (int i = 0; i < size; ++i)
	{
		for (int j = 1; j < size; ++j)
		{
			if (a[j - 1] > a[j]) 
			{
				int t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
	}
}

int main() {
	int a[13] = {1, 5, 2, 8, 1, 9, 9, 5, 0, 7, 2, 4, 5};
	bubble_sort(a, 13);

	for (int i = 0; i < 13; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}