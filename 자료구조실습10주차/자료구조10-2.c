#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char elem;
    struct node *next;
}node;

typedef struct stack{
    node *t;
}stack;

stack *initStack();
node *getnode(char e);
void push(stack *S, char e);
char pop(stack *S);
int isEmpty(stack *S);
void emptyStackException();
void putnode(node *p);
void traverse(stack *S);
void visit(char e);
int isOperand(char s);
int doOperator(char op, int x, int y);
void evaluate(char *postfix_arry);

int main(){
    char tmp[101], *postfix_arry = NULL;
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        getchar();
        scanf("%s", tmp);
        postfix_arry = (char *)malloc(sizeof(char)*strlen(tmp)+1);
        strcpy(postfix_arry, tmp); 
        evaluate(postfix_arry);
        free(postfix_arry);
        printf("\n");
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

void push(stack *S, char e){
    node *p = getnode(e);

    if (S->t == NULL) {
        S->t = p;
    }
    else {
        p->next = S->t;
        S->t = p;
    }
}

char pop(stack *S){
    if(isEmpty(S)){
        emptyStackException();
        return -1;
    } 
    char e = S->t->elem;
    node *p = S->t;
    S->t = S->t->next;
    putnode(p);
    return e;
}

int isEmpty(stack *S){
    if(S->t == NULL)
        return 1;
    return 0;
}

void emptyStackException(){
    printf("Error\n");
}

void putnode(node *p){
    free(p);
    p = NULL;
    return;
}

void traverse(stack *S){
    node *p = S->t;
    while (p != NULL)
    {
        visit(p->elem);
        p = p->next;
    }
    printf("\n");
}

void visit(char e){
    printf("%d", e-'0');
}

int isOperand(char s){
    char oper[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0; i < 10; ++i){
        if(s == oper[i])
            return 1;
    }
    return 0;
}

int doOperator(char op, int x, int y){
    int v;
    switch (op)
    {
    case '+': v = x+y; break;
    case '-': v = x-y; break;  
    case '*': v = x*y; break;
    case '/': v = x/y; break;
    }
    return v;
}

void evaluate(char *postfix_arry){
    stack *S = initStack();
    int N = strlen(postfix_arry);
    int idx = 0;

    while (idx != N)
    {
        char s = postfix_arry[idx++];
        if(isOperand(s))
            push(S,s);
        else{
            int a = pop(S)-'0';
            int b = pop(S)-'0';
            push(S, doOperator(s, b, a)+'0');
        }
    }
    visit(pop(S));
    return;
}