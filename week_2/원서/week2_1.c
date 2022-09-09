#include <stdio.h>
#include <stdlib.h>
void sort1(int *arr,int n) {
	int max, index,tmp,tmpj;
	max = 0;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (max < arr[j]) {
				max = arr[j];
				index = j;
			}
			tmpj = j;
		}
		tmp = arr[index];
		arr[index] = arr[tmpj];
		arr[tmpj] = tmp;
		max = 0;
	}
}
void print(int *arr, int n) { 
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
}
int main() {
	int n,*arr;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

	sort1(arr, n);
	print(arr, n);

}