#include <stdio.h>
#include <stdlib.h>
typedef struct nod{
int data;
struct nod *urm;
}Nodul, *Lista;
typedef struct{
Lista prim;
int *index;
int *citit;
}noua;
void init(Lista cap){
cap->urm=NULL;
//cap=(Lista)malloc(sizeof(Nodul));
}
int vida(Lista cap)
{
    return (cap->urm==NULL);
}
void afis(Lista cap)
{
    Nodul *q;
    q=cap->urm;
    while (q->urm!=NULL)
    {
        printf("%d ",q->data);
    }
}
void adaug_incipit(Lista cap,int elem)
{
Lista nou=(Lista)malloc(sizeof(Nodul));
nou->data=elem;
nou->urm=cap->urm;
cap->urm=nou;
}
void adaug_fin(Lista cap,int elem)
{
    Lista nou=(Lista)malloc(sizeof(Nodul));
    nou->data=elem;
    nou->urm=NULL;
    Nodul *q=cap->urm;
    while (q->urm!=NULL)
    {
        q=q->urm;
    }
    q->urm=nou;
}
int elim_prim(Lista cap)
{
    Lista q;
    int rezultat;
    q=cap->urm;
    rezultat=q->data;
    cap->urm=q->urm;
    free(q);
    return rezultat;
}
int elim_elem(Lista cap,int elem)
{
    Nodul *q=cap->urm;
    int rezultat;
    while (q->urm=NULL&&q->urm->data!=elem)
    {
        q=q->urm;
    }
    if(q->urm==NULL)
    {
        rezultat=-1;
    }
    else
    {
        rezultat=q->urm->data;
        q->urm=q->urm->urm;
    }
    return rezultat;
}
void inv(Nodul *q, Nodul *st, Lista cap){
    q=cap->urm;
   if (q->urm==NULL) {
      q=q->urm;
      q->urm=st;
      return;
   }
   Nodul *dr=q->urm;
   q->urm=st;
   inv(dr,q,&cap);
}
void invv(Lista cap){
   if (cap->urm==NULL)
      return;
   inv(cap, NULL, cap);
}
void interclass(Lista a,Lista b,Lista c)
{
    init(&c);
    Nodul *i,*j;
    i=a->urm;
    j=b->urm;

    while (i->urm!=NULL&&j->urm!=NULL)
    {
        if(i->data<j->data)
        {
            adaug_fin(c,i->data);
            i=i->urm;
        }
        else
            {
                adaug_fin(c,j->data);
                j=j->urm;
            }
    }
    while (j->urm!=NULL)
    {
        adaug_fin(c,j->data);
                j=j->urm;
    }
    while (i->urm!=NULL)
    {
        adaug_fin(c,i->data);
    }
}
int numara(Lista cap,int *v)
{
    int n,k;
    n=0;
    k=0;
    Nodul *q;
    q=cap->urm;
    while (q->urm!=NULL)
    {
        n++;
        q=q->urm;
    }
    v=(int*)malloc(n*sizeof(int));
    n=0;
    q=cap->urm;
    while (q->urm!=NULL)
    {
        v[k++]=n;
        n++;
        q=q->urm;
    }
    return n;
}
int contains_cycle(Lista cap)
{
    noua lst;
    int ok=0;
    init(lst.prim);
    lst.prim=cap;
    Nodul *q,*p;
    p=lst.prim->urm;
    q=cap->urm;
    while (q->urm!=NULL)
    {
        adaug_fin(lst.prim,q->data);
        q=q->urm;
    }
    int nr;
    nr=numara(&lst.prim,&lst.index);
    int i;
    lst.citit=(int*)calloc(nr,sizeof(int));
    i=0;
    for(q=lst.prim->urm;q!=NULL&&ok==0;q=q->urm)
    {
        i++;
        lst.citit[lst.index[i]]++;
        q=q->urm;
        if (lst.citit[lst.index[i]]>1)
            ok=1;
    }
    return ok;
}
int main()
{
    Lista l1,l2,l3;
    int n,i,m,x;
    l1=(Lista)malloc(sizeof(Nodul));
    l2=(Lista)malloc(sizeof(Nodul));
    l3=(Lista)malloc(sizeof(Nodul));
    init(l1);
    init(l2);
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&x);
        adaug_fin(l1,x);
    }
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        scanf("%d",&x);
        adaug_fin(l2,x);
    }
    afis(l1);
    printf("\n");
    afis(l2);
    scanf("%d",&x);
    adaug_incipit(l1,x);
    elim_prim(l2);
    scanf("%d",&x);
    elim_elem(l1,x);
    //presupunem ca l1 si l2 sunt ordonate crescator
    interclass(l1,l2,l3);
    invv(l3);
    return 0;
}
