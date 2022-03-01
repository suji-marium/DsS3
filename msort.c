#include <stdio.h>
void read(int [],int );
void msort(int [],int,int);
void simplemerge(int [],int ,int ,int );
void print(int [],int );

int i,j;
void main()
{
   int a[100],n;
   printf("Enter number of elements in the array: ");
   scanf("%d",&n);
   read(a,n);
   msort(a,0,n-1);
   print(a,n);
}

void read(int a[],int n)
{
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Array before sorting\t");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
}

void msort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        msort(a,beg,mid);
        msort(a,mid+1,end);
        simplemerge(a,beg,mid+1,end);
    }
}

void simplemerge(int a[],int f,int s,int l)
{
    int temp[100],k=0;
    i=f,j=s;
    while(i<s && j<=l)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<s)
        temp[k++]=a[i++];
    
    while(j<=l)   
        temp[k++]=a[j++];
        
    for(i=f,j=0;j<k;)
        a[i++]=temp[j++];
}

void print(int a[],int n)
{
    printf("\nArray after sorting\t");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
}

