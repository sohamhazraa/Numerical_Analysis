#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of data points: \n");
    scanf("%d", &n);
    
    double tab[n+3][n+3]; // Initialize a 2D array with size (n+3)x(n+3)
    printf("Enter the values of x and f(x)");
    // Read data into the first two columns of the table
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%lf", &tab[j][i]);
        }
        printf("\n");
    }

    // Calculate differences and store them in the table
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            tab[j][i+1] = tab[j][i] - tab[j-1][i];
        }
    }

    // Print the resulting difference table
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%lf  ", tab[i][j+2]);
        }
        printf("\n");
    }

    return 0;
}
