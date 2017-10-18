#include <stdio.h>

int mySqrt(int x) {
    long a = x;

    while(a * a > x) {
        a = (a + x / a) / 2;
    }

    return a;
}

int main() {
    int x, num;

    scanf("%d", &x);

    num = mySqrt(x);

    printf("%d\n", num);

    return 0;
}
