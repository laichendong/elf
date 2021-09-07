#include <stdio.h>
#include <ctype.h>


void r(int num){
    if (num == 0) return;
    else printf("%d", num);
    // int k = num-1;
    r(--num);
}
int main(int argc, char *argv[]){
    // char s1[] = "abc";
    // char s2[] = "abc";
    // if(s1==s2) printf("y");
    // else printf("n");
    // return 0;
    // printf("%c", *++argv[0]);
    r(3);
}

