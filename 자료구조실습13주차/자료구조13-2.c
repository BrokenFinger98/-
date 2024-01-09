#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    int data;
    struct node* left;
    struct node* right;
} node;

typedef struct tree {
    node* root;
} tree;

node* getnode(int id, int data, node* left, node* right) {
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->id = id;
    p->left = left;
    p->right = right;
    return p;
}

node* initTree() {
    node* N1, * N2, * N3, * N4, * N5, * N6, * N7, * N8;
    N8 = getnode(8, 80, NULL, NULL);
    N7 = getnode(7, 130, NULL, NULL);
    N4 = getnode(4, 70, NULL, NULL);
    N5 = getnode(5, 90, NULL, NULL);
    N6 = getnode(6, 120, N7, N8);
    N2 = getnode(2, 30, N4, N5);
    N3 = getnode(3, 50, NULL, N6);
    N1 = getnode(1, 20, N2, N3);
    return N1;
}

node* FindNode(node* p, int id) {
    if (p == NULL)
        return NULL;
    if (p->id == id)
        return p;

    node* leftResult = FindNode(p->left, id);
    if (leftResult != NULL)
        return leftResult;

    node* rightResult = FindNode(p->right, id);
    if (rightResult != NULL)
        return rightResult;

    return NULL;
}

int preOrder(node* p) {
    if (p == NULL)
        return 0;
    return p->data + preOrder(p->left) + preOrder(p->right);
}

void freeTree(node *p){
    if(p){
        freeTree(p->left);
        freeTree(p->right);
        free(p);
    }
}

int main() {
    int id;
    tree T;
    T.root = initTree();

    scanf("%d", &id);
    if (id < 1 || id > 8) {
        printf("-1\n");
        return -1;
    }

    node* p = FindNode(T.root, id);
    if (p == NULL) {
        printf("Node not found\n");
        return -1;
    }
    printf("%d\n", preOrder(p));
    freeTree(T.root);
    return 0;
}
