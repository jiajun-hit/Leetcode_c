#include <stdio.h>

char* intToRoman(int num) {
    static char roman[100];
    int i = 0;

    if (num < 1000 && num >= 900) {
        roman[i] = 'C';
        num += 100;
        i++;
    }

    while (num >= 1000) {
        roman[i] = 'M';
        num -= 1000;
        i++;

        if (num < 1000 && num >= 900) {
            roman[i] = 'C';
            num += 100;
            i++;
        }
    }

    if (num < 500 && num >= 400) {
        roman[i] = 'C';
        num += 100;
        i++;
    }

    while (num >= 500) {
        roman[i] = 'D';
        num -= 500;
        i++;

        if (num < 500 && num >= 400) {
            roman[i] = 'C';
            num += 100;
            i++;
        }
    }

    if (num < 100 && num >= 90) {
        roman[i] = 'X';
        num += 10;
        i++;
    }

    while (num >= 100) {
        roman[i] = 'C';
        num -= 100;
        i++;

        if (num < 100 && num >= 90) {
            roman[i] = 'X';
            num += 10;
            i++;
        }
    }

    if (num < 50 && num >= 40) {
        roman[i] = 'X';
        num += 10;
        i++;
    }

    while (num >= 50) {
        roman[i] = 'L';
        num -= 50;
        i++;

        if (num < 50 && num >= 40) {
            roman[i] = 'X';
            num += 10;
            i++;
        }
    }

    if (num < 10 && num >= 9) {
        roman[i] = 'I';
        num += 1;
        i++;
    }

    while (num >= 10) {
        roman[i] = 'X';
        num -= 10;
        i++;

        if (num < 10 && num >= 9) {
            roman[i] = 'I';
            num += 1;
            i++;
        }
    }

    if (num < 5 && num >= 4) {
        roman[i] = 'I';
        num += 1;
        i++;
    }

    while (num >= 5) {
        roman[i] = 'V';
        num -= 5;
        i++;

        if (num < 5 && num >= 4) {
            roman[i] = 'I';
            num += 1;
            i++;
        }
    }

    while (num > 0) {
        roman[i] = 'I';
        num -= 1;
        i++;
    }

    roman[i] = '\0';

    return roman;
}

int main() {
    int num;
    char* roman;

    scanf("%d", &num);

    roman = intToRoman(num);

    printf("%s\n", roman);

    return 0;
}
