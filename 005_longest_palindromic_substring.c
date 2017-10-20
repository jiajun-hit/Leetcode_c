#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char *s, int begin, int end) {
    for (int i = 0; i <= (end - begin) / 2; i++) {
        if (s[begin+i] != s[end-i]) {
            return 0;
        }
    }

    return 1;
}

char* longestPalindrome(char* s) {
    if (s == NULL) {
        return NULL;
    }

    int length = strlen(s);
    int max_pal_len = 0;
    char* result = NULL;
    int index;

    for (int i = 0; i < length; i++) {
        if (max_pal_len > length-i) {
            break;
        }

        for (int j = length-1; j >= i; j--) {
            if (s[i] == s[j]) {
                if (isPalindrome(s, i, j) && max_pal_len < j-i+1) {
                    max_pal_len = j-i+1;
                    free(result);
                    result = (char *)malloc((max_pal_len+1) * sizeof(char));

                    index = 0;
                    for (int k = i; k <= j; k++) {
                        result[index] = s[k];
                        index++;
                    }
                    result[index] = '\0';

                    break;
                }
            }
        }
    }

    return result;
}

int main() {
    char *s = "aaabaaa";
    char *palind;

    palind = longestPalindrome(s);

    printf("%s\n", palind);
    //printf("%d\n", isPalindrome(s, 2, 4));

    return 0;
}
