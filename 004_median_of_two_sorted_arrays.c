#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double midnum;
    int length = nums1Size + nums2Size;
    int nums[length];
    int index1 = 0, index2 = 0;

    for (int i = 0; i <= (length) / 2; i++) {
        if (index1 >= nums1Size) {
            nums[i] = nums2[index2];
            index2++;
        } else if (index2 >= nums2Size) {
            nums[i] = nums1[index1];
            index1++;
        } else if (nums1[index1] < nums2[index2]) {
            nums[i] = nums1[index1];
            index1++;
        } else {
            nums[i] = nums2[index2];
            index2++;
        }
    }

    if ((length) % 2) {
        return (double)nums[length/2];
    } else {
        return ((double)nums[length/2-1] + (double)nums[length/2]) / 2;
    }
}


int main() {
    int nums1Size, nums2Size;
    int *nums1, *nums2;
    float mid;

    scanf("%d %d", &nums1Size, &nums2Size);

    nums1 = (int*)malloc(nums1Size * sizeof(int));
    nums2 = (int*)malloc(nums2Size * sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        scanf("%d", &nums1[i]);
    }

    for (int i = 0; i < nums2Size; i++) {
        scanf("%d", &nums2[i]);
    }

    mid = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("%f\n", mid);

    return 0;
}
