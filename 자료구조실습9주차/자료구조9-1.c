#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char *s;
    int t;
    int N;
}stack;

stack *initStack(int n);
void push(stack *S, char c);
char pop(stack *S);
void peek(stack *S);
void duplicate(stack *S);
void upRotate(stack *S, int n);
void downRotate(stack *S, int n);
void print(stack *S);
int isEmpty(stack *S);
void freeStack(stack *S);

int main(){
    int N, c, i, n;
    char *tmp = (char *)malloc(sizeof(char)*6), e;
    stack *S;

    scanf("%d", &N);
    scanf("%d", &c);
    S = initStack(N);
    for(i = 0; i < c; ++i){
        getchar();
        scanf("%s", tmp);
        if(strcmp(tmp, "POP") == 0)
            pop(S);
        else if(strcmp(tmp, "PUSH") == 0){
            getchar();
            scanf("%c", &e);
            push(S,e);
        }
        else if(strcmp(tmp, "PEEK") == 0)
            peek(S);
        else if(strcmp(tmp, "DUP") == 0)
            duplicate(S);
        else if(strcmp(tmp, "UpR") == 0){
            getchar();
            scanf("%d", &n);
            upRotate(S, n);
        }
        else if(strcmp(tmp, "DownR") == 0){
            getchar();
            scanf("%d", &n);
            downRotate(S, n);
        }
        else if(strcmp(tmp, "PRINT") == 0)
            print(S);
    }
    free(tmp);
    freeStack(S);
    
    return 0;
}

stack *initStack(int n){
    stack *S = (stack *)malloc(sizeof(stack));

    S->t = -1;
    S->N = n;
    S->s = (char *)malloc(sizeof(char)*n);

    return S;
}
void push(stack *S, char c){
    if(S->t == S->N-1)
        printf("Stack FULL\n");
    else{
        ++S->t;
        S->s[S->t] = c;  
    }
}
char pop(stack *S){
    if(isEmpty(S)){
        printf("Stack Empty\n");
        return '\0';
    }
    else{
        --S->t;
        return S->s[S->t+1];
    }
}
void peek(stack *S){
    if(isEmpty(S))
        printf("Stack Empty\n");
    else
        printf("%c\n", S->s[S->t]);
}
void duplicate(stack *S){
    if(S->t == S->N-1)
        printf("Stack FULL\n");
    else{
        char e;
        e = pop(S);
        push(S,e);
        push(S,e);
    }
}
void upRotate(stack *S, int n){
    if(n>S->t+1)
        return;
    char temp = S->s[S->t];
    for(int i = S->t; i > S->t - n; --i){
        S->s[i] = S->s[i-1];
    }
    S->s[S->t-n+1] = temp;
}
void downRotate(stack *S, int n){
    if(n>S->t+1)
        return;
    char temp = S->s[S->t-n+1];
    for(int i = S->t-n+1; i < S->t; ++i){
        S->s[i] = S->s[i+1];
    }
    S->s[S->t] = temp;
}
void print(stack *S){
    for(int i = S->t; i > -1; --i){
        printf("%c", S->s[i]);
    }
    printf("\n");
}
int isEmpty(stack *S){
    if(S->t < 0)
        return 1;
    return 0;
}
void freeStack(stack *S){
    free(S);
}