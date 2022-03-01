#include <stdio.h>
void read(int a[],int n);
void isort(int a[],int n);
void print(int a[],int n);

int i,j;

void main()
{
   int a[100],n;
   printf("Enter number of elements in the array: ");
   scanf("%d",&n);
   read(a,n);
   isort(a,n);
   print(a,n);
}

void read(int a[],int n)
{
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("Array before sorting : ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

}

void isort(int a[],int n)
{
    int key;
    for(i=1;i<n;i++)
     {  key=a[i];
        for(j=i-1;j>=0 && a[j]>key;j--)
            a[j+1]=a[j];
        a[j+1]=key;
     }
}

void print(int a[],int n)
{
    printf("\nArray after sorting :\t");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
}
