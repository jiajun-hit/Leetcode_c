#include <stdio.h>

int romanToInt(char* s) {
    int i = 0;
    int num_temp[100];
    int num = 0;

    while (s[i]) {
        switch (s[i]){
            case 'I':
                num_temp[i] = 1;
                break;
            case 'X':
                num_temp[i] = 10;
                break;
            case 'C':
                num_temp[i] = 100;
                break;
            case 'M':
                num_temp[i] = 1000;
                break;
            case 'V':
                num_temp[i] = 5;
                break;
            case 'L':
                num_temp[i] = 50;
                break;
            case 'D':
                num_temp[i] = 500;
                break;
        }

        i++;
    }

    for (int j = 0; j < i-1; j++) {
        if (num_temp[j] < num_temp[j+1]) {
            num -= num_temp[j];
        } else {
            num += num_temp[j];
        }
    }

    num += num_temp[i-1];

    return num;
}

int main() {
    char roman[30];
    int num;

    scanf("%s", roman);

    num = romanToInt(roman);

    printf("num = %d\n", num);

    return 0;
}
