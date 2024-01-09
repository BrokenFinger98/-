#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *initTree();
treenode *getTree(int e, treenode *leftnode, treenode *rightnode);
void printTree(treenode* tree);

int main(){
    treenode *F[8];
    F[6] = getTree(130, NULL, NULL);
    F[7] = getTree(80, NULL, NULL);
    F[3] = getTree(70, NULL, NULL);
    F[4] = getTree(90, NULL, NULL);
    F[5] = getTree(120, F[6], F[7]);
    F[1] = getTree(30, F[3], F[4]);
    F[2] = getTree(50, NULL, F[5]);
    F[0] = getTree(20, F[1], F[2]);
    
    int Fnum;

    scanf("%d", &Fnum);
    
    if(Fnum>=1 && Fnum<=8) {
        printTree(F[Fnum-1]);
    }
    else {
        printf("-1\n");
    }
    
    for(int i = 0; i<8;i++) free(F[i]);
    return 0;
}

treenode *getTree(int e, treenode *leftnode, treenode *rightnode){
    treenode *node = (treenode *)malloc(sizeof(treenode));
    node->data = e;
    node->left = leftnode;
    node->right = rightnode;
    return node;
}

void printTree(treenode* tree){
    treenode* p = tree;
    printf("%d ", p->data);
    if(p->left!=NULL) printf("%d ", p->left->data);
    if(p->right!=NULL) printf("%d ", p->right->data);
    printf("\n");
}