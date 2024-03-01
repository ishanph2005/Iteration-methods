/*
This code is for Gauss-Jacobi Iteration method used in numerical analysis for solving multivariable simultaneous equations that are not solvable manually or even by calculator using matrix principles.
*/
#include <stdio.h>

int main() 
{
int i, j, n, k, t;
float sum;
printf("Enter number of variables: "); 
// Enter number of variables in the simultaneous equations given
scanf("%d", &n);
float A[n][n], X1[n], X2[n], B[n];
printf("Enter Matrix A:\n");      
/*Enter coefficients of all the variables serially, in all the equations.
for example: if equations are
2x + 3y - 4z = 7
5x + 5y + 2z = 8
7x - 13y + z = 14
Matrix A values will be: 2 3 -4 5 5 2 7 -13 1
*/
for(i=0; i<n; i++)
{
    for(j=0; j<n; j++)
    {
        scanf("%f", &A[i][j]);
    }
}
printf("Enter Matrix B: \n");
/*
Matrix B is matrix of constant terms.
In above example it will be:
7 8 14
*/
for(i=0; i<n; i++) scanf("%f", &B[i]);
printf("Enter initial guess values: ");
/*
Enter initial guess values to solve equations using iteration method.
For example if x=1, y=0, z=2 is assumed, enter:
1 0 2
*/
for(i=0; i<n; i++) scanf("%f", &X1[i]);
for(i=0; i<n; i++) X2[i]=X1[i];
printf("Enter iteration count: ");
/*
Enter number of times iteration is to be done. More the number of iterations, more will be the accuracy of the solution
*/
scanf("%d", &k);
for(t=0; t<k; t++)
{
    for(i=0; i<n; i++)
    {
        sum=0;
      for (j=0; j<n; j++)
      {
          if (i==j) continue;
          else sum=sum+A[i][j]*X1[j];
      }
      X2[i]=((B[i]-sum)/A[i][i]);
    }
for(i=0; i<n; i++) X1[i]=X2[i]; 
printf("Values after iteration %d: ", t+1);
/*
This step will give value of variables after every iteration
*/
for(i=0; i<n; i++) printf("%f ", X1[i]);
printf("\n");
}
    return 0;
}