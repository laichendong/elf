#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int search(int* nums, int numsSize, int target){
    int mid;
    int s = 0;
    int e = numsSize-1;
    while(s<=e){ // s==e 的情况也要继续，结果可能就是s
        mid = s + (e-s)/2; // mid的表达式记得+s
        printf("s=%d,e=%d,mid=%d,v=%d", s, e, mid, nums[mid]);
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid] < target){
            s = mid+1; // mid 已经被判断过了，从mid+1开始
        } else {
            e = mid-1; // mid已经被判断过了， 从mid-1开始
        }
    }
    return -1;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){
   (*returnSize) = 0;
    int* ans = malloc(sizeof(int) * numsSize);
    // 找到正负数的分界点
    int pos = -1;
    for (int i = 0; i < numsSize; i++){
        if(nums[i]<0){
            pos = i;
        }else{
            break;
        }
    }
     printf("%d, \n", pos);
    
    int i = pos;
    int j = pos+1;
    while(i>=0 || j<=numsSize-1){
        if(i<0){ // i 已经走到头， j++就好
            ans[(*returnSize)++] = nums[j] * nums[j];
            j++;
        }else if(j == numsSize){ // j已经到头 i--就好
            ans[(*returnSize)++] = nums[i] * nums[i];
            i--;
        } else if(nums[i] * nums[i] <= nums[j] * nums[j]){ // 都没走到头，谁小谁放前面
            ans[(*returnSize)++] = nums[i] * nums[i];
            i--;
        } else{
            ans[(*returnSize)++] = nums[j] * nums[j];
            j++;
        }
    }
    
    return ans;
}

void rotate(int* nums, int numsSize, int k){
    int kk = k % numsSize;
    int* temp = malloc(sizeof(int) * kk);
    for(int i = 0; i<kk; i++){
        temp[kk-i-1] = nums[numsSize - i - 1];
    }

    for(int j=numsSize-kk-1; j>=0; j--){
        nums[j+kk] = nums[j];
    }

    for(int m=0; m<kk; m++){
        nums[m] = temp[m];
    }
    
}
void moveZeroes(int* nums, int numsSize){
    int zero_n=0;
    int* zero_pos = malloc(sizeof(int) * numsSize);
    // 遍历一遍数组，把每一个非零数字前面有几个0给数出来
    for(int i=0; i<numsSize; i++){
        if(nums[i] == 0){
            zero_n++;
        } else {
            zero_pos[i] = zero_n;
        }
    }

    // for(int i =0; i< numsSize; i++){
    //     printf("%d, ----", zero_pos[i]);
    // }

    // 再遍历一遍数组，把非零元素往前移动“前面有0的个数”个位置
    for(int j=0; j<numsSize; j++){
        if(nums[j] != 0){
            nums[j-zero_pos[j]] = nums[j];
        }
    }

    // 最后用0补全数组
    for(int k = zero_n; k>0; k--){
        nums[numsSize-k] = 0;
    }

}
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* ans = malloc(sizeof(int) * 2);
    for(int i=0; i<numbersSize-1; i++){
        for(int j = i+1; j<numbersSize; j++){
            int sum = numbers[i] + numbers[j];
            if(sum < target){
                continue;
            }else if(sum == target){
                ans[0] = ++i;
                ans[1] = ++j;
                return ans;
            }
        }
    }
    return ans;
}

struct Circle
{
    char name[10];
    int r;   
    struct P
    {
        int x;
        int y;
        char cc[];
    } pt;
};

int is_yeap(int y){
    if((y%4==0 && y%100==0) || y%400==0){
        return 1;
    }else{
        return 0;
    }
}
int get_weekday(int y, int m, int d){
    int days1[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平年每月有多少天
    int days2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰年每月有多少天
    int day_to_today = 0; // 今天到公元一共经历了多少天
    for(int i = 1; i<=y; i++){
        for (int j = 0; j < 12; j++)
        {
            if(is_yeap(i)){
                day_to_today += days1[j];
            }else{
                day_to_today += days2[j];
            }
        }
    }
    for (int k = 0; k < m-1; k++)
    {
        if (is_yeap(y))
        {
            day_to_today +=  days1[k];
        }else{
            day_to_today += days2[k];
        }    
    }
    day_to_today += d;

    return day_to_today%7;
}

/**
 * @brief 将单词转成小写
 * 
 * @param word 
 * @return char* 
 */
char* to_low_case(char word[]){
    int i=0;
    char c;
    char* newWord = malloc(sizeof(char));
    while ( (c = word[i]) != '\0')
    {
        newWord[i++] = tolower(c);        
    }
    return newWord;
}

int is_cword(char* src, char* target){
    // 字符串相等  不是变位词
    if(strcmp(src, target)  == 0){
        return 0;
    }
    // 获得两个字符串长度
    int i = 0, j=0;
    while (src[i++] != '\0');
    while (target[j++] != '\0');
    //  长度不等 不是变位词
    if(i != j){
        return 0;
    }
    // 将两个单词字母排序，如果排序后
    
   
    
}

void change_words(char* w, char* f_name){
    char content[100][21];
    char target[100][21];
    char* readBuff = malloc(sizeof(char) * 21);
    // 把文件内容读入content数组
    int i = 0;
    FILE *fp ;
    if((fp = fopen(f_name, "r")) == NULL){
        printf("文件打开失败");
        exit(1);
    }
    
    while (fscanf(fp, "%s", readBuff) != EOF)
    {
        // printf("%s ", to_low_case(readBuff));
        strcpy(content[i++], to_low_case(readBuff));
    }
    fclose(fp);

    // 打印content
    for(int j = 0; j < i; j++){
        printf("%s ", content[j]);
    }

    // 依次判断 是不是变位词, 把变位词存下来
    int targetc = 0;
    for(int j = 0; j < i; j++){
        if(is_cword(w, content[j])){
            strcpy(target[targetc++], content[j]);
        }
    }



}

int main(int argc, char* argv[]){
    char *word;
    char *fname;
    word = "abc";
    fname = "change.txt";
    // 把单词写进文件
    // FILE *fp;
    // if((fp = fopen(fname, "w+")) == NULL){
    //     exit(1);
    // }
    // for(int i = 0; i<100; i++){
    //     for(int j=0; j<rand()%20; j++){
    //         fputc(rand()%26 + 'a', fp);
    //     }
    //     fputc(' ', fp);
    // }
    // fclose(fp);

    change_words(word, fname);

    // if(argc != 3) {
    //     printf("请输入单词和文件名");
    //     return -1;
    // }else{
    //     char* word = argv[1];
    //     char* file = argv[2];
    //     change_words(word, file);
    // }
    // printf("%s",to_low_case("Lsdf"));
    // char c = tolower('A');
    // printf("%c", c);
}