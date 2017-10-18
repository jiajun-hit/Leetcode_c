#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int length;
    int i, j;
    int *a = (int *)malloc(2 * sizeof(int));

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1;  j < numsSize; j++) {

            if (*(nums + i) + *(nums +j) == target) {
                a[0] = i;
                a[1] = j;

                return a;
            }
        }
    }

    return a;
}

int main() {
    int nums[] = {3, 2, 4};
    int target = 6;
    int *a;

    a = twoSum(nums, 3, 6);

    printf("%d %d\n", a[0], a[1]);

    return 0;
}
