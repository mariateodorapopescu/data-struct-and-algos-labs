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
    s->last=s->first;
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
    newnod->prev = s->last;
    s->first->prev = newnod;
    s->last->next = newnod;
    s->first = newnod;
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
    for (q=s->first;q!=s->last;q=q->next)
        printf("%d ",q->elem);
    return 0;
}
