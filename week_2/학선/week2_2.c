#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	int* x = (int)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	int cnt = 1;
	while (cnt < n) {
		for (int i = 0; i < cnt; i++) {
			if (x[cnt] < x[i]) {
				int tmp = x[cnt];
				for (int j = cnt; j >= i; j--) {
					x[j] = x[j-1];
				}
				x[i] = tmp;
				break;
			}
			
		}
		cnt++;
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