#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter a number");
    scanf("%d",&n);
    int ma[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&ma[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",ma[i][j]);
        printf("\n");
    }
    return 0;
}
