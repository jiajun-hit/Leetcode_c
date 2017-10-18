#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int sum = nums[0], sum_temp = 0;

    for (int i = 0; i < numsSize; i++) {
        sum_temp += nums[i];

        if (sum < sum_temp) {
            sum = sum_temp;
        }

        if (sum_temp < 0 ) {
            sum_temp = 0;
        }
    }

    return sum;
}


int main() {
    int nums[100];
    int num_size;
    int sum;

    scanf("%d", &num_size);

    for (int i = 0; i < num_size; i++) {
        scanf("%d", &nums[i]);
    }

    sum = maxSubArray(nums, num_size);

    printf("%d\n", sum);

    return 0;
}
