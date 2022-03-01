#include <stdio.h>
#define size 50
int isfull();
int isempty();
void push(int );
int pop();
int peek();
void display();

int s[size],top=0,item;
void main()
{
  int ch;
  do
  {
    printf("\n1.Push the item \n2.Pop the item \n3.Peek the item \n4.Display the stack \n5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
      {
        case 1:
            printf("Enter the item to be inserted:");
            scanf("%d",&item);
            push(item);
            break;
            
        case 2:
            item=pop();
            if(item!=-1)
                printf("Item retrieved is %d\n",item);
            break;
            
        case 3:
            item=peek();
            if(item!=-1)
                printf("Item is %d\n",item);
            break;
            
        case 4:
            display();
            break;
        
        case 5:
            break;
            
        default:
            printf("Invalid choice\n");
      }
   } while(ch!=5);
}



int isfull()
{
    if(top==size)
            return 1;
    else
            return 0;
}

int isempty()
{
    if(top==0)
            return 1;
    else 
            return 0;
}

void push(int item)
{
    if(isfull())
            printf("Stack is full");
    else
     {
            s[top]=item;
            top++;
     }
}

int pop()
{
    if(isempty())
       {
            printf("Stack is empty");
            return -1;
       }
    else
       {
            top--;
            item=s[top];
            return item;
       }
}

int peek()
{
    if(isempty())
       {
            printf("Stack is empty");
            return -1;
       }
    else
       {
            item=s[top-1];
            return item;
       }
}

void display()
{
    int i;
    printf("Elements in the stack is \t");
    for(i=0;i<top;i++)
    {
        printf("%d \t",s[i]);
    }
    printf("\n");
}



