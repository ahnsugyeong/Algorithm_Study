#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	int* x = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		while (cnt <= i) {
			if ()
		}
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", x[i]);
	}
	free(x);

	return 0;
}
/*
7
3 73 48 31 8 11 20

8
73 65 48 31 29 20 8 3
*/