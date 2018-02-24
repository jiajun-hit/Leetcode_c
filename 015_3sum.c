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

    for (int i = 0; i < numsSize-2; i++) {
        if (nums[i] > 0) {
            break;
        }

        int j = i + 1;
        int k = numsSize -1;
        int sum = 0;

        while (j > i && j < k) {
            sum = nums[i] + nums[j] + nums[k];

            if (sum == 0) {
                int already_exist = 0;
                int index = *returnSize - 1;

                while(index >= 0 && results[index][0] == nums[i]) {
                    if (results[index][1] == nums[j]) {
                        already_exist = 1;
                        break;
                    } else {
                        index--;
                    }
                }

                if (!already_exist) {
                    *returnSize += 1;
                    results = (int**)realloc(results, (*returnSize) * sizeof(int*));
                    results[*returnSize - 1] = (int *)malloc(3 * sizeof(int));

                    results[*returnSize - 1][0] = nums[i];
                    results[*returnSize - 1][1] = nums[j];
                    results[*returnSize - 1][2] = nums[k];
                }

                j++;
                while (j < k && nums[j] == nums[j-1]) {
                    j++;
                }
            } else if (sum > 0) {
                k--;
            } else {
                j++;
                while (j < k && nums[j] == nums[j-1]) {
                    j++;
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
