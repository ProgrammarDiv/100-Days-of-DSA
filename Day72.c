#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[100005]; // Adjust size based on constraints
    if (scanf("%s", s) != 1) return 0;

    // Boolean array to keep track of characters seen (ASCII size)
    bool seen[256] = {false};
    char result = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        int val = (int)s[i];

        // If character has been seen before, it's our first repeated character
        if (seen[val]) {
            result = s[i];
            break;
        }

        // Mark this character as seen
        seen[val] = true;
    }

    // Output the result
    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}