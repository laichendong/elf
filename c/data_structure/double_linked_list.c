#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dNode 
{
    char data;
    struct dNode *next, *pre;
}DLinkedList, *DNode;

void print(DLinkedList *list){
    printf("{");
    if(list != NULL){
        DLinkedList *p = list;
        while(p != NULL){
            printf("%c ", p->data);
            p = p->next;
        }
    }
    printf("}\n");
}

DNode fromString(char *str){
    DLinkedList *list, *tail;
    for(int i =0; i<strlen(str); i++){
        DNode node = (DNode) malloc(sizeof(DLinkedList));
        node->data = str[i];
        node->pre = NULL;
        node->next = NULL;
        if (list == NULL)
        {
            list = node;
            tail = list;
        }else{
            tail->next = node;
            node->pre = tail;
            tail = tail->next;
        }
    }
    return list;
}

int main(){
    DLinkedList *list = fromString("abc");
    print(list);
    return 0;
}