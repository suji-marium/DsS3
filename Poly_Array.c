#include <stdio.h>

typedef struct
{
    int coeff;
    int expo_x;
    int expo_y;
    int expo_z;
} terms;

void main()
{
    int i,n;
    printf("Enter number of terms in the expression :");
    scanf("%d",&n);

    terms poly[n];

    for(i=0;i<n;i++)
    {
        printf("\n");
        printf("Enter coefficient of term %d ",(i+1));
        scanf("%d",&poly[i].coeff);
        printf("Enter exponent of x in term %d ",(i+1));
        scanf("%d",&poly[i].expo_x);
        printf("Enter exponent of y in term %d ",(i+1));
        scanf("%d",&poly[i].expo_y);
        printf("Enter exponent of z in term %d ",(i+1));
        scanf("%d",&poly[i].expo_z);
    }

    printf("The expression is : ");
    for(i=0;i<n;i++)
    {
        printf("%d x^%d y^%d z^%d",poly[i].coeff,poly[i].expo_x,poly[i].expo_y,poly[i].expo_z);
        if(i<n-1)
            printf(" + ");
  }
}
