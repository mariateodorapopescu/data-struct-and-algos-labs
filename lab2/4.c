#include <stdio.h>
#include <stdlib.h>
int sum(int *v,int st,int dr)
{
    int mijl;
    mijl=(st+dr)/2;
        if (st>dr)
       return 0;
    else
    {
        return sum(v,st,mijl-1)+v[mijl]+sum(v,mijl+1,dr);
    }
}
int main()
{
    int i;
    int n;
    int s;
    s=0;
    int *v;
    scanf("%d",&n);
    v=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
    scanf("%d",&v[i]);
    s=sum(v,0,n-1);
    printf("%d",s);
    return 0;
}