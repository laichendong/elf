#include <stdio.h>

// 求 1-二分之一+三分之一-四分之一  一直到100分之1
int main(){
    float sum =0;
    for(float i = 1; i<=100; i++){
        if((int)i%2==0){
            sum -= (1/i);
        }else{
            sum += (1/i);
        }
    }
    printf("结果是:%5.10f", sum);
}