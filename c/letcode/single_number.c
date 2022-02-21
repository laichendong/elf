// https://leetcode-cn.com/problems/single-number/
#include <stdio.h>
#include <stdlib.h>


int cmp(const void * a, const void * b){
    return(*(int *)a - *(int *)b);
}

int singleNumber(int * nums, int numsSize){
    int target;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i=0, j=1; i<numsSize; i+=2, j+=2){
        if((i == numsSize-1) || (nums[i] != nums[j])){
            target = nums[i];
            break;
        }
    }
    return target;
}


int main(){
    int nums[5] = {4,7,2,7,2};
    printf("the single num is:%d\n", singleNumber(nums, 5));
}