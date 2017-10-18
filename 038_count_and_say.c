#include <stdio.h>

char* countAndSay(int n) {
    static char say[100000];
    static char say_temp[100000];
    int count;
    int position;

    say[0] = '1';
    say[1] = '\0';

    for (int i = 1; i < n; i++) {
        int index = 0;

        while (say[index]) {
            say_temp[index] = say[index];
            index++;
        }
        say_temp[index] = '\0';

        count = 1;
        position = 0;
        for (int j = 1; j <= index; j++) {
            if (say_temp[j] == say_temp[j-1]) {
                count++;
            } else {
                say[position++] = '0' + count;
                say[position++] = say_temp[j-1];
                count = 1;
            }
            say[position] = '\0';
        }
    }

    return say;
}

int main() {
    int n;
    char *say;

    scanf("%d", &n);

    say = countAndSay(n);

    printf("%s\n", say);

    return 0;
}
