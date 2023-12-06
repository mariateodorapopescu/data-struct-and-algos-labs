#include<stdio.h>
#include<stdlib.h>
#define INFINIT 1000000000
typedef struct muchie{
    int in, out, dim;
}muchie;
typedef struct graf
{
    int n;
    int m;
    muchie *l;
}graf;
graf *init(int n1, int m1)
{
    graf *a;
    a = (graf*)malloc(1*sizeof(graf));
    a -> n = n1;
    a -> m = m1;
    g -> l = (muchie*)malloc(m1*sizeof(muchie));
    return a;
}
void print(int d[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d %d", i, d[i]);
    }
}
int BellmanFord (graf *a, int sursa)
{
    int m1, n1;
    m1 = a -> m;
    n1 = a -> n;
    int sum[n1];
    int i, j;
    int u, v;
    int val;
    for (i = 0; i < m1; i++)
    {
        sum[i] = INFINIT;
    }
    sum[sursa] = 0;
    for (i = 0; i <= n1 - 1; i ++)
    {
        for (j = 0; j < m1; j++)
        {
            u = a -> l[j].in;
            v = a -> l[j].out;
            val = a -> l[j].dim;
            if (sum[u] + val < sum [v])
            {
                sum[v] = sum[u] + val;
            }
        }
    }
    for (j = 0; j < m1; j++)
    {
            u = a -> l[j].in;
            v = a -> l[j].out;
            val = a -> l[j].dim;
            if (sum[u] + val < sum [v])
            {
               print(sum,n1);
               return -1;
            }
    }
    print(sum,n1);
    return 0;
}

int main()
{
    int n1, m1;
    int i;
    int sursa;
    graf a;
    scanf("%d",&n1);
    scanf("%d",&m1);
    scanf("%d",&sursa);
    a = init(n1, m 1);  
    for(i = 0; i < E; i++)
    {
        scanf("%d",&a -> l[i].in);
        scanf("%d",&a -> l[i].out);
        scanf("%d",&a -> l[i].dim);
    }
    BellmanFord(a, sursa);
    return 0;
}