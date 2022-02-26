#include <stdio.h>
void read(int [],int);
void bsort(int [],int);
void swap(int *,int *);
void display(int [],int);

int i,j;
void main()
{
    int a[100],n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    read(a,n);
    bsort(a,n);
    display(a,n);
}

void read(int a[],int n)
{
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
         scanf("%d",&a[i]);
}

void bsort(int a[],int n)
{
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
}

void swap(int *p,int *q)
{
    int r;
    r=*p;
    *p=*q;
    *q=r;
}

void display(int a[],int n)
{
    printf("Sorted Elements are :\n");
    for(i=0;i<n;i++)
        printf("%d \n",a[i]);
}
