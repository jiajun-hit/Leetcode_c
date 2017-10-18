#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1;
    int area_max = 0, area_temp;
    int length;


    while (i < j) {
        length = height[i] < height[j] ? height[i] : height[j];
        area_temp = (j - i) * length;

        if (area_temp > area_max) {
            area_max = area_temp;
        }

        while(height[i] <= length && i < j) {
            i++;
        }
        while(height[j] <= length && i < j) {
            j--;
        }
    }

    return area_max;
}

int main() {
    int height[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int area;

    area = maxArea(height, 10);

    printf("The max area is %d\n", area);


    return 0;
}
