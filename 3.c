#include <stdio.h>
#include <stdlib.h>
const int n=3;
int main()
{
   float a[n][2*n], c, b[n][n], h[n][n];
    int i, k, j, p;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            scanf("%f", &a[i][j]);
            b[i][j]=a[i][j];
        }
  for (i=0; i<n; i++)
          for (j=n; j<2*n; j++)
          {
              if (i==j-n) a[i][j]=1;
              else a[i][j]=0;
          }
    for (k=0; k<n-1; k++)
    {
        if (a[k][k]==0)
        {
            p=k+1;
            while (a[p][k]==0) p++;
            for (j=p; j<2*n; j++)
            {
                c=a[p][k];
                a[p][k]=a[k][k];
                a[k][k]=c;
            }
        }
        for (i=k+1; i<n; i++)
            for (j=2*n-1; j>=k; j--) a[i][j]=a[i][j]-a[i][k]*a[k][j]/a[k][k];
    }
for (j=n-1; j>0; j--)
    {
    for (i=j-1; i>=0; i--)
    {
        for (p=n; p<2*n; p++) a[i][p]=a[i][p]-a[i][j]*a[j][p]/a[j][j];
        a[i][j]=0;
    }
    }
    for (i=0; i<n; i++)
    {
        for (j=n; j<2*n; j++) a[i][j]=a[i][j]/a[i][i];
        a[i][i]=1;
    }


    printf("inverse matrix");
    for (i=0; i<n; i++)
    {
        printf("\n");
        for (j=n; j<2*n; j++) printf("%-6.2f", a[i][j]);
    }


    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
           h[i][j]=0;
        for (k=0; k<n; k++) h[i][j]=h[i][j]+a[i][n+k]*b[k][j];
        }
        printf("\n");
        printf("check (product of original and inverse matrices)");
     for (i=0; i<n; i++)
    {
        printf("\n");
        for (j=0; j<n; j++) printf("%-6.2f", h[i][j]);
    }
    return 0;
}
