#include <stdio.h>
/** 
 * 利用堆栈，将10进制转成8进制
 */
// void convert(int n){
//     int stack[10];
//     int i = 0;
//     do{
//         stack[i++] = n%8; // 取余
//         n = n/8; // 商
//     }while (n!=0);
    
//     while (i>0)
//     {
//         printf("%d", stack[--i]);
//     }
// }

typedef struct stack
{
    int container[10];
    int len;
} Stack;

void print(Stack *stack){
    printf("[");
    for (int i = 0; i < stack->len; i++)
    {
        printf(&", %d"[2*!i], (stack->container)[i]);
    }
    printf("]\n");
}

void push(Stack *stack, int item){
    for(int i=stack->len; i>0; i--)
    {
        stack->container[i] = stack->container[i-1];
    }
    stack->container[0] = item;
    stack->len+=1;
}

int pop(Stack *stack){
    int item = stack->container[0];
    for (int i = 0; i < stack->len-1; i++)
    {
        stack->container[i] = stack->container[i+1];
    }
    stack->len -= 1;
    return item;
}

int walk(int i, int n){
    if(i == 1){
        n = 1;
    }
    if(i == 2) {
        n=2;
    }
    if(i>2){
        n = n * walk(i-1, n);
    }
    return n;
}

int main(int argc, char const *argv[])
{
    Stack s ;
    s.len = 0;
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    print(&s);

    Stack t;
    t.len=0;
    printf("%d", walk(3,1));
    
    
    return 0;
}
