#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x)
{
    double f=pow(x,3)+2*x-2;
    return f;
}

int main()
{
    double a=0.0,b=1.0;
    double xn,xn_temp=0.0;
    double tolerance=0.0005;
    double iter=0.0, maxiter=100.0;
    double h;

    if (func(a) * func(b) >= 0) {
        printf("Invalid initial interval. The function must have opposite signs at a and b.\n");
        return 1;
    }

    do{
        h=(fabs(func(a))*(b-a))/(fabs(func(a))+fabs(func(b)));
        xn=a+h;
        iter=iter+1.0;
        
        if(fabs(xn_temp-xn)<tolerance)
        {
            printf("Approximate root found at x = %.6lf after %.2lf iterations\n", xn, iter);
            return 0;
        }

        if(func(xn)<0)
            a=xn;
        
        if(func(xn)>0)
            b=xn;

        xn_temp=xn;
    }while (iter < maxiter);

    if (iter == maxiter) {
        printf("Maximum number of iterations reached. Solution may not be accurate.\n");
        return 1;}
}