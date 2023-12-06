#include <stdio.h>
#include <stdlib.h>
typedef struct cell
{
    int elem;
    struct cell *next;
} Stack, *TStack;
TStack initStack()
{
    TStack s;
    return s=NULL;
}
int isEmptyStack(TStack s)
{
    return s==NULL;
}
TStack push(TStack s, int element)
{
    TStack t;
    t = (TStack) malloc(sizeof(Stack));
    if (t == NULL)
        {
        return NULL;
        }
    t->elem = element;
    t->next = s;
    return t;
}
TStack pop(TStack s)
{
    int element;
    TStack t;
    if (s == NULL) {
    return NULL;
    }
    element = s->elem;
    t = s;
    s = s->next;
    free(t);
    return s;
}
int top(TStack s)
{
    if (!isEmptyStack(s))
        return s->elem;
    else
    {
        return -1;
    }
}
void print(TStack s)
 {
     while (s!=0)
     {
         printf ("%d\n", s->elem);
         s=s->next;
     }
 }
int main ()
{
    int x,n,i;
    TStack s;
    s=initStack();
    i=0;
    scanf("%d",&n);
    while (i<n)
        {
            scanf("%d", &x);
            s=push(s, x);
            i++;
        }
    print(s);
    s=pop(s);
    printf("dupa pop\n");
    print(s);
    return 0;
}
