#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *pHead; // 存储list的数组的指针
    int cap;    // capacity of array list
    int count;  // number of items in the array
} ArrayList;

void print(ArrayList *list)
{
    printf("cap:%d, count:%d, ", list->cap, list->count);
    printf("content:{");
    for (int i = 0; i < list->count; i++)
    {
        printf(&", %d"[2*!i], list -> pHead[i]);
        // printf("%d", list -> pHead[i]);
    }
    printf("}\n");
}

/**
 * 初始化一个长度为cap的list
 */
void init(ArrayList *list, int cap)
{
    list->pHead = (int *)malloc(sizeof(int) * cap);
    if (NULL == list->pHead)
    {
        printf("free error 动态内存分配失败！\n");
        exit(-1); //终止整个程序
    }
    else
    {
        list->count = 0;
        list->cap = cap;
        printf("free  动态内存分配成功！\n");
    }
    return;
}

/**
 * test the list is empty, if empty, return 0, else return 1
 */
int is_empty(ArrayList *list)
{
    return list->count > 0;
}

/**
 * return the number of items in arrayList
 */
int size_of(ArrayList *list)
{
    return list->count;
}

/**
 * 返回第i个元素   i从1开始
 */
int get(ArrayList *list, int i, int *ret)
{
    if (i < 0 || i > list->count)
    {
        return -1;
    }
    *ret = list->pHead[i - 1];
    return 0;
}

/**
 * 查找n在线性表里第一次出现的位置  , 位置从1开始计数
 */
int index_of(ArrayList *list, int n)
{
    for (int i = 0; i < list->count; i++)
    {
        if (n == list->pHead[i])
        {
            return i + 1;
        }
    }
    return -1;
}

/**
 * 在第i个位置插入n   i从1开始计数
 */
int insert(ArrayList *list, int i, int n)
{
    // 插入位置无效
    if (i < 1 || i > list->count + 1)
    {
        return -1;
    }
    // 超过容量
    if (i > list->cap)
    {
        return -1;
    }
    // i 往后的元素都后移一格
    for (int j = list->count; j >= i; j--)
    {
        list->pHead[j] = list->pHead[j - 1];
    }
    list->pHead[i - 1] = n;
    list->count = list->count + 1;
    return 0;
}

/**
 * 第i个位置的值设置为n  i从1开始
 */
int set(ArrayList *list, int i, int n)
{
    if (i < 1 || i > list->count)
    {
        return -1;
    }
    list->pHead[i - 1] = n;
    return 0;
}

/**
 * 删除第i个位置的元素， i从1开始
 */
int delete (ArrayList *list, int i)
{
    if (i < 1 || i > list->count)
    {
        return -1;
    }
    for (int j = i - 1; j < list->count; j++)
    {
        list->pHead[j] = list->pHead[j + 1];
    }
    list->count = list->count - 1;
    return 0;
}

/**
 * 删除重复元素         
 */
int distinct(ArrayList *list)
{
    if (list->count <= 1)
    {
        return 0;
    }
    for (int i = 0; i <= list->count - 1; i++)
    {
        int d[list->count]; // 记录重复元素的位置
        int k = 0;
        for (int j = i + 1; j <= list->count; j++)
        {
            if (list->pHead[i] == list->pHead[j])
            {
                d[k++] = j;
            }
        }
        for (int q = k - 1; q >= 0; q--)
        {
            delete (list, d[q] + 1);
        }
    }
    return 0;
}

int main()
{
    // ArrayList list;
    // init(&list, 6);
    // insert(&list, 1, 4);
    // insert(&list, 1, 6);
    // insert(&list, 1, 6);
    // insert(&list, 1, 8);
    // insert(&list, 1, 8);
    // insert(&list, 1, 8);
    // print(&list);
    // distinct(&list);
    // print(&list); 
    // int i = 1;
    // printf("%d", !i);
    char s[] = "1234";
    printf("%s, %p",&s[2], &s);
}