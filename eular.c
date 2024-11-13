#include <stdio.h>
#include <math.h>
// function taken here is (x^3+y)
double func(double x,double y)
{
    double f=pow(x,3)+y;//just replace with the required function
    return f;
}
void main()
{
    double x,y,xr,yr,h;
    printf("Enter the value of x0 :   ");
    scanf("%lf",&x);
    printf("Enter the value of y0 :   ");
    scanf("%lf",&y);
    printf("Enter the value of x to find its f(x) :   ");
    scanf("%lf",&xr);
    printf("Enter the interval length :   ");
    scanf("%lf",&h);
    printf("x                   y\n");
    while (x!=xr)
    {
        yr=y+(h*func(x,y));
        y=yr;
        x=x+h;
        printf("%.2lf                %.8lf\n",x,yr);
    }
}