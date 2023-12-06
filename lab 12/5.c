#include <stdlib.h>
#include <stdio.h>
int degin(int g[100][100], int n, int j)
{
    int i;
    int nr;
    nr = 0;
    for (i = 0; i < n; i++)
    {
        if (g[i][j] == 1)
        {
            nr = nr + 1;
        }
    }
return nr;
}
int main()
{
    int g[100][100];
    int n;
    int m;
    int i;
    int j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        g[i]
    }
    return 0;
}