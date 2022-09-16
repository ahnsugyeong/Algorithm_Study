//
//  main.c
//  week2_1
//
//  Created by 정희호 on 2022/09/13.
//


#include<stdio.h>
#include<stdlib.h>

void sorttest(int *arr,int num){
    int i,j,max=0,maxindex=0,tmp;

    for(i=0;i<num-1;i++){
        max=arr[0];
        maxindex=0;
        for(j=0;j<num-i;j++){
            if(max<arr[j]){    //최대값 찾고
                max=arr[j];
                maxindex=j;
            }
        }
        tmp=arr[num-i-1];    //바꾸기
        arr[num-i-1]=max;
        arr[maxindex]=tmp;
    }
}

int main()
{
    int num,i,tmp;
    int *ar;

    scanf("%d",&num);
    ar= (int *)malloc(sizeof(int)*num);

    for(i=0;i<num;i++){    //입력받고 배열에 저장
        scanf("%d",&tmp);
        ar[i]=tmp;
    }

    sorttest(ar,num);    //정렬 진행

    for(i=0;i<num;i++){    //전체 배열 출력
        printf(" %d",ar[i]);
    }
    
    free(ar);
}
