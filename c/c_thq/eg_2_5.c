#include <stdio.h>

// 判定一个大于等于3的数是否为素数
int main(){
    for(int i =3; i<=300; i++){
        int flag = 1;
        for(int j=2; j<i; j++){
            if(i%j == 0){
                // printf("%d不是素数\n", i);
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("%d是素数\n", i);
        }
    }
}