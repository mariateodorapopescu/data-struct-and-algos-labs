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
int nr(Lista s)
{
    int num;
    num = 0;
    Nodul *q;
    for (q = s; q != NULL; q++)
    {
        num = num + 1;
    }
    return num;
}
Lista sum(unsigned long long int n, unsigned long long int m)
{
    Lista a, b, s, nou;
    int c;
    int d;
    int i;
    int dat;
    Nodul *p, *q;
    a=(Lista)malloc(sizeof(Nodul));
    b=(Lista)malloc(sizeof(Nodul));
    s=(Lista)malloc(sizeof(Nodul));
    nou=(Lista)malloc(sizeof(Nodul));
    init(a);
    init(b);
    init(s);
    init(nou);
    while (n != 0)
    {
        c = n % 10;
        adaug_fin(a, c);
        n = n / 10;
    }
    while (m != 0)
    {
        c = m % 10;
        adaug_fin(b, c);
        m = m / 10;
    }
    if (nr(a) > nr(b))
    {
        d = nr(a) - nr(b);
        for (i = 0; i < d; i++)
        {
            adaug_incipit(nou, 0);
        }
        p = a;
        for (i = 0; i < nr(a); i++)
        {
            adaug_incipit(nou, p->elem);
            p = p->urm;
        }
        p = nou;
        q = b;
        while (p != NULL && q != NULL)
        {
            dat = p->elem + q->elem;
            adaug_incipit(s, dat);
            p = p->urm;
            q = q->urm;
        }
    }
    else
    {
        d = nr(b) - nr(a);
        for (i = 0; i < d; i++)
        {
            adaug_incipit(nou, 0);
        }
        p = b;
        for (i = 0; i < nr(b); i++)
        {
            adaug_incipit(nou, p->elem);
            p = p ->urm;
        }
        p = nou;
        q = a;
        while (p != NULL && q != NULL)
        {
            dat = p->elem + q->elem;
            adaug_incipit(s, dat);
            p = p->urm;
            q = q->urm;
        }
    }
    return s;
}
int main()
{
    Lista suma;
    init(suma);
    unsigned long long int n, m;
    suma = sum(n,m);
    Nodul *q;
    for (q = suma; q != NULL; q = q->urm)
    {
        printf("%d", q);
    }
    return 0;
}
