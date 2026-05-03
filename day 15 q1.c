#include <stdio.h>

int main() {
    int m, n;
    int mat[100][100];
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int sum = 0;
    int minDim = m < n ? m : n;
    
    for (int i = 0; i < minDim; i++) {
        sum += mat[i][i];
    }
    
    printf("%d\n", sum);
    return 0;
}
