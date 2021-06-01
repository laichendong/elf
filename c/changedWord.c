#include <stdio.h>

int main(int argc, char *argv[] ){
    printf("%s   %s   %s", argv[0], argv[1], argv[2]);
    if (argc == 2) {
        printf("%s   %s", argv[0], argv[1]);
    }
}