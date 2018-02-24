#include <stdio.h>
#include <string.h>

int numJewelsInStones(char* J, char* S) {
    int jewel_num = 0;

    int jewel_kind = strlen(J);
    int stone_num = strlen(S);

    for(int i = 0; i < jewel_kind; i++) {
        for (int j = 0; j < stone_num; j++) {
            if (J[i] == S[j]) {
                jewel_num++;
            }
        }
    }

    return jewel_num;
}


int main() {
    int jewel_num;

    char J[] = "aA";
    char S[] = "aAAbbbb";

    jewel_num = numJewelsInStones(J, S);

    printf("%d\n", jewel_num);

    return 0;
}
