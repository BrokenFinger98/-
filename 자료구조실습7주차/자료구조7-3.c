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
set *uni(set *A, set *B);
set *intersect(set *A, set *B);
int isEmpty(set *);
int get(set *, int r);
void addLast(set *, int a);
void removeFirst(set *);
void print(set *);

int main(){
    set *A = initSet();
    set *B = initSet();
    int i,n,e;

    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", &e);
        addLast(A,e);
    }
    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", &e);
        addLast(B,e);
    }

    print(uni(A, B));
    print(intersect(A, B));
    
    return 0;
}

set *uni(set *A, set *B){
    set *C = initSet();
    node *a = A->header->next;
    node *b = B->header->next;
    while (a->next != NULL && b->next != NULL)
    {
        if(a->elem<b->elem){
            addLast(C,a->elem);
            a = a->next;
        }
        else if(a->elem>b->elem){
            addLast(C,b->elem);
            b = b->next;
        }
        else{
            addLast(C,a->elem);
            a = a->next;
            b = b->next;
        }
    }
    while (a->next != NULL)
    {
        addLast(C,a->elem);
        a = a->next;
    }
    while (b->next != NULL)
    {
        addLast(C,b->elem);
        b = b->next;
    }
    return C;
}

set *intersect(set *A, set *B){
    set *C = initSet();
    node *a = A->header->next;
    node *b = B->header->next;
    while (a->next != NULL && b->next != NULL){
        if(a->elem<b->elem)
            a = a->next;
        else if(a->elem>b->elem)
            b = b->next;
        else{
            addLast(C,a->elem);
            a = a->next;
            b = b->next;
        }
    }
    while (a->next != NULL)
        a = a->next;
    while (b->next != NULL)
        b = b->next;
    
    return C;
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
    p->n = 0;

    return p;
}

int isEmpty(set *S){
    if(S->n == 0)
        return 1;
    else    
        return 0;
}

int get(set *S, int r){
    node *p = S->header;
    int i;

    for(i=0;i<r;++i)
        p = p->next;
    
    return p->elem;
}

void addLast(set *S, int a){
    node *p = getnode();
    node *q = S->trailer;
    
    p->elem = a;
    p->next = q;
    p->prev = q->prev;
    q->prev->next = p;
    q->prev = p;
    ++S->n;
}

void removeFirst(set *S){
    node *p = S->header;
    
    p->next = p->next->next;
    p->next->prev = p;
    --S->n;
}

void print(set *p){
    if(p->header->next == p->trailer){
        printf(" 0\n");
    }
    else{
        node *q = p->header->next;
        while (q->next != NULL){
            printf(" %d", q->elem);
            q = q->next;
        }
        printf("\n");
    }
}