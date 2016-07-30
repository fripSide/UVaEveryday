#include <cstdio>

int main() {
    int n, maxn = 100;
    char s[maxn];
    scanf("%d", &n);
    while (n--) {
        int t = 1, ans = 0;
        scanf("%s", s);
        for (int i = 0; s[i]; ++i) {
            if (s[i] == 'O') {
                ans += t++;
            } else if (s[i] == 'X')
                t = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
