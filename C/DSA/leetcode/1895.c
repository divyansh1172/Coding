int checkMagic(int m, int n, int **a, int pre_x[m][n],int pre_y[m][n], int i, int j, int k){
    if(i+k > m || j+k > n) return 0;
    int r = j + k - 1;
    int b = i + k - 1;
    int req = pre_x[i][r] - (j > 0 ? pre_x[i][j - 1] : 0);
    // check row sum
    for (int x = i; x <= b; x++) {
        int s = pre_x[x][r] - (j > 0 ? pre_x[x][j - 1] : 0);
        if (s != req) return 0;
    }
    // check cols
    for (int y = j; y <= r; y++) {
        int s = pre_y[b][y] - (i > 0 ? pre_y[i - 1][y] : 0);
        if (s != req) return 0;
    }
    // check diagonal from top left to bottom right
    int sum=0;
    for(int x=0;x<k;x++){
        sum += a[i+x][j+x]; 
    }
    if(req!=sum) return 0;

    sum = 0;
    for (int x = 0; x < k; x++)
        sum += a[i + x][j + (k - 1 - x)];
    if (sum != req) return 0;
    return 1;
}
int largestMagicSquare(int** a, int m, int* n) {
    int min = (m>*n) ? *n : m;
    int pre_x[m][*n], pre_y[m][*n];
    // setting the first elems
    for(int i=0;i<m;i++){
        pre_x[i][0]=a[i][0];
    }
    for(int i=0; i<*n;i++){
        pre_y[0][i]=a[0][i];
    }

    // calculating the prefix Sum matrices
    for(int i=0;i<m;i++){
        for(int j=1;j<*n ; j++){
            pre_x[i][j] = pre_x[i][j-1] + a[i][j];
        }
    }
    for(int j=0;j< *n; j++){
        for(int i=1; i<m;i++){
            pre_y[i][j] = pre_y[i-1][j] + a[i][j];
        }
    }

    for(int k=min;k>=1;k--){
        for(int i=0;i<=m-k;i++){
            for(int j=0; j<=*n-k;j++){
                if(checkMagic(m,*n, a, pre_x, pre_y, i,j,k)) return k;
            }
        }
    }
    return 1;
}