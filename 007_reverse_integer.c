#include <stdio.h>

int reverse(int x) {
    int y = 0;
    int symbol = 1;
    int temp;

    if (x < 0) {
        x = -x;
        symbol = -1;

        if (x == -x) {
            return 0;
        }
    }
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;

        printf("%d\n", y);
        if ((y > 214748364 && x > 0) || (y == 214748364 && x > 8)) {
            return 0;
        }
    }

    return symbol * y;
}

int main() {
    int num = 0;


    scanf("%d", &num);
    printf("%d\n", reverse(num));


    return 0;
}
