#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int coeff,expo;
    struct node *next;
};

typedef struct node poly;

poly *readpoly();
poly *addpoly(poly *p1, poly *p2);
poly *displaypoly(poly *p);
poly *newnode();

int main()
{
    poly *poly1,*poly2,*poly3;
    printf("Enter first polynomial\n");
    poly1=readpoly();
    printf("Enter second polynomial\n");
    poly2=readpoly();
    printf("\nFirst polynomial is: ");
    displaypoly(poly1);
    printf("\nSecond polynomial is: ");
    displaypoly(poly2);
    poly3=addpoly(poly1,poly2);
    printf("Resultant polynomial is: ");
    displaypoly(poly3);
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
    poly *head,*temp;
    temp=newnode();
    head=temp;
    do 
    {
        printf("Enter coefficient of and exponent of the term \n");
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
    return head;
}

poly *addpoly(poly *p1, poly *p2)
{
    poly *poly3,*p3;
    poly3=newnode();
    p3=poly3;
    
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo==p2->expo)
            {
                p3->coeff=p1->coeff+p2->coeff;
                p3->expo=p1->expo;
                p1=p1->next;
                p2=p2->next;
            }
        else if(p1->expo > p2->expo)
            {
                p3->coeff=p1->coeff;
                p3->expo=p1->expo;
                p1=p1->next;
            }
        else
            {
                p3->coeff=p2->coeff;
                p3->expo=p2->expo;
                p2=p2->next;
            }
            
        if(p1!=NULL && p2!=NULL)
            {
                p3->next=newnode();
                p3=p3->next;
            }
    }
    
    while(p1!=NULL)
    {
        p3->next=newnode();
        p3=p3->next;
        p3->coeff=p1->coeff;
        p3->expo=p1->expo;
        p1=p1->next;
    }
    
    while(p2!=NULL)
    {
        p3->next=newnode();
        p3=p3->next;
        p3->coeff=p2->coeff;
        p3->expo=p2->expo;
        p2=p2->next;
    }
    printf("\nAddition Completed ");
    return(poly3);
}

poly *displaypoly(poly *p)
{
    while(p!=NULL)
    {
        printf("%d x^%d",p->coeff,p->expo);
        p=p->next;
        if(p!=NULL)
            printf(" + ");
    }
}
