#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int info;
    struct Node *next;
};

typedef struct Node node;

void insert(int item);
int delete();
void display();
node *newnode();

node *front=NULL,*rear=NULL,*p;
int item;

int main()
{
    int ch;
    do
      {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d",&item);
                insert(item);
                printf("Item inserted..");
                printf("\n");
                break;
                
            case 2:
                item=delete();
                if(item!=-1)
                    printf("Item deleted is %d",item);
                printf("\n");
                break;
                    
            case 3:
                display();
                printf("\n");
                break;
                
            case 4:
                printf("Exiting..");
                break;
                
            default:
                printf("Invalid entry..");
                printf("\n");
        }
    }while(ch!=4);
}

void insert(int item)
{
    p=newnode();
    if(p==NULL)
        printf("Insufficient memory");
    else
        p->info=item;
        if(front==NULL)
            front=rear=p;
        else
        {
            rear->next=p;
            rear=p;
        }
}

int delete()
{
    if(front==NULL)
    {
        printf("Queue is empty");
        return -1;
    }
    else 
        {
            item=front->info;
            p=front;
            if(front==rear) 
                front=rear=NULL;
            else
                front=front->next;
            free(p);
            return item;
        }
       
}

void display()
{
    node *curr;
    curr=front;
    printf("Elements in the Queue are:\t");
    while(curr!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    }
}

node *newnode()
{
    p=(node *)malloc(sizeof(node));
    return p;
}
