#include <stdio.h>
#include <stdlib.h>
void main()
{
    printf("Enter the number of entries :-  ");
    int n;
    scanf("%d",&n);
    double M[n][n+1];
    printf("Enter the elements:-\nEnter the values of the X and Y\n");
    for(int j=0;j<2;j++)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&M[i][j]);
        }
    }
    printf("Backward Difference Operator Table\n");
    printf("X     Y\n");
    int temp1 = 1;
    for(int j=1;j<n;j++)
    {
        for(int i=temp1;i<5;i++)
        {
            M[i][j+1]=M[i][j]-M[i-1][j];
        }
        temp1=temp1+1;
    }

       for (int i=0;i<n;i++)
    {
        for (int j=0;j<=i+1;j++)
        {
            printf("%.2lf  ",M[i][j]);
        }
        printf("\n");
    }
    }
