#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
    int i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            break;
        }
    }

    return i;
}



int main() {
    int numsSize;
    int *nums;
    int target;

    scanf("%d", &numsSize);

    nums = (int *)malloc(sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &target);

    printf("%d\n", searchInsert(nums, numsSize, target));

    return 0;
}
