/*
	1. 내림차순 정렬 함수 sort
	2. 매수 인원 출력하는 함수 buy
*/
#include <stdio.h>
#include <stdlib.h>
void sort(int *arr,int N) {//내림차순 정렬
	int max = 0,tmp,index;
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (arr[j] > max) {
				max = arr[j];
				index  = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;		
		max = 0;
	}
}
void buy(int *arr, int N) {
	int buycnt=0;//매수인원
	if (N == 1) printf("0");//후보가 1명 매수 X
	else {
		while (arr[0] <= arr[1]) {//arr[0] -> 다솜 arr[1] -> 최다득표 후보자
			arr[0]++; arr[1]--; buycnt++; //매수 진행
			sort(arr, N);//내림차순 정렬
		}
		printf("%d", buycnt);
	}
}
int main() {
	int cand,*vote;
	scanf("%d",&cand);//후보자 수
	vote = (int*)malloc(sizeof(int)*cand);//후보자 수만큼 할당
	for (int i = 0; i < cand; i++) {
		scanf("%d", &vote[i]);//받은 표수 입력
	}
	sort(vote, cand);//내림차순 정렬
	buy(vote, cand);//매수인원 출력
	free(vote);
}