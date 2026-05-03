#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    int mat[100][100];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    bool isIdentity = true;
    
    for (int i = 0; i < n && isIdentity; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (mat[i][j] != 1) {
                    isIdentity = false;
                    break;
                }
            } else {
                if (mat[i][j] != 0) {
                    isIdentity = false;
                    break;
                }
            }
        }
    }
    
    printf("%s\n", isIdentity ? "Identity Matrix" : "Not an Identity Matrix");
    return 0;
}
