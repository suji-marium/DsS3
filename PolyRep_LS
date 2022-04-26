#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff,expo;
    struct node *next;
};

typedef struct node poly;
poly *newnode();
poly *readpoly();
poly *displaypoly(poly *temp);

int main()
{
    poly *poly1;
    printf("Enter the polynomial expression\n");
    poly1=readpoly();
    printf("The polynomial expression is");
    displaypoly(poly1);
}

poly *newnode()
{
    poly *p;
    p=(poly *)malloc(sizeof (poly));
    return p;
}

poly *readpoly()
{
    int ch;
    poly *temp,*head;
    temp=newnode();
    head=temp;
    do 
    {
        printf("Enter coefficient and exponent of the term \n");
        scanf("%d",&temp->coeff);
        scanf("%d",&temp->expo);
        printf("Continue adding more terms to the list: Y-1,N-0");
        scanf("%d",&ch);
        if(ch)
        {
            temp->next=newnode();
            temp=temp->next;
        }
    }while(ch);
    return (head);
}

poly *displaypoly(poly *temp)
{
    while(temp!=NULL)
    {
        printf(" %d x^ %d ",temp->coeff,temp->expo);
        temp=temp->next;
        if(temp!=NULL)
            printf(" + ");
    }
}
