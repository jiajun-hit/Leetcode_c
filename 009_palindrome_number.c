#include <stdio.h>

typedef int bool;

bool isPalindrome(int x) {
    int nums[20];
    int i = 0, j;
    
    if (x < 0) {
        return 0;
    } else if (x == 0) {
        return 1;
    }
    
    while (x) {
        nums[i] = x % 10;
        x /= 10;
        i++;
    }
    
    i = i - 1;
    
    for (j = 0; j <= i / 2; j++) {
        if (nums[j] != nums[i-j]) {
            return 0;
        }
    }
    
    return 1;
}


int main() {
    int x;

    scanf("%d", &x);

    printf("%d", isPalindrome(x));

    return 0;
}
