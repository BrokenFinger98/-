#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *prev;
    struct node *next;
}node;

typedef struct set{
    int n;
    node *header;
    node *trailer;
}set;


set *initSet();
node *getnode();
int subset(set *A, set *B);
int member(set * ,int e);
void add(set *, int e);

int main(){
    int n,i,e;
    set *A = initSet();
    set *B = initSet();
    A->n = 0;
    B->n = 0;

    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", &e);
        add(A,e);
    }

    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", &e);
        add(B,e);
    }
    printf("%d\n", subset(A,B));

    return 0;
}

node *getnode(){
    node *p = (node *)malloc(sizeof(node));

    p->elem = '\0';
    p->next = NULL;
    p->prev = NULL;

    return p;
}

set *initSet(){
    set *p = (set *)malloc(sizeof(set));

    node *header = getnode();
    node *trailer = getnode();
    header->next = trailer;
    trailer->prev = header;
    p->header = header;
    p->trailer = trailer;

    return p;
}

int member(set * S,int e){
    if(S->n == 0)
        return 0;

    node *p = S->header->next;
    int a;

    while (1){
        a = p->elem;
        if(a<e){
            if(p->next->next == NULL)
                return 0;
            else   
                p = p->next;
        }
        else if(a>e)
            return 0;
        else   
            return 1;
    }
}

int subset(set *A, set *B){
    if(A->n == 0)
        return 0;
    node *p = A->header->next;
    while (1){
        if(member(B,p->elem)){
            if(p->next->next == NULL)
                return 0;
            else   
                p = p->next;
        }
        else
            return p->elem;
    }
    
}

void add(set *S, int e){
    node *q = getnode();
    node *p = S->header;
    int i;

    ++S->n;
    for(i=0;i<S->n;++i){
        p = p->next;
    }
    q->elem = e;
    q->prev = p->prev;
    q->next = p;
    p->prev->next = q;
    p->prev = q;
}