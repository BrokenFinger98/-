#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *next;
}node;

typedef struct set{
    int n;
    node *header;
}set;

set *initSet();
node *getnode();
node *uni(node *A, node *B);
node *intersect(node *A, node *B);
void freeSet(set *A, set *B, set *C, set *D);
void addLast(set *, int a);

int main(){
    set *A = initSet();
    set *B = initSet();
    set *C = initSet();
    set *D = initSet();
    node *p, *q;
    int i,n,m,e;

    scanf("%d", &n);
    if(n != 0){
        for(i=0;i<n;++i){
            scanf("%d", &e);
            addLast(A,e);
        }
    }
    scanf("%d", &m);
    if(m != 0){
        for(i=0;i<m;++i){
            scanf("%d", &e);
            addLast(B,e);
        }
    }
    C->header->next = uni(A->header->next, B->header->next);
    D->header->next = intersect(A->header->next, B->header->next);
    
    p = C->header->next;
    if(p == NULL)
        printf("0\n");
    else{
        while (p != NULL){
            printf(" %d", p->elem);
            p = p->next;
        }
        printf("\n");
    }
    p = D->header->next;
    if(p == NULL)
        printf("0\n");
    else{
        while (p != NULL){
            printf(" %d", p->elem);
            p = p->next;
        }
        printf("\n");
    }
    freeSet(A,B,C,D);

    return 0;
}

node *getnode(){
    node *p = (node *)malloc(sizeof(node));
    p->elem = '\0';
    p->next = NULL;

    return p;
}

set *initSet(){
    set *p = (set *)malloc(sizeof(set));
    p->header = getnode();
    p->n = 0;
    return p;
}

node *uni(node *A, node *B){
    if(A == NULL && B == NULL)
        return NULL;
    node *p = getnode();
    if(A == NULL){
        p->elem = B->elem;
        p->next = uni(A, B->next);
    }
    else if(B == NULL){
        p->elem = A->elem;
        p->next = uni(A->next, B);
    }
    else{
        if(A->elem < B->elem){
            p->elem = A->elem;
            p->next = uni(A->next, B);
        }
        else if(A->elem > B->elem){
            p->elem = B->elem;
            p->next = uni(A, B->next);
        }
        else{
            p->elem = A->elem;
            p->next = uni(A->next, B->next);
        }
    }
    return p;
}

node *intersect(node *A, node *B){
    if(A == NULL || B == NULL)
        return NULL;
    if(A->elem < B->elem)
        return intersect(A->next, B);
    else if(A->elem > B->elem)
        return intersect(A, B->next);
    else{
        node *p = getnode();
        p->elem = A->elem;
        p->next = intersect(A->next, B->next);
        return p;
    }
}

void addLast(set *S, int e){
    node *p = getnode();
    node *q = S->header;
    int i;

    p->elem = e;
    while (q->next != NULL){
        q = q->next;
    }
    q->next = p;
    ++S->n;
}

void freeSet(set *A, set *B, set *C, set *D){
    node *p, *q;

    p = A->header;
    while (p != NULL){
        q = p;
        free(p);
        p = q->next;
    }
    free(A);

    p = B->header;
    while (p != NULL){
        q = p;
        free(p);
        p = q->next;
    }
    free(B);

    p = C->header;
    while (p != NULL){
        q = p;
        free(p);
        p = q->next;
    }
    free(C);

    p = D->header;
    while (p != NULL){
        q = p;
        free(p);
        p = q->next;
    }
    free(D);
}