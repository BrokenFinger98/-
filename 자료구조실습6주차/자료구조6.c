#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coef,exp;
    struct node *next;
}node;

typedef struct polynomial{
    struct node *header;
}poly;

node *getnode();
node *appendTerm(node *k, int c, int e);
node *addPoly(node *A, node *B);

int main(){
    node *A = getnode();
    node *B = getnode();
    node *p;
    poly *AP = (poly *)malloc(sizeof(poly));
    poly *BP = (poly *)malloc(sizeof(poly));
    poly *CP = (poly *)malloc(sizeof(poly));
    int a,b,c,e,i;

    AP->header = A;
    BP->header = B;
    
    scanf("%d", &a);
    for(i=0;i<a;++i){
        scanf("%d %d", &c, &e);
        A = appendTerm(A,c,e);
    }
    scanf("%d", &b);
    for(i=0;i<b;++i){
        scanf("%d %d", &c, &e);
        B = appendTerm(B,c,e);
    }
    CP->header = addPoly(AP->header, BP->header);
    p = CP->header;

    while (p->next != NULL){
        p = p->next;
        printf(" %d %d", p->coef, p->exp);
    }
    printf("\n");
    
    p = CP->header;
    while (p->next != NULL){
        p = p->next;
        free(p);
    }
    p = AP->header;
    while (p->next != NULL){
        p = p->next;
        free(p);
    }
    p = BP->header;
    while (p->next != NULL){
        p = p->next;
        free(p);
    }
    free(AP),free(BP),free(CP);

    return 0;
}

node *getnode(){
    node *p = (node *)malloc(sizeof(node));

    p->next = NULL;

    return p;
}

node *appendTerm(node *k, int c, int e){
    node *t = getnode();

    t->next = NULL;
    t->coef = c;
    t->exp = e;
    k->next = t;
    k = t;

    return k;
}

node *addPoly(node *A, node *B){
    node *result = getnode();
    node *i = A->next;
    node *j = B->next;
    node *k = result;
    int sum;

    while (i != NULL && j != NULL){
        if(i->exp > j->exp){
            k = appendTerm(k, i->coef, i->exp);
            i = i->next;
        }
        else if(i->exp < j->exp){
            k = appendTerm(k, j->coef, j->exp);
            j = j->next;
        }
        else{
            sum = i->coef + j->coef;
            if(sum != 0)
                k = appendTerm(k, sum, i->exp);
            i = i->next;
            j = j->next;
        }
    }
    while (i != NULL){
        k = appendTerm(k, i->coef, i->exp);
        i = i->next;
    }
    while (j != NULL){
        k = appendTerm(k, j->coef, j->exp);
        j = j->next;
    }

    return result;
}