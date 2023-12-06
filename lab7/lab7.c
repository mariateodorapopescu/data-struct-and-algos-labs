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
int main() {
int n,i,x,y;
  scanf("%d",&n);
  scanf("%d",&x);
  arb r = creare_nod(r,x);
 while (scanf("%d",&x)!=NULL)
      {
          if (x!=0)
      inserare(r,x);
  }
  printf("SRD \n");
  srd(r);
  printf("\nRSD\n");
  rsd(r);
  printf("\nSDR \n");
  sdr(r);
  printf("\n");
  printf("%d\n",height(r)-1);
  sterge_nod(r,5);
  sdr(r);
  printf("%d",trei(r));
  return 0;
}
