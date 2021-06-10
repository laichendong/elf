#include <stdio.h>
#define MAXLINE 1000
#define SWITCH 80

int getline_(char line[], int maxline);

/**
 * 编写一个程序， 打印长度大于80 个字符的所有输入行
*/
int main(){
    int len;
    char line[MAXLINE];

    while ((len = getline_(line, MAXLINE)) > 0)
    {
        if (len > SWITCH) {
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
