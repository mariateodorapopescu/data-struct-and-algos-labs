#include <stdio.h>
#include <stdlib.h>
int n;
int *v;
void mergesrt()
{
    int *vect;
    vect=(int*)malloc(n*sizeof(int));
    MergeSort(vect,0,n-1);
}
void MergeSort(int *vect,int st,int dr)
{
    int mijl;
    if (st==dr)
    {
      return ;
    }
    else
    {
        mijl=(st+dr)/2;
        MergeSort(vect,st,mijl);
        MergeSort(vect,mijl+1,dr);
        merge(vect,st,mijl+1,dr);
    }
}
void merge(int *vect,int st,int dr,int sfarsit)
{
    int i,j,inceput,mijl,m;
    j=0;
    inceput=st;
    mijl=dr-1;
    m=sfarsit-inceput+1;
    while(st<=mijl&&dr<=sfarsit)
    {
        if(v[st]<v[dr])
            vect[j++]=v[st++];
        else
            vect[j++]=v[dr++];
    }
    while (st<=mijl)
    {
        vect[j++]=v[st++];
    }
    //complexitate n^2 - cel mai rau caz
    //cel mai bun caz = log n
    //in general = complexitate nlogn
    while(dr<=sfarsit)
    {
        vect[j++]=v[dr++];
    }
    for (j=0;j<n;j++)
        v[inceput+j]=vect[j];
}
int main()
{
    int i;
    scanf("%d",&n);
    v=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        scanf("%d",&v[i]);
        mergesrt();
        for (i=0;i<n;i++)
        printf("%d ",v[i]);
    return 0;
}
