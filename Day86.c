#include <stdio.h>

long long integerSquareRoot(long long n) {
    if (n < 2) return n;

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // Check if mid * mid is less than or equal to n
        // Using mid <= n / mid to avoid potential long long overflow
        if (mid <= n / mid) {
            ans = mid;     // mid could be the answer
            low = mid + 1; // look for a larger value in the right half
        } else {
            high = mid - 1; // mid is too large, look in the left half
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    if (n < 0) {
        // Square root of negative numbers is not defined in integers
        return 0;
    }

    printf("%lld\n", integerSquareRoot(n));

    return 0;
}