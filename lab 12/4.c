#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n;
    int x;
    int mini1, mini2;
    int maxi1, maxi2;
    int i;
    int p1, p2;
    int v[100];
    mini1 = mini2 = INT_MAX;
    maxi1 = maxi2 = INT_MIN;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] > maxi1)
        {
            maxi1 = v[i];
        }
        if (v[i] < mini1)
        {
            mini1 = v[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] > maxi2 && v[i] < maxi1 && maxi1 * v[i] > 0)
        {
            maxi2 = v[i];
        }
        if (v[i] < mini2 && v[i] > mini1 && mini1 * v[i] > 0)
        {
            mini2 = v[i];
        }
    }
    p1 = mini1 * mini2;
    p2 = maxi1 * maxi2;
    if (p1 > p2)
    {
        printf("%d", p1);
    }
    else
     {
        printf("%d", p2);
    }
    return 0;
}