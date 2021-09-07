#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}LinkedList, *Node;

void printItem(LinkedList *node){
    printf("%d", node->data);
    if (node->next != NULL)
    {
        printf(" -> ");
        printItem(node->next);
    }
}

void print(LinkedList *list){
    

    printf("{");
    if(list != NULL){
        printItem(list);
    }
    printf("}\n");
}

Node creat(int n){
    Node head = (Node) malloc(sizeof(LinkedList));
    head->data = n;
    head->next = NULL;
    return head;
}

void append(LinkedList *list, int n){
    LinkedList *node = creat(n);
    if(list == NULL){
        list = node;
        return;
    }
    LinkedList *last  = list;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = node;
}

int length(LinkedList *list){
    int l = 0;
    LinkedList *p = list;
    while (p != NULL)
    {
        l = l+1;
        p = p->next;
    }
    return l;
    
}

/**
 * 向list的第pos位置插入item节点， pos从1开始计数
 */
int insert(LinkedList **list, int pos, int item){
    int l = length(*list);
    if (pos < 1 || pos > l+1)
    {
        return -1;
    }

    int cpos = 0;
    LinkedList *cnode = *list;
    LinkedList *pnode = NULL;
    while (++cpos < pos)
    {
        pnode = cnode;
        cnode = cnode->next;
    
    }
    
    LinkedList *n = creat(item);
    n->next = cnode;
    if (pnode != NULL)
    {
        pnode->next = n;
    }else{
        *list = n;
    }
    
    return pos;
}

void delete(LinkedList **list, int item){
    LinkedList *p = NULL;
    LinkedList *c = *list;
    while (c != NULL)
    {
        if (c->data == item)
        {
            if(p != NULL){
                p->next = c->next;
            }else{
                *list = c->next;
            }
            free(c);
        }
        p = c;
        c = c->next;
    }
    
}

/**
 * 反转链表
 * 三个指针，从 -2， -1， 0的位置逐格后移，在后移的过程中调整指针指向，达到反转目的
 */
void revert(LinkedList **list){
    LinkedList *p, *q, *r;
    p =  *list;
    q = NULL;
    r = NULL;
    
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;

    }
    *list = q;
    
}

/**
 * 线性表本身按从小到大排序， 插入一个新元素，不破坏排序规则
 */
void sortedInsert(LinkedList **list, int item){
    LinkedList *node = creat(item);
    if(*list == NULL){
        *list = node;
        return;
    }
    LinkedList *i = NULL;
    LinkedList *j = *list;
    while (j != NULL)
    {
        if(j->data >= item){ // 找到第一比item大的元素，item在他之前插入
            node->next = j;
            if(i == NULL){
                *list = node;
            } else{
                i->next = node;
            }
            break;
        }else{
            i = j;
            if(j->next != NULL){
                j = j->next; // 后面还有元素，往后走
            }else{
                j->next = node;  // 已经到最后一个元素了， 把node挂到最后，并结束循环
                break;
            }
        }
    }
    
}

/**
 * 利用sortedInsert方法，排序，
 * 时间复杂度  O(n^2)
 */
void sort(LinkedList **list){
    LinkedList *newList = NULL;
    for (LinkedList *p = *list; p != NULL; p = p->next)
    {
        sortedInsert(&newList, p->data);
    }
    *list = newList;
}


void joseph_remove(LinkedList *pointer, int m){
    if (pointer != pointer->next)
    {
        // 开始报数, 报到m-1个时，删除后面那个节点
        // printf("从%d开始数，数%d个,", pointer->data, m-1);
        for (int i = 1; i < m-1; i++)
        {
            pointer = pointer->next;
        }
        // printf("数到了%d,", pointer->data);
        printf("%d出列\n", pointer->next->data);
        pointer->next = pointer->next->next;
        joseph_remove(pointer->next, m);
    } else {
        // 只有一个在环里了
        printf("%d出列\n", pointer->next->data);
        return;
    }
    
}
/**
 * 约瑟夫环问题，n个人围成一圈， 从第k个人开始报数，报到m的人出列，求出列顺序
 */
void joseph(int n, int m, int k){
    // make ring
    LinkedList *ring = NULL;
    LinkedList *pre = NULL;
    
    for(int i = 1; i<=n; i++){
        LinkedList *node = creat(i);
        if (ring == NULL)
        {
            ring = node;
            pre = ring;
        }
        pre->next = node;
        pre = node;
        if(i == n){
            node->next = ring;
        }
    }

    // 找到第k个人
    LinkedList *pointer = ring;
    for (int  i = 0; i < k-1; i++)
    {
        pointer = pointer->next;
    }
    // printf("数了k个，到达%d\n", pointer->data);
    joseph_remove(pointer, m);
    printf("");
}


int main(){
    joseph(8, 4, 3);
    // LinkedList *list = creat(3);
    // append(list, 4);
    // append(list, 9);
    // insert(&list, 4, 5);
    // insert(&list, 5, 0);
    // print(list);
    // // delete(&list, 3);
    // // delete(&list, 0);
    // // delete(&list, 9);
    // // delete(&list, 3);
    // // revert(&list);
    // // sortedInsert(&list, 6);
    // // sortedInsert(&list, 10);
    // // sortedInsert(&list, 1);
    // // sortedInsert(&list, 1);
    // sort(&list);
    // print(list);
    // // printf("%d", length(list));
}