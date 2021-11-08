#include <stdio.h>
#include <string.h>

int freqs(char sourse[], char destination[]);

int main(){
    printf("%d\n", freqs("aaaa", "aa"));
    printf("%d\n", freqs("abcdefgdefkdxef", "def"));
}

int freqs(char sourse[], char destination[]){
    int i, j;
    int n = 0;
    i = j = 0;
    while (sourse[i] != '\0')
    {
        while (destination[j] != '\0' && sourse[i+j] != '\0')
        {
            if(sourse[i+j] != destination[j]){
                // 没找到,
                break;
            }
            j++;
        }
        if(destination[j] == '\0'){ // 找到了
            n++;
        }
        i++;
        j=0;
    }
    
    return n;
}