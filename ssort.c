#include <stdio.h>
void read(int [],int);
void ssort(int [],int);
void swap(int *,int *);
void print(int [],int );

int i,j;
void main()
{
    int a[100],n;
    printf("Enter number of elements in the array:");
    scanf("%d",&n);
    read(a,n);
    ssort(a,n);
    print(a,n);
}

void read(int a[],int n)
{
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Array before sorting is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void ssort(int a[],int n)
{
    int small,ind;
    for(i=0;i<n-1;i++)
    {
        small=a[i];
        ind=i;
        for(j=i+1;j<n;j++)
            if(a[j]<small)
            {
                small=a[j];
                ind=j;
            }
        swap(&a[i],&a[ind]);
    }
}

void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

void print(int a[],int n)
{
    printf("\nSorted array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
