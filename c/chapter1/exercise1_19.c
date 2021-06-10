#include <stdio.h>
#define LIMIT 1000

int getLine(char s[], int lim);
void reverse(char s[]);

/**
 * 编写函数reverse(s) 将字符串s中的字符顺序颠倒过来，使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。
*/
int main()
{
    char line[LIMIT];
    int length;
    while ((length = getLine(line, LIMIT)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++)
    {
        s[i] = c;
        if (c == '\n')
        {
            break; // 只获取一行
        }
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[])
{
    int i = 0;
    int j = 0;
    char c;
    while (s[j] != '\0')
    {
        j++;
    }
    j--;

    while (i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
}