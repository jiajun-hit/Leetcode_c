#include <stdio.h>

double myPow(double x, int n) {
    double result = 1.0;
    double square = 1.0;

    if (n == -2147483648) {
        result = 1 / x;
        n += 1;
    }

    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    for (int i = 0; i < 1000; i++) {
        square *= x;
    }


    for (int i = 0; i < n / 1000; i++) {
        result *= square;
    }

    for (int i = 0; i < n % 1000; i++) {
        result *= x;
    }

    return result;
}

int main() {
    double x;
    int n;
    double result;

    scanf("%lf", &x);
    scanf("%d", &n);

    result = myPow(x, n);

    printf("%lf\n", result);

    return 0;
}
