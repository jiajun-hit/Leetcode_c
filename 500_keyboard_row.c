#include <stdio.h>
#include <stdlib.h>

int inLine(char* letters, char letter) {
    int i = 0;

    while (letters[i]) {
        if (letter == letters[i]) {
            return 1;
        }

        i++;
    }

    return 0;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    char a[] = "qwertyuiopQWERTYUIOP";
    char b[] = "asdfghjklASDFGHJKL";
    char c[] = "zxcvbnmZXCVBNM";
    char** rows = (char **) malloc(sizeof(char *) * wordsSize);
    int size = 0;


    for (int i = 0; i < wordsSize; i++) {
        char *letters = words[i];
        int j = 0;
        int row = 0;
        int flag_a = 0, flag_b = 0, flag_c = 0;
        int flag = 0;

        while (letters[j] != '\0') {
            if (inLine(a, letters[j])) {
                flag_a = 1;
            } else if (inLine(b, letters[j])) {
                flag_b = 1;
            } else if (inLine(c, letters[j])) {
                flag_c = 1;
            } else {
                break;
            }

            flag = flag_a + flag_b + flag_c;


            if (flag > 1) {
                break;
            }

            j++;
        }

        if (flag == 1) {
            rows[size] = letters;
            size++;
        }
    }

    *returnSize = size;
    return rows;
}


int main() {
    char *aa[20] = {"Hello", "Alaska", "Dad", "Peace"};
    char **words = aa;
    int i;
    char **result = NULL;
    int size;

    result = findWords(words, 4, &size);

    for (i = 0; i < size; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
