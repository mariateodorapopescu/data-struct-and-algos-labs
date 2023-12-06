#include <stdio.h>
#include <stdlib.h>
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
arb succesorinord(arb t) {
 arb curr = t;
  while (curr && curr->st != NULL)
    curr = curr->st;
  return curr;
}
arb sterge_nod(arb t, int date) {
  if (t == NULL) return t;
  if (date < t->data)
    t->st = sterge_nod(t->st, date);
  else if (date>t->data)
    t->dr = sterge_nod(t->dr, date);
  else {
    if (t->st == NULL) {
      arb temp = t->dr;
      free(t);
      return temp;
    } else if (t->dr == NULL) {
      arb temp = t->st;
      free(t);
      return temp;
    }
    arb temp = succesorinord(t->dr);
    t->data = temp->data;
    t->dr = sterge_nod(t->dr, temp->data);
  }
  return t;
} //ok1
void srd(arb t) {
  if (t == NULL) return;
  srd(t->st);
  printf("%d ", t->data);
  srd(t->dr);
} //ok2
void rsd(arb t) {
  if (t == NULL) return;
  printf("%d ", t->data);
  rsd(t->st);
  rsd(t->dr);
}//ok2
void sdr(arb t) {
  if (t == NULL) return;
  sdr(t->st);
  sdr(t->dr);
  printf("%d ", t->data);
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
arb cautare(arb t, int date)
{
    if (t == NULL || t->data == date)
       return t;
    if (t->data < date)
       return cautare(t->dr, date);
       return cautare(t->st, date);
}

int trei(arb t)
{
    int nr;
    nr=0;
    if (t!=NULL)
    {
        if (t->st==NULL&&t->dr!=NULL||t->dr==NULL&&t->st!=NULL)
        nr++;
        trei(t->st);
        trei(t->dr);
    }
    return nr;
}

int este(arb t) {
  if (t==NULL) return 1;
  if (t->st!=NULL && maxValue(t->st) > t->data)
    return 0;
  if (t->dr!=NULL && minValue(t->dr) <= t->data)
    return 0;
  if (!este(t->st) || !este(t->dr))
    return 0;
  return 1;
}

int este2(arb t) {
  return(este3(t, INT_MIN, INT_MAX));
}
int este3(arb t, int min, int max) {
  if (t==NULL) return 1;
  if (t->data<min || t->data>max) return 0;
  return
    (este3(t->st, min, t->data) &&
    este3(t->dr, t->data+1, max)
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
    if (este2(t)==1)
    printf("Este arbore binar de cautare\n");
  else
    printf("NU este arbore binar de cautare\n");

      printf("SRD \n");
  printf("SRD \n");
  srd(t);
  printf("\nRSD\n");
  rsd(t);
  printf("\nSDR \n");
  sdr(t);
  printf("\nInaltimea arborelui este ");
  printf("%d\n",height(t)-1);
  printf("Pentru ce noduri sa se afla LCA-ul?\n");
  scanf("%d%d",&n1,&n2);
  frunza=lca(t,n1,n2);
  printf("\nLCA-ul cautat este %d\n",frunza->data);
  inversare(t);
  rsd(t);
  printf("\nParcurgerea in lungime:\n");
  bfs(t);
  printf("\nParcurgerea in adancime:\n");
  dfs(t);
  return 0;
}
