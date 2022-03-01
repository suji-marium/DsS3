#include <stdio.h>
#define size 50

int isfull();
int isempty();
void insert_front(int item);
void insert_rear(int item);
int delete_front();
int delete_rear();
void display();

int q[size],n=size,f=-1,r=-1,item;

void main()
{
  int ch;
  do
  {
    printf("\n1.Insert the item from front \n2.Insert the item from back \n3.Delete the item from front \n4.Delete the item from back\n5.Display the queue \n6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
      {
        case 1:
            printf("Enter the item to be inserted frm front:");
            scanf("%d",&item);
            insert_front(item);
            break;
            
        case 2:
            printf("Enter the item to be inserted from rear:");
            scanf("%d",&item);
            insert_rear(item);
            break;  
            
        case 3:
            item=delete_front();
            if(item!=-1)
                printf("Item deleted from front is %d\n",item);
            break;
        
        case 4:
            item=delete_rear();
            if(item!=-1)
                printf("Item deleted from rear is %d\n",item);
            break;
            
        case 5:
            display();
            break;
        
        case 6:
            break;
            
        default:
            printf("Invalid choice\n");
      }
   } while(ch!=6);
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

void insert_front(int item)
{
    if(isfull())
        printf("Queue is full\n");
    else
    {
        if(f==-1 && r==-1)
            f=r=0;
        else
            f=(f+n-1)%n;
        q[f]=item;
    }
}

void insert_rear(int item)
{
    if(isfull())
        printf("Queue is full\n");
    else
    {
        if(f==-1 && r==-1)
            f=r=0;
        else
            r=(r+1)%n;
        q[r]=item;
    }
}

int delete_front()
{
    if(isempty())
      {
          printf("Queue is empty\n");
          return -1;
      }
    else
    {
        item=q[f];
        if(f==-r)
            f=r=-1;
        else
            f=(f+1)%n;
       return item;
    }
}

int delete_rear()
{
    if(isempty())
      {
          printf("Queue is empty\n");
          return -1;
      }
    else
    {
        item=q[r];
        if(f==r)
            f=r=-1;
        else
            r=(r+n-1)%n;
       return item;
    }
}

void display()
{
    int i;
    printf("Elements in the queue are: \t");
    for(i=f;i!=r;i=(i+1)%n)
        printf("%d \t",q[i]);
    printf("%d",q[r]);
}

