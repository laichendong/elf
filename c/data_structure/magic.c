#define MaxN 20
void magic(int map[5][5], int n){
    // initial map
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            map[i][j] = 0;
        }
    }

    // 开始填数
    int c = 1;
    int i = 0; 
    int j = n/2;
    while (c <= n*n)
    {
        if(i < 0  && j<0 || map[i][j] != 0){
            i = i+2;
            j = j+1;
        }
        map[i--][j--] = c++;
        if(i<0 && j>=0){
            i = n-1;
        }
        if(j<0 && i>=0){
            j = n-1;
        }
       
    }
    
    // 打印
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf(" %4d", map[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int map[5][5] ;
    magic(map, 5);
    return 0;
}
