#include <cstdio>
#include <cstring>

int main() {
    int n;
    char c;
    const int maxn = 90;
    char s[maxn];
    scanf("%d", &n);
    scanf("%c", &c);
    while (n--) {
        scanf("%s", s);
        scanf("%c", &c);
        int k = 0;
        int len = strlen(s);
        bool seq = true;
        for (k = 1; k <= len / 2; ++k) {
            if (len % k == 0) {
                seq = true;
                for (int j = 0; j < k; ++j) {
                    for (int l = k; l + k <= len; l += k) {
                        if (s[j] != s[j + l]) {
                            seq = false;
                            break;
                        }
                    }
                }
            }
            if (seq) break;
        }
        if (!seq) k = len;
        if (n > 0) printf("%d\n\n", k);
        else printf("%d\n", k);
    }
    return 0;
}
