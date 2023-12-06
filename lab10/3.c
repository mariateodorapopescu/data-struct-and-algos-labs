#include<stdio.h>
#include<stdlib.h>
#define INF 100000000
int G[100][100];
int spanning[100][100];
int n;
int prims()
{
int cost[100][100];
int u, v, min, dist[100], sursa[100];
int viz[100], m, i, costminim, j;
for(i = 0; i < n; i++)
{
    for(j=0;j<n;j++)
    {
        if(G[i][j]==0)
    {
        cost[i][j]=INF;
    }
    else
    {
        cost[i][j]=G[i][j];
    }
    spanning[i][j]=0;
    }
}
dist[0] = 0;
viz[0] = 1;
for(i = 1; i < n; i++)
    {
        dist[i]=cost[0][i];
        sursa[i]=0;
        viz[i]=0;
    }
costminim = 0; 
m = n - 1;
while(m > 0)
{
min = INF;
for(i = 1; i < n; i++)
{
    if(viz[i] == 0 && dist[i] < min)
    {
        v = i;
        min = dist[i];
    }
}
    u = sursa[v];
    spanning[u][v] = dist[v];
    spanning[v][u] = dist[v];
    m--;
    viz[v] = 1;
}
for(i = 1; i < n; i++)
{
    if(viz[i] == 0 && cost[i][v] < dist[i])
    {
        dist[i] = cost[i][v];
        sursa[i] = v;
    }
}
costminim = costminim + cost[u][v];
return costminim;
}
int main()
{
int i,j,cost;
scanf("%d",&n);
for(i = 0; i < n; i++)
for(j = 0; j < n; j++)
scanf("%d", &G[i][j]);
cost=prims();
for(i = 0; i < n; i++)
{
    for(j=0;j<n;j++)
    {
        printf("%d\t",spanning[i][j]);
    }
}
printf("%d",cost);
return 0;
}
 
