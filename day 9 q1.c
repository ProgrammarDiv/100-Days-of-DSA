#include <stdio.h>
#include 

int main() {
    char str[1000];
    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    
    printf("%s\n", str);
    return 0;
}
