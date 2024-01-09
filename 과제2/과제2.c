#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    char gro;
    struct node *nextgroup;
    struct node *nextelement;
}node;

typedef struct Groups{
    node *header;
}Groups;

typedef struct Elements{
    node *header;
}Elements;

Groups G[5];                                  
Elements E[4];

int NE = 4;
int NG = 5;

node *getnode(int e, char g);
void initShare();
void addShare(int e, char g);
void removeShare(int e, char g);
void traverseShareElements(char g);
void traverseShareGroups(int e);
void freeShare();

int main(){
    int e;
    char g, type;

    initShare();
    while (1)
    {
        scanf("%c", &type);
        getchar();
        switch (type){
            case 'a':
                scanf("%d", &e);
                getchar();
                scanf("%c", &g);
                getchar();
                addShare(e, g);
                break;
            case 'r':
                scanf("%d", &e);
                getchar();
                scanf("%c", &g);
                getchar();
                removeShare(e, g);
                break;
            case 'e':
                scanf("%c", &g);
                getchar();
                traverseShareElements(g);
                break;
            case 'g':
                scanf("%d", &e);
                getchar();
                traverseShareGroups(e);
                break;
            default:
                freeShare();
                return -1;
                break;
        }
    }
    
    return 0;
}

node *getnode(int e, char g){
    node *p = (node *)malloc(sizeof(node));
    p->nextelement = NULL;
    p->nextgroup = NULL;
    p->elem = e;
    p->gro = g;
    return p;
}
void freeShare(){
    node *HE, *HG, *p, *f;
    int i;

    for(i = 0; i < NE; ++i){
        HE = E[i].header;
        p = HE->nextgroup;
        while (1){
            if(p == HE)
                break;
            else{
                f = p;
                p = p->nextgroup;
                free(f);
            }
        }
        free(HE);
    }
    for(i = 0; i < NG; ++i){
        HG = G[i].header;
        free(HG);
    } 
}
void initShare(){
    int i;
    node *H;
    
    for(i = 0; i < NE; ++i){
        H = getnode(i+1, '\0');
        H->nextgroup = H;
        E[i].header = H;
    }
    for(i = 0; i < NG; ++i){
        H = getnode('\0', 'A'+i);
        H->nextelement = H;
        G[i].header = H;
    }
}
void addShare(int e, char g){
    node *p = getnode(e, g);
    node *HG = G[g-'A'].header;
    p->nextelement = HG->nextelement;
    HG->nextelement = p;
    node *HE = E[e-1].header;
    p->nextgroup = HE->nextgroup;
    HE->nextgroup = p;
    printf("OK\n");
}
void removeShare(int e, char g){
    node *p = G[g-'A'].header;
    node *r;

    while (p->nextelement->elem != e){
        p = p->nextelement;
    }
    r = p->nextelement;
    p->nextelement = p->nextelement->nextelement;

    p = E[e-1].header;
    while (p->nextgroup->gro != g){
        p = p->nextgroup;
    }
    r = p->nextgroup;
    p->nextgroup = p->nextgroup->nextgroup;
    free(r);
    printf("OK\n");
}
void traverseShareElements(char g){
    node *H = G[g-'A'].header;
    node *p = H->nextelement;

    if(p->elem == '\0')
        printf("0\n");
    else{
        while (p != H){
            printf("%d ",p->elem);
            p = p->nextelement;
        }
        printf("\n");
    }
}
void traverseShareGroups(int e){
    node *H = E[e-1].header;
    node *p = H->nextgroup;

    if(p->gro == '\0')
        printf("0\n");
    else{
        while (p != H){
            printf("%c ",p->gro);
            p = p->nextgroup;
        }
        printf("\n");
    }
}
