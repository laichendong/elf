#include <stdio.h>

#define MAX 2000

void validate(char *file_name);
int validate_line_1(char *line1, char *error_msg);
int validate_line_2(char *line2, int *line_len, char *error_msg);
int validate_line_3(char *line3, char *error_msg);
int validate_line_4(char *line4, char *error_msg);

int main(int argc, char *argv[]){
    if(argc == 2){
        char *file_name = argv[1];
        validate(file_name);
    }else{
        printf("参数个数不合法，请输入文件名。");
    }
}

void validate(char *file_name){
    FILE *f = fopen(file_name, 'r');
}

int validate_line_1(char *line1, char *error_msg){
    if("@" != line1[0]){
        error_msg = "非法文件：第一行不是以@开头";
        return -1;
    }
    return 0;
}

int validate_line_2(char *line2, int *line_len, char *error_msg){
    line_len = 0;
    for (int i=0; i<MAX; i++){
        if('A'!=line2[i] && 'T'!=line2[i] && 'G'!=line2[i] && 'C'!=line2[i] && 
        'a'!=line2[i] && 't'!=line2[i] && 'g'!=line2[i] && 'c'!=line2[i] ){
            error_msg = "非法文件：第二行出现不了不允许存在的字符";
            return -1;
        }
        line_len = i;
        return 0;
    }
}

int validate_line_3(char *line3, char *error_msg){}