#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x)
{
    double f= pow(x,3)-1.1*(pow(x,2))+4*x-4.4;
    return f;
}

int main()
{
    double a=1.0,b=2.0;
    double xn_temp;
    double tolerance=0.005;
    double maxiter=100.0;
    double iter=0.0;
    double xn;

    if (func(a) * func(b) >= 0) {
        printf("Invalid initial interval. The function must have opposite signs at a and b.\n");
        return 1;
    }

    do{
        xn=(a+b)/2;
        iter = iter+1.0;

        if (fabs(xn_temp - xn ) < tolerance) {
            printf("Approximate root found at x = %.6lf after %.2lf iterations\n", xn, iter);
            return 0;
        }

        if(func(xn)<0)
        {
            a=xn;
        }
        if(func(xn)>0)
        {
            b=xn;
        }
        xn_temp=xn;
    }
    while (iter < maxiter);

    if (iter == maxiter) {
        printf("Maximum number of iterations reached. Solution may not be accurate.\n");
        return 1;
}
}