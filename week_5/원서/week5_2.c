#include <stdio.h>
typedef struct index {
	int L, R;
}index;

int findpivot(int *L, int l, int r);
void inPlaceQuickSort(int *L, int l, int r);
index inPlacePartition(int *L, int l, int r, int k);
void print(int *arr, int n);
int main() {
	int n,*arr;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
	}

	inPlaceQuickSort(arr, 0, n-1);
	print(arr,n);
}
void inPlaceQuickSort(int *L, int l, int r) {
	int k,a,b;
	index RES;

	if (l >= r) return;
	k = findpivot(L, l, r);
	
	RES = inPlacePartition(L, l, r, k);
	a = RES.L;//a값 ==  최대값 of smaller than pivot
	b = RES.R;//b값 == 최소값 of bigger than pivot
	//L[a]~L[b]까지는 same 

	inPlaceQuickSort(L, l, a-1);
	inPlaceQuickSort(L, b+1, r);
}
int findpivot(int *L, int l, int r) {
	int pivot;
	pivot = l;
	return pivot;
}
index inPlacePartition(int *L, int l, int r, int k) {
	int LE, R,tmp, rr;
	index RES;
	rr = r;
	while (1) {
		while (L[k] >= L[l] && l < r)
		{
			l++;
		}//pivot보다 큰 값 찾기 && 존재X시 r == n
		while (L[k] <= L[r] && r > k)
		{
			r--;
		}//pivot보다 smaller 값 && 존재 x시 r==pivot
		
		if (l >= r) {
			tmp = L[k];
			L[k] = L[r];
			L[r] = tmp;
			break;
		}
		tmp = L[l];
		L[l] = L[r];
		L[r] = tmp;
		
	}
		
	
	LE = r; R = r;//save r in L, R
	while (L[LE] == L[LE - 1] && LE>0) { LE--; }
	while (L[R] == L[R + 1] && R<rr) { R++; }

	RES.L = LE;
	RES.R = R;
	return RES;
}

void print(int *arr,int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
}