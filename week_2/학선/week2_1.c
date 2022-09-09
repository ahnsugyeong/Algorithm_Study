#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	int* x = malloc(n * sizeof(int));

	int N = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	while (n > 0) {
		n--;
		int maxidx = 0;
		for (int i = 0; i <= n; i++) {

			if (x[maxidx] < x[i]) maxidx = i;
		}
		int tmp = x[maxidx];
		x[maxidx] = x[n];
		x[n] = tmp;
	}
	for (int i = 0; i < N; i++) {
		printf(" %d", *(x + i));
	}
	return 0;
}
/*
*
*/