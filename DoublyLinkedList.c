#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node node;

void Insertfirst(int item);
void Insertbefore(int item1,int item);
void Insertafter(int item1,int item) ;
void Delete(int item);
void traverse_right();
void traverse_left();
node *newnode();

node *head=NULL,*tail=NULL,*curr,*p;
int main()
{
    int ch,item,item1;
    do
    {
        printf("\n1.Insertfirst \n2.Insertbefore \n3.Insertafter \n4.Delete \n5.Traverse to right \n6.Traverse to left \n7.Exit");
        printf("\n\nEnter your choice:");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                printf("Enter item to be inserted at first: ");
                scanf("%d",&item);
                Insertfirst(item);
                printf("\n");
                break;
                
            case 2:
                printf("Enter item to be inserted: ");
                scanf("%d",&item);
                printf("Enter before which item the new item is to be placed: ");
                scanf("%d",&item1);
                Insertbefore(item1,item);
                printf("\n");
                break;
            
            case 3:
                printf("Enter item to be inserted: ");
                scanf("%d",&item);
                printf("Enter after which item the new item is to be placed: ");
                scanf("%d",&item1);
                Insertafter(item1,item);
                printf("\n");
                break;
                
            case 4:
                printf("Enter item to be deleted: ");
                scanf("%d",&item);
                Delete(item);
                printf("\n");
                break;
                
            case 5:
                traverse_right();
                printf("\n");
                break;
            
            case 6:
                traverse_left();
                printf("\n");
                break;
                
            case 7:
                printf("Exiting...");
                break;
            
            default:
                printf("Invalid choice");
                printf("\n");
        }
    }while(ch!=7);
}

node *newnode()
{
    p=(node *)malloc(sizeof(node));
    p->prev=NULL;
    p->next=NULL;
    return p;
}

void Insertfirst(int item)
{
    p=newnode();
    p->info=item;
    p->prev=NULL;
    p->next=head;
    if(head==NULL)
        head=tail=p;
    else
      {
        head->prev=p;  
        head=p;
      }
}

void Insertbefore(int item1,int item)
{
    curr=head;
    while(curr!=NULL && curr->info!=item1)
        curr=curr->next;
    if(curr==NULL)
        printf("No such node");
    else
      {
        p=newnode();
        p->info=item;
        p->next=curr;
        p->prev=curr->prev;
        if(curr==head)
            head=p;
        else
            curr->prev->next=p;
        curr->prev=p;
      }
}
        
void Insertafter(int item1,int item) 
{
    curr=head;
    while(curr!=NULL && curr->info!=item1)
        curr=curr->next;
    if(curr==NULL)
        printf("No such node");
    else
     {
        p=newnode();
        p->info=item;
        p->prev=curr;
        p->next=curr->next;
        if(curr==tail)
            tail=p;
        else
            curr->next->prev=p;
        curr->next=p;
     }
}
        
void Delete(int item)
{
    curr=head;
    while(curr!=NULL && curr->info!=item)
        curr=curr->next;
    if(curr==NULL)
        printf("No such node");
    else
     {
        if(curr==head) 
            head=curr->next;
        else
            curr->prev->next=curr->next;
        if(curr==tail)
            tail=curr->prev;
        else
            curr->next->prev=curr->prev;
        free(curr);
     }
}
        
void traverse_right()
{
    curr=head;
    printf("\nItem from left to right:\t");
    while(curr!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    }
}

void traverse_left()
{
    curr=tail;
    printf("\nItem from right to left:\t");
    while(curr!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->prev;
    }
}
