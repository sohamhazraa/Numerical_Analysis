#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x)
{
    double f= pow(x,3)-8*x-4;
    return f;
}

double dif_func(double x)
{
    double df= 3*(pow(x,2))-8;
    return df;
}

int main()
{
    double a=3.0,b=4.0;
    double xn=a,xn_temp=0.0;
    double h;
    double iter=0.0,maxiter=100.0;
    double tolerance=0.0000005;

    if (func(a) * func(b) >= 0) {
        printf("Invalid initial interval. The function must have opposite signs at a and b.\n");
        return 1;
    }

    do{
        h=(func(xn)/dif_func(xn));
        xn=xn-h;
        iter=iter+1.0;
        
        if(fabs(xn_temp-xn) < tolerance)
        {
            printf("Approximate root found at x = %.6lf after %.2lf iterations\n", xn, iter);
            return 0;
        }

        xn_temp=xn;

    }while(iter < maxiter);

    if(iter == maxiter)
    {
        printf("Maximum number of iterations reached. Solution may not be accurate.\n");
        return 1;
    }
}