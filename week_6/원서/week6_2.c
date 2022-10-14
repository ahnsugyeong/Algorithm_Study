#include <stdio.h>
#include <stdlib.h>
/*1. 이진탐색은 배열이 정렬되어 있는 경우에만 사용 가능하다.*/
int find(int *arr, int k, int l, int r);
int main() {
	int n, k,*arr,RES;
	scanf("%d %d", &n,&k);
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	RES = find(arr, k, 0, n-1);
	printf("%d", RES);
}
int find(int *arr, int k, int l, int r) {
	int mid,L,R,RES;
	L = l; R = r;
	while (1){
		mid = (L + R) / 2;
		if (L > R) {
			if (L == l) { RES = 0; break; }
			RES = mid + 1;
			break;
		}
		if (arr[mid] == k) { 
			while (arr[mid] == arr[mid - 1]) mid--;
			RES = mid;
			break;
		}
		else if (arr[mid] < k) {
			L = mid + 1;
		}
		else if (arr[mid] > k) {
			R = mid - 1;
		}
	}
	return RES;
}
/*
8 

-92 -31 -7 4 14 20 29 44
*/