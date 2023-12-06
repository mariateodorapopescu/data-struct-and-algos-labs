#include <stdio.h>
#include <stdlib.h>
typedef int data;
typedef struct nod{
data elem;
struct nod *next;
}nod,*listnod;
typedef struct list{
listnod first;
listnod last;
}list,*slist;
void initlist(slist s)
{
    s->first=s->last=NULL;
    s->first=(listnod)malloc(sizeof(nod));
    s->last=s->first;
}
listnod addinc(slist s,data a)
{
    nod *newnod;
    newnod=(listnod)malloc(sizeof(nod));
    if (s->first == NULL)
    {
        newnod->elem = a;
        newnod->next = newnod;
        s->first= newnod;
        s->last= newnod;
        return;
    }

    newnod->elem = a;
    newnod->next = s->first;
    s->last->next = newnod;
    s->first = newnod;
}
int nr(slist s, int x)
{
    nod *q;
    int num;
    num = 0;
    for (q=s->first;q!=s->last;q=q->next)
        {
            if (q->elem == x)
            {
                num = num + 1;
            }
        }
        return num;
}
int main()
{
    int i,n;
    data y;
    nod *q;
    slist s;
    int x;
    initlist(s);
    scanf("%d",&n);
    int num;
    for (i=0;i<n;i++)
    {
        scanf("%d",&y);
        addinc(s,y);
    }
    for (q=s->first;q!=s->last;q=q->next)
        {
            num = nr(s,x);
            printf ("%d ", num);
        }
        // zicem si noi asa
    return 0;
}
