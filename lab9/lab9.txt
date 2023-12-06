#include<stdio.h>
#include<stdlib.h>
#define INFINIT 1000000000
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
    int i,j;
    for (i=1;i<=n;i++)
    a->mat[i]=(int*)malloc(n*sizeof(int));
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        a->mat[i][j]=INFINIT;
    for (i=1;i<=n;i++)
    a->mat[i][i]=0;
    return a;
}
void add_edge(graf *g,int i,int j)
{
    g->mat[i][j]=1;
}
void del_edge(graf *g,int i,int j)
{
    g->mat[i][j]=INFINIT;
}
int in_degree(graf *g,int i) //pe coloane
{
    int c;
    int nr;
    nr=0;
    for (c=1;c<=g->n;c++)
    if (g->mat[i][c]!=INFINIT)
    nr++;
    return nr;
}
int ex_dregree(graf *g,int i) //pe liniij
{
    int l;
    int nr;
    nr=0;
    for (l=1;l<=(g->n);l++)
    if (g->mat[l][i]!=INFINIT1)
    nr++;
    return nr;
}
int mini(int a,int b)
{
    if (a<b)
        return a;
    else
        return b;
}
int **floyd_warshall(graf *g) //deci, mat din structura e matricea de costuri direct
{
    int **D;
    D=(int**)malloc((g->n)*sizeof(int*));
    int i,j;
    int m;
    for (i=1;i<=(g->n);i++)
    D[i]=(int*)malloc((g->n)*sizeof(int));
    for (i=1;i<=(g->n);i++)
        for (j=1;j<=(g->n);j++)
        D[i][j]=g->mat[i][j];
    m=g->n;
    //m este n-ul din alg; g->mat este W-ul din alg
    int k;
    for (k=1;k<=m;k++)
        for (i=1;i<=m;i++)
        for (j=1;j<=m;j++)
        D[i][j]=mini(D[i][j],(D[i][k],D[k][j]));
    return D;
}
void creare_graf(graf *g)
{
    int i;
    int x,y,cost;
    int n,m; //m este nr de muchii, n este nr de noduri
    printf("citire nr noduri si nr muchii\n");
    scanf("%d%d",&n,&m);
    g=init(n);
    for (i=1;i<=m;i++)
    {
        printf("citire nod x, nod y, cost\n");
        scanf("%d%d%d",&x,&y,&cost);
        add_edge(g,x,y); //dupa ce face adiacenta, pune si costul
        g->mat[x][y]=cost;
    }
}
int sum_lin(graf g,int i)
{
    int s;
    s=0;
    int j;
    for (j=1;j<n;j++)
        s=s+g.mat[i][j];
    return s;
}
int unu(graf *g)
{
    creare_graf(g);
    int a,b,c,d;
    printf("stergere arc intre a si b\n");
    scanf("%d%d",&a,&b);
    del_edge(g,a,b);
    printf("adaugare arc intre c si d\n");
    scanf("%d%d",&c,&d);
    add_edge(g,c,d);
    return 0;
}

int mindist(graf g,int *dist,int *sptSet)
{
    int min, min_index;
    min=INFINIT;
    int i;
    for (i=1;i<=(g.n);i++)
        if (sptSet[i]==0&&dist[i]<=min)
            {
                min=dist[i];
            min_index=i;
            }
    return min_index;
}

void printPath(int *parent,int j)
{
    if (parent[j]==-1)
        return;
    printPath(parent,parent[j]);
    printf("%d ",j);
}
int printSolution(int *dist,graf g,int *parent)
{
    int src;
    int i;
    src = 0;
    printf("Nod\t Distanta\tCale\n");
    for (i=1;i<=(g.n);i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ",src,i,dist[i],src);
        printPath(parent,i);
    }
}

void dijkstra(graf g, int src)
{
    int *dist;
    int *sptSet;
    int *parent;
    int i,j;
    int u;
    dist=(int*)malloc((g.n)*sizeof(int));
    sptSet=(int*)malloc((g.n)*sizeof(int));
    parent=(int*)malloc((g.n)*sizeof(int));
    for(i=1;i<=(g.n);i++)
        sptSet[i]=0;
    for(i=1;i<=(g.n);i++)
        parent[i]=-1;
    for (i=1;i<=(g.n);i++) {
        dist[i]=INFINIT;
    }
    dist[src]=0;
    for (i=0;i<=(g.n)-1;i++)
        {
        u=mindist(g,dist,sptSet);
        sptSet[u]=1;
        for (j=1;j<=(g.n);j++)
            if (!sptSet[j]&&g.mat[u][j]&&dist[u]+g.mat[u][j]<dist[j])
                {
                parent[j]=u;
                dist[j]=dist[u]+g.mat[u][j];
                }
        }
    printSolution(dist,g,parent);
}

int trei(graf *g)
{
    creare_graf(g);
    dijkstra(*g, 0);
    return 0;
}

int patru(graf *g)
{
    creare_graf(g);
    int **W;
    W=(int**)malloc((g->n)*sizeof(int*));
    int i,j;
    int s;
    int minn;
    minn=INFINIT;
    for (i=1;i<=(g->n);i++)
    W[i]=(int*)malloc((g->n)*sizeof(int));
    floyd_warshall(g);
    int lin_min;
    for (i=1;i<=(g->n);i++)
    {
        s=sum_lin(&g,i);
        if(s<minn)
            minn=s;
    }
    return minn;
}
int main()
{
    graf g;
    int op;
    printf("Ce doriti sa faca programul?\n");
    printf("1=primul exercitiu;\n3=al treilea exercitiu;\n4=al patrulea exercitiu;5=ieisre;");
    do
    switch(op)
    {
        case (1){
            unu(&g); break;
        }
        case(3)
        {
            trei(&g); break;
        }
        case(4)
        {
            patru(&g); break;
        }
        case(5)
        {
            printf("Iesire");
            exit(0); break;
        }
        default: {
            printf("Optiune gresita\n"); break;
        }
    }
        while (op!=5);
    return 0;
}
