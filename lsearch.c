#include <stdio.h>
int lsearch (int [],int,int );
int i;

void main()
{
        int a[100],n,y,key;
        printf("Enter the size of the array:");
        scanf("%d",&n);
        printf("Enter array elements:\n");
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("Enter element to be searched:");
        scanf("%d",&key);
        y=lsearch(a,n,key);
        if(y!=0)
            printf("%d is present at %d position",key,y);
        else
            printf("Element is not present in the array");
}

int lsearch(int a[],int n,int key)
{
        for(i=0;i<n;i++)
            if(a[i]==key)
                return (i+1);
        return 0;
}
