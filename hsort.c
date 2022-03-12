#include <stdio.h>
void read(int a[],int n);
void heapsort(int a[],int size);
void buildheap(int a[],int size);
void heapify(int a[],int size,int i);
void print(int a[],int n);
void swap(int *p,int *q);

int i,n;
int main()
{
   int a[100];
   printf("Enter number of elements in the array:");
   scanf("%d",&n);
   read(a,n);
   heapsort(a,n);
   print(a,n);
}

void read(int a[],int n)
{
    printf("Enter array elements\n");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        
    printf("\nArray before sorting:\t");
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);
}

void heapsort(int a[],int size)
{
    buildheap(a,size);
    n=size;
    for(i=1;i<n;i++)
        {
            swap(&a[1],&a[size]);
            size=size-1;
            heapify(a,size,1);
        }
        
}

void buildheap(int a[],int size)
{
    for(i=n/2;i>=1;i--) 
        heapify(a,size,i);
}

void heapify(int a[],int size,int i)
{
    int lc,rc,lar;
    lc=2*i;
    rc=2*i+1;
    lar=i;
    
    if(lc<=size && a[lc]>a[lar])
        lar=lc;
    if(rc<=size && a[rc]>a[lar])
        lar=rc;
    if(i!=lar)
    {
        swap(&a[lar],&a[i]);
        heapify(a,size,lar);
    }
}

void print(int a[],int n)
{
    printf("\nArray after sorting:\t");
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);
}

void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
