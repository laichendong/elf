#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char s[] = "addsdfsd\tfsdf\nsdf ff  ";
    char t[30];
    printf("1--%s\n", s);
    escape(s, t);
    printf("2--%s\n", t);
    unescape(t, s);
    printf("3--%s\n", s);
}

void escape(char s[], char t[])
{
    char c;
    int i;
    int j = 0;
    for (i = 0; (c = s[i]) != '\0'; ++i)
    {
        switch (c)
        {
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        default:
            t[j++] = c;
            break;
        }
    }
    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    char c;
    int i;
    int j = 0;
    int f = 0; // 标识是不是进入转义字符，即上一个字符是否为'\'
    for (i = 0; (c = s[i]) != '\0'; ++i)
    {
        // printf("%c",c);
        switch (c)
        {
        case '\\':
            f = 1;
            break;
        case 't':
            t[j++] = f ? '\t' : 't';
            f=0;
            break;
        case 'n':
            t[j++] = f ? '\n' : 'n';
            f=0;
            break;
        default:
            if (f)
            { // 如果前面是‘\’ 但后面不是转义的字符，要把杠补回来
                t[j++] = '\\';
                f=0;
            }
            t[j++] = c;
            break;
        }
    }
    t[j] = '\0';
}
