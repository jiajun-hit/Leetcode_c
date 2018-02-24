#include <stdio.h>
#include <string.h>

#define bool int

bool isMatch(char* s, char* p) {
    int len_s = strlen(s);
    int len_p = strlen(p);
    int i, j = 0;
    char temp;
    int len_1, len_2;

    for (i = 0; i < len_s; i++) {
        if (j >= len_p) {
            return 0;
        }

        // when there exists .*
        if (p[j] == '.' && (j < len_p-1 && p[j+1] == '*')) {
            if (j == len_p-1) {
                return 1;
            } else {
                while (i < len_s && s[i] != p[j+1]) {
                    i++;
                }
            }
        }

        // determine the length of the repeat letters in S
        len_1 = 1;
        while(i < len_s-1 && s[i+1] == s[i]) {
            i++;
            len_1++;
        }

        while (p[j] != s[i] && p[j] != '.') {
            if(j < len_p-1 && p[j+1] == '*') {
                j += 2;
            } else {
                return 0;
            }
        }

        if (p[j] == s[i] || p[j] == '.') {
            len_2 = 1;
            if (j < len_p-1 && p[j+1] == '*') {
                j += 2;
            }

            // determine the length of the repeat letters in P
            while(j < len_p-1 && (p[j+1] == s[i] || p[j+1] == '.')) {
                j++;
                len_2++;
            }

            if (len_1 < len_2) {
                return 0;
            } else if (len_1 > len_2) {
                i = i - len_1 + len_2;
                j += len_2;
            }
        }
    }

    // s is fully matched
    if (j == len_p-1) {
        if(p[j] == '*') {
            return 1;
        } else if (p[j] == s[i-1]) {
            return 1;
        } else {
            return 0;
        }
    }

    while (j < len_p-1) {
        if (j < len_p-1 && p[j+1] != '*') {
            j += 2;
        } else {
            return 0;
        }
    }

    return 1;
}

int main() {
    char s[] = "aaa";
    char p[] = "ab*a";
    bool match = isMatch(s, p);

    if (match) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
