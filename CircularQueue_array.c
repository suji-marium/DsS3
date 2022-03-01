#include <stdio.h>
# define size 100

int isfull();
int isempty();
void insert(int);
int delete();
void display();

int q[size],f=-1,r=-1,n=size,item;
void main()
{
  int ch;
  do
  {
    printf("\n1.Insert the item \n2.Delete the item \n3.Display the queue \n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
      {
        case 1:
            printf("Enter the item to be inserted:");
            scanf("%d",&item);
            insert(item);
            break;
            
        case 2:
            item=delete();
            if(item!=-1)
                printf("Item deleted is %d\n",item);
            break;
            
        case 3:
            display();
            break;
        
        case 4:
            break;
            
        default:
            printf("Invalid choice\n");
      }
   } while(ch!=4);
}

int isfull()
{
    if(f==(r+1)%n)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(r==-1 && f==-1)
        return 1;
    else
        return 0;
}

void insert(int item)
{
    if(isfull())
        printf("Queue is full");
    else
    {
        if(f==-1 && r==-1)
            f=r=0;
        else
            r=(r+1)%n;
        q[r]=item;
    }
}

int delete()
{
    if(isempty())
      {
        printf("Queue is empty");
        return -1;
      }
    else
    {
        item=q[f];
        if(f==r)
            f=r=-1;
        else
            f=(f+1)%n;
        return item;
    }
}

void display()
{
    int i;
    printf("Elements in the queue are: \t");
    for(i=f;i!=r;i=(i+1)%n)
        printf("%d \t",q[i]);
    printf("%d\n",q[r]);
}


