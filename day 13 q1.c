#include <stdio.h>

int main() {
    int r, c;
    int mat[100][100];
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    
    while (top <= bottom && left <= right) {
     
        for (int j = left; j <= right; j++) {
            printf("%d ", mat[top][j]);
        }
        top++;
        
      
        for (int i = top; i <= bottom; i++) {
            printf("%d ", mat[i][right]);
        }
        right--;
        
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%d ", mat[bottom][j]);
            }
            bottom--;
        }
        
    
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", mat[i][left]);
            }
            left++;
        }
    }
    
    printf("\n");
    return 0;
}
