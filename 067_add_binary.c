#include <stdio.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int length_a = strlen(a);
    int length_b = strlen(b);
    int length = length_a > length_b ? length_a : length_b;
    int num_a, num_b;
    static char c[1000];
    int plus = 0;
    int temp;

    c[length] = '\0';

    for (int i = 0; i < length; i++) {
        num_a = length_a > i ? a[length_a-i-1] - '0': 0;
        num_b = length_b > i ? b[length_b-i-1] - '0': 0;

        temp = num_a + num_b + plus;
        c[length-i-1] = temp % 2 + '0';
        plus = temp / 2;
    }

    if (plus) {
        for (int i = length + 1; i > 0; i--) {
            c[i] = c[i-1];
        }
        c[0] = '1';
    }

    return c;
}

int main() {
    char a[1000];
    char b[1000];
    char *d;

    scanf("%s %s", a, b);

    d = addBinary(a, b);

    printf("%s\n", d);

    return 0;
}
