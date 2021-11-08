#include <stdio.h>
#include <string.h>

typedef struct node
{
    int flag;
    union {
        int data;
        struct node *pointer;
    };
    struct node *link;
} BSNode;

int len(BSNode *bs){
    int n = 0;
    BSNode *node = bs;
    while (node != NULL)
    {
        n++;
        node = node->link;
    }
    return n;
}

int lenRecursion(BSNode *bs){
    if(bs != NULL){
        return lenRecursion(bs->link) + 1;
    }
    return 0;
}

int deep(BSNode *bs){
    int maxDeep = 1;
    BSNode *p = bs;
    while (p != NULL)
    {
        if(p->flag){
            
        }
    }
    return maxDeep;
}