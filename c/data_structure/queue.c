#include <stdio.h>
#define MAX 5
typedef struct queue
{
    int container[MAX];
    int front;
    int rear ;
} Queue;

void init(Queue *q){
    q->rear = -1;
    q->front = -1;
}

int isEmpty(Queue *q){
    return q->rear == q->front;
}


int get(Queue *q, int *item){
    if (isEmpty(q))
    {
        return -1;
    }
    *item = (q->container)[q->front];
    return 0;
}

int add(Queue *q, int item){
    q->rear = (q->rear+1) % MAX;
    if(q->rear == q->front){
        printf("满队列不允许再插入\n");
        return -1;
    }
    
    (q->container)[++q->rear] = item;
    return 0;
}

int del(Queue *q){
    if (isEmpty(q)){
        printf("空队列不能再删除元素\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX;
    return 0;
}

void print(Queue *q){
    printf("[");
    for (int i = 0; i <= q->rear; i++)
    {
        printf(&", %d"[2*!i], (q->container)[i]);
    }
    printf("]\n");
    
}

int main(int argc, char const *argv[])
{
    Queue q;
    init(&q);
    print(&q);
    add(&q, 1);
    add(&q, 2);
    add(&q, 3);
    print(&q);
    del(&q);
    print(&q);
    int k ;
    get(&q, &k);
    printf("%d", k);
    return 0;
}

