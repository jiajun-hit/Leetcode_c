#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    int** results = NULL;

    for (int i = 0; i < numsSize-2; i++) {
        for (int j = i + 1; j < numsSize-1; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    (*returnSize)++;
                    results = (int**)realloc(results, (*returnSize) * sizeof(int));
                    results[*returnSize - 1] = (int *)malloc(3 * sizeof(int));

                    results[*returnSize - 1][0] = nums[i];
                    results[*returnSize - 1][1] = nums[j];
                    results[*returnSize - 1][2] = nums[k];
                }
            }
        }
    }

    return results;
}

int main() {
    int resultSize = 0;
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int **results;

    results = threeSum(nums, sizeof(nums)/sizeof(nums[0]), &resultSize);

    for (int i = 0 ; i < resultSize; i++) {
        printf("%d, %d, %d\n", results[i][0], results[i][1], results[i][2]);
    }

    return 0;
}
