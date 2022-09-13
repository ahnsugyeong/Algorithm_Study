#include<stdio.h>
#include<stdlib.h>

void sorttest(int *arr,int num){
    int i,j,target;

    for(i=1;i<num;i++){
        target=arr[i];
        for(j=i-1;j>=0;j--){
            if(target<arr[j]) arr[j+1]=arr[j];
            else break;
        }
        arr[j+1]=target;
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
