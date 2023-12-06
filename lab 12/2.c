#include <stdio.h>
#include <stdlib.h>
typedef int data;
typedef struct nod{
data elem;
struct nod *prev;
struct nod *next;
}nod,*dlistnod;
typedef struct list{
dlistnod first;
dlistnod last;
}list,*dlist;
void initlist(dlist s)
{
    s->first=s->last=NULL;
    s->first=(dlistnod)malloc(sizeof(nod));
}
dlistnod addinc(dlist s,data a)
{
    nod *newnod;
    newnod=(dlistnod)malloc(sizeof(nod));
    if (s->first == NULL)
    {
        newnod->elem = a;
        newnod->next = newnod;
        newnod->prev = newnod;
        s->first= newnod;
        s->last= newnod;
        return;
    }

    newnod->elem = a;
    newnod->next = s->first;
    newnod->prev = NULL;
    s->first->prev = newnod;
    s->last->next = NULL;
    s->first = newnod;
}
//stim ca lista e deja sortata => doua valori consecutive sunt egale
void elim_dup(dlist s)
{
 nod *q;
 nod *aux;
 for (q=s->first;q!=s->next->last;q=q->next)
        {
            if (q->elem == q->next->elem)
            {
              q->next->prev = q;
              q->next=q->next->next;
            }
        }  
}
int main()
{
    int i,n;
    data x;
    nod *q;
    dlist s;
    initlist(s);
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&x);
        addinc(s,x);
    }
    elim(s);
    for (q = s->first; q != s->next->last; q = q->next)
    {
        printf("%d ", q->elem);
    }
    return 0;
}
