#include <stdio.h>
#define MAXLINE 1000

int getline_(char line[], int maxline);

/**
 * 编写一个程序， 删除每个输入行末尾的空格及制表符，并删除完成是空格的行
*/
int main(){
    int len;
    char line[MAXLINE];

    while ((len = getline_(line, MAXLINE)) > 0)
    {
        int i;
        for(i = len-2; i>=0 && (line[i] == '\t' || line[i]==' '); i--){
            ;
        }
        if (i >= 0){ // 删完之后不是空行
            line[i+1] = '\n';
            line[i+2] = '\0';
            printf("%s", line);
        }
        
        
    }

    return 0;
}

int getline_(char s[], int lim){
    int c, i;
    
    for(i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
