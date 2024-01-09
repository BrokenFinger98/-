#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct node {
    int elem, min;
    struct node* next;
}node;

typedef struct stack {
    node* t;
    int n;
}stack;

stack* initStack();
node* getnode(int e);
void push(stack* S, int e);
void pushMillion(stack* S);
char pop(stack* S);
void popMillion(stack* S);
int findMin(stack* S);
void putnode(node* p);

int main() {
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    char ch = 'a', ch_p;
    int e, Min;
    stack* S = initStack();

    while (ch != 'q')
    {
        scanf("%c", &ch);
        if (ch == 'p') {
            scanf("%d", &e);
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            push(S, e);
            QueryPerformanceCounter(&end);

            diff.QuadPart = end.QuadPart - start.QuadPart;
            printf("push %d (%d), cputime = %.12f\n", e, S->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            getchar();
        }
        else if (ch == 'P') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            pushMillion(S);
            QueryPerformanceCounter(&end);

            diff.QuadPart = end.QuadPart - start.QuadPart;
            printf("pushMillon (%d), cputime = %.12f\n", S->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            getchar();
        }
        else if (ch == 'o') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            ch_p = pop(S);
            QueryPerformanceCounter(&end);

            diff.QuadPart = end.QuadPart - start.QuadPart;
            printf("pop %d (%d), cputime = %.12f\n", ch_p, S->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            getchar();
        }
        else if (ch == 'O') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            popMillion(S);
            QueryPerformanceCounter(&end);

            diff.QuadPart = end.QuadPart - start.QuadPart;
            printf("popMillon (%d), cputime = %.12f\n", S->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            getchar();
        }
        else if (ch == 'f') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            Min = findMin(S);
            QueryPerformanceCounter(&end);

            diff.QuadPart = end.QuadPart - start.QuadPart;
            printf("min %d (%d), cputime = %.12f\n", Min, S->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            getchar();
        }
        else if (ch == 'q') {
            node* p = NULL;
            while (S->t != NULL) {
                p = S->t->next;
                putnode(S->t);
                S->t = p;
            }
            free(S);
            break;
        }
        else {
            printf("잘못된 명령어입니다.\n");
        }
    }

    return 0;
}

stack* initStack() {
    stack* S = (stack*)malloc(sizeof(stack));

    S->t = NULL;
    S->n = 0;

    return S;
}

node* getnode(int e) {
    node* p = (node*)malloc(sizeof(node));

    p->elem = e;
    p->next = NULL;

    return p;
}

void push(stack* S, int e) {
    node* p = getnode(e);

    if (S->n == 0) {
        p->min = e;
        S->t = p;
    }
    else {
        if (e < S->t->min)
            p->min = e;
        else 
            p->min = S->t->min;
        p->next = S->t;
        S->t = p;
    }
    ++S->n;
}

void pushMillion(stack* S) {
    for (int i = 0; i < 1000000; ++i)
        push(S, rand() % 9000 + 1000);
}

char pop(stack* S) {
    if (S->n == 0) {
        printf("Error\n");
        return -1;
    }
    int e = S->t->elem;
    node* p = S->t;
    S->t = S->t->next;
    --S->n;
    putnode(p);
    return e;
}

void popMillion(stack* S) {
    for (int i = 0; i < 1000000; ++i)
        pop(S);
}

int findMin(stack* S) {
    if (S->n <= 0) {
        printf("Error\n");
        return -1;
    }
    return S->t->min;
}

void putnode(node* p) {
    free(p);
    p = NULL;
    return;
}