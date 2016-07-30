#include <cstdio>
#include <cstring>

const char * rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char * msg[] = {"a mirrored palindrome", "a regular palindrome", "a mirrored string", "not a palindrome"};

char getRev(char c) {
    if (c >= 'A' && c <= 'Z') return rev[c - 'A'];
    return rev[c - '1' + 26];
}

int main() {
    char s[100];
    while (scanf("%s", s) != EOF) {
        int m = 0, p = 0;
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            if (s[i] != s[len - i - 1]) p = 1;
            if (getRev(s[i]) != s[len - i - 1]) m = 1;
        }
        printf("%s -- is %s.\n\n", s, msg[m + p * 2]);
    }
    return 0;
}
