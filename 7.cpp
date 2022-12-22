// Practical 7

#include<stdio.h>
#define max 100
int main(void)
{
    int n;
    int m=9999;
    printf("Enter the number of nodes: \n");
    scanf("%d",&n);
    int i,j;
    int mat[n][n];
    printf("Enter the values of the matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int a[n];
    printf("Enter the heuristic:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int start;
    printf("Enter the start node:\n");
    scanf("%d",&start);
    int goal;
    printf("Enter the goal node:\n");
    scanf("%d",&goal);
    int visited[max]={0};
    int t=0;
    visited[start]=1;
    int x=start;
    int p=0;
    int y,v,sum=0;
    printf("Start state is %c\n",start+65);
    printf("Goal state is %c\n",goal+65);
    printf("%c ",start+65);
    while(x!=goal)
    {
        for(i=0;i<n;i++)
        {
            if(mat[x][i]!=0 && visited[i]!=1)
            {
                p=mat[x][i]+a[i];
                if(m>p)
                {
                    y=mat[x][i];
                    m=p;
                    v=i;
                }
            }
        }
        sum=sum+y;
        visited[v]=1;
        printf("%c ",v+65);
        x=v;
        m=9999;
    }
printf("\nCost is %d\n",sum);
return 0;
}
