#include<stdio.h>
#include<stdlib.h>
typedef struct graf
{
    int n;
    int **mat;
}graf;
graf *init(int n)
{
    graf *a;
    a->n=n;
    a->mat=(int**)malloc(n*sizeof(int*));
    int i;
    for (i=0;i<n;i++)
    a->mat[i]=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
    a->mat[i][i]=0;
    return a;
}
void add_edge(graf *g,int i,int j)
{
    g->mat[i][j]=g->mat[j][i]=1;
}
void del_edge(graf *g,int i,int j)
{
    g->mat[i][j]=g->mat[j][i]=0;
}
int grad(graf *g,int i)
{
    int c;
    int nr;
    nr=0;
    for (c=0;c<g->n;c++)
    if (g->mat[i][c]==1)
    nr++;
    return nr;
}
int x[100];
int v[100];
void bfs (graf *g,int start)
{
  int i,k,st,dr;
  st=dr=1;
  x[0]=start;
  v[start]=1;
  while(st<=dr)
  {
    k=x[st];
    for(i=0;i<g->n;i++)
      if(v[i]==0 && g->mat[k][i]==1)
      {
        v[i]=1;
        printf("%d ", v[i]);
        x[++dr]=i;
      }
    st++;
  }
}
void dfs(graf *g,int k)
{
    int i;
  v[k]=1; 
  for(i=0;i<g->n;i++) 
    if(g->mat[k][i]==1 && v[i]==0)
    {
        printf("%d ",v[i]);
      dfs(g,i); 
    }
}

int nr_cc(graf *g)
{
    int nr;
    nr=0;
    int i;
    int ok;
    for (i=0;i<g->n;i++)
    {
        dfs(g,i);
        if (v[i]==0)
        nr++;
    }
    return nr;
}
int verif_h(graf *g)
{
    int i,j;
    if (grad(g,1)+grad(g,g->n)>=g->n)
    return 1;
    for (i=0;i<g->n;i++)
    for (j=0;j<g->n;j++)
    {
        if (g->mat[i][j]==0)
        {
            if(grad(g,i)+grad(g,j)>=g->n)
            return 1;
        }
    }
    for (i=0;i<g->n;i++)
    if (grad(g,i)>=g->n/2)
    return 1;
    return 0;
}
void creare_graf(graf *g)
{
    int i;
    int x,y;
    int n;
    scanf("%d",&n);
    g=init(n);
    for (i=0;i<g->n;i++)
    {
        scanf("%d%d",&x,&y);
        add_edge(g,x,y);
    }
}
int main()
{
    graf *g;
    creare_graf(g);
    int nod;
    scanf("%d",&nod);
    bfs(g,nod);
    int a,b;
    scanf("%d%d",&a,&b);
    del_edge(g,a,b);
    printf("%d\n",nr_cc(g));
    printf("%d\n",verif_h(g));
    return 0;
}
