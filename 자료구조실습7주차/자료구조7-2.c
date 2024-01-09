#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *next;
}node;

typedef struct list{
    int n;
    node *list;
}list;

list *initList();
node *getnode();
int subset(list *A, list *B);
int member(list * ,int e);
void add(list *, int e);

int main(){
    int i,n,e;
    list *A = initList();
    list *B = initList();
    node *p, *q;

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
    p = A->list;
    for(i = 0; i < A->n; ++i){
        q = p->next;
        free(p);
        p = q;
    }
    p = B->list;
    for(i = 0; i < B->n; ++i){
        q = p->next;
        free(p);
        p = q;
    }
    return 0;
}

list *initList(){
    list *p = (list *)malloc(sizeof(list));

    node *q = getnode();
    p->list = q;
    p->n = 0;

    return p;
}

node *getnode(){
    node *p = (node *)malloc(sizeof(node));

    p->elem = '\0';
    p->next = NULL;

    return p;
}

int subset(list *A, list *B){
    if(A->list == NULL)
        return 0;

    node *p = A->list;
    int a;

    while (1){
        if(member(B,p->elem)){
            if(p->next == NULL)
                return 0;
            else    
                p = p->next;
        }
        else   
            return p->elem;
    }
    
}

int member(list *L ,int e){
    if(L->list == NULL)
        return 0;

    node *p = L->list;
    int a;

    while (1){
        a = p->elem;
        if(a<e){
            if(p->next == NULL)
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

void add(list *L, int e){
    node *p = getnode();
    node *q = L->list;
    int i;

    p->elem = e;
    for(i = 0; i < L->n; ++i){
        q = q->next;
    }
    q->next = p;
    ++L->n;
}