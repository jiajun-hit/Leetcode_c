#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    if (target == nums[0]) {
        return 0;
    }

    int i;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }

        if (nums[i] < nums[i-1]) {
            if (target > nums[i-1]) {
                return -1;
            }

            break;
        }
    }

    for ( ; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }

        if (nums[i] > target) {
            return - 1;
        }
    }

    return -1;
}

int main() {

    return 0;
}
