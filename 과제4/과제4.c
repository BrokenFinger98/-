#pragma warning(disable:4996)
#include<time.h>
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

typedef struct node {
    int elem;
    struct node* prev;
    struct node* next;
}node;

typedef struct queue {
    node* front;
    node* rear;
}queue;

typedef struct stack {
    queue* q1;
    queue* q2;
}stack;



// stack에 대한 method
int isStackEmpty(stack* S);
int top(stack* S);
void push(stack* S, int e);
void pushMillion(stack* S);
int pop(stack* S);
void freeStack(stack* S);

// queue에 대한 method
void initQueue(queue* Queue);
int isQueueEmpty(queue* Queue);
void enqueue(queue* Queue, int e);
int queueTop(queue* Queue);
int dequeue(queue* Queue);


int size = 0;

int main(void) {
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    char order;
    int n;
    srand(time(NULL));


    stack* S = (stack*)malloc(sizeof(stack));
    if (!S) {
        return 1;
    }
    S->q1 = (queue*)malloc(sizeof(queue));
    if (!S) {
        return 1;
    }
    initQueue(S->q1);
    S->q2 = (queue*)malloc(sizeof(queue));
    if (!S) {
        return 1;
    }
    initQueue(S->q2);

    scanf("%c", &order);
    getchar();
    while (order != 'q') {
        if (order == 'S') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            n = isStackEmpty(S);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            if (n) {
                printf("Empty ");
            }
            else {
                printf("Nonempty ");
            }
            printf("(%d), cputime = %.10f\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
        }
        else if (order == 't') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            n = top(S);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            if (isStackEmpty(S)) {
                printf("Empty Stack Exception!! (%d), cputime = %.10f\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            }
            else {
                printf("%d (%d), cputime = %.10f\n", n, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            }
        }
        else if (order == 'p') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            scanf("%d", &n);
            push(S, n);
            size++;
            while (getc(stdin) == ' ') {
                scanf("%d", &n);
                push(S, n);
                size++;
            }
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            printf("OK (%d), cputime = %.10f\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
        }
        else if (order == 'P') {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            pushMillion(S);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            size += 1000000;
            printf("OK (%d), cputime = %.10f\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
        }
        else if (order == 'o') {
            int s = isStackEmpty(S);
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            n = pop(S);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            if (s) {
                printf("Empty Stack Exception!! (%d), cputime = %.10f\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            }
            else {
                size--;
                printf("%d (%d), cputime = %.10f\n", n, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
            }
        }
        else {
            printf("Invalid order!!\n");
        }
        scanf("%c", &order);
        getchar();
    }


    node* seek = (S->q1)->front;
    node* temp = seek;
    while (seek) {
        temp = temp->next;
        free(seek);
        seek = temp;
    }
    freeStack(S);
    //free(S->q1);
    //free(S->q2);
    //free(S);
    return 0;
}
void initQueue(queue* Queue) {
    Queue->front = NULL;
    Queue->rear = NULL;
}
int isQueueEmpty(queue* Queue) {
    return (Queue->front == NULL);
}
int queueTop(queue* Queue) {
    if (isQueueEmpty(Queue)) {
        return 1;
    }
    return (Queue->front)->elem;
}
void enqueue(queue* Queue, int e) {
    node* p = (node*)malloc(sizeof(node));
    if (!p) {
        return 1;
    }
    p->elem = e;
    p->prev = p->next = NULL;
    if (isQueueEmpty(Queue))Queue->front = Queue->rear = p;
    else {
        (Queue->rear)->next = p;
        p->prev = Queue->rear;
        Queue->rear = p;
    }
}
int dequeue(queue* Queue) {
    if (isQueueEmpty(Queue)) {
        return 1;
    }
    int e = (Queue->front)->elem;
    node* p = Queue->front;
    (Queue->front) = (Queue->front)->next;
    if ((Queue->front) == NULL)Queue->rear = NULL;
    free(p);
    return e;
}
int isStackEmpty(stack* S) {
    return isQueueEmpty(S->q1);
}
int top(stack* S) {
    if (isStackEmpty(S)) {
        return 1;
    }
    return ((S->q1)->rear)->elem;
}
void push(stack* S, int e) {
    enqueue(S->q1, e);
}
void pushMillion(stack* S) {
    for (int i = 0; i < 1000000; i++) {
        push(S, (rand() % 90 + 10));
    }
}
int pop(stack* S) {
    if (isStackEmpty(S)) {
        return 1;
    }
    for (int i = 0; i < size - 1; i++) {
        enqueue(S->q2, dequeue(S->q1));
    }
    int e = dequeue(S->q1);
    for (int i = 0; i < size - 1; i++) {
        enqueue(S->q1, dequeue(S->q2));
    }
    return e;
}
void freeStack(stack* S) {
    free(S->q1);
    free(S->q2);
    free(S);
}