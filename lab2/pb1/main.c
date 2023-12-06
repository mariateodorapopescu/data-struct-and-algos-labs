//2.
#include <stdio.h>
#include <stdlib.h>
int binsrc(int *v,int x,int st,int dr)
{
    int mijl;
    mijl=(st+dr)/2;
    if (v[mijl]==x)
        return 1;
    else
        if (st>dr)
        return 0;
    else
    {
        if (v[mijl]<x)
            return binsrc(v,x,mijl+1,dr);
        else
            return binsrc(v,x,st,mijl-1);
    }
}
int main()
{
    int i;
    int n,m;
    int *x,*y;
    scanf("%d",&n);
    x=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
    scanf("%d",&x[i]);
    scanf("%d",&m);
    y=(int*)malloc(m*sizeof(int));
    for (i=0;i<m;i++)
    scanf("%d",&y[i]);
    for (i=0;i<m;i++)
        printf("%d ",binsrc(x,y[i],0,n-1));
    return 0;
}
