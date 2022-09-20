//
//  main.c
//  week_3
//
//  Created by 정희호 on 2022/09/20.
//

#include <stdio.h>

int H[100];
int n;

void upHeap(int i)
{
    int tmp;
    if(i==1)    return;
    if(H[i]<H[i/2])    return;
    tmp=H[i];
    H[i]=H[i/2];
    H[i/2]=tmp;
    upHeap(i/2);
}

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

void insertkey(int key)
{
    n++;
    H[n]=key;
    upHeap(n);
}

int removeMax()
{
    int key=H[1];
    H[1]=H[n];
    n--;
    downHeap(1);
    return key;
}

void printHeap()
{
    int i;
    for(i=1;i<n+1;i++) printf(" %d",H[i]);
    printf("\n");
}

int main()
{
    int key;
    char func;

    n=0;
    while(1)
    {
        scanf("%c",&func);

        switch(func)
        {
        case 'i':
            scanf("%d",&key);
            insertkey(key);
            printf("0\n");
            break;
        case 'd':
            printf("%d\n",removeMax());
            break;
        case 'p':
            printHeap();
            break;
        case 'q':
            return 0;
        }
    }
}
