#include <stdio.h>

#define TABINC 8

/**
 * 编写程序detab， 将输入中的制表符换成适当数目的空格， 使空格充满到下一个制表符终止位的地方.
 * 按一下Tab键或者8列后 就跳到下一个“单元格”开始输入
*/
main()
{
    int c, nb, pos;
    nb = 0;
    pos = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0)
            {
                putchar(' ');
                ++pos;
                --nb;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }
}
