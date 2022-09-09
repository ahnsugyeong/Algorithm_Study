#include <stdio.h>
#include <stdlib.h>
void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
}
void sort2(int *arr,int n) {
	int tmp;
	for (int i = 1; i < n; i++) {
		for (int j = i; j >0; j--) {
			if (arr[j] < arr[j-1]) {
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
}
int main() {
	int n,*arr;
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }
	sort2(arr, n);
	print(arr, n);

}