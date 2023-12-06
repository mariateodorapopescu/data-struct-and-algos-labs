#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -99999999
#define INT_MAX 99999999
typedef struct tree
{
int data;
struct tree *st;
struct tree *dr;
}tree, *arb; //ok1
arb creare_nod(arb t,int date)
{
    t=(arb)malloc(1*sizeof(tree));
    if (!t)
    {
        printf("Eroare\n");
    exit(-1);
    }
    t->data=date;
    t->st=NULL;
    t->dr=NULL;
    return t;
}//ok1
arb inserare(arb t,int date)
{
    if (t==NULL)
        return creare_nod(t,date);
    if (date<t->data)
        t->st=inserare(t->st,date);
    else
        if (date>t->data)
        t->dr=inserare(t->dr,date);
    return t;
} //ok1

void rsd(arb t) {
  if (t == NULL) return;
  printf("%d ", t->data);
  rsd(t->st);
  rsd(t->dr);
}//ok2

int height(arb t) {
  if (t==NULL) {
    return(0);
  }
  else {
    int lDepth = height(t->st);
    int rDepth = height(t->dr);
    if (lDepth > rDepth) return(lDepth+1);
    else return(rDepth+1);
  }
}//ok1

arb lca(arb t, int n1, int n2)
{
    if (t == NULL) return NULL;
    if (t->data > n1 && t->data > n2)
        return lca(t->st, n1, n2);
    if (t->data < n1 && t->data < n2)
        return lca(t->dr, n1, n2);
    return t;
}

void inversare(arb t) {
    tree *temp;
  if (t==NULL) {
    return;
  }
  else {
    inversare(t->st);
    inversare(t->dr);
    temp = t->st;
    t->st = t->dr;
    t->dr = temp;
  }
}

int minValue(arb t) {
  tree *q = t;
  while (q->st != NULL) {
    q = q->st;
  }

  return(q->data);
}

int maxValue(arb t) {
  tree *q = t;
  while (q->dr != NULL) {
    q = q->dr;
  }

  return(q->data);
}

int este(arb t) {
  return(este2(t, INT_MIN, INT_MAX));
}
int este2(arb t, int min, int max) {
  if (t==NULL) return 1;
  if (t->data<min || t->data>max) return 0;
  return
    (este2(t->st, min, t->data) &&
    este2(t->dr, t->data+1, max)
  );
}

void bfs(arb t)
{
    int h = height(t);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(t, i);
}
void printCurrentLevel(arb t, int niv)
{
    if (t == NULL)
        return;
    if (niv == 1)
        printf("%d ",t->data);
    else if (niv > 1) {
        printCurrentLevel(t->st, niv - 1);
        printCurrentLevel(t->dr, niv - 1);
    }
}

void dfs(arb t)
{
    if (t)
    {
        if (t->st)
        {
            dfs(t->st);
        }
        if (t->dr)
        {
            dfs(t->dr);
        }
        printf("%d  ", t->data);
    }
}

int main() {
int x,y;
int n1,n2;
tree *frunza;
  scanf("%d",&x);
  arb t = creare_nod(t,x);
 while (scanf("%d",&x)!=NULL)
      {
          if (x!=0)
      inserare(t,x);
  }
    if (este(t)==1)
    printf("Este arbore binar de cautare\n");
  else
    printf("NU este arbore binar de cautare\n");
  printf("\nRSD\n");
  rsd(t);
  frunza=lca(t,1,4);
  printf("LCA-ul nodurilor cu valorile 1 si 4 este %d\n",frunza->data);
  printf("Arborele inversat este\n");
  inversare(t);
  rsd(t);
  inversare(t);
  printf("\nParcurgerea in lungime:\n");
  bfs(t);
  printf("\nParcurgerea in adancime:\n");
  dfs(t);
  return 0;
}
