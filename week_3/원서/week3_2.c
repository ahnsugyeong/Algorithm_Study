/*
	1. �������� ���� �Լ� sort
	2. �ż� �ο� ����ϴ� �Լ� buy
*/
#include <stdio.h>
#include <stdlib.h>
void sort(int *arr,int N) {//�������� ����
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
	int buycnt=0;//�ż��ο�
	if (N == 1) printf("0");//�ĺ��� 1�� �ż� X
	else {
		while (arr[0] <= arr[1]) {//arr[0] -> �ټ� arr[1] -> �ִٵ�ǥ �ĺ���
			arr[0]++; arr[1]--; buycnt++; //�ż� ����
			sort(arr, N);//�������� ����
		}
		printf("%d", buycnt);
	}
}
int main() {
	int cand,*vote;
	scanf("%d",&cand);//�ĺ��� ��
	vote = (int*)malloc(sizeof(int)*cand);//�ĺ��� ����ŭ �Ҵ�
	for (int i = 0; i < cand; i++) {
		scanf("%d", &vote[i]);//���� ǥ�� �Է�
	}
	sort(vote, cand);//�������� ����
	buy(vote, cand);//�ż��ο� ���
	free(vote);
}