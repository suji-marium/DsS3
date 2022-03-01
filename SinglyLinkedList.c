#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int info;
    struct NODE *next;
};

typedef struct NODE node;

node *newnode();
int insertfirst(int item);
int insertafter(int item1,int item);
int insertbefore(int item1,int item);
int deletenode(int item);
void display();
void NoofNode();

node *head=NULL, *p;
int item,item1;

void main()
 { 
  int ch;
  do
  {
    printf("\n1.Insert the node in the front \n2.Insert the node after an node \n3.Insert the node before an node  \n4.Delete the node \n5.Display the items in the node \n6.Diplay the number of nodes \n7.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
      {
        case 1:
            printf("Enter the item to be inserted in the front:");
            scanf("%d",&item);
            insertfirst(item);
            break;
            
        case 2:
            printf("Enter the item after which the item is to be placed:")    ;
            scanf("%d",&item1);
            printf("Enter the item to be inserted:");
            scanf("%d",&item);
            insertafter(item1,item);
            printf("\n");
            break;  
            
        case 3:
            printf("Enter the item before which the item is to be placed:");  
            scanf("%d",&item1);
            printf("Enter the item to be inserted:");
            scanf("%d",&item);
            insertbefore(item1,item);
            printf("\n");
            break;
        
        case 4:
            printf("Enter the item to be deleted:");
            scanf("%d",&item);
            deletenode(item);
            printf("\n");
            break;
            
        case 5:
            display();
            printf("\n");
            break;
            
        case 6:
            NoofNode();
            printf("\n");
            break;
            
        case 7:
            break;
            
        default:
            printf("Invalid choice\n");
      }
   } while(ch!=7);
}


node *newnode()
{
    p=(node *)malloc(sizeof (node));
    return p;
}

int insertfirst(int item)
{
    p=newnode();
    p->info=item;
    p->next=head;
    head=p;
}

int insertafter(int item1,int item)
{
    node *curr=head;
    while(curr!=NULL && curr->info!=item1)
        curr=curr->next;
        
    if(curr==NULL)
        printf("No such nodes");
    else
     {
        p=newnode();
        p->info=item;
        p->next=curr->next;
        curr->next=p;
     }
}

int insertbefore(int item1,int item)
{
    node *curr=head,*prev=NULL;
    while(curr!=NULL && curr->info!=item1)
    {
        prev=curr;        
        curr=curr->next;
    }
    
    if(curr==NULL)
        printf("No such nodes");
    else
    {
        p=newnode();
        p->info=item;
        p->next=curr;
        if(curr==head)
            head=p;
        else
            prev->next=p;
    }
}

int deletenode(int item)
{
    node *curr=head,*prev=NULL;
    while(curr!=NULL && curr->info!=item)
    {
        prev=curr;        
        curr=curr->next;
    }
    
    if(curr==NULL)
        printf("No such nodes");
    else
    {
        item=curr->info;
        if(curr==head)
            head=curr->next;
        else
            prev->next=curr->next;
        free(curr);
        return item;
    }
}

void display()
{
    node *curr=head;
    printf("Elements in the node are:\t");
    while(curr!=NULL)
       {
        printf("%d \t",curr->info);
        curr=curr->next;
       }
}

void NoofNode()
{
    node *curr=head;
    int c=0;
    while(curr!=NULL)
       {
        c++;
        curr=curr->next;
       }
    printf("No of nodes: %d",c);
}

