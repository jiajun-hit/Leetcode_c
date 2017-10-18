#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    int size = pow(2, n);
    int *code = (int *)malloc(size * sizeof(int));
    int temp;

    for (int i = 0; i < size; i++) {
        temp = i;
        code[i] = (i >> 1) ^ temp;
    }

    *returnSize = size;
    return code;
}

int main() {
    int n;
    int length;
    int *l = &length;
    int *code = NULL;

    scanf("%d", &n);

    code = grayCode(n, l);

    for (int i = 0; i < length; i++) {
        printf("%d\n", code[i]);
    }

    return 0;
}
