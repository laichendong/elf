
/**
 * 将一个稀疏数组压缩成 3元组表示的数组。
 * 简化问题，将数组维数和非0元素个数都由函数传入
 * m 行  n列， t个非零元素
 */
int * zip(int *from, int m, int n, int t){
    int to[t+1][3];
    to[0][0] = m;
    to[0][1] = n;
    to[0][2] = t;
    int tr = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int c = *(from + (i*n) + j);
            if(c != 0){
                to[tr][0] = i;
                to[tr][1] = j;
                to[tr][2] = c;
                tr++;
            }
        }
    }
    return to;
}

void print(int *arr, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf(" %4d", *(arr + (i*n) + j));
        }
        printf("\n");
    }
}

int main(){
    int arr[3][3] = {
        {1,0,0},
        {0,0,6},
        {7,0,0}
    };
    print(arr, 3, 3);
    // zip(arr, 3, 3, 3);
    int z[4][3];
    z = zip(arr, 3, 3, 3);
    print(z, 4, 3);
}