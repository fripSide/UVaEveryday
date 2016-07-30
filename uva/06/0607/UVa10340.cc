#include <cstdio>

int main() {
    const int maxn = 100000;
    char t[maxn], s[maxn];
    while (scanf("%s%s", s, t) != EOF) {
        int s1 = 0, s2 = 0;
        bool seq = true;
        while (t[s1] != 0 && s[s2] != 0) {
            if (t[s1] == s[s2]) ++s1, ++s2;
            else ++s1;
        }
        // printf("%s %s %d %d\n", t, s, s1, s2);
        seq = s[s2] == 0;
        puts(seq ? "Yes" : "No");
    }
    return 0;
}
