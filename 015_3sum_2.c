#include <stdio.h>
#include <stdlib.h>

void quickSort(int* nums, int begin, int end) {
    int i = begin;
    int j = end;
    int temp;

    int mid = nums[(begin + end) / 2];

    while (i <= j){
        while (nums[i] < mid) {
            i++;
        }
        while (nums[j] > mid) {
            j--;
        }

        if (j >= i) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            i++;
            j--;
        }
    }

    if (i < end) {
        quickSort(nums, i, end);
    }
    if (j > begin) {
        quickSort(nums, begin, j);
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    int** results = NULL;

    // sort the numbers
    quickSort(nums, 0, numsSize-1);

    // the index of first positive number
    int zero_index_r = numsSize;
    for (int i = numsSize-1; i >= 0; i--) {
        if (nums[i] <= 0) {
            zero_index_r = i;
            break;
        }
    }

    for (int i = 0; i < numsSize-2; i++) {
        if (nums[i] > 0) {
            break;
        }

        for (int j = i + 1; j < numsSize-1; j++) {
            // set the start index of the largest num, to reduce the loops
            int k_start = zero_index_r;
            if (zero_index_r <= j)
            {
                k_start = j+1;
            }

            for (int k = numsSize-1; k >= k_start; k--) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    break;
                }

                if (nums[i] + nums[j] + nums[k] == 0) {

                    int index_i = 0;
                    int already_exist = 0;
                    while (*returnSize-1-index_i >=0 && nums[i] == results[*returnSize - 1 - index_i][0]) {
                        if (nums[j] == results[*returnSize - 1 - index_i][1]) {
                            already_exist = 1;
                            break;
                        }
                        index_i++;
                    }

                    if (already_exist) {
                        break;
                    }

                    (*returnSize)++;
                    results = (int**)realloc(results, (*returnSize) * sizeof(int*));
                    results[*returnSize - 1] = (int *)malloc(3 * sizeof(int));

                    results[*returnSize - 1][0] = nums[i];
                    results[*returnSize - 1][1] = nums[j];
                    results[*returnSize - 1][2] = nums[k];
                    break;
                }
            }
        }
    }

    return results;
}

int main() {
    int resultSize = 0;
    int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int* nums = a;
    int **results = NULL;

    results = threeSum(nums, sizeof(a)/sizeof(a[0]), &resultSize);

    for (int i = 0 ; i < resultSize; i++) {
        printf("%d, %d, %d\n", results[i][0], results[i][1], results[i][2]);
    }

    return 0;
}
