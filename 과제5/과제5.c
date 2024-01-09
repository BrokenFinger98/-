#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *left;
    struct node *right;
    char *elem;
}node;

typedef struct tree{
    node *root;
}tree;

node *getnode(){
    node *p = (node *)malloc(sizeof(node));
    p->left = NULL;
    p->right = NULL;
    return p;
}

node *makeExternalNode(){
    char tmp[101];
    node *p = getnode();

    printf("Enter decision: ");
    gets(tmp);
    p->elem = (char *)malloc(sizeof(char)*(strlen(tmp)+1));
    strcpy(p->elem, tmp);

    return p;
}

node *makeInternalNode(){
    char tmp[101];
    node *p = getnode();

    printf("Enter question: ");
    gets(tmp); 
    p->elem = (char *)malloc(sizeof(char)*(strlen(tmp)+1));
    strcpy(p->elem, tmp);

    printf("Question if yes to \'");
    printf("%s", p->elem);
    printf("\'? ");
    gets(tmp); 
    if(strcmp(tmp, "yes") == 0)
        p->left = makeInternalNode();
    else
        p->left = makeExternalNode();
    
    printf("Question if no to \'");
    printf("%s", p->elem);
    printf("\'? ");
    gets(tmp);
    if(strcmp(tmp, "yes") == 0)
        p->right = makeInternalNode();
    else
        p->right = makeExternalNode();
    
    return p;
}

node *buildDecisionTree(){
    printf("***Let's build a dichotomous QA system\n");
    return makeInternalNode();
}

int isInternal(node* p) {
    return (p->left != NULL && p->right != NULL);
}

void processNode(node *p){
    printf("%s ", p->elem);
    if(isInternal(p)){
        char tmp[101];
        gets(tmp);
        if(strcmp(tmp, "yes") == 0)
            processNode(p->left);
        else
            processNode(p->right);
    }
}

void runDecisionTree(node *p){
    printf("***Please answer questions\n");
    processNode(p);
    printf("\n");
}

void freeTree(node *p){
    if(p){
        freeTree(p->left);
        freeTree(p->right);
        free(p);
    }
}

int main(){
    tree T;
    T.root = buildDecisionTree();
    printf("Tree complete. Now Running!!\n");
    for(int i = 0; i < 3; ++i){
        runDecisionTree(T.root);
        printf("\n");
    }
    freeTree(T.root);   
    return 0;
}

/*
Enter question: 빠른 식사를 원하세요?
Question if yes to '빠른 식사를 원하세요?'? yes
Enter question: 양식도 좋으세요?
Question if yes to '양식도 좋으세요?'? no
Enter decision: 햄버거
Question if no to '양식도 좋으세요?'? no
Enter decision: 국수
Question if no to '빠른 식사를 원하세요?'? yes
Enter question: 비싸도 됩니까?
Question if yes to '비싸도 됩니까?'? no
Enter decision: 레스토랑
Question if no to '비싸도 됩니까?'? no
Enter decision: 요리해 드세요
Tree complete. Now Running!!
***Please answer questions
빠른 식사를 원하세요? yes
양식도 좋으세요? no
국수 

***Please answer questions
빠른 식사를 원하세요? yes
양식도 좋으세요? yes
햄버거 

***Please answer questions
빠른 식사를 원하세요? no
비싸도 됩니까? no
요리해 드세요 
*/