#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m;
    int i,j,l;
    int *x,*y,*z;
    int k;
    scanf("%d",&n);
    x=(int*)malloc(n*sizeof(int));
     for (i=0;i<n;i++)
    scanf("%d",&x[i]);
    scanf("%d",&m);
    y=(int*)malloc(m*sizeof(int));
    for (i=0;i<m;i++)
    scanf("%d",&y[i]);
    z=(int*)malloc((n+m)*sizeof(int));
    i=0;
    j=0;
    l=0;
    while(i<n&&j<m)
    {
        if (x[i]<y[j])
        {
            z[l++]=x[i++];
        }
        else
        {
            z[l++]=y[j++];
        }
    }
    while(i<n)
    {
        z[l++]=x[i++];
    }
    while(j<m)
    {
        z[l++]=y[j++];
    }
    scanf("%d",&k);
    printf("%d",z[k-1]);
    return 0;
}
