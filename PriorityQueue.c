#include <stdio.h>
#define max 50

void Insert(int item);
int Delete();
void heapify(int a[],int size,int i);
void swap(int *p,int *q);
int PQ[max],Qsize=0,item;

int main()
{
    int ch;
    do
        {
            printf("\n1.Insert \n2.Delete \n3.Exit\n");
            printf("Enter your choice:");
            scanf("%d",&ch);
            
            switch(ch)
            {
                case 1:
                    printf("Enter item to be inserted: ");
                    scanf("%d",&item);
                    Insert(item);
                    break;
                
                case 2:
                    item=Delete();
                    if(item!=-1)
                        printf("Item deleted is %d",item);
                    printf("\n");
                        
                case 3:
                    break;
                    
                default:
                    printf("Invalid Entry");
            }
        }while(ch!=3);
}

void Insert(int item)
{
    int curr,par;
    if(Qsize==max)
        printf("Queue is full");
    else
    {
        Qsize=Qsize+1;
        PQ[Qsize]=item;
        curr=Qsize;
        par=curr/2;
    }
    
    while(par>=1 && PQ[par]>PQ[curr])
     {   
             swap(&PQ[par],&PQ[curr]);
             curr=par;
             par=curr/2;
      }
}

int Delete()
{
    if(Qsize==0)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        item=PQ[1];
        swap(&PQ[1],&PQ[Qsize]);
        Qsize=Qsize-1;
        heapify(PQ,Qsize,1);
        return item;
    }
}

void heapify(int a[],int size,int i)
{
    int lc,rc,small;
    lc=2*i;
    rc=2*i+1;
    small=i;
    
    if(lc<=size && a[lc]<a[small])
        small=lc;
    if(rc<=size && a[rc]<a[small])
        small=rc;
    if(i!=small)
    {
        swap(&a[small],&a[i]);
        heapify(a,size,small);
    }
}

void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
