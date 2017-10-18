#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = (digits[digitsSize-1] + 1) / 10;
    int num;

    digits[digitsSize-1] = (digits[digitsSize-1] + 1) % 10;

    for (int i = digitsSize-2; i >= 0; i--) {
        num = carry + digits[i];
        carry = num / 10;
        digits[i] = num % 10;
    }

    if (carry != 0) {
        *returnSize = digitsSize + 1;
        for (int i = digitsSize; i > 0; i--) {
            digits[i] = digits[i-1];
        }
        digits[0] = carry;
    } else {
        *returnSize = digitsSize;
    }

    return digits;
}

int main() {
    int nums[100];
    int* digits = nums;
    int length = 0;
    int *size = &length;

    digits[0] = 9;
    digits[1] = 9;
    digits[2] = 9;
    digits = plusOne(digits, 3, size);

    for (int i = 0; i < length; i++) {
        printf("%d", digits[i]);
    }

    printf("\n");

    return 0;
}
