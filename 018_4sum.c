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

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int** results = NULL;
    int i, j, k, l;
    int sum;

    *returnSize = 0;

    // sort the numbers
    quickSort(nums, 0, numsSize-1);

    for (i = 0; i < numsSize-3; i++) {
        for (j = i+1; j < numsSize-2; j++) {

            k = j + 1;
            l = numsSize -1;

            while (k > j && k < l) {
                sum = nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    int already_exist = 0;
                    int index = *returnSize - 1;

                    while(index >= 0 && results[index][0] == nums[i]) {
                        if (results[index][1] == nums[j] && results[index][2] == nums[k]) {
                            already_exist = 1;
                            break;
                        } else {
                            index--;
                        }
                    }

                    if (!already_exist) {
                        *returnSize += 1;
                        results = (int**)realloc(results, (*returnSize) * sizeof(int*));
                        results[*returnSize - 1] = (int *)malloc(4 * sizeof(int));

                        results[*returnSize - 1][0] = nums[i];
                        results[*returnSize - 1][1] = nums[j];
                        results[*returnSize - 1][2] = nums[k];
                        results[*returnSize - 1][3] = nums[l];
                    }

                    k++;
                    while (k < l && nums[k] == nums[k-1]) {
                        k++;
                    }
                } else if (sum > target){
                    l--;
                } else {
                    k++;
                    while (k < l && nums[k] == nums[k-1]) {
                        k++;
                    }
                }
            }
        }
    }


    return results;
}

int main() {
    int resultSize = 0;
    int a[] = {2, 0,3,0,1,2,4};
    int* nums = a;
    int **results = NULL;
    int target = 7;

    results = fourSum(nums, sizeof(a)/sizeof(a[0]), target, &resultSize);

    for (int i = 0 ; i < resultSize; i++) {
        printf("%d, %d, %d, %d\n", results[i][0], results[i][1], results[i][2], results[i][3]);
    }

    return 0;
}
