#include <stdio.h>

typedef struct node
{
    int data;
    Qnode *link;
} Qnode;

void init(Qnode *front, Qnode *rear){
    front = NULL;
    rear = NULL;
}

/**
 * add  加到队尾
 */
void add(Qnode *front, Qnode *rear, int item){
    Qnode node;
    node.data = item;
    node.link = NULL;

    if(isEmpty(front, rear)){
        front = &node;
    }else{
        rear->link = &node;
    }
    rear = &node;
     
}

void del(Qnode *front, Qnode *rear, int *item){
    if (isEmpty(front, rear))
    {
        printf("队列为空，不允许再删除");
    }else{
        Qnode *node = front;
        item = node->data;
        front = node->link;
        free(node);
    }
}

int isEmpty(Qnode *front, Qnode *rear){
    return front == NULL;
}

