#include <stdio.h>
#include <stdlib.h>
void main()
{
    printf("Enter the number of entries :-  ");
    int n;
    scanf("%d",&n);
    double M[n][n+1];
    printf("Enter the elements:-\nEnter the values of the X\n");
    for(int j=0;j<2;j++)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&M[i][j]);
        }
        printf("Enter the Y elements:-\n");
    }
    printf("Forward Difference Operator Table \n");
    printf("X    Y\n");
    int temp = n;
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<temp;i++)
        {
            M[i][j+1]=M[i+1][j]-M[i][j];
        }
        temp=temp-1;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<2;j++)
        {
            printf("%.2lf    ",M[i][j]);
        }
        for(int k=2;k<=n-i;k++)
        {
            printf("%.2lf  ",M[i][k]);
        }
        printf("\n");
    }
    
}
