//
//  main.c
//  week3_2
//
//  Created by 정희호 on 2022/09/20.
//

#include<stdio.h>

int H[100];
int n;

void downHeap(int i)
{
    int tmp,bigKey;
    if (i*2>n && i*2+1>n)    return;
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


void rBuildHeap(int i)
{
    if(i>n)    return;
    rBuildHeap(2*i);
    rBuildHeap(2*i+1);
    downHeap(i);
}
void buildHeap() {
    int i;
    for(i=n/2;i>=1;i--){
        downHeap(i);
    }
}

void printHeap()
{
    int i;
    for(i=1;i<n+1;i++)
        printf(" %d",H[i]);
    printf("\n");
}
int main()
{
    int i;
    scanf("%d",&n);

    for(i=1;i<n+1;i++){
        scanf("%d",&H[i]);
    }

    buildHeap();
    printHeap();

}
