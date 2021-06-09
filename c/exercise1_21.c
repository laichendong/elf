#include <stdio.h>

#define TABINC 8

/**
 * 编写程序entab， 将空格串替换成最少数量的制表符和空格，但要保持单词之间的间隔不变。
*/
int main(int argc, char const *argv[])
{
    char c;
    int pos, nt, nb;

    nb = 0;
    nt = 0;

    for (pos = 0; (c = getchar()) != EOF; pos++)
    {
        if (c == ' ')
        { // 是空格，计算要不要把空格变成tab

            if (pos % TABINC == 0)
            {
                nt++;
                nb = 0;
            }
            else
            {
                nb++;
            }
        }
        else
        {
            // 先输出可能存在的 空格，包括替换了的tab
            while (nt > 0)
            {
                putchar('|');
                nt--;
            }
            if (c == '\t')
            { // 如果是tab，则刚才的空格就不输出了，直接输出tab就好
                nb = 0;
                putchar('|');
            }
            else
            {
                while (nb > 0)
                {
                    putchar('-');
                    nb--;
                }
                putchar(c);
            }

            if (c == '\n')
            {
                pos = 0;
            }
            else if (c == '\t')
            { // 如果是tab，得重新计算pos
                pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
            }
        }
    }

    return 0;
}
