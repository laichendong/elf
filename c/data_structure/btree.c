#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *lchild, *rchild; 
} Btree;

Btree * strToBtree(char *str)
{
    Btree *root = NULL;
    Btree *stack[100];
    int top = -1;
    Btree *last;
    char c;
    int flag;
    int i = 0;
    while ((c = str[i++]) != '@')
    {
        if('A' <= c && c <= 'Z'){
            Btree *node = malloc(sizeof(Btree));
            node->data = c;
            node->lchild = NULL;
            node->rchild = NULL;
            if(root == NULL){
                root = node;
            }else if(flag == 1){ // 左子树开始，把父节点入栈
                stack[top]->lchild = node;
            }else if(flag == 2){
                stack[top]->rchild = node;
            }
            last = node;
        } else if( c == '('){
            stack[++top] = last; 
            flag = 1;
        } else if( c == ','){
            flag  = 2;
        } else if( c == ')'){
            top--;
        }
    }
    
    return root;
}

/**
 * 统计叶子节点
 */
int countLeaf(Btree *t){
    if(t == NULL){
        return 0;
    } else if (t->lchild == NULL  && t->rchild == NULL){
        return 1;
    } else {
        return countLeaf(t->lchild) + countLeaf(t->rchild);
    }
}

/**
 * 计算深度
 */
int deepth(Btree *t){
    int d = 0;
    int ldeep, rdeep;
    if (t != NULL)
    {
        ldeep = deepth(t->lchild);
        rdeep = deepth(t->rchild);
        
        if(ldeep > rdeep){
            d =ldeep + 1;
        }else{
            d = rdeep + 1;
        }
        printf("t=%c; ldeep=%d; rdeep=%d; deepth=%d\n", t->data, ldeep,  rdeep, d);
    }else{
        printf("t=NULL\n");
    }
    
    return d;
    
}

void  preorder(Btree *tree){
    // printf("前序-递归\n");
    if(tree != NULL){
        printf("%c, ", tree->data);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
}

void preOrderStack(Btree *tree){
    // printf("前序-堆栈\n");
    Btree *stack[100], *p=tree;
    int top = -1;
    if(tree != NULL){
        do{
            while (p != NULL)
            {
                printf("%c- ", p->data);
                stack[++top] = p;
                p = p->lchild;
            }
            p = stack[top--];
            p = p->rchild;
        } while(p != NULL || top != -1);
    }
}


void midorder(Btree *tree){
    // printf("中序-递归\n");
    if (tree != NULL)
    {
        midorder(tree->lchild);
        printf("%c, ", tree->data);
        midorder(tree->rchild);
    }
}

void midOrderStack(Btree *tree){
    // printf("中序-堆栈\n");
    Btree *stack[100], *p=tree;
    int top = -1;
    if (tree != NULL)
    {
        do{
            while (p != NULL)
            {
                stack[++top] = p;
                p = p->lchild;
            }
            p = stack[top--];
            printf("%c- ", p->data);
            p = p->rchild;
        } while (p != NULL || top != -1);
    }
}

void afterorder(Btree *tree){
    // printf("后序-递归\n");
    if (tree != NULL)
    {
        afterorder(tree->lchild);
        afterorder(tree->rchild);
        printf("%c, ", tree->data);
    }
}

void afterOrderStack(Btree *tree){
    // printf("后序-堆栈\n");
    Btree *stack1[10], *p=tree;
    int stack2[10], flag, top = -1;
    if(tree != NULL){
        do{
            while (p != NULL)
            {
                stack1[++top] = p;
                stack2[top] = 0;
                p = p->lchild;
            }
            p = stack1[top];
            flag = stack2[top--];
            if(flag == 0){
                stack1[++top] = p;
                stack2[top] = 1;
                p = p->rchild;
            }else{
                printf("%c- ", p->data);
                p = NULL;
            }
        } while(p != NULL || top != -1);
    }
}



int main(int argc, char const *argv[])
{
    char *str = "A(B(D,E(G)),C(F(,H)))@";
    Btree *t = strToBtree(str);
    // printf("deep=%d", deepth(t));
    
    preorder(t);
    printf("\n");
    preOrderStack(t);
    printf("\n");
    midorder(t);
    printf("\n");
    midOrderStack(t);
    printf("\n");
    afterorder(t);
    printf("\n");
    afterOrderStack(t);
    return 0;
}
