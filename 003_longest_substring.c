#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int max_length = 0;
    int i = 0, j;
    char temp[100];
    int length = 0;

    while (*(s + i)) {
        for (j = 0; j < length; j++) {
            if (*(s + i) == temp[j]) {
                length = length - j - 1;

                for (j = 0; j < length; j++) {
                    temp[j] = *(s + i - (length - j));
                }
            }
        }

        temp[length++] = *(s + i++);

        max_length = length > max_length ? length : max_length;

//        length++;
//        i++;
    }

    return max_length;
}

int main() {
    char s[100];

    scanf("%s", s);

    printf("%d\n", lengthOfLongestSubstring(s));

    return 0;
}
