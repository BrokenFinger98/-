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
int strfind(char *str, char s);
int getPrior(char s);
void convert(char *infix_array);

int main(){
    char tmp[101], *infix_array = NULL;
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        getchar();
        scanf("%s", tmp);
        infix_array = (char *)malloc(sizeof(char)*strlen(tmp)+1);
        strcpy(infix_array, tmp); 
        convert(infix_array);
        free(infix_array);
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

    p->next = S->t;
    S->t = p;
    return;
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
    if(e == '[')
        printf("%c", '+');
    else if(e == ']')
        printf("%c", '-');
    else
        printf("%c", e);
}

int isOperand(char s){
    char oper[26];
    for(int i = 0; i < 26; ++i){
        oper[i] = 'A' + i;
    }
    for(int i = 0; i < 26; ++i){
        if(s == oper[i])
            return 1;
    }
    return 0;
}

int strfind(char *str, char s){
    for(int i = 0; i < strlen(str); ++i){
        if(str[i] == s)
            return i;
    }
    return 0;
}

int getPrior(char s){
    char Prior[12] = {'(', '|', '&', '<', '>', '-', '+', '/', '*', '!', '[', ']'};
    char Prior_N[12] = {0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6};
    
    return Prior_N[strfind(Prior, s)];
}

void convert(char *infix_array){
    stack *S = initStack();
    int N = strlen(infix_array);
    int idx = 0;
    char ch;

    while (idx != N)
    {
        char s = infix_array[idx++];
        if(s == '+' || s == '-'){
            if(idx == 1){
                if(s == '+')
                    s = '[';
                else
                    s = ']';
            }
            else if(infix_array[idx-2] != ')' && !('A' <= infix_array[idx-2] && infix_array[idx-2] <= 'Z')){
                if(s == '+')
                    s = '[';
                else
                    s = ']';
            }
        }
        if(isOperand(s))
            visit(s);
        else if(s == '(')
            push(S, s);
        else if(s == ')'){
            while (S->t->elem != '('){
                ch = pop(S);
                visit(ch);
                if(ch == '&' || ch == '|')
                    visit(ch);
            }
            pop(S);
        }
        else{
            while (!isEmpty(S) && getPrior(s) <= getPrior(S->t->elem)){
                ch = pop(S);
                visit(ch);
                if(ch == '&' || ch == '|')
                    visit(ch);
            }
            push(S,s);
            if(s == '&' || s == '|')
                s = infix_array[idx++];
        }
    }
    while (!isEmpty(S)){
        ch = pop(S);
        if(ch == '&' || ch == '|')
            visit(ch);
        visit(ch);
    }
    
    return;
}
