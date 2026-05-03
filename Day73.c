#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;

    int count[26] = {0}; // Frequency array for 'a'-'z'
    int n = strlen(s);

    // First Pass: Count occurrences of each character
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    char result = '$';

    // Second Pass: Find the first character with count 1
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            result = s[i];
            break;
        }
    }

    printf("%c\n", result);

    return 0;
}