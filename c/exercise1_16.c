#include <stdio.h>
#define MAXLINE 1000

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

/**
 * 修改打印最长文本行的程序的主程序Main， 使之可打印任意长度的输入的长度， 并尽可能多地打印文本
 */
int main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline_(line, MAXLINE)) > 0)
    {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0){
        printf("maxLength=%d\n", max);
        printf("%s", longest);
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

void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
    
}
