#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 1e-6
double trapezoidal(int n, double A[n][2], double h);

void main()
{
    printf("Enter the number of values :- ");
    int n;
    scanf("%d",&n);
    double A[n][2];
    printf("Enter the values of X\n");
    for(int j=0;j<2;j++)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&A[i][j]);
        }
        printf("Enter the functional values of X\n");
    }
    double h=A[1][0]-A[0][0];
    double p;
    for(int i=2;i<n;i++)
    {
        p=(A[i][0]-A[i-1][0]);
        if( fabs(p - h) > EPSILON)
        {
            printf("Exited\n");
            exit(0);
        }
    }
    double trap = trapezoidal(n,A,h);
    printf("The integrational value using trapizodial method is :- %.4lf", trap);
}

double trapezoidal(int n, double A[n][2],double h)
{
    double sum=0.0;
    for(int i=1;i<n-1;i++)
    {
        sum+= A[i][1];
    }
    double trap=(h/2)*((A[0][1]+A[n-1][1])+2*(sum));
    return trap;
}