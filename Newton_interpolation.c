#include <stdio.h>
#include <stdlib.h>
void main()
{
    printf("Enter the number of elements:-  ");
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
    for(int i=0;i<n-2;i++)
    {
        double a =(M[i+1][0]-M[i][0]);
        double b =(M[i+2][0]-M[i+1][0]);
        if(a != b)
        {
            printf("Wrong input the values of X waren't euidistant.........");
            exit(0);
        }
    }
    double h=M[1][0]-M[0][0];
    printf("Enter the value of X for which you wanna find the value of f(x):- ");
    double x;
    scanf("%lf",&x);
    if(abs(M[0][0]-x) < abs(M[n-1][0]-x))
    {
        double u = (x-M[0][0])/h;
        printf("The value of u is :- %.5lf\n",u);
        forward(n,M,u);
    }
    else
    {
        double v = (x-M[n-1][0])/h;
        printf("The value of v is :- %.5lf\n",v);
        backward(n,M,v);
    }
}
//..............................................................................................................................................................
double bfact(double v,int n)
{
    double factA=1.0, factB=1.0;
    for(int i=1;i<=n;i++)
    {
        factA=factA*v;
        v=v+1.0;
        factB=factB*i;

    }
    double bfactC=factA/factB;
    return bfactC;
}
//..............................................................................................................................................................
double ffact(double u,int n)
{
    double factA=1.0, factB=1.0;
    for(int i=1;i<=n;i++)
    {
        factA=factA*u;
        u=u-1.0;
        factB=factB*i;

    }
    double ffactC=factA/factB;
    return ffactC;
}
//..............................................................................................................................................................
void forward(int n, double M[n][n+1], double u)
{
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
            printf("%.5lf    ",M[i][j]);
        }
        for(int k=2;k<=n-i;k++)
        {
            printf("%.5lf  ",M[i][k]);
        }
        printf("\n");
    }
    double P = M[0][1];
    for(int j=2;j<=n;j++)
    {
        P=P+(M[0][j]*ffact(u,j-1));
    }
    printf("\n");
    printf("The value of f(x) is :- %.5lf",P);
}
//..................................................................................................................................................................
void backward(int n, double M[n][n+1], double v)
{
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
            printf("%.5lf  ",M[i][j]);
        }
        printf("\n");
    }
    double P = M[n-1][1];
    for(int j=2;j<=n;j++)
    {
        P=P+(M[n-1][j]*bfact(v,j-1));
    }
    printf("\n");
    printf("The value of f(x) is :- %.5lf",P);
}