#include <stdio.h>
#define max 50

int instackpri(char c);
int isfull();
int isempty();
void push(char a);
char pop();
char peek();
int inputpri(char c);
void displayStack();
void displayPost(char a[],int k);

int top=0;
char s[max];
int isfull()
{
    if(top==max)
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

void push(char a)
{
    if(!isfull())
        s[top++]=a;
}

char pop()
{
    if(!isempty())
        return(s[--top]);
}

char peek()
{
    if(!isempty())
        return(s[top-1]);
}

int inputpri(char c)
{
    switch(c)
    {
        case '+':
        case '-':return 1;break;
        case '*':
        case '/':return 3;break;
        case '^':return 6;break;
    }
}

int instackpri(char c)
{
    switch(c)
    {
        case '+':
        case '-':return 2;break;
        case '*':
        case '/':return 4;break;
        case '^':return 5;break;
        case '(':return 0;break;
    }
}

int main()
{
    char exp[100],post[100],token,c;
    int i,j=0;
    printf("Enter the expression :");
    scanf("%[^\n]",exp);
    printf("Infix expression is %s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        token=exp[i];
        switch(token)
        {
            case '(': push(token);break;
            case ')': while((c=pop())!='(')
                        post[j++]=c;
                      break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^': while(!isempty() && (instackpri(peek())>inputpri(token)))
                        post[j++]=pop();
                      push(token);
                      break;
            default: post[j++]=token;
        }
            printf("\nToken %c",token);
            displayStack();
            displayPost(post,j);
    }
    while(!isempty())
        post[j++]=pop();
    post[j]='\0';
    
    printf("\nPostfix expression is %s",post);
}

void displayStack()
{
    int i;
    printf("\t Stack: ");
    for(i=0;i<top;i++)
        printf(" %c ",s[i]);
}

void displayPost(char a[],int k)
{
    int i;
    printf("\t Postfix: ");
    for(i=0;i<k;i++)
        printf(" %c ",a[i]);
}
