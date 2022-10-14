#include <stdio.h>
#include <stdlib.h>
/*1. 이진탐색은 배열이 정렬되어 있는 경우에만 사용 가능하다.*/

int find(int *arr, int k, int L, int R);
void print(int *arr, int n);


int main() {
	int n, *arr, k, RES;
	scanf("%d %d", &n, &k);
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

	RES = find(arr, k, 0, n - 1);
	printf(" %d", RES);
}
int find(int *arr, int k, int L, int R) {//partition 필요 없고 가장 왼쪽, 오른쪽 값 정해준다.
	int mid;
	
	if (L > R) { 
		if (R==-1)
			return -1;
		else 
			 return R; 
	
	}// return (important)
	mid = (L + R) / 2;
	if (arr[mid] == k) {
		while (arr[mid] == arr[mid + 1]) mid++;
		return mid;
	}
	else if (arr[mid] > k) {
		return find(arr, k, L, mid - 1);
	}
	else {
		return find(arr, k, mid + 1, R);
	}
}

void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

/*
8 33
-92 -31 -7 4 14 20 29 44
*/