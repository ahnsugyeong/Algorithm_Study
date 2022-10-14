#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find(char *answer,int l,int r);
int main() {
	int a, b, answercnt,k,target;
	char *answer;

	scanf("%d %d %d", &a, &b, &answercnt);
	answer = (char*)malloc(sizeof(char)*(answercnt + 1));
	scanf("%s", answer);
	target = find(answer, a, b);
	printf("%d", target);
	
}
int find(char *answer,int l,int r) {
	int mid, L = l, R = r,RES;
	for (int i = 0; i < strlen(answer); i++) {
		mid = (L + R) / 2;
		if (answer[i] == 'Y') {//target > mid
			L = mid + 1;
			RES = L;
		}
		else if (answer[i] == 'N') {//target< mid
			R = mid;
			RES = R;
		}
		printf("RES : %d\n", RES);
	}
	return RES;
}