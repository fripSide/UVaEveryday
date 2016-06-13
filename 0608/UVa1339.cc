#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    const int maxn = 105;
    const int sz = 26;
    char s1[maxn], s2[maxn];
    int c1[sz], c2[sz];
    while (scanf("%s%s", s1, s2) != EOF) {
        int len1 = strlen(s1), len2 = strlen(s2);
        // printf("%s %s\n", s1, s2);
        memset(c1, 0, sizeof c1);
        memset(c2, 0, sizeof c2);
        for (int i = 0; i < len1; ++i) {
            c1[s1[i] - 'A']++;
            c2[s2[i] - 'A']++;
        }
        sort(c1, c1 + sz);
        sort(c2, c2 + sz);
        bool res = memcmp(c1, c2, sizeof c1) == 0;
        puts(res ? "YES" : "NO");
    }
    return 0;
}
