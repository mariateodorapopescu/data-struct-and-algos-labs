#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct muchie
{
   int in, out, dim;
}muchie;
typedef struct graf
{
   int n, m;
   muchie* l;
}graf;
graf* init(int N, int M)
{
   graf* g = (graf*)(malloc(1*sizeof(graf)));
   g->n = N;
   g->m = M;
   g->l = (muchie*)malloc(sizeof(mcuhie)*M);
   return g;
}
typedef struct vect
{
   int tata;
   int grad;
}vect;
int src(vect v[], int i)
{
   if (v[i].tata != i)
      {
          v[i].tata = src(v, v[i].tata);
      }
   return v[i].tata;
}
void unire(vect v[], int x, int y)
{
   int X = src(v, x);
   int Y = src(v, y);
   if (v[X].grad < v[Y].grad)
      {
          v[X].tata = Y;
      }
   else 
    if (v[X].grad > v[Y].grad)
        {
          v[Y].tata = X;
        }
    else
    {
      v[Y].tata = X;
      v[X].grad++;
    }
}
int compfunc(const void* a, const void* b)
{
   muchie* a1 = (muchie*)a;
   muchie* b1 = (muchie*)b;
   return a1->dim > b1->dim;
}
void Kruskal(graf* g){
   int N;
   int e;
   int i;
   int j;
   int x;
   int y;
   int costminim;
   vect* v;
   muchie rez[N];
   muchie urm;
   v = (vect*)malloc(N * sizeof(vect));
   N = g->n;
   e = 0;
   i = 0;
   costminim = 0;
   qsort(g->l, g->m, sizeof(g->l[0]), compfunc);
   for (j = 0; j < N; ++j) 
   {
      v[j].tata = j;
      v[j].grad = 0;
   }
   while (e < N - 1 && i < g->m) 
   {
      urm = g->l[i++];
      x = src(v, urm.in);
      y = src(v, urm.out);
      if (x != y)
      {
         rez[e++] = urm;
         unire(v, x, y);
      }
   }
   for (i = 0; i < e; ++i){
      printf("%d -- %d == %d\n", rez[i].in, rez[i].out, rez[i].dim);
      costminim = costminim + rez[i].dim;
   }
   printf("%d", costminim);
   return;
}
int main()
{
   int N = 24;
   int M = 25;
   int IN;
   int OUT;
   int VAL;
   int i;
   graf* g;
   scanf("%d",&N);
   scanf("%d",&M);
   g = init(N, M);
   for (i = 0; i < M; i++)
   {
       scanf("%d", &IN);
       scanf("%d", &OUT);
       scanf("%d", &VAL);
       g -> l[i].in = IN;
       g -> l[i].out = OUT;
       g -> l[i].dim = VAL;
   }
   Kruskal(g);
   return 0;
}