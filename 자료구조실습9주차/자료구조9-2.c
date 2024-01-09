#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node *next;
}node;

typedef struct stack{
    node *t;
}stack;

stack *initStack();
node *getnode(char e);
node *makenode();
void addnode(node *p, char e);
void push(stack *S, char e);
char pop(stack *S);
void emptyStackException();
int isOpenSymbol(char e);
int isCloseSymbol(char e);
int isEmpty(stack *S);
int isCounterpart(char s, char e);
int isBalanced(node *H);
int countSymbols(node *H);

int main(){
    node *H = makenode();
    node *p;
    char e;
    int i, count = 0;

    count = countSymbols(H);
    i = isBalanced(H);
    if(i == 1)
        printf("OK_%d\n", count);
    else
        printf("Wrong_%d\n", count);
    while (H != NULL){
        p = H;
        H = H->next;
        free(p);
    }
    
    return 0;
}

stack *initStack(){
    stack *S = (stack *)malloc(sizeof(stack));

    S->t = NULL;

    return S;
}
node *getnode(char e){
    node *p = (node *)malloc(sizeof(node));

    p->elem = e;
    p->next = NULL;

    return p;
}
node *makenode(){
    node *H = NULL, *p = NULL;
    char e;
    int i;

    for(i = 0; i < 1000; ++i){
        scanf("%c", &e);
        if(e == '\n')
            break;
        if(i == 0){
            p = getnode(e);
            H = p;
        }
        else{
            addnode(p, e);
            p = p->next;
        }
    }
    return H;
}
void addnode(node *p, char e){
    node *q = getnode(e);
    p->next = q;
}
void push(stack *S, char e){
    node *p = getnode(e);

    p->next = S->t;
    S->t = p;
}
char pop(stack *S){
    if(isEmpty(S))
        emptyStackException();
    char e = S->t->elem;
    node *p = S->t;
    S->t = S->t->next;
    free(p);
    return e;
}
void emptyStackException(){
    printf("Error\n");
}
int isOpenSymbol(char e){
    if(e == '(' || e == '{' || e == '[')
        return 1;
    return 0;
}
int isCloseSymbol(char e){
    if(e == ')' || e == '}' || e == ']')
        return 1;
    return 0;
}
int isEmpty(stack *S){
    if(S->t == NULL)
        return 1;
    return 0;
}
int isCounterpart(char e, char t){
    if(e == ')'){
        if(t == '(')
            return 1;
        return 0;
    }
    else if(e == '}'){
        if(t == '{')
            return 1;
        return 0;
    }
    else{
        if(t == '[')
            return 1;
        return 0;
    }
}
int isBalanced(node *H){
    stack *S = initStack();
    char e, t;
    while (H != NULL){
        e = H->elem;
        if(isOpenSymbol(e))
            push(S,e);
        else if(isCloseSymbol(e)){
            if(isEmpty(S))
                return 0;
            t = pop(S);
            if(!isCounterpart(e,t))
                return 0;
        }
        H = H->next;
    }
    return isEmpty(S);
}
int countSymbols(node *H){
    int count = 0;
    node *p = H;
    while (p != NULL){
        count += isOpenSymbol(p->elem);
        count += isCloseSymbol(p->elem);
        p = p->next;
    }
    return count;
}

