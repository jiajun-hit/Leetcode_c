#include <stdio.h>

int hammingDistance(int x, int y) {
    int temp;
    int count = 0;

    if (x > y) {
        temp = x;
        x = y;
        y =temp;
    }

    while (y) {
        if (y % 2 != x % 2) {
            count++;
        }

        x /= 2;
        y /= 2;
    }

    return count;
}

int main() {
    int x, y;

    scanf("%d %d", &x, &y);

    printf("%d\n", hammingDistance(x,y));

    return 0;
}
