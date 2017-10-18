#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int length = 1;

    if (numsSize == 0) {
        return 0;
    }

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            nums[length] = nums[i];
            length++;
        }
    }

    return length;
}

int main() {
    int nums[] = {1, 1, 2};
    int length;

    length = removeDuplicates(nums, 3);

    printf("%d\n", length);

    return 0;
}
