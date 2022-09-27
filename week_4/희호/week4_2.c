//
//  main.c
//  week4_2
//
//  Created by 정희호 on 2022/09/27.
//


#include<stdio.h>
#include<stdlib.h>

int *H;
int n;

void downHeap(int i)
{
    int tmp,bigKey;
    if (i*2>n)    return;
    bigKey=i*2;
    if(i*2+1<=n)
    {
        if(H[2*i+1]>H[bigKey])    bigKey=2*i+1;
    }
    if(H[i]>H[bigKey]) return;
    tmp=H[i];
    H[i]=H[bigKey];
    H[bigKey]=tmp;
    downHeap(bigKey);
}

void buildHeap() {
    int i;
    for(i=n/2;i>=1;i--){
        downHeap(i);
    }
}
void printArray(int tmp)
{
    int i;
    for(i=1;i<tmp+1;i++)
    {
        printf(" %d",H[i]);
    }
}
void inPlaceHeapSort()
{
    int i;
    int tmp;
    buildHeap();
    for(i=n;i>1;i--){
        tmp=H[1];
        H[1]=H[i];
        H[i]=tmp;
        n--;
        downHeap(1);
    }
}

int main()
{
    int i;
    int tmpnum;
    scanf("%d",&n);
    H = (int *)malloc(sizeof(int)*n+1);
    tmpnum=n;
    for(i=1;i<n+1;i++)
    {
        scanf("%d",&H[i]);
    }

    inPlaceHeapSort();
    printArray(tmpnum);

    return 0;
}

