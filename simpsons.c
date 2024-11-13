#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 1e-6

double simpsons(int n, double A[n][2], double h);

void main()
{
    printf("Enter the number of x values :- ");
    int n;
    scanf("%d",&n);
    double A[n][2];
    printf("Enter the values of x :-");
    for(int j=0;j<2;j++)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&A[i][j]);
        }
        printf("Enter the functional values of X\n");
    }
    double h=A[1][0]-A[0][0];
    for(int i=2;i<n;i++)
    {
        double p=(A[i][0]-A[i-1][0]);
        if(fabs(p - h) > EPSILON)
        {
            printf("Exited\n");
            exit(0);
        }
    }
    double simp = simpsons(n, A, h);
    printf("The integral value using Simpson method :- %lf", simp);
}
double simpsons(int n, double A[n][2], double h)
{
    double Y1=0;
    double Y2=0;
    double inte;
    for(int i=1;i<n-1;i++)
    {
        if(i%2 != 0)
        Y1=Y1+A[i][1];
        else
        Y2=Y2+A[i][1];
    }
    inte = (h/3)*((A[0][1]+A[n-1][1])+(4*Y1)+(2*Y2));
    return inte;
}