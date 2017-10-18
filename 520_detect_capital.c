#include <stdio.h>

typedef _Bool bool;

bool detectCapitalUse(char* word) {
    if (!word) {
        return 0;
    }

    if (word[1] == '\0') {
        return 1;
    }


    if (word[1] >= 'a' && word[1] <= 'z') {
        int i = 1;
        while(word[i]) {
            if (word[i] > 'z' || word[i] < 'a') {
                return 0;
            }

            i++;
        }

        return 1;
    } else if ((word[0] >= 'A' && word[0] <= 'Z') && (word[1] >= 'A' && word[1] <= 'Z')) {
        int i = 2;
        while(word[i]) {
            if (word[i] > 'Z' || word[i] < 'A') {
                return 0;
            }

            i++;
        }

        return 1;
    } else if ((word[0] >= 'a' && word[0] <= 'z') && (word[1] >= 'A' && word[1] <= 'Z')) {
        return 0;
    }

    return 0;
}

int main() {
    char word[100];

    scanf("%s", word);

    printf("%d\n", detectCapitalUse(word));

    return 0;
}
