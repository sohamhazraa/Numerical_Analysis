#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of data: \n");
    scanf("%d", &n);
    
    double tab[n+3][n+3];
    printf("Enter the values of x and f(x)");
    int i=0;
    while(i<2)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%lf", &tab[j][i]);
        }
        printf("\n");
        i++;
    }

    i=1;
    while(i<n+1)
    {
        for (int j=0; j<n-i; j++)
        {
            tab[j][i+1]=tab[j+1][i]-tab[j][i];
        }
        i++;
    }

    int j=0;
    while(j<n)
    {
        for (int i=2; i<=n-j; i++)
        {
            printf("%lf  ", tab[j][i]);
        }
        printf("\n");
        j++;
    }
}