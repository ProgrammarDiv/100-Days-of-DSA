#include <stdio.h>

int main() {
    int m, n;
    int mat1[100][100], mat2[100][100], result[100][100];
    
    scanf("%d %d", &m, &n);
    
    // Read first matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    // Read second matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    // Add matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    
    // Print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", result[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
