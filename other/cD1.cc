#include <cstdio>

const int maxn = 105;
int n;
char s[maxn], t[maxn];
//char out[maxn * 2];

int main() {
    scanf("%d", &n);
    scanf("%s%s", s, t);
    //printf("%s %s\n", s, t);
    int p1 = 0, p2 = 0;
    // for (int i = 0; i < n; i++) out[i] = s[i];
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (j = 0; i + j < n; j++) {
            if (s[i + j] != t[j]) {
                j = 0;
                break;
            }
        }
        if (i + j == n) {
            p1 = j;
            break;
        }
    }
    // p2 = n;
    // for (int i = p1; i < n; i++) out[p2++] = t[i];
    // out[p2] = 0;
    printf("%d\n", n + n - p1);
    return 0;
}
