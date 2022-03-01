#include <stdio.h>
void read(int [],int );
int partition(int [],int ,int );
void qsort(int [],int ,int );
void print(int [],int );
void swap(int *,int *);
int i,j;

void main()
{
    int a[100],n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    read(a,n);
    qsort(a,0,n-1);
    print(a,n);
}

void read(int a[],int n)
{
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Array before sorting: \t");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
}

void qsort(int a[],int lb,int ub)
{
    int pos;
    if(lb<ub)
    {
        pos=partition(a,lb,ub);
        qsort(a,lb,pos-1);
        qsort(a,pos+1,ub);
    }
}

int partition(int a[],int l,int r)
{
    i=l+1,j=r;
    int key;
    key=a[l];
        
    do  
      {
        while(a[i]<key && i<r)
            i++;
        while(a[j]>key && j>l)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
      } while(i<j);
      
    swap(&a[j],&a[l]); 
    return j;
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
   printf("\nArray after sorting: \t");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
}

