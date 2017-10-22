#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int length = numsSize;
    int count = 0;
    int index;

    for (int i = 0; i < length; i++) {
        index = i;
        while (index < length && nums[index] == val) {
            count++;
            index++;
        }

        if (count) {
            length -= count;

            for (int j = i; j < length; j++) {
                nums[j] = nums[j+count];
            }

            count = 0;
        }
    }

    return length;
}

int main() {
    int nums[] = {4, 4, 4};
    int len;

    len = removeElement(nums, sizeof(nums)/sizeof(nums[0]), 4);

    for (int i = 0; i < len; i++) {
        printf("%d\n", nums[i]);
    }

    printf("len = %d\n", len);

    return 0;
}
