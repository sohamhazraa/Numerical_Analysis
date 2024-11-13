#include <stdio.h>
void main()
{
    printf("Enter the number of elements :  ");
    int n;
    scanf("%d", &n);
    double A[n][2];
    printf("Enter the values of X:-\n");
    for(int j=0;j<2;j++)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&A[i][j]);
        }
        printf("Enter the functional values:-\n");
    }
    printf("Enter the value of x to calculate the f(x):-  ");
    double x;
    scanf("%lf",&x);
    lagrenge(n,A,x);
}
void lagrenge(int n, double A[n][2],double x)
{
    double sum=0;
    
    for(int i=0;i<n;i++)
    {
        double Wr_x=A[i][1];
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                Wr_x*=((x-A[j][0])/(A[i][0]-A[j][0]));
            }
        }sum+=(Wr_x);
    }
    printf("The value of f(%lf) is :- %.5lf",x,sum);
}