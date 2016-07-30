#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    const int maxn = 105;
    char s1[maxn], s2[maxn];
    while (scanf("%s %s", s1, s2) != EOF) {
        char t = '0' + '3';
        int len1 = strlen(s1), len2 = strlen(s2);
        int p1 = 0, p2 = 0, s = 0, len = 0;
        while (p1 < len1 && p2 < len2) {
            if (s1[p1] + s2[p2] <= t) {
                p1++, p2++;
            } else p1 = ++s, p2 = 0;
        }
        len = len1 + len2 - p2;
        p1 = p2 = s = 0;
        while (p1 < len1 && p2 < len2) {
            if (s1[p1] + s2[p2] <= t) p1++, p2++;
            else p2 = ++s, p1 = 0;
        }
        if (len > len1 + len2 - p1) 
            len = len1 + len2 - p1;
        printf("%d\n", len);
    }
    return 0;
}
