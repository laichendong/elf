#include <stdio.h>
void expand(char s1[], char s2[]);

int main(){
    char s1[] = "-a-d";
    char s2[100];
    expand(s1, s2);
    printf("%s", s2);

    // for(char k = 'a'; k <= 'r'; k++){
    //             printf("%c", k);
    //         }
}


void expand(char s1[], char s2[]){
    char c, s, e;
    int i, j;
    for (i = 0, j=0; (c = s1[i]) != '\0'; i++){
        if(c == '-'){
            s = s1[i-1];
            e = s1[i+1];
            for(char k = s; k <= e; k++){
                s2[j++] = k;
            }
        }else{
            s2[j++] = c;
        }
    }
    s2[j] =  '\0';
}


// 去掉私域词的流量分布情况    -- 用户用脚投票的结果被排除在外了
// 搜索的分析方向是 “微观层面 高层级的 获得的流量 小于 下一层级 的流量”  =》没有爆品？
// 平台希望让L2-L3的流量整体变多吗？  --分层和流量（搜索）结合的目标是什么呢？
// 有机会的告诉他，浪费了流量的告诉他
/**
 * 分层的价值主张： 什么情况会被加速成长， 什么情况会加速衰退
 * 比如说新品，符合需求趋势的新品会加速，  只是换包装的新品不会被加速
*/
