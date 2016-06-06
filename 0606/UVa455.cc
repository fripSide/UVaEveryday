#include <cstdio>
#include <cstring>

int main() {
    const int maxn = 85;
    //printf("%d\n", 1 % 2);
    char s[maxn];
    int n, c;
    scanf("%d", &n);
    scanf("%d", &c);
    while (n--) {
        scanf("%s", s);
        scanf("%d", &c);
        bool seq = true;
        int len = strlen(s);
        int k = 0;
        for (k = 1; k <= len / 2 + 1; k++) {
            //printf("len/k=%d %d %d\n", len%k, len, k);
            if (len % k == 0) {
                seq = true;
                for (int j = 0; j < k; j++) {
                    for (int l = k; l + k <= len; l += k) {
                        if (s[j] != s[j + l]) {
                            seq = false;
                            break;
                        }
                        if (!seq) break;
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
