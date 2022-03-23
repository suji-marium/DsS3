#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int info;
    struct Node *next;
};

typedef struct Node node;

void push(int item);
int pop();
void display();
node *newnode();

node *top,*p;
int item;

int main()
{
    int ch;
    do
      {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter item to be pushed: ");
                scanf("%d",&item);
                push(item);
                printf("Item pushed..");
                printf("\n");
                break;
                
            case 2:
                item=pop();
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

void push(int item)
{
    p=newnode();
    if(p==NULL)
        printf("Insufficient memory");
    else
        {
            p->info=item;
            p->next=top;
            top=p;
        }
}

int pop()
{
    if(top==NULL)
        {
            printf("Queue is empty");
            return -1;
        }
    else
        {
            item=top->info;
            p=top;
            top=top->next;
            free (p);
            return item;
        }
}

void display()
{
    node *curr;
    curr=top;
    printf("Elements in the stack: \t");
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

