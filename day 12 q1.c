#include <stdio.h>
#include 

int main() {
    int m, n;
    int mat[100][100];
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    bool isSymmetric = true;
    
    
    if (m != n) {
        isSymmetric = false;
    } else {
       
        for (int i = 0; i < m && isSymmetric; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[j][i]) {
                    isSymmetric = false;
                    break;
                }
            }
        }
    }
    
    printf("%s\n", isSymmetric ? "Symmetric Matrix" : "Not a Symmetric Matrix");
    return 0;
}
