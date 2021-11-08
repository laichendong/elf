#include <stdio.h>

int main(int argc, char const *argv[])
{   
    // char a = 'A';
    // printf("%d, %c", a, a+1);
    // for (int  i = 1; i < 128; i++)
    // {
    //     printf("%c=%d\n", i, i);
    // }
    
    // return 0;


    // int k=1;
    // int t = 3;
    // do{
    //     t+=k++;
    //     if(t%7==0){
    //         continue;
    //     }else{
    //         ++k;
    //     }

    // }while (t<15);
    // printf("%d", k);

    // struct date
    // {
    //     int y, m, d;
    // } today;
    // printf("%d\n", sizeof(struct date));
    // printf("%d\n", sizeof(today));
    // printf("%d\n", sizeof(int));
    
    FILE *in, *out;
    char *str1="YOU PLAN TO FAIL.";
    char *str2="IF YOU FAIL TO PLAN.";
    if((in=fopen("file1.txt","w")) != NULL){
        while (*str1 != '.')
        {
            fputc(*str1++, in);
        }
    }
    fclose(in);
    if(((in=fopen("file1.txt","r"))!=NULL) && ((out=fopen("file2.txt","w"))!=NULL)){
        while (fgetc(in)!=EOF)
        {
            ;
            fputc(*str2++, out);
        }
    }
    fclose(in);
    fclose(out);
}

