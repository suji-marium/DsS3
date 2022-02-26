#include <stdio.h>
int bsearch(int [],int,int,int);
void bsort(int [],int);
void swap(int *,int *);
void print(int [],int);

int i,j;
void main()
{
        int n,y,key,a[100];
        printf("Enter size of the array:");
        scanf("%d",&n);
        printf("Enter the array elements: \n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        bsort(a,n);
        print(a,n);
        printf("Enter element to be searched:");
        scanf("%d",&key);
        y=bsearch(a,0,n-1,key);
        if(y!=0)
            printf("%d is present at position %d",key,y);
        else
            printf("Element is not present in the list");
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
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

void print(int a[],int n)
{
    printf("Sorted elements:\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}

int bsearch(int a[],int f,int l,int key)
{
    if(f<=l)
    {
        int m=(f+l)/2;
        if(a[m]==key)
            return(m+1);
        else
            {
                if(a[m]>key)
                    bsearch(a,f,m-1,key);
                else
                    bsearch(a,m+1,l,key);
            }
    }
    else
        return 0;
}



